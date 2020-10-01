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

void message(char msg[], float value)
{
    printf("%s %.2f\n\n", msg, value);
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

int findFreeSpace(sEmployee employeeList[], int sizeEmployee)
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

int addEmployee(sEmployee employeeList[],int sizeEmployee,int IdGenerate)
{
    int index;
    int auxReturn=-1;
    index=findFreeSpace(employeeList,sizeEmployee);

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

int removeEmployee(sEmployee employeeList[], int sizeEmployee, int employeeCounter)
{
    int auxID=0;
    int findID=0;
    int auxReturn=0;

    if(employeeCounter!=0)
    {
        system("cls");
        printf(" _____________________\n");
        printf("| ELIMINAR EMPLEADO  |\n");
        printf("|____________________|\n");

        printEmployees(employeeList,sizeEmployee);
        auxID=GetInt("\n Ingrese el ID del empleado a eliminar: ");
        findID=FindEmployeeById(employeeList,sizeEmployee,auxID);

        if (findID==1)
        {
            changeEmployeeStatus(employeeList,sizeEmployee,auxID);
            printf("Empleado eliminado con exito!\n");
            auxReturn=1;
        }
        else
        {
            printf("ERROR! El ID ingresado no existe\n");
            auxID=GetInt("\nReingrese el ID del empleado a eliminar: ");
            findID=FindEmployeeById(employeeList,sizeEmployee, auxID);
            if (findID == 1)
            {
                changeEmployeeStatus(employeeList,sizeEmployee,auxID);
            }
            printf("Empleado eliminado con exito!\n");
            auxReturn=1;
        }
    }
    else
    {
        printf("ERROR! NO HAY NINGUN EMPLEADO DISPONIBLE.\n");
    }
    return auxReturn;
}


void changeEmployeeStatus(sEmployee employeeList[], int sizeEmployee,int auxiliaryID)
{
    int i;

    for(i=0; i<sizeEmployee; i++)
    {
        if((auxiliaryID == employeeList[i].IdEmployee) && (employeeList[i].isEmpty==OCUPADO))
        {
            employeeList[i].isEmpty = LIBRE;
            break;
        }
    }

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



void doSwitchCase2(sEmployee employeeList[], int sizeEmployee, int employeeCounter)
{
    int auxID;
    int findID=-1;
    int i;
    if(employeeCounter!=0)
    {
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
    else
    {
        printf("ERROR! NO HAY NINGUN EMPLEADO DISPONIBLE.\n");
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

void doSwitchCase4(sEmployee employeeList[], int sizeEmployee, int employeeCounter)
{
    int optionCase4=0;
    int optionCaseOrdInv=0;
    if(employeeCounter!=0)
    {
        system("cls");
        do
        {
            printf("4. INFORMAR:\n");
            printf ("%cQu%c desea que se informe?\n\n",168,130);
            printf("\t1) Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
            printf("\t2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
            fflush(stdin);
            optionCase4= GetOption("Ingrese opcion: ");
            system("cls");
        }
        while(optionCase4==0);

        orderEmployees(employeeList, sizeEmployee);
        switch(optionCase4)
        {
        case 1:
            printf("\t ______________________\n");
            printf("\t|  MOSTRAR EMPLEADO    |\n");
            printf("\t|______________________|\n");

            printf("0)Ascendente A=>Z\n");
            printf("1)Descendente Z=>A  \n");
            optionCaseOrdInv=GetOption("Ingrese en el orden a mostrar: ");
            sortEmployee(employeeList,sizeEmployee,optionCaseOrdInv);
            break;
        case 2:
            showSalaryAverage (employeeList, sizeEmployee);
            break;
        }
    }
    else
    {
        printf("ERROR! NO HAY NINGUN EMPLEADO DISPONIBLE.\n");
    }
}

void orderEmployees(sEmployee employeeList[],int sizeEmployee)
{
    int i;
    int j;
    sEmployee aux;
    for(i=0; i<sizeEmployee-1; i++)
    {
        for(j=i+1; j<sizeEmployee; j++)
        {
            if(strcmp(employeeList[i].lastName,employeeList[j].lastName)>0)
            {
                aux=employeeList[i];
                employeeList[i]=employeeList[j];
                employeeList[j]=aux;
            }
            else if(strcmp(employeeList[i].lastName,employeeList[j].lastName)==0 && employeeList[i].sector>employeeList[j].sector)
            {
                aux=employeeList[i];
                employeeList[i]=employeeList[j];
                employeeList[j]=aux;
            }
        }
    }
}

void sortEmployee(sEmployee employeeList[], int sizeEmployee, int OrdAscDesc)
{
    int i;

    printf("\t _____________________________________________________________");
    printf("\n\t|ID\t    NAME\tLAST NAME\tSALARY\t\tSECTOR|\n");
    printf("\t|_____________________________________________________________|\n");

    switch(OrdAscDesc)
    {
    case 0:
        for (i = 0; i < sizeEmployee; i++)
        {
            if(employeeList[i].isEmpty == OCUPADO)
            {
                printOneEmployee(employeeList[i]);
            }
        }
        break;
    case 1:
        for (i = sizeEmployee -1; i >=0; i--)
        {
            if(employeeList[i].isEmpty == OCUPADO)
            {
                printOneEmployee(employeeList[i]);
            }
        }
        break;
    }
}

void showSalaryAverage (sEmployee employeeList[], int sizeEmployee)
{

    int i;
    float salaryAcumulator=0;
    int counter=0;
    float average;

    for(i=0; i < sizeEmployee; i++)
    {
        if(employeeList[i].isEmpty==OCUPADO)
        {
            salaryAcumulator = salaryAcumulator + employeeList[i].salary;
            counter++;
        }
    }
    average = salaryAcumulator/counter;


    printf("\t _____________________________________________________________");
    printf("\n\t|ID\t    NAME\tLAST NAME\tSALARY\t\tSECTOR|\n");
    printf("\t|_____________________________________________________________|\n");
    for(i=0; i < sizeEmployee; i++)
    {

        if(employeeList[i].salary > average && employeeList[i].isEmpty == OCUPADO)
        {
            printOneEmployee(employeeList[i]);
            break;
        }
    }
    printf("\nLa suma total de los salarios es: %.2f\n",salaryAcumulator);
    printf("El promedio de los salarios es: %.2f\n",average);
    system("pause");
    system("cls");

}
