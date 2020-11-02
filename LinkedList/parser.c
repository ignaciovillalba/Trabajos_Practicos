#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* myEmployee;
    char auxId[10];
    char auxNombre[128];
    char auxHorasTrabajadas[10];
    char auxSueldo[10];
    int leyo;
    int retorno=0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        while(!feof(pFile))
        {
            leyo=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            if(leyo==4)
            {
                myEmployee=employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                ll_add(pArrayListEmployee,myEmployee);
            }
            if(feof(pFile))
            {
                break;
            }

        }
        fclose(pFile);
        controller_ListEmployee(pArrayListEmployee);
        retorno=1;
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int leyo;

    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {
        while(!feof(pFile))
        {
            if (feof(pFile))
            {
                break;
            }
            employee=employee_new();
            leyo=fread(&employee,sizeof(Employee),1,pFile);
            if(leyo==1)
            {
                ll_add(pArrayListEmployee,employee);
            }
        }
        fclose(pFile);
        controller_ListEmployee(pArrayListEmployee);
    }

    return 1;
}

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
      Employee* employee;
    int i;
    int size;
    int id;
    char name[100];
    int hoursWorked;
    float salary;
    int ret=0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

        size=ll_len(pArrayListEmployee);
        for(i=0; i<size; i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee, i);

            if(employee_getId(employee, &id)==1 && employee_getHorasTrabajadas(employee, &hoursWorked)==1 &&
               employee_getNombre(employee, name)==1 && employee_getSueldo(employee, &salary)==1)
            {
                ret=1;
                fprintf(pFile, "%d,%s,%d,%f\n", id, name, hoursWorked, salary);
            }
        }
        fclose(pFile);

    }
    return ret;
}
