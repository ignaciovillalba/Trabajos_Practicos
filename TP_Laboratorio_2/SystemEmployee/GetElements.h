
/** \brief The function ask the user to enter data of type string and make of the function Validateion_String.
 *
 * \param char[] Receives a message to show.
 * \param char[] Receives data that user enters.
 * \param int Receives the length of the "string".
 * \return void Return nothing
 *
 */
void GetString(char message[],char input[],int sizeString);


/** \brief Ask the user to enter an option for menu in a range of 1 to 5 (amount of option in menu). Use the same for sector(1 to 5) and make of the function Validate_Integer.
 *
 * \param char[] Receives a message to show.
 * \return int Return an option validated.
 *
 */
int GetOption(char message[]);


/** \brief Ask the user to enter a number and after get validate using function Validation_IntId.
 *
 * \param char[] Receives a message to show.
 * \param int Receive size of the "string".
 * \return int Return validated number.
 *
 */
int GetInt(char message[],int sizeInt);


/** \brief Ask the user to enter a float number.
 *
 * \param char[] Receives a message to show.
 * \return float Return the number loaded.
 *
 */
float GetFloat(char message[]);

/** \brief Ask the user to enter a character
 *
 * \param message[] char Receives a message to show.
 * \return char Return character validated.
 *
 */
char GetChar(char message[]);


/** \brief Ask the user for sort by surname to enter 1 if decide print Employees in UP way.
 *                                                   0 if decide print Employees in DOWN way.
 * \param char message[] Receives a message to show.
 * \return int Return validated number.
 *
 */
int GetUpDown(char message[]);

/** \brief
 *
 * \param id int
 * \param cont int
 * \return int
 *
 */
int GenerarId(int id,int cont);
