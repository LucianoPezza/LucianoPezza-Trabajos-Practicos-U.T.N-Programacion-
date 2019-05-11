#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
 int id;
 char name[50];
 char lastName[50];
 float salary;
 int sector;
 int isEmpty;
}Employee;

#endif // BIBLIOTECA_H_INCLUDED

/** \brief Pide y escanea todos los empleados

 * \param Employee que me permite utilizar toda la estructura
 * \return s
 *
 */

Employee Employeeadd();

/** \brief Me busca un lugar libre
 *
 * \param list para poder utilizar lo que hay en la estructura employee
 * \param int cant definida en el main para las estructuras repetitivas
 * \return aux
 *
 */

int isEmpty(Employee [], int);


/** \brief Me inicializa todos los empleados
 *
 * \param  list para poder utilizar lo que hay en la estructura employee
 * \param int cant definida en el main para las estructuras repetitivas
 * \return
 *
 */

void initEmployees(Employee [], int);



/** \brief Busca un lugar libre y cuando lo encuentra le adhiere un empleado
 *
 * \param list para poder utilizar lo que hay en la estructura employee
 * \param int cant definida en el main para las estructuras repetitivas
 * \return aux
 *
 */

int addemployees(Employee [], int);


/** \brief Me modifica un empleado
 * \param  list para poder utilizar lo que hay en la estructura employee
 * \param int cant definida en el main para las estructuras repetitivas
 * \param int id para encontrar al empleado y modificarlo
 * \return 0
 *
 */


int modifyEmployee(Employee[] ,int, int);



/** \brief Borra un empleado por id
 *
 * \param list para poder utilizar lo que hay en la estructura employee
 * \param  int id para encontrar al empledao y borrarlo
 * \param int cant definida en el main para las estructuras repetitivas
  * \return  0
*/

int removeEmployee(Employee [],int);





/** \brief Me muestra los empleados
 *
 * \param list para poder utilizar lo que hay en la estructura employee
 * \param  definida en el main para las estructuras repetitivas
 * \return  0
 *
 */
int printEmployeers(Employee [], int);




/** \brief Sirve para ordenar la lista por el apellido
 *
 * \param list para poder utilizar lo que hay en la estructura employee
 * \param int int cant definida en el main para las estructuras repetitivas
  * \return  0
 */
int sortEmployeesByLastName(Employee [], int);
