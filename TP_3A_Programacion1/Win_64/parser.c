#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char aux1[30];
    char aux2[30];
    char aux3[30];
    char aux4[30];
    Employee* empleado;
    int r=0;
    r=fscanf(pFile,"%[^\n]",aux1);
    do{
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",aux1,aux2,aux3,aux4);
        if(r==4)
        {

            empleado=employee_new();
            empleado->id=atoi(aux1);
            strcpy(empleado->nombre,aux2);
            empleado->horasTrabajadas=atoi(aux3);
            empleado->sueldo=atoi(aux4);
            ll_add(pArrayListEmployee,empleado);
            r=ll_len(pArrayListEmployee);
        }

    }while(!feof(pFile));


    return r;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char aux1[30];
    char aux2[30];
    char aux3[30];
    char aux4[30];
    Employee* empleado;
    int r=0;
    r=fscanf(pFile,"%[^\n]",aux1);
    do{
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",aux1,aux2,aux3,aux4);
        if(r==4)
        {

            empleado=employee_new();
            empleado->id=atoi(aux1);
            strcpy(empleado->nombre,aux2);
            empleado->horasTrabajadas=atoi(aux3);
            empleado->sueldo=atoi(aux4);
            ll_add(pArrayListEmployee,empleado);
            r=ll_len(pArrayListEmployee);
        }

    }while(!feof(pFile));



    return r;
}
