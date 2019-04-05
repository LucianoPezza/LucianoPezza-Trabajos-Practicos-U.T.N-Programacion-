#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
char seguir = 's';
int opcion;
float numero1;
float numero2;
float sumar = 0;
float restar = 0;
float multiplicar =0;
float dividir = 0;
int factoreo1;
int factoreo2;

printf("\n**CALCULADORA EN C**\n");

do
{
fflush(stdin);
printf("\nBienvenidos a la calculadora C.\n1. Para introducir el primer numero\n2. Para introducir el segundo numero\n3. Calcular las operaciones en base a los numeros escritos (Suma, Resta, Division, Multiplicacion y Factoreo)\n4 Resultado de las respuestas\n5.Salir\n");
scanf("%d",&opcion);

switch(opcion){
case 1:
        numero1 = escribirnumero("Introduzca el primer numero: ");
    break;
case 2:
        numero2 = escribirnumero("Introduzca el segundo numero: ");
    break;
case 3:
        sumar = suma(numero1, numero2);
        restar = resta(numero1,numero2);
        dividir = division(numero1,numero2);
        multiplicar = multiplicacion(numero1,numero2);
        factoreo1 = factorear(numero1);
        factoreo2 = factorear(numero2);
        printf("\nLas operaciones han sido calculadas\n");
    break;
case 4:
        printf("\nLa suma es: %.1f",sumar);
        printf("\nLa resta es: %.1f",restar);
        printf("\nLa division es: %.1f",dividir);
        printf("\nLa multiplicacion es: %.1f",multiplicar);
        printf("\nEl factoreo del primer numero es: %d",factoreo1);
        printf("\nEl factoreo del segundo numero es: %d\n",factoreo2);
    break;
case 5:
    seguir = 'n';
    break;
default:
    printf("\nError. Ingrese una opcion valida\n");
    break;
}
system("pause");
system("cls");

}while(seguir == 's');
return 0;
}
