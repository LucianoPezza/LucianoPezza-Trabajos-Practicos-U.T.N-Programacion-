#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int getInt(char message[])
{
    char Aux[10];
    int intad;

    printf("%s", message);
    scanf("%s", Aux);
    fflush(stdin);
    intad = atoi(Aux);

    while(intad == 0)
    {
        printf("%s", "Error. Ingrese SOLO un numero entero \n");
        scanf("%s", Aux);
        fflush(stdin);
        intad = atoi(Aux);
    }

    return intad;

}

float getFloat(char message[])
{
    char Aux[10];
    float Floatad;

    printf("%s", message);
    scanf("%s", Aux);
    fflush(stdin);
    Floatad = atof(Aux);

    while(Floatad == 0)
    {
        printf("%s", "Error. Ingrese SOLO un numero y puede ser float\n");
        scanf("%s", Aux);
        fflush(stdin);
        Floatad = atof(Aux);
    }


    return Floatad;

}


void getStr(char message[], char input[])
{
    printf(message);
    fflush(stdin);
    gets(input);
}
