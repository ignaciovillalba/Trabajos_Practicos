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

int employee_setId(Employee* employeeList,int id)
{
    int returnValue=0;

    if(id>0 && employeeList!=NULL)
    {
        employeeList->id=id;
        returnValue=1;
    }
    return returnValue;
}

int employee_getId(Employee* employeeList,int* id)
{
    int returnValue=0;

    if(id!=NULL && employeeList!=NULL)
    {
        *id=employeeList->id;
        returnValue=1;
    }
    return returnValue;
}

int employee_setNombre(Employee* employeeList,char* nombre)
{
    int returnValue=0;

    if(nombre!=NULL && employeeList!=NULL)
    {
        strcpy(employeeList->nombre,nombre);
        returnValue=1;
    }
    return returnValue;
}

int employee_getNombre(Employee* employeeList,char* nombre)
{
    int returnValue=0;

    if(nombre!=NULL && employeeList!=NULL)
    {
        strcpy(nombre,employeeList->nombre);
        returnValue=1;
    }

    return returnValue;
}

int employee_setHorasTrabajadas(Employee* employeeList,int horasTrabajadas)
{
    int returnValue=0;

    if(employeeList!=NULL)
    {
        employeeList->horasTrabajadas=horasTrabajadas;
        returnValue=1;
    }
    return returnValue;
}

int employee_getHorasTrabajadas(Employee* employeeList,int* horasTrabajadas)
{
    int returnValue=0;

    if(horasTrabajadas!=NULL && employeeList!=NULL)
    {
        *horasTrabajadas=employeeList->horasTrabajadas;
        returnValue=1;
    }
    return returnValue;
}

int employee_setSueldo(Employee* employeeList,int sueldo)
{
    int returnValue=0;

    if(employeeList!=NULL)
    {
        employeeList->sueldo=sueldo;
        returnValue=1;
    }

    return returnValue;
}

int employee_getSueldo(Employee* employeeList,int* sueldo)
{
    int returnValue=0;

    if(sueldo!=NULL && employeeList!=NULL)
    {
        *sueldo=employeeList->sueldo;
        returnValue=1;
    }

    return returnValue;
}

int GenerarId(int id,int cont)
{
    return id+cont;
}

int employee_FindById(LinkedList* pArrayListEmployee, int id)
{
    Employee* employee;
    int auxId;
    int i;
    int index=-1;
    int size;

    if(pArrayListEmployee != NULL)
    {
        size=ll_len(pArrayListEmployee);

        for(i=0; i<size; i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee, i);
            auxId=employee->id;
            employee_getId(employee, &auxId);

            if(id == auxId)
            {
                index=i;
                break;
            }
        }
    }
    return index;

}


int employee_modifyEmployee(Employee* employeeList)
{
    char auxNombre[51];
    int auxHorasTrabajadas;
    int auxSueldo;
    int opcion;

    do
    {
        printf("%4d%15s%4d%4d\n",employeeList->id,employeeList->nombre,employeeList->horasTrabajadas,employeeList->sueldo);
        printf("Que desea modificar?: ");
        printf("\n 1) Nombre.\n 2)Horas trabajadas.\n 3)Sueldo.\n 4)Salir \n Ingrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre del empleado: ");
            scanf("%s",auxNombre);
            employee_setNombre(employeeList,auxNombre);
            system("clear");
            break;
        case 2:
            printf("Ingrese nuevas horas trabajadas del empleado: ");
            scanf("%d",&auxHorasTrabajadas);
            employee_setHorasTrabajadas(employeeList,auxHorasTrabajadas);
            system("clear");
            break;
        case 3:
            printf("Ingrese nuevo sueldo del empleado: ");
            scanf("%d",&auxSueldo);
            employee_setSueldo(employeeList,auxSueldo);
            system("clear");
            break;
        case 4:
            printf("Empleado modificado con exito.\n\n");
            break;
        }
    }
    while(opcion!=4);
    return 1;
}
