#include <stdio.h>
#include <stdlib.h>


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
