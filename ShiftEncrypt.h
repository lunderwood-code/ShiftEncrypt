#ifndef SHIFTENCRYPT_H_INCLUDED
#define SHIFTENCRYPT_H_INCLUDED


/** \brief When given an encryped line and a key, this function will print out plain text on stdout
 *
 * \param key const char*
 * \param line const char*
 * \return int
 *
 */
int PrintPlainText(const char *key, const char *line);

/** \brief Encryps buffer "line" with key
 *
 * \param key char*
 * \param line const char*
 * \return int
 *
 */
int EncryptBufferconst(const char *key, char (*line)[BUFSIZ]);

#endif // SHIFTENCRYPT_H_INCLUDED
