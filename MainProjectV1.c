#include "ProjectView.h"
#include "ShiftEncrypt.h"

enum userRequest{read, append, error};

static enum userRequest getUserMode(void);

static int handleInputFile(const char *key, FILE *file);
static int handleOutputFile(const char *key, FILE *file);


int MainProject(const char *key, const char *savedFile)
{
    int iResult = EXIT_FAILURE;

    enum userRequest response = getUserMode();

    if (response == read)
    {
        FILE *inputFile;
        if ((inputFile = fopen(savedFile, "r")))
        {
            iResult = handleInputFile(key, inputFile);

            fclose(inputFile);
        }
        else
        {
            puts("\nCould not open file for reading");
        }
    }
    else if (response == append)
    {
        FILE *outputFile;

        if ((outputFile = fopen(savedFile, "a")))
        {
            iResult = handleOutputFile(key, outputFile);

            fclose(outputFile);
        }
        else
        {
            puts("\nCould not open file for writing");
        }
    }


    return iResult;
}

static int handleInputFile(const char *key, FILE *file)
{
    int iResult = EXIT_FAILURE;
    char inputBuffer[BUFSIZ]={0};

    while (fgets(inputBuffer, BUFSIZ, file))
    {
        // Remove \n
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

        PrintPlainText(key, inputBuffer);
        iResult = EXIT_SUCCESS;

        // New line for different entry
        putchar('\n');
    }

    return iResult;
}


static int handleOutputFile(const char *key, FILE *file)
{
    int iResult = EXIT_FAILURE;
    char outputBuffer[BUFSIZ]={0};

    // Start new line
    fputc('\n', file);

    if (fgets(outputBuffer, BUFSIZ, stdin))
    {
        // Remove \n
        outputBuffer[strcspn(outputBuffer, "\n")] = '\0';

        int outputSize = strlen(outputBuffer);

        EncryptBufferconst(key, &outputBuffer);

        fwrite(outputBuffer, sizeof(*outputBuffer), outputSize, file);

        iResult = EXIT_SUCCESS;
    }

    return iResult;
}

static enum userRequest getUserMode(void)
{
    puts("\nOptions:\n1 - Print contents\n2 - Append\n");

    char userResponse[BUFSIZ] = {0};

    if(fgets(userResponse, BUFSIZ, stdin))
    {
        int userResponseAsInt = 0;

        if (sscanf(userResponse, "%d", &userResponseAsInt) == 1)
        {
            switch(userResponseAsInt)
            {
            case 1:

                return read;

            case 2:

                return append;
            }
        }
    }

    return error;
}
