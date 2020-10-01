
/** \brief Validate string in case user enter: Space.
                                               Less than 3 letters.
                                               Enter-key.
                                               Something that not are letters.
 *
 * \param char[] Receives string.
 * \return int Return 0 for Error.
 *                    1 for OK.
 *
 */
int Validation_String(char string[]);


/** \brief Validate a strings of numbers and validate in a range from 1 to 5 and if the user enter space or Enter-key for first time.
 *                It used to validate options.
 *
 * \param char[] Receives string.
 * \return int Return 0 for Error.
 *                     1 for OK.
 *
 */
int Validation_Integer(char stringInteger[]);


/** \brief Validate a strings of numbers and validate if the user enter space or Enter-key for first time and something that not is a number.
 *
 * \param char[] Receives string.
 * \return int Return 0 for Error.
 *                    1 for OK.
 *
 */
int Validation_IntID(char[]);
