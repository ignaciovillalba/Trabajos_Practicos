#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "GetElements.h"
#define SIZE 6

int main()
{
    int option;
    int employeeLoaded=-1;
    int employeeCounter=0;
    int confirmRemove=0;
    int idGenerator=1;
    sEmployee listEmployee[SIZE];

    initEmployee(listEmployee,SIZE);
    hardcodearEmployee(listEmployee,SIZE);
    do
    {
        mainMenu();
        option= GetOption("Ingrese opcion: ");

        while (option<1 || option>5)
        {
            system("cls");
            mainMenu();
            message("ERROR! Eso no es una opcion:",option);
            option= GetOption("Reingrese opcion: ");
        }
        switch(option)
        {
        case 1:
            employeeLoaded=doSwitchCase1(listEmployee,SIZE,idGenerator);
            if(employeeLoaded==1)
            {
                employeeCounter++;
                idGenerator++;
            }
            system("pause");
            system("cls");
            break;
        case 2:
            doSwitchCase2(listEmployee,SIZE,employeeCounter);
            system("pause");
            system("cls");
            break;
        case 3:
            confirmRemove=removeEmployee(listEmployee,SIZE,employeeCounter);
            if(confirmRemove==1)
            {
                employeeCounter--;
            }
            system("pause");
            system("cls");
            break;
        case 4:
            fflush(stdin);
            doSwitchCase4(listEmployee,SIZE, employeeCounter);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            printf("\n\nUsted eligio la opcion de salir. Hasta luego\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option !=5);
    return 0;
}
