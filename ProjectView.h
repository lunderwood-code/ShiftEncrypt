#ifndef PROJECTVIEW_H_INCLUDED
#define PROJECTVIEW_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** \brief Main flow of the project
 *
 * \param key - XOR or Shift key
 * \param savedFile - Attempt to open file at this location.
 * \return
 *
 */
int MainProject(const char *key, const char *savedFile);

#endif // PROJECTVIEW_H_INCLUDED
