#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


void MainMenu (float numberA, float numberB)
{
    printf("BIENVENIDOS A LA CALCULADORA");
    printf("\n\n 1) Ingresar 1er operando (A= %.2f )",numberA);/**< Se muestra el valor cargado en A hasta el momento */
    printf("\n 2) Ingresar 2do operando (B= %.2f )",numberB);/**< Se muestra el valor cargado en B hasta el momento */
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
    int factorialA;
    int factorialB;
    int comprobacionIngresoA=0;
    int comprobacionIngresoB=0;
    int comprobacionCaso3=0;

    do
    {
        MainMenu(numberA,numberB);
        option=obtainNumber("\n\nIngrese una opcion: ");
        system("cls");

        switch(option)
        {
        case 1:
            numberA=obtainNumber("\n Eligio la 1ra opcion.\nIngrese primer valor: ");
            comprobacionIngresoA=1;/**< Se verifica que se haya cargado un valor en numberA */
            system("cls");
            break;
        case 2:
            numberB=obtainNumber("\nEligio la 2da opcion.\n Ingrese segundo valor: ");
            comprobacionIngresoB=1;/**< Se verifica que se haya cargado un valor en numberB */
            system("cls");
            break;
        case 3:

            if(comprobacionIngresoA==1 && comprobacionIngresoB==1)/**< Si ambos valores se ingresaron se realiza el switch 3 */
            {
                additionValue=additionFunction(numberA,numberB);
                substractionValue=substractionFunction(numberA,numberB);
                multiplicationValue=multiplicationFunction(numberA,numberB);
                divisionValue=divisionFunction(numberA,numberB);
                factorialA=factorialFunction(numberA);
                factorialB=factorialFunction(numberB);
                printf("\nSe han realizado todas las operaciones.\nPresione 4 para informar los resultados.\n\n");
                comprobacionCaso3=1;/**< Se comprueba que se haya hecho el calculo de los valores. */
            }
            else if (comprobacionIngresoA==0 && comprobacionIngresoB==1)
            {
                numberA=obtainNumber("\nERROR! no ingreso ningun 1er valor.\nIngrese primer valor: ");
                comprobacionIngresoA=1;
                MainMenu (numberA, numberB);
                system("cls");
            }
            else if(comprobacionIngresoA==1 && comprobacionIngresoB==0)
            {
                numberB = obtainNumber ("\nERROR! no ingreso ningun 2do valor.\nIngrese segundo valor: ");
                comprobacionIngresoB=1;
                MainMenu(numberA, numberB);
                system("cls");
            }
            else
            {
                MainMenu (numberA, numberB);
                printf("\n\nERROR! Usted no cargo ningun valor en A o B .\n");
                system("pause");
                system("cls");
            }

            break;
        case 4:
            if (comprobacionIngresoA==1 && comprobacionIngresoB==1 && comprobacionCaso3==1)
            {
                resultMessage("\nEl resultado de la suma es: ", additionValue);
                resultMessage("El resultado de la resta es: ", substractionValue);
                resultMessage("El resultado de la multiplicacion es: ", multiplicationValue);

                if (numberA == 0)
                {
                    resultMessage("No se puede dividir por cero. A= ", numberB);
                }
                else
                {
                    resultMessage("El resultado de la division es: ", divisionValue);
                }

                if (factorialA==0 || factorialA==-1)
                {
                    resultMessage("No se puede calcular el factorial de un numero con coma o negativo. A=", numberA);
                }
                else
                {
                    resultMessage ("El factorial de A es: ", factorialA);
                }

                if (factorialB==0 || factorialB==-1)
                {
                    resultMessage("No se puede calcular el factorial de un numero con coma o negativo. B=", numberB);
                }
                else
                {
                    resultMessage ("El factorial de B es: ", factorialB);
                }
                system("pause");
                system("cls");
            }
            else if (comprobacionIngresoA==0 || comprobacionIngresoB==0)
            {
                MainMenu (numberA, numberB);
                printf("\n\nERROR! Usted no cargo ningun valor en A o B .\n");
                system("pause");
                system("cls");
            }
            else if(comprobacionCaso3==0)
            {
                MainMenu(numberA, numberB);
                printf("\n\nERROR! Usted no realizo el calculo de los valores.\n");
                system("pause");
                system("cls");
            }
            break;
        case 5:
            system("cls");
            printf("\nUsted eligio la opcion de salir de la calculadora.Hasta luego.\n\n");
            break;
        default:
            MainMenu(numberA,numberB);
            resultMessage("\n\nERROR! Eso no es una opcion: ",option);
            system("pause");
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

int factorialFunction (float number)
{

    int factorial;
    int returnValue;
    long int factor = 1;

    if (number== (int) number && number>=0)
    {
        for (factorial = number; factorial > 0; factorial--)
        {
            factor = factor * factorial;
            returnValue=factor;
        }
    }
    else if (number<0)
    {
        returnValue= -1;
    }
    else
    {
        returnValue= 0;
    }
    return (returnValue);
}

void resultMessage(char msg[], float valueResult)
{
    printf("%s %.2f\n\n", msg, valueResult);
}
