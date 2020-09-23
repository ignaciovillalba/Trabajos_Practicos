#include <stdio.h>
#include <stdlib.h>
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

int doSwitchCase1(sEmployee employeeList[], int sizeEmployee, int employeeCounter, int employeeLoaded)
{
    employeeLoaded=addEmployee(employeeList,sizeEmployee,employeeCounter);
        if(employeeLoaded==1)
    {
        printf("\nEMPLEADO INGRESADO\n\n");
        system("pause");
        system("cls");
    }
    else
    {
        mainMenu();
        printf("NO HAY MAS ESPACIO!!\n");
        system("pause");
        system("cls");
    }
    return employeeLoaded;
}

int addEmployee(sEmployee employeeList[],int sizeEmployee,int cont)
{
    int index;
    int auxReturn=-1;
    index=findFree(employeeList,sizeEmployee);


    if(index!=-1)
    {
        printf(" _____________________\n");
        printf("|   ALTA EMPLEADO     |\n");
        printf("|_____________________|\n");

        employeeList[index].IdEmployee=GenerarId(999,cont);
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

int initEmployees(sEmployee employeeList[],int sizeEmployee)
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
