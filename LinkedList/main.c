#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>


int main()
{
    int option;
    LinkedList* listaEmpleados;

    listaEmpleados= ll_newLinkedList();

    do
    {
        do
        {
            Menu();
            scanf("%d",&option);
            system("clear");
        }
        while(option<1 || option>10);

        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            //controller_loadFromBinary
            break;
        case 3:
            //controller_addEmployee
            break;
        case 4:
            //controller_editEmployee
            break;
        case 5:
            // controller_removeEmployee
            break;
        case 6:
            //controller_ListEmployee
            break;
        case 7:
            //controller_sortEmployee
            break;
        case 8:
            //controller_saveAsText("data.csv",myEmployee);
            break;
        case 9:
            //controller_saveAsBinary
            break;
        case 10:
            printf("Usted ha elegido la opcion de salir. Hasta luego! \n");
            getchar();
            break;
        }
        system("clear");
    }
    while(option!=10);

    return 0;
}
