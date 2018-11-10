#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "S_Ariel.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        system("cls");
        get_String_soloNum(&option," Menu:\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n 3. Alta de empleado\n 4. Modificar datos de empleado\n 5. Baja de empleado\n 6. Listar empleado\n 7. Ordenar empleados\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n 10. Salir \n","\nError, indique solo numeros",1);
        switch(option)
        {
            case 1:
                ll_deleteLinkedList(listaEmpleados);
                listaEmpleados=ll_newLinkedList();
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    system("cls");
                    printf("Datos Cargados Correctamente\n");
                    system("pause");
                }
                else{
                    printf("Error,no se puedo Abrir el Archivo\n");
                    system("pause");
                }
                break;
            case 2:
                ll_deleteLinkedList(listaEmpleados);
                listaEmpleados=ll_newLinkedList();
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    system("cls");
                    printf("Datos Cargados Correctamente\n");
                    system("pause");
                }
                else{
                    printf("Error,no se puedo Abrir el Archivo\n");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("\n Empleado Agregado con exito\n");
                }
                else{
                    printf("\nError,no se ha podido Cargar el Empleado, Vuelva a intentarlo Mas tarde\n");
                }
                system("pause");
                break;
            case 4:
                system("cls");
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("No Hay datos Cargados\n");
                }
                else{
                    if(controller_editEmployee(listaEmpleados))
                    {
                    printf("\nEmpleado Modificado con Exito\n");
                    }
                    else{
                    printf("\nError, el empleado No existe\n");
                }
                system("pause");

                }

                break;
            case 5:
                system("cls");
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("Error,no hay datos cargados\n");
                }
                else
                {
                    if(controller_removeEmployee(listaEmpleados))
                    {
                    printf("Se Ha dado de baja con exito el empleado\n");
                    }
                    else{
                    printf("Error, el empleado NO existe\n");
                    }
                }
                system("pause");
                break;
            case 6:
                if(controller_ListEmployee(listaEmpleados)==0)
                {
                    printf("Error,No Hay Dato Cargados\n");
                }
                system("pause");
                break;
            case 7:
                system("cls");
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("\nSe Ha Ordenado correctamente\n");
                }
                else{
                    printf("\nError,No se ha logrado ordenar\n");
                }
                system("pause");
                break;
            case 8:
                system("cls");
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("\nDatos Guardados Correctamente\n");
                }
                else{
                    printf("\nError al cargar los datos\n");
                }
                system("pause");
                break;
            case 9:
                system("cls");
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("\nDatos Guardados Correctamente\n");
                }
                else{
                    printf("\nError al cargar los datos\n");
                }
                system("pause");
                break;
        }
    }while(option != 10);
    return 0;
}
