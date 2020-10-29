#include <stdlib.h>
#include <stdio_ext.h>
#include <stdio.h>
#include "Employee.h"
#include <string.h>

void Menu()
{
    printf("\t ------------------------------------\n");
    printf("\t|Bienvenido al sistema de empleados  |\n");
    printf("\t|____________________________________|\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.dat (modo binario).\n");
    printf("10. Salir\n\n");
    printf("Ingrese opcion: ");
}

Employee* employee_new(void)
{
    Employee* pEmployee;
    pEmployee=(Employee*)malloc(sizeof(Employee));
    return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* pEmployee;
    pEmployee=employee_new();

    if(pEmployee!=NULL)
    {
        employee_setId(pEmployee,atoi(idStr));
        employee_setNombre(pEmployee,nombreStr);
        employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
        employee_setSueldo(pEmployee,atof(sueldoStr));
    }
    return pEmployee;
}
int employee_CompareByName(void* e1, void* e2)
{
    int returnValue;
    if(e1!=NULL && e2!=NULL)
    {
        Employee* emp1=(Employee*)e1;
        Employee* emp2=(Employee*)e2;
        returnValue = strcasecmp(emp1->nombre, emp2->nombre);
    }

    return returnValue;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int comparar=0;

    if(e1->id > e2->id)
    {
        comparar= 1;
    }
    else
    {
        if(e1->id<e2->id)
        {
            comparar=-1;
        }
    }
    return comparar;
}

int employee_setId(Employee* this,int id)
{
    int returnValue=0;

    if(id!=NULL && this!=NULL)
    {
        this->id=id;
        returnValue=1;
    }
    return returnValue;
}

int employee_getId(Employee* this,int* id)
{
    int returnValue=0;

    if(id!=NULL && this!=NULL)
    {
        id=this->id;
        returnValue=1;
    }
    return returnValue;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int returnValue=0;

    if(nombre!=NULL && this!=NULL)
    {
        strcpy(this->nombre,nombre);
        returnValue=1;
    }
    return returnValue;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int returnValue=0;

    if(nombre!=NULL && this!=NULL)
    {
        strcpy(*nombre,this->nombre);
        returnValue=1;
    }

    return returnValue;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int returnValue=0;

    if(horasTrabajadas!=NULL && this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        returnValue=1;
    }
    return returnValue;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int returnValue=0;

    if(horasTrabajadas!=NULL && this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        returnValue=1;
    }
    return returnValue;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int returnValue=0;

    if(sueldo!=NULL && this!=NULL)
    {
        this->sueldo=sueldo;
        returnValue=1;
    }

    return returnValue;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int returnValue=0;

    if(sueldo!=NULL && this!=NULL)
    {
        *sueldo=this->sueldo;
        returnValue=1;
    }

    return returnValue;
}

int GenerarId(int id,int cont)
{
    return id+cont;
}
