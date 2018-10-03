#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "S_Ariel.h"
#define TAM 1000
int main()
{
    int opcion;
    eSector sectores[]={
        {1,"RRHH"},
        {2,"VENTAS"},
        {3,"CONTABILIDAD"},
        {4,"TRASPORTE"},
        {5,"TESORERIA"},
    };
    eEmployee empleados[TAM];
    eEmployee aux;
    int contAltas=0;
    initEmployees(empleados,TAM,0);
    do{
            system("cls");
            opcion=pedir_entero("\n-----TP2----- \n 1-ALTAS \n 2-MODIFICAR \n 3-BAJA \n 4-INFORMAR \n 0-Salir\n Indique una Opcion: ");
            switch(opcion)
            {
                case 1:
                    if(buscarPrimerLibre(empleados,TAM,0)!=-1)
                    {
                        if(getString(aux.name,"\n Indique el Nombre: ","\nEl Nombre Indicado debe tener al menos 3 Caracteres \n",3,50,3)==-1)
                        {
                            break;
                        }
                        if(getString(aux.lastName,"\n Indique el Apellido: ","\nEl Apellido debe tener al menos 2 Carcteres \n",2,50,3)==-1)
                        {
                            break;
                        }
                        if(getFloat(&aux.salary,"\n Indique el Salario: ","\nel Salario no puede ser menor a 1\n",1,999999999999,3)==-1)
                        {
                            break;
                        }
                        if(-1==(aux.sector=cargarSector(sectores,5)))
                        {
                            printf("\nError\n");
                            system("pause");
                            break;
                        }
                        if(addEmployee(empleados,TAM,1000+contAltas,aux.name,aux.lastName,aux.salary,aux.sector)==1)
                        {
                            printf("\nEl Empleado se ha cargado Correctamente\n\n");
                            system("pause");
                            contAltas++;
                        }

                    }
                    else
                    {
                        printf("\nSe ah Alcanzado el Limite de Empleados  a cargar\n");
                        system("pause");
                    }
                    break;
                case 2:
                    if(buscarPrimerLibre(empleados,TAM,1)!=-1)
                    {
                        Modificar_Empleado(empleados,TAM,sectores,5);
                    }
                    else{
                        printf("\nNo hay datos Cargados\n\n");
                        system("pause");
                    }
                    break;
                case 3:
                    if(buscarPrimerLibre(empleados,TAM,1)!=-1){
                            if(removeEmployee(empleados,TAM,pedir_entero("\nIndique el Numero de ID:"),sectores,5))
                            {
                                printf("\n EL Empleado ha sido dado de baja con exito\n");
                                system("pause");
                            }
                    }
                    else{
                        printf("\n No hay datos Cargados\n\n");
                        system("pause");
                    }
                    break;
                 case 4:
                     if(buscarPrimerLibre(empleados,TAM,1)!=-1)
                     {
                         informes(empleados,TAM,sectores,5);

                     }
                     else{
                        printf("\nNo hay datos Cargados\n\n");
                        system("pause");
                     }

                    break;

            }

    }while(opcion!=0);
    return 0;
}
