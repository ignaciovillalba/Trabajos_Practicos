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
            if(employeeCounter!=0)
            {
            printf("\nModificar empleados.\n");
            doSwitchCase2(listEmployee,SIZE);
            }
            else
            {
                printf("ERROR! NO HAY NINGUN EMPLEADO DISPONIBLE.\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(employeeCounter!=0)
            {
                removeEmployee(listEmployee,SIZE);
                employeeCounter--;
            } else
            {
                printf("ERROR! NO HAY NINGUN EMPLEADO DISPONIBLE.\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            fflush(stdin);
            doSwitchCase4(listEmployee,SIZE);
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
