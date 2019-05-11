#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#define CANT 4

int main()
{
    int opcion;
    Employee list[CANT];
    initEmployees(list, CANT);
    int pirateFlag=0;
     do
    {
    printf("\n1 Alta\n2Modificacion\n3Baja\n4Mostrar la lista\n5Salir\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        system("cls");
        addemployees(list, CANT);
        pirateFlag=1;
        break;
    case 2:
        if(pirateFlag == 1)
            {
             system("cls");
             printEmployeers(list, CANT);
             modifyEmployee(list, CANT, 0);
            }
            else
            {
             printf("\nNo hay empleaditos cargados\n");
             system("pause");
             system("clear");
            }
        break;
    case 3:
         if(pirateFlag == 1)
            {
             system("cls");
             printEmployeers(list, CANT);
             removeEmployee(list, CANT);
            }
        else{
              printf("\nNo hay empleaditos cargados\n");
            system("pause");
             system("clear");
            }
        break;
    case 4:
        if(pirateFlag == 1)
            {
        system("cls");
        printEmployeers(list,CANT);
            }
            else
            {
              printf("\nNo hay empleaditos cargados\n");
            system("pause");
             system("clear");
            }
        break;

system("pause");
system("cls");
    }
}while(opcion != 5);

}
