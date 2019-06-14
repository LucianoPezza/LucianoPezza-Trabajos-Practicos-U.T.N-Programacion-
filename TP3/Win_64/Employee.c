#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new()
{
    Employee* empleadito;
    empleadito=(Employee*)calloc(sizeof(Employee),1);
    return empleadito;
}

Employee* employee_newParameters(char* idStr, char* nameStr, char* hoursWorkedStr, char* salaryStr)
{
    int id;
    int horasTrabajadas;
    int salario;

    Employee* pEmployee;
    pEmployee = employee_new();

    id = atoi(idStr);
    salario = atoi(salaryStr);
    horasTrabajadas = atoi(hoursWorkedStr);


    employee_setId(pEmployee,id);
    employee_setSueldo(pEmployee,salario);
    employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
    employee_setNombre(pEmployee,nameStr);
    return pEmployee;
}





int employee_setId(Employee* this,int id)
{
int correct;
    if(this!=NULL)
    {
        this->id=id;
        correct = 1;
    }
return correct;
}





int employee_setNombre(Employee* this,char* nombre)
{
int correct;
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        correct = 1;
    }
return correct;
}





int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
int correct;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        correct = 1;
    }
return correct;

}




int employee_setSueldo(Employee* this,int sueldo)
{
int correct;
    if(this!=NULL)
    {
     this->sueldo=sueldo;
     correct = 1;
    }
return correct;
}




int employee_getId(Employee* this,int* id)
{
int correct;
    if(this != NULL)
    {
       *id = this->id;
       correct = 1;
    }
return correct;
}




int employee_getNombre(Employee* this,char* nombre)
{
int correct;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        correct = 1;
    }
return correct;
}




int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
int correct;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        correct = 1;
    }
return correct;

}




int employee_getSueldo(Employee* this,int* sueldo)
{
int correct;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        correct = 1;
    }
return correct;
}





void employee_delete(Employee*liberar)
{
    if(liberar!=NULL)
    {
        free(liberar);
    }
}

