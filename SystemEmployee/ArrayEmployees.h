#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int IdEmployee;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;

/** \brief
 *
 * \return void
 *
 */
void mainMenu();

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \param IdGenerate int
 * \return int
 *
 */
int doSwitchCase1(sEmployee employeeList[], int sizeEmployee,int IdGenerate);

/** \brief Print a message
 *
 * \param msj[] char Receives a message to be shown.
 * \param valor float Receives a float to be shown
 * \return void This function do not return anything because it only to print something
 *
 */
void message(char msj[], float valor);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \return int
 *
 */
int initEmployee(sEmployee employeeList[],int sizeEmployee);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \return void
 *
 */
void hardcodearEmployee(sEmployee employeeList[], int sizeEmployee);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \return int
 *
 */
int findFreeSpace(sEmployee employeeList[], int sizeEmployee);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \param IdGenerate int
 * \return int
 *
 */
int addEmployee(sEmployee employeeList[],int sizeEmployee,int IdGenerate);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \param employeeID int
 * \return int
 *
 */
int FindEmployeeById(sEmployee employeeList[], int sizeEmployee, int employeeID);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \return void
 *
 */
void removeEmployee(sEmployee employeeList[], int sizeEmployee);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \return void
 *
 */
void printEmployees(sEmployee employeeList[], int sizeEmployee);

/** \brief
 *
 * \param employeeList sEmployee
 * \return void
 *
 */
void printOneEmployee(sEmployee employeeList);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \return void
 *
 */
void doSwitchCase2(sEmployee employeeList[], int sizeEmployee);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \param auxID int
 * \return void
 *
 */
void modifyEmployee(sEmployee employeeList[], int sizeEmployee, int auxID);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \return void
 *
 */
void doSwitchCase4(sEmployee employeeList[], int sizeEmployee);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \return void
 *
 */
void orderEmployees(sEmployee employeeList[],int sizeEmployee);

/** \brief
 *
 * \param employeeList[] sEmployee
 * \param sizeEmployee int
 * \param OrdAscDesc int
 * \return void
 *
 */
void sortEmployee(sEmployee employeeList[], int sizeEmployee, int OrdAscDesc);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void showSalaryAverage (sEmployee employeeList[], int sizeEmployee);


#endif // ARRAYEMPLOYEES_H_INCLUDED
