#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

float suma(float numero1, float numero2)
{
 float suma = numero1 + numero2;
 return suma;

}
float resta(float numero1, float numero2)
{
float resta = numero1 - numero2;
return resta;
}

float division(float numero1, float numero2)
{
if(numero2 == 0)
{
   printf("\nImposible dividir por cero, introduzca otro numero\n");
}else
{
   float division = numero1/numero2;
return division;

}
return 0;
}
float multiplicacion(float numero1, float numero2)
{
float multiplicacion = numero1*numero2;
return multiplicacion;
}

float escribirnumero(char mensaje[])
{
float numero;
printf("%s",mensaje);
scanf("%f",&numero);
return numero;
}

float factorear(float numero)
{
    float factorial;

    if (numero<0)
    {
        printf("\nIntroduzca un numero mayor o igual a cero para poder factorear\n");
    }
    else if (numero == 0 || numero == 1)
    {
        factorial= 1;
    }
    else
    {
    factorial= numero*factorear(numero-1);
    }

    return factorial;
}
