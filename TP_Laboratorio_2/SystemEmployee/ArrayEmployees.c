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
        printf(" _____________________\n");
        printf("|   ALTA EMPLEADO     |\n");
        printf("|_____________________|\n");

        employeeList[index].IdEmployee=GenerarId(999,IdGenerate);
        printf("El ID del empleado es: %d\n",employeeList[index].IdEmployee);
        GetString("Ingrese el nombre del empleado: ",employeeList[index].name,sizeEmployee);
        GetString("Ingrese el apellido del empleado: ",employeeList[index].lastName,sizeEmployee);
        employeeList[index].salary=GetFloat("Ingrese el sueldo del empleado: ");
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

    for (i=0; i<sizeEmployee; i++)
    {
        if (employeeList[i].isEmpty==1)
        {
            printf("%4d %15s %15s %.2f %4d \n",employeeList[i].IdEmployee,
                   employeeList[i].name,
                   employeeList[i].lastName,
                   employeeList[i].salary,
                   employeeList[i].sector);
        }

    }
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
