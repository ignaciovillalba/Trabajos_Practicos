#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "GetElements.h"
#define LIBRE 0
#define OCUPADO 1

void mainMenu()
{
    printf("\t |----------------------------------|\n");
    printf("\t |Bienvenido al sistema de empleados|\n");
    printf("\t |__________________________________|\n\n");

    printf(" 1)Alta empleados.\n");
    printf(" 2)Modificar empleados.\n");
    printf(" 3)Baja empleados.\n");
    printf(" 4)INFORMAR\n");
    printf("\t 1)Listado de empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("\t 2)Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
    printf(" 5)Salir\n");
}

int doSwitchCase1(sEmployee employeeList[], int sizeEmployee,int IdGenerate)
{
    int employeeLoaded;
    employeeLoaded=addEmployee(employeeList,sizeEmployee,IdGenerate);
    if(employeeLoaded==1)
    {
        printf("\nEMPLEADO INGRESADO\n\n");
    }
    else
    {
        printf("\nNO HAY MAS ESPACIO!!\n");
    }
    return employeeLoaded;
}

int addEmployee(sEmployee employeeList[],int sizeEmployee,int IdGenerate)
{
    int index;
    int auxReturn=-1;
    index=findFree(employeeList,sizeEmployee);

    if(index!=-1)
    {
        system("cls");
        printf(" _____________________\n");
        printf("|   ALTA EMPLEADO     |\n");
        printf("|_____________________|\n");

        employeeList[index].IdEmployee=GenerarId(999,IdGenerate);
        printf("El ID del empleado es: %d\n",employeeList[index].IdEmployee);
        GetString("Ingrese el nombre del empleado: ",employeeList[index].name,sizeEmployee);
        GetString("Ingrese el apellido del empleado: ",employeeList[index].lastName,sizeEmployee);

        do
        {
            employeeList[index].salary=GetFloat("Ingrese el sueldo del empleado: ");
        }
        while(employeeList[index].salary<1);
        employeeList[index].sector=GetInt("Ingrese el sector del empleado(1 a 10): ");
        while (employeeList[index].sector < 1 || employeeList[index].sector > 10)
        {
            employeeList[index].sector=GetInt("Reingrese el sector del empleado: ");
        }
        employeeList[index].isEmpty=OCUPADO;

        auxReturn=1;
    }
    return auxReturn;
}

int initEmployee(sEmployee employeeList[],int sizeEmployee)
{
    int i;
    int auxReturn=-1;
    for(i=0; i<sizeEmployee; i++)
    {
        employeeList[i].isEmpty=LIBRE;
        auxReturn=0;
    }
    return auxReturn;
}

int findFree(sEmployee employeeList[], int sizeEmployee)
{
    int i;
    int index = -1;

    for(i=0; i<sizeEmployee; i++)
    {
        if(employeeList[i].isEmpty==LIBRE)
        {
            index =  i;
            break;
        }
    }
    return index;
}

void message(char msg[], float value)
{
    printf("%s %.2f\n\n", msg, value);
}

void printEmployees(sEmployee employeeList[], int sizeEmployee)
{
    int i;

    printf("\t _____________________________________________________________");
    printf("\n\t|ID\t    NAME\tLAST NAME\tSALARY\t\tSECTOR|\n");
    printf("\t|_____________________________________________________________|\n");

    for (i=0; i<sizeEmployee; i++)
    {
        if (employeeList[i].isEmpty==1)
        {
            printOneEmployee(employeeList[i]);
        }

    }
}

void printOneEmployee(sEmployee employeeList)
{
            printf("\t|%4d\t%8s\t%8s\t%5.2f\t  %3d |\n",employeeList.IdEmployee,
                   employeeList.name,
                   employeeList.lastName,
                   employeeList.salary,
                   employeeList.sector);

            printf("\t|_____________________________________________________________|\n");
}

void hardcodearEmployee(sEmployee employeeList[], int sizeEmployee)
{

    int IdEmployee[4]= {1004, 1005, 1006, 1003};
    char name[4][51] = {"Pepe","Juan","Leonel","Moni"};
    char lastName[4][51]= {"Gonzalez","Benito","Gonzalez","Argento"};
    float salary[4]= {20000.35, 26940.74, 31934.07,15033.48};
    int sector[4]= {1,2,3,6};
    int isEmpty[4]= {1,1,1,1};

    int i;
    for(i=0; i<4; i++)
    {
        employeeList[i].IdEmployee= IdEmployee[i];
        strcpy(employeeList[i].name,name[i]);
        strcpy(employeeList[i].lastName,lastName[i]);
        employeeList[i].salary=salary[i];
        employeeList[i].sector=sector[i];
        employeeList[i].isEmpty= isEmpty[i];
    }
}

void removeEmployee(sEmployee employeeList[], int sizeEmployee)
{
    int auxID=0;
    int findID=0;
    int i;
    system("cls");
    printf(" _____________________\n");
    printf("| ELIMINAR EMPLEADO  |\n");
    printf("|____________________|\n");

    printEmployees(employeeList,sizeEmployee);
    auxID=GetInt("\n Ingrese el ID del empleado a eliminar: ");
    findID=FindEmployeeById(employeeList,sizeEmployee,auxID);

    if (findID==1)
    {
        for(i=0; i<sizeEmployee; i++)
        {
            if((auxID == employeeList[i].IdEmployee) && (employeeList[i].isEmpty==OCUPADO))
            {
                employeeList[i].isEmpty = LIBRE;
                break;
            }
        }
        printf("Empleado eliminado con exito!\n");
    }
    else
    {
        printf("ERROR! El ID ingresado no existe\n");
        auxID=GetInt("\nReingrese el ID del empleado a eliminar: ");
        findID=FindEmployeeById(employeeList,sizeEmployee, auxID);
        if (findID == 1)
        {
            for(i=0; i<sizeEmployee; i++)
            {
                if((auxID == employeeList[i].IdEmployee) && (employeeList[i].isEmpty==OCUPADO))
                {
                    employeeList[i].isEmpty = LIBRE;
                    break;
                }
            }

        }
        printf("Empleado eliminado con exito!\n");
    }
}


int FindEmployeeById(sEmployee employeeList[], int sizeEmployee, int employeeID)
{
    int i;
    int index=0;

    for (i=0; i<sizeEmployee; i++)
    {
        if (employeeID==employeeList[i].IdEmployee && employeeList[i].isEmpty== OCUPADO)
        {
            index=1;
            break;
        }
    }

    return index;
}

void doSwitchCase2(sEmployee employeeList[], int sizeEmployee)
{
    int auxID;
    int findID=-1;
    int i;
    system("cls");
    printf(" _____________________\n");
    printf("|  MODIFICAR EMPLEADO |\n");
    printf("|_____________________|\n");
    printEmployees(employeeList,sizeEmployee);
    auxID=GetInt("\nIngrese el ID del empleado a modificar: ");
    findID=FindEmployeeById(employeeList,sizeEmployee, auxID);

    if (findID == 1)
    {
        for(i=0; i<sizeEmployee; i++)
        {
            modifyEmployee(employeeList,sizeEmployee, auxID);
            break;
        }
    }
    else
    {
        printf("ERROR! El ID ingresado no existe\n");
        auxID=GetInt("\nReingrese el ID del empleado a modificar: ");
        findID=FindEmployeeById(employeeList,sizeEmployee, auxID);
        if (findID == 1)
        {
            for(i=0; i<sizeEmployee; i++)
            {
                modifyEmployee(employeeList,sizeEmployee, auxID);
                break;
            }
        }
        printf("Usted ha modificado el empleado con exito.\n");
    }
}

void modifyEmployee(sEmployee employeeList[], int sizeEmployee, int auxID)
{
    int i;
    int optionCase2=0;
    for(i=0; i<sizeEmployee; i++)
    {
        if(employeeList[i].IdEmployee==auxID && employeeList[i].isEmpty==OCUPADO)
        {
            do
            {
                system("cls");
                printf("\t _____________________________________________________________");
                printf("\n\t|ID\t    NAME\tLAST NAME\tSALARY\t\tSECTOR|\n");
                printf("\t|_____________________________________________________________|\n");
                printOneEmployee(employeeList[i]);
                printf("\n*************************\n");
                printf("1).Nombre\n");
                printf("2).Apellido\n");
                printf("3).Salario\n");
                printf("4).Sector\n");
                printf("5).Salir\n");
                optionCase2=GetOption("\n\nQue desea modificar?: ");

                while (optionCase2<1 || optionCase2>5)
                {
                    printf("\n\n¿Que desea modificar del empleado?");
                    message("\nERROR! Eso no es una opcion:",optionCase2);
                    optionCase2= GetOption("Reingrese opcion: ");
                }
                switch(optionCase2)
                {
                case 1:
                    GetString("\nIngrese el nuevo Nombre: ",employeeList[i].name,sizeEmployee);
                    break;
                case 2:
                    GetString("\nIngrese el nuevo Apellido: ", employeeList[i].lastName,sizeEmployee);
                    break;
                case 3:
                    employeeList[i].salary=GetFloat("\nIngrese el nuevo salario: ");
                    break;
                case 4:
                    employeeList[i].sector=GetInt("\nIngrese el nuevo sector (1 a 10): ");
                    while (employeeList[i].sector < 1 || employeeList[i].sector > 10)
                    {
                        employeeList[i].sector=GetInt("Reingrese el sector del empleado: ");
                    }
                    break;
                case 5:
                    printf("\n\nUsted ha modificado el empleado con exito.\n");
                    break;
                }
            }
            while(optionCase2!=5);
        }
    }

}
