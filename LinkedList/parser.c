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
    char auxID[10];
    char auxName[128];
    char auxWorkedHours[10];
    char auxSalary[10];
    int leyo;
    int retorno=0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxName,auxWorkedHours,auxSalary);
        while(!feof(pFile))
        {
            leyo=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxName,auxWorkedHours,auxSalary);
            if(leyo==4)
            {
                myEmployee=employee_newParametros(auxID,auxName,auxWorkedHours,auxSalary);
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
    Employee* myEmployee;

    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {
        while(!feof(pFile))
        {
            if (feof(pFile))
            {
                break;
            }
            myEmployee=employee_new();
            if(myEmployee!=NULL)
            {
                if(fread(myEmployee,sizeof(Employee),1,pFile)==1)
                {
                    ll_add(pArrayListEmployee,myEmployee);
                }
            }
        }
        fclose(pFile);
        controller_ListEmployee(pArrayListEmployee);
    }
    return 1;
}

int parser_EmployeeToText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* myEmployee;
    int i;
    int size;
    int auxID;
    char auxName[100];
    int auxWorkedHours;
    int auxSalary;
    int retorno=0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
        size=ll_len(pArrayListEmployee);
        for(i=0; i<size; i++)
        {
            myEmployee=(Employee*)ll_get(pArrayListEmployee, i);

            if(employee_getId(myEmployee, &auxID)==1 && employee_getHorasTrabajadas(myEmployee, &auxWorkedHours)==1 &&
                    employee_getNombre(myEmployee, auxName)==1 && employee_getSueldo(myEmployee, &auxSalary)==1)
            {
                retorno=1;
                fprintf(pFile, "%d,%s,%d,%d\n", auxID, auxName, auxWorkedHours, auxSalary);
            }
        }
        ll_clear(pArrayListEmployee);
        fclose(pFile);

    }
    return retorno;
}

int parser_EmployeeToBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* myEmployee;
    int size;
    int i;
    int retorno=0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        size=ll_len(pArrayListEmployee);

        for(i=0; i<size; i++)
        {
            myEmployee=(Employee*)ll_get(pArrayListEmployee, i);
            fwrite(myEmployee, sizeof(Employee),1,pFile);
        }
        fclose(pFile);
        retorno=1;
    }

    return retorno;
}

