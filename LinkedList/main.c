#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>

int main()
{
    int option;
    int contID=1;
    int confirmacion;
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
            confirmacion=getchar();
            break;
        case 2:
            controller_loadFromBinary("data.dat",listaEmpleados);
            break;
        case 3:
            controller_addEmployee(listaEmpleados,contID);
            contID++;
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("data.dat",listaEmpleados);
            break;
        case 10:
            printf("Usted ha elegido la opcion de salir. Hasta luego! \n");
            break;
        }
    }
    while(option!=10);

    return 0;
}
