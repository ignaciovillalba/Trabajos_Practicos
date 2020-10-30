#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

void Menu();

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* employeeList,int id);
int employee_getId(Employee* employeeList,int* id);

int employee_setNombre(Employee* employeeList,char* nombre);
int employee_getNombre(Employee* employeeList,char* nombre);

int employee_setHorasTrabajadas(Employee* employeeList,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* employeeList,int* horasTrabajadas);

int employee_setSueldo(Employee* employeeList,int sueldo);
int employee_getSueldo(Employee* employeeList,int* sueldo);

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(Employee* e1, Employee* e2);

int GenerarId(int id,int cont);
int employee_FindById(LinkedList* pArrayListEmployee, int id);
#endif // employee_H_INCLUDED
