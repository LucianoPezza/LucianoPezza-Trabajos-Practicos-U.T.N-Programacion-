#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char auxId;
    char auxNombre[128];
    char auxHorasTrabajadas;
    char auxSueldo;
    int r;

        if(pFile == NULL)
        {
            return -1;
        }
        do
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n,",auxId, auxNombre, auxSueldo, auxHorasTrabajadas);
        }while(!feof(pFile));

        return 1;
    }




/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
