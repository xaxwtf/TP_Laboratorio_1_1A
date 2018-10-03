#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "S_Ariel.h"
#include "ArrayEmployees.h"

void initEmployees(eEmployee *lista, int len,int dato)
{
    int i;
    for(i=0;i<len;i++)
    {
        lista[i].isEmpty=dato;
    }
}
int addEmployee(eEmployee* lista, int len,int id,char name[],char lastName[],float salary, int sector)
{
    int r=0;
    int aux;
    aux=buscarPrimerLibre(lista,len,0);
    if(aux!=-1)
    {
        lista[aux].id=id;
        strcpy(lista[aux].name,name);
        strcpy(lista[aux].lastName,lastName);
        lista[aux].salary=salary;
        lista[aux].sector=sector;
        lista[aux].isEmpty=1;
        r=1;
    }
    return r;
}
int buscarPrimerLibre(eEmployee* lista,int len,int dato)
{
    int i;
    int r=-1;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==dato)
        {
            r=i;
            break;
        }
    }
    return r;
}
void mostrarSectores(eSector* lista,int tam,char titulo[])
{
    int i;
    system("cls");
    printf(titulo);
    for(i=0;i<tam;i++)
    {
        printf("\n%3d     %5s",lista[i].id,lista[i].descripcion);
    }

}
int cargarSector(eSector *lista,int tam)
{
   int dato;
   mostrarSectores(lista,tam,"\nIndique un Sector : ");
   if(getInt(&dato,"\n","\nla opcion indicada no es Valida",1,5,3)==0)
   {
       dato=-1;
   }
    return dato;
}
int findEmployeeById(eEmployee* lista,int len,int id)
{
    int i;
    int r=-1;
    for(i=0;i<len;i++)
    {
        if((lista[i].id==id)&&(lista[i].isEmpty=1))
        {
           r=i;
        }
    }
    return r;
}
void imprimirEmpleado(eEmployee empleado,eSector* sectores,int tamSector)
{
    char descripcion[21];
    cargarDescSector(sectores,tamSector,empleado.sector,descripcion);
    printf("\n%d %7s %12s    %2.f     %6s \n",empleado.id,empleado.lastName,empleado.name,empleado.salary,descripcion);

}
int removeEmployee(eEmployee* lista,int len,int id,eSector *sectores,int tamSec)
{
    int index;
    int r=0;
    char x;
    index=findEmployeeById(lista,len,id);
    if(index!=-1)
    {
        do{
            printf("Empleado ID Nro:%d \n ID    Apellido    Nombre    Salario   Sector ",id);
            imprimirEmpleado(lista[index],sectores,tamSec);
            printf("\nEsta seguro que desea dar de Baja a este empleado?(s/n):");
            fflush(stdin);
            scanf("%c",&x);
            switch(x)
            {
                case 's':
                    lista[index].isEmpty=0;
                    r=1;
                    x='n';
                    break;

            }
        }while(x!='n');
    }
    return r;
}
void cargarDescSector(eSector* lista, int tam,int sector,char *descripcion)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].id==sector)
        {
            strcpy(descripcion,lista[i].descripcion);
        }
    }
}
void Modificar_Empleado(eEmployee* lista,int tamEmp,eSector* lista2,int tamSector)
{
    int opcion=23;
    int dato=pedir_entero("\nindique su Numero de Id:");
    int index=findEmployeeById(lista,tamEmp,dato);
    if(index!=-1)
    {
        do{
            system("cls");
            printf("Empleado ID Nro:%d \n ID    Apellido    Nombre    Salario   Sector ",dato);
            imprimirEmpleado(lista[index],lista2,tamSector);
            opcion=pedir_entero("--MODIFICAR EMPLEADO-- \n 1-Nombre\n 2-Apellido \n 3-SUELDO \n 4-SECTOR \n 0-Salir\n");
            switch(opcion)
            {
                case 1:
                    if(getString(lista[index].name,"\n Indique el Nuevo Nombre: ","\n Error,el nombre debe tener al menos 3 caracteres",3,50,3)==0){
                        printf("\n El dato ha sido Modificado con exito");
                    }
                    break;
                case 2:
                    if(getString(lista[index].lastName,"\n Indique el Nuevo Apellido: ","Error, el apellido debe ter al menos 3 caracteres",3,50,3)==0){
                        printf("\n El dato ha sido Modificado con exito");
                    }
                    break;
                case 3:
                    if(getFloat(&lista[index].salary,"\n Indique el nuevo Importe de su Salario: ","Error,el Salario no puede ser Iferior a 1",1,9999999999999,3)==0){
                        printf("\n El dato ha sido Modificado con exito");
                    }
                    break;
                case 4:
                    if((dato=cargarSector(lista2,5))!=-1){
                        lista[index].sector=dato;
                        printf("\n El dato ha sido Modificado con exito");
                    }

                    break;
            }
        }while(opcion!=0);
    }
    else
    {
        printf("El ID indicado no existe");
    }

}
void sortEmployees(eEmployee *lista, int tamEmp,int order,eSector *sectores,int tamSec)
{
    char descripcionI[21];
    char descripcionJ[21];
    eEmployee aux;
    int i,j;
    switch(order)
    {
        case 1:
            for(i=0;i<tamEmp;i++)
            {
                for(j=i+1;j<tamEmp;j++)
                {
                    cargarDescSector(sectores,tamSec,lista[i].sector,descripcionI);
                    cargarDescSector(sectores,tamSec,lista[j].sector,descripcionJ);
                    if(strcmp(descripcionI,descripcionJ)>0)
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                    }
                    else if(strcmp(descripcionI,descripcionJ)==0 && strcmp(lista[i].lastName,lista[j].lastName)>0)
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                    }
                }
            }
            break;
        case 0:
            for(i=0;i<tamEmp;i++)
            {
                for(j=i+1;j<tamEmp;j++)
                {
                    cargarDescSector(sectores,tamSec,lista[i].sector,descripcionI);
                    cargarDescSector(sectores,tamSec,lista[j].sector,descripcionJ);
                    if(strcmp(descripcionI,descripcionJ)<0)
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                    }
                    else if(strcmp(descripcionI,descripcionJ)==0 && strcmp(lista[i].lastName,lista[j].lastName)<0)
                    {
                        aux=lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                    }
                }
            }
            break;
    }
}
void informes(eEmployee *lista,int tamEmp,eSector *sectores,int tamSec)
{
    int x;
    float prom;
    int cantidad;
    sortEmployees(lista,tamEmp,1,sectores,tamSec);
    do{

        system("cls");
        x=pedir_entero("\n ---INFORMES--- \n 1-Lista de Empleados Ordenados Alfabeticamente por Apellido y Sector \n 2-Total y Promedio de los Salarios,y cuantos empleados superan el Salario Promedio\n 0-Atras\n");
        switch(x)
        {
            case 1:printEmployees(lista,tamEmp,sectores,tamSec);
                break;
            case 2:
                system("cls");
                prom=promedioSalarios(lista,tamEmp);
                cantidad=contDeSueldosArribaDelPromedio(lista,tamEmp);
                printf("\n El Promedio de Los Sueldos: %2.f\n La cantidad empleados que Superan el Salario  Promedio es: %d\n",prom,cantidad);
                system("pause");
                break;
        }

        }while(x!=0);
}
void printEmployees(eEmployee *lista, int tamEmp,eSector *sectores,int tamSec)
{
    int i;
    system("cls");
    printf(" ID    Apellido    Nombre    Salario   Sector ");
    for(i=0;i<tamEmp;i++)
    {
        if(lista[i].isEmpty==1)
        {
            imprimirEmpleado(lista[i],sectores,tamSec);
        }
    }
    system("pause");
}
float promedioSalarios(eEmployee *lista,int tam)
{
    float total=0;
    float r;
    int i;
    int j=0;
    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty==1){
            total=total+lista[i].salary;
            j++;
        }
    }
    r=total/j;
    return r;

}
int contDeSueldosArribaDelPromedio(eEmployee *lista,int tam)
{
    int i;
    int contador=0;
    float pro=promedioSalarios(lista,tam);
    for(i=0;i<tam;i++)
    {
       if(lista[i].salary>pro&&lista[i].isEmpty==1)
       {
           contador++;
       }
    }
    return contador;
}
