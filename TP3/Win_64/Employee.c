#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>


Employee* employee_new()
{
    Employee* empleadito;
    empleadito=(Employee*)calloc(sizeof(Employee),1);
    return empleadito;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{

}

