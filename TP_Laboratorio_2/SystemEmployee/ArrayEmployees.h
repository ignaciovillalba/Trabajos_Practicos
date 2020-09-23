#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;

void mainMenu();

void initEmployees(sEmployee listEmployee[], int sizeEmployee);

#endif // ARRAYEMPLOYEES_H_INCLUDED
