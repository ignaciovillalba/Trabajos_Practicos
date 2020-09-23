#include <stdio.h>
#include <stdlib.h>
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

void initEmployees(sEmployee employeeList[], int sizeEmployee)
{
    int i;

  for(i=0; i<sizeEmployee; i++)
  {
      employeeList[i].isEmpty = LIBRE;
  }
}


void loadEmployee(sEmployee employeeList[], int sizeEmployee)
{
  int index;

  index = findFree(employeeList, sizeEmployee);

  if(index!=-1)
  {
      employeeList[index] = crearUnAlumno();
  }
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

