#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validation.h"

void GetString(char message[],char input[],int sizeString)
{
    printf("%s",message);
    fflush(stdin);
    gets(input);
    while(Validation_String(input)!=1 || input[0]=='\0' || input[0]==' ' || (strlen(input)<3))
    {
        printf("Reingrese un dato valido: ");
        fflush(stdin);
        gets(input);
    }
    input[0]=toupper(input[0]);
    for(int i=1; i< input[i]; i++){
        if (input[i-1] == ' ')
        {
            input[i]=toupper(input[i]);
        }
        else
        {
            input[i]=tolower(input[i]);
        }
    }
}

int GetOption(char message[])
{
    int number;
    char auxilaryNum[11];
    printf("%s",message);
    fflush(stdin);
    gets(auxilaryNum);
    while(Validation_Integer(auxilaryNum)!=1 || auxilaryNum[0]=='\0')
    {
        printf("Reingrese una opcion valida: ");
        fflush(stdin);
        gets(auxilaryNum);
    }
    number=atoi(auxilaryNum);
    return number;
}

int GetInt(char message[])
{
    int number;
    char auxilaryNum[11];
    printf("%s",message);
    fflush(stdin);
    gets(auxilaryNum);
    while(Validation_IntID(auxilaryNum)!=1 || auxilaryNum[0]=='\0')
    {
        printf("Reingrese un numero valido: ");
        fflush(stdin);
        gets(auxilaryNum);
    }
    number=atoi(auxilaryNum);
    return number;
}

int getInModificate(char msj[],char error[],int min, int max, int limit)
{
int num;
int acum=0;
printf("%s",msj);
while(acum!=2)
    {
    acum=0;
    if (scanf("%d",&num)!=1)
        {
        fflush(stdin);
        printf("%s",error);
        }
    else
        {
        acum++;
        if(limit==1)
            {
            if(num<min || num >max)
                {
                fflush(stdin);
                printf("%s",error);
                }
            else
                {
                acum++;
                }
            }
        else
            {
            acum++;
            }
        }
    }
fflush(stdin);
return num;
}

float GetFloat(char message[])
{
    float numberFloat;
    printf("%s",message);
    scanf("%f",&numberFloat);
    return numberFloat;
}

char GetChar(char message[])
{
    char letter;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&letter);
    while((letter<'a' || letter>'z') && (letter<'A' || letter>'Z'))
    {
        printf("Reingrese un caracter valido: ");
        fflush(stdin);
        scanf("%c",&letter);
    }
    return letter;
}

int GetUpDown(char message[])
{
    int number;
    char auxilaryNum[11];
    printf("%s",message);
    fflush(stdin);
    gets(auxilaryNum);
    while(Validation_Integer(auxilaryNum)!=1 || auxilaryNum[0]=='\0' || strlen(auxilaryNum)>1 || (auxilaryNum<'0' && auxilaryNum>'1'))
    {
        printf("Ingrese 0 o 1 para el orden a mostrar: ");
        fflush(stdin);
        gets(auxilaryNum);
    }
    number=atoi(auxilaryNum);
    return number;
}

int GenerarId(int id,int cont)
{
    return id+cont;
}
