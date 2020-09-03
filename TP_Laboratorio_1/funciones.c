#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


void MainMenu (float numberA, float numberB)
{
    printf("BIENVENIDOS A LA CALCULADORA");
    printf("\n\n 1) Ingresar 1er operando (A= %.2f )",numberA);
    printf("\n 2) Ingresar 2do operando (B= %.2f )",numberB);
    printf("\n 3)Calcular todas las operaciones");
    printf("\n\t A)Calcular la suma (A+B)");
    printf("\n\t B)Calcular la resta (A-B)");
    printf("\n\t C)Calcular la division (A/B)");
    printf("\n\t D)Calcular la multiplicacion (A*B)");
    printf("\n\t E)Calcular el factorial (A! B!)");
    printf("\n 4)Informar resultados");
    printf("\n 5)Salir");

}

float obtainNumber(char message[])
{
    float auxiliaryNumber;

    printf("%s",message);
    fflush(stdin);

    scanf("%f",&auxiliaryNumber);

    return auxiliaryNumber;
}

void doSwitch(float numberA,float numberB)
{
    int option;
    float additionValue;
    float substractionValue;
    float multiplicationValue;
    float divisionValue;

    do
    {
        MainMenu(numberA,numberB);
        option=obtainNumber("\n\n Ingrese una opcion: ");

        switch(option)
        {
        case 1:
            system("cls");
            numberA=obtainNumber("\n Ingrese primer valor: ");
            system("cls");
            break;
        case 2:
            system("cls");
            numberB=obtainNumber("\n Ingrese segundo valor: ");
            system("cls");
            break;
        case 3:
            system("cls");
            additionValue=additionFunction(numberA,numberB);
            substractionValue=substractionFunction(numberA,numberB);
            multiplicationValue=multiplicationFunction(numberA,numberB);
            divisionValue=divisionFunction(numberA,numberB);
            printf("Se han calculado todo los resultados.Presione 4 para conocer los resultados.\n");
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            printf("\n A)Suma= %.2f",additionValue);
            printf("\n B)Resta= %.2f",substractionValue);
            printf("\n C)Multiplicacion= %.2f",multiplicationValue);
            printf("\n D)Division= %.2f\n\n",divisionValue);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            printf("\n Eligio salir \n");
            break;
        default:
            MainMenu(numberA,numberB);
            printf("ERROR! Eso no es una opcion: %d",option);
            system("cls");
            break;
        }
    }
    while (option!=5);
}

float additionFunction(float numberA,float numberB)
{
    float auxiliaryValue;

    auxiliaryValue= numberA+(numberB);

    return auxiliaryValue;
}

float substractionFunction(float numberA,float numberB)
{
    float auxiliaryValue;

    auxiliaryValue = numberA-(numberB);

    return auxiliaryValue;
}

float multiplicationFunction(float numberA,float numberB)
{
    float auxiliaryValue;

    auxiliaryValue = (numberA)*(numberB);

    return auxiliaryValue;
}

float divisionFunction(float numberA,float numberB)
{
    float auxiliaryValue;

    auxiliaryValue = (numberA)/(numberB);

    return auxiliaryValue;
}
