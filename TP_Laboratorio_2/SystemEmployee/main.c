#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define SIZE 4

int main()
{
    sEmployee listEmployee[SIZE];
    int option;


    initEmployees(listEmployee,SIZE);
    do
    {
        mainMenu();
        printf("\n Selecciones una opcion: ");
        scanf("%d",&option);

        while (option<1 || option>5)
        {
            system("cls");
            mainMenu();
            printf("\n ERROR! ESA NO ES UNA OPCION: ");
            scanf("%d",&option);
        }
        switch(option)
        {
        case 1:
            printf("\nAlta empleados\n");
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
