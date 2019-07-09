#include "CheckArgs.h"

_Bool InputArgumentsValid(unsigned int largc, const char *largv[])
{
    _Bool bResult = false; // Assume fail

    if (largc == 3)
    {
        int iResult;
        if (sscanf(largv[1], "%d", &iResult) == 1)
        {
            bResult = true;
        }
    }

    return bResult;
}

void PrintProgrammeUsage(const char *programmeName)
{
    printf("\nError with input arguments\nUSAGE: %.64s [key] [i/o file]\n", programmeName);
}
