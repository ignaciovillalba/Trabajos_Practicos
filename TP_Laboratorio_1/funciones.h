#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Muestra menu de opciones
 *
 * \param numeroA float Es el 1er valor ingresado por el usuario y se muestra en el menu de opciones
 * \param numeroB float Es el 2do valor ingresado por el usuario y se muestra en el menu de opciones
 * \return void No retorna nada ya que solo muestra opciones.
 *
 */
void MainMenu (float numberA, float numberB);

/** \brief Obtener numeros
 *
 * \param mensaje[] char Mensaje de ingreso de valor.
 * \return float Numero obtenido al ingreso del usuario.
 *
 */
float obtainNumber(char message[]);


/** \brief Realiza el switch segun opcion
 *
 * \param numberA float primer valor a interactuar segun la opcion elegida.
 * \param numberB float segundo valor a interactuar segun la opcion elegida.
 * \return void No retorna nada, ya que solo realiza las funcion de switch.
 *
 */
void doSwitch(float numberA, float numberB);

/** \brief Realiza la suma de valores ingresados.
 *
 * \param 'numeroA' es el 1er valor ingresado por el usuario.
 * \param 'numeroB' es el 2do valor ingresado por el usuario.
 * \return Retorna valor de la adicion de ambos valores.
 *
 */
float additionFunction(float numberA,float numberB);

/** \brief Realiza la resta de valores ingresados.
 *
 * \param 'numeroA' es el 1er valor ingresado por el usuario.
 * \param 'numeroB' es el 2do valor ingresado por el usuario.
 * \return Retorna valor de la diferencia de ambos valores.
 *
 */
float substractionFunction(float numberA,float numberB);

/** \brief Realiza la multiplicacion de los valores ingresados.
 *
 * \param 'numeroA' es el 1er valor ingresado por el usuario.
 * \param 'numeroB' es el 2do valor ingresado por el usuario.
 * \return Retorna valor del producto de ambos valores.
 *
 */
float multiplicationFunction(float numberA,float numberB);

/** \brief Realiza la division de los valores ingresados.Si el valor B es igual a cero, se da un mensaje de ERROR.
 *
 * \param 'numeroA' es el 1er valor ingresado por el usuario.
 * \param 'numeroB' es el 2do valor ingresado por el usuario.
 * \return Retorna valor del cociente de ambos valores.
 *
 */
float divisionFunction(float numberA,float numberB);

/** \brief Realiza validacion de si es un valor entero y positivo.
 *         De ser verdad se multiplica todos los numeros anteriores al numero seleccionado hasta llegar a 1
 *
 * \param  Valor a validar de ser entero, positivo y luego factorearlo.
 * \return Retorna el factorial del valor
 *
 */
int factorialFunction (float number);

/** \brief Muestra mensaje según funcion solicitada.
 *
 * \param msj[] char Mensaje de resultado a mostrar.
 * \param valor float valor de resultado a mostrar.
 * \return void no retorna ya que solo informa datos.
 *
 */
void resultMessage(char msg[], float valueResult);

#endif // FUNCIONES_H_INCLUDED
