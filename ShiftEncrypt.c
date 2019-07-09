#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "ShiftEncrypt.h"

#define MIN_ENC_CHARACTER ' '
#define MAX_ENC_CHARACTER '~'

static char decrypt(char keyByte, unsigned char messageByte);
static char encrypt(char keyByte, unsigned char messageByte);

int PrintPlainText(const char *key, const char *line)
{
    int iResult = EXIT_FAILURE;
    int keyLength = strlen(key);
    int i = 0;

    if (keyLength != 0)
    {
        printf("\nOutput:\n\r");
        while(line[i] != '\0')
        {
            putchar( decrypt(key[i % keyLength], line[i]));
            i++;
        }

        iResult = EXIT_SUCCESS;
    }
    else
    {
        puts("*** ERROR: 0 length key ***");
    }

    return iResult;
}

int EncryptBufferconst(const char *key, char (*line)[BUFSIZ])
{
    int iResult = EXIT_FAILURE;
    int keyLength = strlen(key);
    int i = 0;

    if (keyLength != 0)
    {
        while((*line)[i] != '\0')
        {
            (*line)[i] = encrypt(key[i % keyLength], (*line)[i]);
            i++;
        }

        iResult = EXIT_SUCCESS;
    }
    else
    {
        puts("*** ERROR: 0 length key ***");
    }

    return iResult;
}

//valid chars -> 32 to 126
static char decrypt(char keyByte, unsigned char messageByte)
{
    if ((messageByte >= MIN_ENC_CHARACTER) && (messageByte <= MAX_ENC_CHARACTER))
    {
        // adjust to range
        messageByte -= MIN_ENC_CHARACTER;

        // Subract key
        messageByte += keyByte;

        // Adjust back to ASCII range
        messageByte = (messageByte % MAX_ENC_CHARACTER) + MIN_ENC_CHARACTER;

    }


    return messageByte;
}

static char encrypt(char keyByte, unsigned char messageByte)
{
    if ((messageByte >= MIN_ENC_CHARACTER) && (messageByte <= MAX_ENC_CHARACTER))
    {
        // adjust to range
        messageByte -= MIN_ENC_CHARACTER;

        // start at offset Max character
        messageByte += MAX_ENC_CHARACTER;

        // Subract key
        messageByte -= keyByte;

        // Adjust back to ASCII range
        messageByte = (messageByte % MAX_ENC_CHARACTER) + MIN_ENC_CHARACTER;

    }


    return messageByte;
}
