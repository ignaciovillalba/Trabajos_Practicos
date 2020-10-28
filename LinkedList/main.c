#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int main()
{


    LinkedList* lista;
    int len;
    int option;

    do
    {
        Menu();
        scanf("%d",&option);
    }
    while(option!=10);
    lista = ll_newLinkedList();

    len = ll_len(lista);

    printf("Cantidad %d", len);

    /**********************

    Employee* e1;
    e1= (Employee*)malloc (sizeof(Employee));*/

    return 0;
}
