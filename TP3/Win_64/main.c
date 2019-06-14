#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flag = 0;
    int flag2 = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

        printf("\n1.Para cargar los datos por texto\n2.Para cargar los datos por binario\n3 para agregar empleados\n4.Para editar empleados\n5.Para remover empleados\n6.Para mostrar\n7.Para guardar datos cargados en texto\n8.Para guardar los datos cargados en binario\n10.Salir\n");
        scanf("\n%d",&option);
        switch(option)
        {
            case 1:
                if(flag==0)
                {
                    system("cls");
                    controller_loadFromText("data.csv",listaEmpleados);
                    flag=1;

                }else
                {
                    system("cls");
                    printf("\n Los archivos en texto se cargaron anteriormente");
                }

                break;
           case 2:
               if(flag2==0)
               {
                    system("cls");
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    flag2=1;
               }else
               {   system("cls");
                   printf("Los archivos en binario ya fueron cargados");
               }
                break;
            case 3:
                if(flag==1 || flag2==1)
                {
                    system("cls");
                    system("pause");
                    controller_addEmployee(listaEmpleados);
                }else
                {
                    system("cls");
                    printf("No se cargaron los datos aun");
                }

                break;
             case 4:
                 if(flag==1 || flag2==1)
                 {
                    system("cls");
                    system("pause");
                    controller_editEmployee(listaEmpleados);
                 }else
                 {
                    system("cls");
                    printf("Aun no se cargaron los datos");
                 }
                break;
            case 5:
                if(flag==1 || flag2==1)
                 {
                    system("cls");
                    controller_removeEmployee(listaEmpleados);
                 }else
                 {
                    system("cls");
                    printf("Aun no se cargaron los datos");
                 }
                break;
            case 6:
                 if(flag==1 || flag2==1)
                 {
                    system("cls");
                    controller_ListEmployee(listaEmpleados);
                 }else
                 {
                    system("cls");
                    printf("Aun no se cargaron los datos");
                 }
                break;
            case 7:
                 if(flag==1 || flag2==1)
                 {
                    system("cls");
                    controller_saveAsText("data.csv",listaEmpleados);
                 }else
                 {
                    system("cls");
                    printf("Aun no se cargaron los datos");
                 }
                break;
            case 8:
                 if(flag==1 || flag2==1)
                 {
                    system("cls");
                    controller_saveAsBinary("data.bin",listaEmpleados);
                 }else
                 {
                    system("cls");
                    printf("Aun no se cargaron los datos");
                 }
                break;

            case 10:
                option=10;
                printf("Saliendo");
                break;
            default:
                printf("Opcion invalida");
                break;
        }
    }while(option != 10);
    return 0;
}
