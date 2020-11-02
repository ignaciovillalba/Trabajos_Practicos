#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
//#include
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
    FILE* archive;
    int retorno;
    archive=(FILE*)malloc(sizeof(FILE));

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        archive=fopen(path,"r");
        if(archive!=NULL)
        {
            retorno=parser_EmployeeFromText(archive,pArrayListEmployee);
        }
        else
        {
            printf("Archivo inexistente,se procedera a crear una carpeta.\n");
            archive=fopen(path,"w");
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
    FILE* archive;
    int retorno;
    archive=(FILE*)malloc(sizeof(FILE));

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        archive=fopen(path,"rb");
        if(archive!=NULL)
        {
            retorno=parser_EmployeeFromBinary(archive,pArrayListEmployee);
        }
        else
        {
            printf("Archivo inexistente,se procedera a crear una carpeta.\n");
            archive=fopen(path,"wb");
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
    int retorno=0;

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
    Employee* auxEmployee;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("Que empleado desea eliminar?");
        scanf("%d",&auxID);

        auxEmployee=ll_pop(pArrayListEmployee,auxID-1);
        printf("EMPLEADO ELIMINADO: \n");
        printf("%4d %15s %4d %4d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
    }

    return 1;
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
    int retorno=0;
    int size;

    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);
        if(size!=0)
        {

            printf("\t ______________________________________________\n");
            printf("\t|ID \t   NOMBRE \tHORAS TRABAJO\tSALARIO|\n");
            for(i=0; i<size; i++)
            {
                auxEmployee =(Employee*)ll_get(pArrayListEmployee, i);
                printf("\t|%3d %15s\t%4d\t\t%4d  |\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
            }
            printf("\t|______________________________________________|\n");

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
    return 1;
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
     FILE* myTextFile;
    int ret=0;

    if(pArrayListEmployee != NULL && path != NULL && ll_isEmpty(pArrayListEmployee)==0)
    {
        myTextFile=fopen(path, "w");
        if(myTextFile!= NULL)
        {
            ret=parser_EmployeeToText(myTextFile, pArrayListEmployee);
        }
    }
    return ret;
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
    /*FILE* myBinaryFile;
    int ret=0;

    if(path!=NULL && pArrayListEmployee!= NULL && ll_isEmpty(pArrayListEmployee)==0)
    {
        myBinaryFile=fopen(path, "wb");
        if(myBinaryFile!=NULL)
        {
            ret=parser_EmployeeToBinary(myBinaryFile, pArrayListEmployee);
        }
    }
*/
    return 1;
}

