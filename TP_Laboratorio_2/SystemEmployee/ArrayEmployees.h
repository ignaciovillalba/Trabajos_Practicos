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

void mainMenu();

int doSwitchCase1(sEmployee employeeList[], int sizeEmployee, int employeeCounter, int employeeLoaded);

int initEmployees(sEmployee listEmployee[], int sizeEmployee);

/** \brief Print a message
 *
 * \param msj[] char Receives a message to be shown.
 * \param valor float Receives a float to be shown
 * \return void This function do not return anything because it only to print something
 *
 */
void message(char msj[], float valor);

//void loadEmployee(sEmployee employeeList[], int sizeEmployee);

int findFree(sEmployee employeeList[], int sizeEmployee);

int doSwitchCase1(sEmployee employeeList[], int sizeEmployee, int employeeCounter, int employeeLoaded);

int addEmployee(sEmployee employeeList[],int sizeEmployee,int cont);

#endif // ARRAYEMPLOYEES_H_INCLUDED
