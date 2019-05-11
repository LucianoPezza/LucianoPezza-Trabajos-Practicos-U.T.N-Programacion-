#include <stdio.h>
#include <string.h>
#include "Biblioteca.h"
#include "Validaciones.h"
#define CANT 4



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
Employee Employeeadd()
{
    Employee list;

    getStr("\nIngrese el nombre del empleado: ", list.name);
    getStr("\nIngrese el apellido del empleado: ", list.lastName);
    list.salary = getFloat("\nIngrese el salario: ");
    list.sector = getInt("\nIngrese el sector: ");
    printf("\nIngrese un id: ");
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
int printEmployeers(Employee list[], int cant)
{
    int i;
    printf("%10s - %10s - %10s - %10s - %10s \n", "ID", "NOMBRE", "APELLIDO","SALARIO"," SECTOR");
 sortEmployeesByLastName(list,cant);

    for(i = 0; i <cant; i++)
    {
        if(list[i].isEmpty != LIBRE)
        {
            printf("%10d  %10s  %10s  %10.2f  %10d \n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);

        }
    }
return 0;
}


int modifyEmployee(Employee list[], int cant, int id)
{
    int i;
    int loEncontro = 0;
    id = getInt("\nIntroduzca el id:\n");

    for(i=0; i<cant; i++)
    {
        if(id == list[i].id)
        {
    getStr("\nIngrese un nuevo nombre del empleado: ", list[i].name);
    getStr("\nIngrese un nuevo apellido del empleado: ", list[i].lastName);
    list[i].salary = getFloat("\nIngrese un nuevo salario: ");
    list[i].sector = getInt("\nIngrese un sector: ");
            loEncontro = 1;
            break;
        }

    }

    if(loEncontro==0)
    {
        printf("El id no existe");
    }
return 0;
}
int removeEmployee(Employee list[],int cant)
{
    int i;
    int foundIT=0;

    int id;
     id = getInt("\nIngrese ID del empleado para eliminar empleado: ");

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

int sortEmployeesByLastName(Employee list[], int cant)
{
    int i;
    int j;
    Employee aux;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(list[i].isEmpty==LIBRE && list[j].isEmpty==LIBRE ){
            if(stricmp(list[i].lastName, list[j].lastName)>LIBRE)
            {
                aux =list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            else if(stricmp(list[i].lastName, list[j].lastName) == LIBRE && list[j].sector < list[i].sector)
            {
                aux=list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            }

            }

    }
  return 0;
}






