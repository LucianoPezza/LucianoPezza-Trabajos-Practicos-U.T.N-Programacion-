#include <stdio.h>
#include <string.h>
#include "Biblioteca.h"
#define CANT 4


int isEmpty(Employee list[], int cant)
{
int i;
int aux = -1;

for(i=0;i<cant;i++)
{
    if(list[i].isEmpty==LIBRE)
    {
        aux = i;
        break;
    }
}
return aux;
}


void initEmployees(Employee list[], int cant)
{
  int i;
  for(i=0;i<cant;i++)
  {
    strcpy(list[i].name," ");
    strcpy(list[i].lastName," ");
    list[i].salary=0;
    list[i].sector=0;
    list[i].id=0;
    list[i].isEmpty=LIBRE;



  }
}
Employee Employeeadd()
{
    Employee list;
    printf("Ingrese el Nombre del empleado: ");
    fflush(stdin);
    gets(list.name);
    printf("Ingrese el Apellido del empleado: ");
    fflush(stdin);
    gets(list.lastName);

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f",&list.salary);

    printf("Ingrese el sector del empleado: ");
    scanf("%d",&list.sector);
      printf("Ingrese el ID: ");
    scanf("%d",&list.id);
    return list;
}

int addemployees(Employee list[], int cant)
    {
        int aux;
        aux= isEmpty(list, cant);
        if(aux != -1)
        {
            list[aux]= Employeeadd();
        }
         else
    {
        printf("No hay mas lugar.");
    }
        return aux;
    }
void printEmployees(Employee print)
{

    printf("\n%s\t%10s\t%2.f\t\t%5d\t\t%10d\n",print.name, print.lastName, print.salary, print.sector, print.id);

}
void modifyEmployee(Employee list[],int cant)
{
    int i;
    int foundIT=0;
    printf("\nIngrese el ID para encontrar y modificar al empleado: ");
    int id;
    scanf("%d",&id);

    for(i=0; i<cant; i++)
    {
        if(id == list[i].id && list[i].id == OCUPADO)
           {
            list[i]= Employeeadd();
            foundIT=1;
            break;
           }
    }
    if(foundIT == 0)
        {
            printf("\nId Inexistente\n");
        }

    }

int removeEmployee(Employee list[],int cant)
{
    int i;
    int foundIT=0;
    printf("\nIngrese el ID para encontrar y eliminar al empleado: \n");
    int id;
    scanf("%d",&id);

    for(i=0; i<cant; i++)
    {
        if(id == list[i].id)
           {
            list[i].isEmpty=LIBRE;
            foundIT=1;
              printf("\nEl empleado fue eliminado exitosamente!!!\n");
            break;
           }
    }
    if(foundIT == 0)
        {
            printf("\nId Inexistente");
        }

        return 0;
    }
void isEmptyEmployeed(Employee list[], int cant)
{
    int i;
    printf("\nNAME-----------LASTNAME-----------SALARY-----------SECTOR-----------ID\n");
    printf("\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].isEmpty != LIBRE)
        {
            printEmployees(list[i]);

        }
    }

}
sortemployeeBylastN(Employee list[],int cant)
{
    int i;
    int j;

    Employee auxLastName;

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(list[i].lastName>list[j].lastName)
            {
                auxLastName=list[i];
                list[i]=list[j];
                list[j]=auxLastName;
            }
        }
    }
}





