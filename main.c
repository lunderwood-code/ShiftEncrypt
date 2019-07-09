#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "ProjectView.h"
#include "CheckArgs.h"

// Usage: argv[0] [key] [saved file name]
int main(int argc, const char* argv[])
{
    int iResult = EXIT_FAILURE;

    if (InputArgumentsValid(argc, argv))
    {
        iResult = MainProject(argv[1], argv[2]);
    }
    else
    {
        PrintProgrammeUsage(argv[0]);
    }

    return iResult;
}
