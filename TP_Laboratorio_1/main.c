#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float numberA=0;
    float numberB=0;

    int option;

    do
    {
        MainMenu(numberA,numberB);
        option=obtainNumber("\n\n Ingrese una opcion: ");
        switch(option)
        {
        case 1:
            system("cls");
            numberA=obtainNumber("\n Ingrese primer valor: ");
            system("cls");
            break;
        case 2:
            system("cls");
            numberB=obtainNumber("\n Ingrese segundo valor: ");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\n c");
            break;
        case 4:
            printf("\n D");
            break;
        case 5:
            system("cls");
            printf("\n Eligio salir \n");
            break;
        default:
            break;
        }
    }
    while (option!=5);


        return 0;
}
