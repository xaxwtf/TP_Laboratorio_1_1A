#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "S_Ariel.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int r=0;
    pFile=fopen(path,"r");
    if(pFile!=NULL)
    {
        r=parser_EmployeeFromText(pFile,pArrayListEmployee);
    }
    fclose(pFile);

    return r;
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
    int r=0;
    FILE* pFile;
    pFile=fopen(path,"rb");
    if(pFile!=NULL)
    {
        r=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }

    return r;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ok=1;
    Employee* emp=employee_new();
    if(!getInt(&emp->id,"\nIndique el Numero de ID: \n","Error,el ID indicado No es Valido\n",1,9999999,3))
    {
        ok=0;
    }
    if(ok==1 && getString(emp->nombre,"\nIndique el Nombre: ","Error,el Nombre debe tener mas de 2 caracteres",3,227,3)!=1)
        {
            ok=0;
        }
    if(ok==1 && getInt(&emp->horasTrabajadas,"\nIndique las Horas trabajadas: \n","Error,El Numero Minimo de horas es 8",8,1000,3)!=1)
    {
        ok=0;
    }
    if(ok==1 && (getInt(&emp->sueldo,"\n Indique El Salario: \n","Error, EL salario no puede ser menor a 1",1,99999999,3)!=1))
    {
        ok=0;
    }
    if(ok==1)
    {
        ll_add(pArrayListEmployee,emp);
    }
    else{
        free(emp);
    }
    return ok;
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
    int r=0;
    int i,index,opcion=33;
    int len;
    Employee* empleado,*aux;
    len=ll_len(pArrayListEmployee);
    //controller_ListEmployee(pArrayListEmployee);
    index=pedir_entero("\nIndique el Numero de ID: \n");
    for(i=0;i<len;i++)
    {
        empleado=(Employee*)ll_get(pArrayListEmployee,i);
        if(empleado->id==index)
        {
            aux=employee_new();
            *aux=*empleado;
            do{
                printf("Empleado ID: %d",aux->id);
                printf("\n%5d %15s %3d %6d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
                get_String_soloNum(&opcion,"\n---Modificar--- \n 1-Nombre.\n 2-Horas Trabajadas \n 3-Sueldo \n 4-Salir y Guardar Cambios efectuados\n 0-Atras\n","\n Error Indique solo Numeros\n",1);
                switch(opcion)
                {
                case 1:
                    if(getString(aux->nombre,"\nIndique el Nombre Nuevo: \n","Error el Nombre debe tener al menos 3 caracteres\n",3,227,3))
                    {
                        printf("\nDato Modificado con exito\n");
                        system("pause");

                    }
                    break;
                case 2:
                    if(getInt(&aux->horasTrabajadas,"\nIndique las Horas de trabajo: \n","Error,las Horas de trabajo no pueden ser menores a 1",1,500,3))
                    {
                        printf("\nDato Modificado con exito\n");
                        system("pause");


                    }
                    break;
                case 3:
                    if(getInt(&aux->sueldo,"\nIndique Sueldo: \n","Error,El sueldo no pueden ser menor a 1",1,99999999,3))
                    {
                        printf("\nDato Modificado con exito\n");
                        system("pause");
                    }
                    break;
                case 4:
                    *empleado=*aux;
                    free(aux);
                    opcion=0;
                }


            }while(opcion!=0);
        r=1;
        break;
        }
     }
    return r;
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
    int r=0;
    int len,index,i;
    char c;
    int flag=0;
    Employee* empleado;
    len=ll_len(pArrayListEmployee);
    //controller_ListEmployee(pArrayListEmployee);
    index=pedir_entero("Indique el Numero de ID: ");
    for(i=0;i<len;i++)
    {
        empleado=(Employee*)ll_get(pArrayListEmployee,i);
        if(empleado->id==index)
        {
            do{
                system("cls");
                printf("Empleado ID: %d",empleado->id);
                printf("\n%5d %15s %3d %6d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
                getChar(&c,"\nEsta seguro que desea elimiar este empleado?(s/n)","",'A','z');
                switch(c)
                {
                    case 's':
                        ll_remove(pArrayListEmployee,i);
                        r=1;
                        flag=1;
                        break;
                    case 'n':
                        flag=1;
                        break;
                }

            }while(flag!=1);

         break;
        }
    }
    return r;
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
    int i;
    Employee* emp;
    int len=ll_len(pArrayListEmployee);
    if(len>0)
    {
        system("cls");
        printf("  ID       Nombre   Hs.Trab. Sueldo\n");
        for(i=0;i<len;i++)
        {
            emp=(Employee*)ll_get(pArrayListEmployee,i);
            printf("%5d %15s %3d %6d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
        }

    }

    return len;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ok=0;
    int r;
    int opcion=22;
    do{
        get_String_soloNum(&opcion,"---Ordenar Por:---\n 1-ID\n 2-Nombre\n 3-Horas Trabajadas\n 4-Salario \n 0-Salir\n","\nindique solo numeros\n",1);
        switch(opcion)
        {
            case 1:
                r=ll_sort(pArrayListEmployee,ordxId,1);
                opcion=0;
                break;
            case 2:
                r=ll_sort(pArrayListEmployee,ordxNombre,1);
                opcion=0;
                break;
            case 3:
                r=ll_sort(pArrayListEmployee,ordxHorasdTrab,1);
                opcion=0;
                break;
            case 4:
                r=ll_sort(pArrayListEmployee,ordxSueldo,1);
                opcion=0;
                break;
        }
    }while(opcion!=0);
    if(r!=-1)
    {
        ok=1;
    }
    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pfile;
    int ok=0;
    int len,i;
    char encabezado[]={"Id,Nombre,HorasTrabajadas,Sueldo"};
    Employee* aux;
    pfile=fopen(path,"w");
    if(pfile!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        fprintf(pfile,"%s\n",encabezado);
        for(i=0;i<len;i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee,i);
            fprintf(pfile,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
        }
        ok=1;
    }
    fclose(pfile);
    return ok;
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
    FILE* pfile;
    int ok=0;
    int len,i;
    char encabezado[]={"Id,Nombre,HorasTrabajadas,Sueldo"};
    Employee* aux;
    pfile=fopen(path,"wb");
    if(pfile!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        fprintf(pfile,"%s\n",encabezado);
        for(i=0;i<len;i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee,i);
            fprintf(pfile,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
        }
        ok=1;

    }
    fclose(pfile);

    return ok;
    return 1;
}
