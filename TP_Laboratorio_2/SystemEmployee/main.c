#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "GetElements.h"
#define SIZE 4

int main()
{
    int option;
    int employeeCounter=0;
    int employeeLoaded=-1;
    sEmployee listEmployee[SIZE];

    initEmployees(listEmployee,SIZE);
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
            printf("\nAlta empleados\n");
            employeeCounter++;
            employeeLoaded=doSwitchCase1(listEmployee,SIZE,employeeCounter,employeeLoaded);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("\nModificar empleados.\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\nBaja empleados.\n");
            system("pause");
            system("cls");
            break;
        case 4:
            printf("\nINFORMAR\n");
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            printf("\nUsted eligio la opcion de salir. Hasta luego\n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option !=5);

    return 0;
}
