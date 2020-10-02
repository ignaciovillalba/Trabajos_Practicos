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

/** \brief Shows Main Menu
 *
 * \return void It is only to show Menu.
 *
 */
void mainMenu();

/** \brief Do the entry of employees
 *
 * \param employeeList[] sEmployee Array of employees available to charge.
 * \param sizeEmployee int Receives size of array.
 * \param IdGenerate int Receives how employees are loaded to get new ID.
 * \return int If employee was loaded
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

/** \brief To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer]
 *                    (0) if Ok
 *
 */
int initEmployee(sEmployee employeeList[],int sizeEmployee);

/** \brief Preload data to show.
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Receives size of array.
 * \return void  It is only to preload data to prove program.
 *
 */
void hardcodearEmployee(sEmployee employeeList[], int sizeEmployee);

/** \brief Search if It is available to load another employee.
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Receives size of array.
 * \return int If a free space was found return the position.
 *
 */
int findFreeSpace(sEmployee employeeList[], int sizeEmployee);

/** \brief Add in a existing list of employees the values received as parameters
 *          in the first empty position
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Array length.
 * \param IdGenerate int Receives how many employees was loaded to get ID.
 * \return int Returns [1] if employee was loaded.
 *
 */
int addEmployee(sEmployee employeeList[],int sizeEmployee,int IdGenerate);

/** \brief Find an employee to be modified or removed by ID.
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Receives the size of employees.
 * \param employeeID int Receives the ID to search.
 * \return int If employee was found return [1].
 *
 */
int FindEmployeeById(sEmployee employeeList[], int sizeEmployee, int employeeID);

/** \brief This function remove an employee by ID changing their status to LIBRE.
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Receives the size of employees.
 * \return void This function do not return anything because it only to remove an employee.
 *
 */
int removeEmployee(sEmployee employeeList[], int sizeEmployee, int employeeCounter);

/** \brief if employee was found, change status isEmpty to LIBRE
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Receives the size of employees
 * \param auxiliaryID int Receives the ID to change.
 * \return void This function do not return anything because it only to change status of an employee
 *
 */
void changeEmployeeStatus(sEmployee employeeList[], int sizeEmployee, int auxiliaryID);

/** \brief Print the content of employees array
 *
 * \param employeeList[] sEmployee Receives the array of employee to be shown.
 * \param  sizeEmployee int Receives the size of employee loaded
 * \return void This function do not return anything because show values
 *
 */
void printEmployees(sEmployee employeeList[], int sizeEmployee);

/** \brief Print only one employee
 *
 * \param employeeList sEmployee position that the user want to show.
 * \return void This function do not return anything because show values.
 *
 */
void printOneEmployee(sEmployee employeeList);

/** \brief Perform switch in case 2 of the Main Menu
 *
 * \param employeeList[] sEmployee Receives the array of employee to be modified
 * \param sizeEmployee int Receives the size of employees loaded
 * \param employeeCounter int Receives the counter to be evaluated if it is loaded an employee
 * \return void  This function do not return anything because modify values
 *
 */
void doSwitchCase2(sEmployee employeeList[], int sizeEmployee, int employeeCounter);

/** \brief Modifiy a employee that user choose
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Receives size of array.
 * \param auxID int Receives Employee ID to be modificated.
 * \return void It is only to modify a employee.
 *
 */
void modifyEmployee(sEmployee employeeList[], int sizeEmployee, int auxID);


/** \brief Shows employees depending the option that user choose.
 *
 * \param employeeList[] sEmployee Receives the array of employee to be shown.
 * \param sizeEmployee int Receives the size of employee loaded
 * \param employeeCounter int Receives the counter to be evaluated if it is loaded an employee
 * \return void This function do not return anything because show values
 *
 */
void doSwitchCase4(sEmployee employeeList[], int sizeEmployee, int employeeCounter);

/** \brief Order employees depending condition.
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Receives size of array.
 * \return void  It is only to order employees.
 *
 */
void orderEmployees(sEmployee employeeList[],int sizeEmployee);

/** \brief  Sort the elements in the array of employees, the argument order
 *          indicate UP or DOWN order
 *
 * \param employeeList[] sEmployee array of employees.
 * \param sizeEmployee int Receives the size of employees.
 * \param OrdAscDesc int Receives order thar user want to show employees
 * \return void This function do not return anything because it only to sort something.
 *
 */
void sortEmployee(sEmployee employeeList[], int sizeEmployee, int OrdAscDesc);

/** \brief Print salary acumulated and Its average.
 *          Also print employees with salary higher than average.
 *
 * \param employeeList sEmployee array of employees.
 * \param sizeEmployee int Receives size of array.
 * \return void It is only to print values.
 *
 */
void showSalaryAverage (sEmployee employeeList[], int sizeEmployee);

#endif // ARRAYEMPLOYEES_H_INCLUDED
