#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
FILE*pFile;

   pFile = fopen(path, "r");

   if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        printf("\nLos datos del archivo se han cargado\n");
    }
    else
    {
        printf("No se pudo cargar el archivo");
    }
fclose(pFile);
return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
FILE *pFile= fopen(path, "rb");
    if(pFile!= NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        printf("\nLos datos del archivo se han cargado\n");

    }
    else
    {
        printf("\nEl archivo no se pudo cargar.\n");
        fclose(pFile);
    }
    return 0;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSalario[50];
    int tamanioLista;
    int auxID;
    int i;
    Employee* auxNewEmployee;

    tamanioLista = ll_len(pArrayListEmployee);
    auxNewEmployee = employee_new();
    if(pArrayListEmployee !=NULL)
    {
        auxID=getInt("Ingrese el id del nuevo empleado");
        itoa(auxID, auxId, 10);
        for(i =0;i<tamanioLista;i++)
        {
            auxNewEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if( auxNewEmployee->id == auxID)
            {
                printf("El id que intenta agregar esta ocupado.\n");
                break;
            }
        }
        if(auxNewEmployee->id!=auxID)
        {
            getStr("ingrese el nombre: \n", auxNombre);
            getStr("ingrese  las cantidad de horas trabajadas: \n", auxHorasTrabajadas);
            getStr("ingrese el salario: \n", auxSalario);

            auxNewEmployee = employee_newParameters(auxId, auxNombre, auxHorasTrabajadas, auxSalario);
            ll_add(pArrayListEmployee, auxNewEmployee);

        }
    }

    return 0;

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char auxNombre[128];
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    int i;
    Employee* auxEmployeeModify;
    int tamanioLista;
    int option;

    tamanioLista = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        auxId = getInt("\nIngrese el id para encontrar el empleado a modificar\n");
        for(i=0;i<tamanioLista;i++)
        {
            auxEmployeeModify = (Employee*)ll_get(pArrayListEmployee, i);
            if(auxId==auxEmployeeModify->id)
            {
                system("cls");
                do
                {
                    printf("\n1.Para ingresar el nombre del empleado\n2.Para ingresar las horas trabajadas\n3.Para ingresar el sueldo\n4 Para salir.");
                    option=getInt("Ingrese la opcion");

                    switch(option)
                    {
                    case 1:
                        system("cls");
                        getStr("Ingrese el nuevo nombre \n", auxNombre);
                        employee_setNombre(auxEmployeeModify, auxNombre);

                        break;
                    case 2:
                        system("cls");
                        auxHorasTrabajadas = getInt("ingrese la cantidad horas trabajadas\n");
                        employee_setHorasTrabajadas(auxEmployeeModify, auxHorasTrabajadas);
                        break;
                    case 3:
                        system("cls");
                        auxSueldo = getInt("ingrese el salario \n");
                        employee_setSueldo(auxEmployeeModify, auxSueldo);
                        break;
                    case 4:
                        system("cls");
                        option = 4;
                        break;
                    default:
                        printf("Ingrese una opcion valida.");
                        break;
                    }
                }
                while(option != 4);

            }
        }

    }
    return 0;


}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployeeDELETE;
    int auxId;
    int i;
    int tamanioLista;
    tamanioLista = ll_len(pArrayListEmployee);
    if(pArrayListEmployee !=NULL)
    {
        auxId = getInt("ingrese ID  a remover");
        for(i=0;i<tamanioLista;i++)
        {
            auxEmployeeDELETE = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxEmployeeDELETE->id == auxId)
            {
                ll_remove(pArrayListEmployee, i);
                printf("\nEmpleado dado de BAJA.\n");
                employee_delete(auxEmployeeDELETE);
                break;
            }
        }
    }
return 0;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSalario;
    int tamanio;
    tamanio = ll_len(pArrayListEmployee);
    int i;
    if(pArrayListEmployee!=NULL)
    {
        printf(" Id------Nombre-----Horas trabajadas---Sueldo \n");

        for(i=0;i<tamanio;i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee, &auxId);
            employee_getNombre(auxEmployee,auxNombre);
            employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas);
            employee_getSueldo(auxEmployee,&auxSalario);
            printf("%5d  %15s %15d  %15d\n",auxId, auxNombre, auxHorasTrabajadas, auxSalario);

        }
    }else
        {
            printf("Los datos no se pudieron mostrar");
        }
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployeeSave;
    FILE* pFile;
    pFile = fopen(path, "w");
    int i;
    int tamanioLista;

    tamanioLista = ll_len(pArrayListEmployee);

    if(pFile != NULL)
    {

        fprintf(pFile, "ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");

        if(pArrayListEmployee!=NULL)
        {
            for(i=0;i<tamanioLista;i++)
            {
                auxEmployeeSave = (Employee*)ll_get(pArrayListEmployee, i);
                fprintf(pFile, "%d,%s,%d,%d\n", auxEmployeeSave->id, auxEmployeeSave->nombre, auxEmployeeSave->horasTrabajadas, auxEmployeeSave->sueldo);
            }
            printf("\nSe han guardado los cambios.\n");
        }
        fclose(pFile);
        return 1;
    }
    else
    {
        printf("Error\n");
        return 0;
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployeeSaveBinari;
    FILE*pFile;

     pFile= fopen(path, "wb");

    int tamanioLista;
    tamanioLista = ll_len(pArrayListEmployee);
    int i;
    if(pFile == NULL)
    {

        printf("Error al guardar\n");
        return 0;
    }

    if(pArrayListEmployee!=NULL)
    {
        for(i=0;i<tamanioLista;i++)
        {
            auxEmployeeSaveBinari = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(auxEmployeeSaveBinari,sizeof(Employee), 1, pFile);
        }
        printf("\nSe han guardado los cambios.\n");
    }
    fclose(pFile);
    return 1;

}

