#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;
    pFile=(FILE*)malloc(sizeof(FILE));

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            retorno=parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
        else
        {
            printf("Archivo inexistente,se procedera a crear una carpeta.\n");
            pFile=fopen(path,"w");
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        ll_clear(pArrayListEmployee);
        pFile=fopen(path,"rb");
        if(pFile!=NULL)
        {
            retorno=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        }
        else
        {
            printf("Archivo inexistente.\n");
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int contID)
{
    Employee* myEmployee;
    int auxID;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxsueldo;
    int retorno=-1;

    if(pArrayListEmployee!=NULL)
    {
        myEmployee=employee_new();
        if(myEmployee!=NULL)
        {
            auxID=GenerarId(1000,contID);
            printf("ID Nuevo empleado: %d\n", auxID);
            printf("Ingrese nombre: ");
            __fpurge(stdin);
            scanf("%s",auxNombre);
            printf("Ingrese horas trabajadas: ");
            scanf("%d",&auxHorasTrabajadas);
            printf("Ingrese sueldo: ");
            scanf("%d",&auxsueldo);

            if(employee_setId(myEmployee,auxID)==1 &&
                    employee_setNombre(myEmployee,auxNombre)==1 &&
                    employee_setHorasTrabajadas(myEmployee,auxHorasTrabajadas)==1 &&
                    employee_setSueldo(myEmployee,auxsueldo)==1)
            {
                ll_add(pArrayListEmployee, myEmployee);
                retorno=1;
            }
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int auxID;
    int index=-1;

    Employee* employee;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("Que empleado desea modificar?: ");
        scanf("%d",&auxID);

        index=employee_FindById(pArrayListEmployee,auxID);
        if(index != -1)
        {
            employee=(Employee*)ll_get(pArrayListEmployee,index);
            employee_modifyEmployee(employee);
            retorno=1;
        }
    }
    else
    {
        retorno=0;
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxID;
    int findID;
    int retorno=-1;
    Employee* auxEmployee;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("Que empleado desea eliminar?");
        scanf("%d",&auxID);

        findID=employee_FindById(pArrayListEmployee,auxID);
        if(findID!=-1)
        {
            auxEmployee=ll_pop(pArrayListEmployee,findID);
            printf("EMPLEADO ELIMINADO: \n");
            printf("%4d %15s %4d %4d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
            retorno=1;
        }

    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int retorno=-1;
    int size;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);
        if(size!=0)
        {   //recorrer lista y mostrar (2 funciones)
           // employee_showEmployee(pArrayListEmployee,size);
            printf("\t ______________________________________________\n");
            printf("\t|ID \t   NOMBRE \tHORAS TRABAJO\tSALARIO|\n");
            for(i=0; i<size; i++)
            {
                auxEmployee =(Employee*)ll_get(pArrayListEmployee, i);
                printf("\t|%3d %15s\t%4d\t\t%4d  |\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
            }
            printf("\t|______________________________________________|\n");
//////////////////////////////
            retorno=1;
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    int retorno=0;
    LinkedList* auxList;
    auxList=ll_clone(pArrayListEmployee);

    if(pArrayListEmployee!= NULL && auxList != NULL && ll_isEmpty(auxList)==0)
    {
        retorno=1;
        do
        {
            printf("MENU DE ORDENAMIENTOS\n1.Ordenar por nombre alfabeticamente\n2.Ordenar por id\n3.Ordenar por salario\n4.Ordenar por horas trabajadas\n5.Salir\nIngrese la opcion: ");
            scanf("%d",&option);
            if(option!=5){
                printf("Ordenando...\n");
            }
            switch(option)
            {
            case 1:
                ll_sort(auxList, employee_CompareByName, 1);
                break;
            case 2:
                ll_sort(auxList, employee_CompareById, 0);
                break;
            case 3:
                ll_sort(auxList, employee_CompareBySalary, 1);
                break;
            case 4:
                ll_sort(auxList, employee_CompareByWorkedHours, 1);
                break;
            }
            if(option==5)
            {
                controller_ListEmployee(auxList);
            }
        }
        while(option!=5);
        ll_deleteLinkedList(auxList);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchive;
    int retorno=-1;

    if(pArrayListEmployee != NULL && path != NULL && ll_isEmpty(pArrayListEmployee)==0)
    {
        pArchive=fopen(path, "w");
        if(pArchive!= NULL)
        {
            retorno=parser_EmployeeToText(pArchive, pArrayListEmployee);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchive;
    int retorno=-1;

    if(path!=NULL && pArrayListEmployee!= NULL && ll_isEmpty(pArrayListEmployee)==0)
    {
        pArchive=fopen(path, "wb");
        if(pArchive!=NULL)
        {
            retorno=parser_EmployeeToBinary(pArchive, pArrayListEmployee);
        }
    }

    return retorno;
}

