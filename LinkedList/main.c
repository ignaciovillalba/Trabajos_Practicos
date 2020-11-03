#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>

int main()
{
    int option;
    int contID=1;
    int leyoTXT=0;
    int leyoBin=0;
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
            if(leyoTXT==0 && leyoBin==0)
            {
                leyoTXT=controller_loadFromText("data.csv",listaEmpleados);
            }
            else
            {
                printf("Archivo abierto en modo binario.\n");
            }
            break;
        case 2:
            if(leyoTXT==0 && leyoBin==0)
            {
                leyoBin=controller_loadFromBinary("data.dat",listaEmpleados);
            }
            else
            {
                printf("Archivo abierto en modo texto.\n");
            }
            break;
        case 3:
            if(leyoTXT==1 ||leyoBin==1)
            {
                controller_addEmployee(listaEmpleados,contID);
                contID++;
            }else
                {
                    printf("Aun no se cargo ningun archivo. Seleccione 1 o 2\n");
                }
            break;
        case 4:
            if(leyoTXT==1 ||leyoBin==1)
            {
                controller_editEmployee(listaEmpleados);
            }else
                {
                    printf("Aun no se cargo ningun archivo. Seleccione 1 o 2\n");
                }
            break;
        case 5:
            if(leyoTXT==1 ||leyoBin==1)
            {
                controller_removeEmployee(listaEmpleados);
            }else
                {
                    printf("Aun no se cargo ningun archivo. Seleccione 1 o 2\n");
                }
            break;
        case 6:
            if(leyoTXT==1 ||leyoBin==1)
            {
                controller_ListEmployee(listaEmpleados);
            }else
                {
                    printf("Aun no se cargo ningun archivo. Seleccione 1 o 2\n");
                }
            break;
        case 7:
            if(leyoTXT==1 ||leyoBin==1)
            {
                controller_sortEmployee(listaEmpleados);
            }else
                {
                    printf("Aun no se cargo ningun archivo. Seleccione 1 o 2\n");
                }
            break;
        case 8:
            if(leyoTXT==1 && leyoBin==0)
            {
                controller_saveAsText("data.csv",listaEmpleados);
                printf("Lista guardada con exito.\n");
            }
            else
            {
                printf("Archivo abierto en modo binario, guardarlo en la opcion 9.\n");
            }
            break;
        case 9:
            if(leyoTXT==0 && leyoBin==1)
            {
                controller_saveAsBinary("data.dat",listaEmpleados);
            }
            else
            {
                printf("Archivo abierto en modo texto, guardarlo en la opcion 8.\n");
            }

            break;
        case 10:
            printf("Usted ha elegido la opcion de salir. Hasta luego! \n");
            break;
        }
        printf("\nPresione una tecla para continuar");
        __fpurge(stdin);
        getchar();
        system("clear");
    }
    while(option!=10);

    return 0;
}
