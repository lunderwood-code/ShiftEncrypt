#ifndef CHECKARGS_H_INCLUDED
#define CHECKARGS_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

/** \brief Gets input from user and sees if it is valid
 *
 * \param largc - "local argc"
 * \param  largv - "local argv"
 * \return True if inputs correct number
 *
 */
 _Bool InputArgumentsValid(unsigned int largc, const char *largv[]);

 /** \brief Prints usage to user
  *
  * \param programmeName - The current name of the programme (arv[0])
  * \return
  *
  */
void PrintProgrammeUsage(const char *programmeName);

#endif // CHECKARGS_H_INCLUDED
