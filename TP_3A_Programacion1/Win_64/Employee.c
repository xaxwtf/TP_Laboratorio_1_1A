#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Employee.h"
#include "S_Ariel.h"
Employee* employee_new()
{
    Employee* emp;
    emp=(Employee*)malloc(sizeof(Employee));
    emp->id=-1;
    strcpy(emp->nombre,"");
    emp->horasTrabajadas=0;
    emp->sueldo=0;
    return emp;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* emp;
    emp=(Employee*)malloc(sizeof(Employee));
    emp->id=atoi(idStr);
    strcpy(emp->nombre,nombreStr);
    emp->horasTrabajadas=atoi(horasTrabajadasStr);
    emp->sueldo=0;
    return emp;
}
int employee_setId(Employee* this,int id)
{
    int r=0;
    if(id>0)
    {
        this->id=id;
        r=1;
    }
    return r;
}
int employee_getId(Employee* this,int* id)
{
    int r=1;

    return r;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int r=0;
    if(soloLetras(nombre)&&strlen(nombre)>2)
    {
        r=1;
        string_save(nombre);
        strcpy(this->nombre,nombre);
    }
    return r;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int r=1;

    return r;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r=0;
    if(horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        r=1;
    }
    return r;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int r=1;

    return r;

}
int employee_setSueldo(Employee* this,int sueldo)
{
    int r=0;
    if(sueldo>0)
    {
        this->sueldo=sueldo;
        r=1;
    }
    return r;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int r=1;

    return r;

}
int ordxNombre(void* empA, void* empB)
{
    int r=0;
    Employee* var1;
    Employee* var2;
    var1=(Employee*)empA;
    var2=(Employee*)empB;
    if(strcmp(var1->nombre, var2->nombre )>0)
    {
            r=1;
    }
    if (strcmp(var1->nombre, var2->nombre )<0)
    {
            r=-1;
    }
    return r;
}
int ordxId(void* empA,void* empB)
{
    int r=0;
    Employee* var1;
    Employee* var2;
    var2=(Employee*)empB;
    var1=(Employee*)empA;
    if(var1->id > var2->id)
    {
            r=1;
    }
    return r;
}
int ordxSueldo(void* empA,void* empB)
{
    int r=0;
    Employee* var1;
    Employee* var2;
    var2=(Employee*)empB;
    var1=(Employee*)empA;
    if(var1->sueldo > var2->sueldo)
    {
            r=1;
    }
    if(var1->sueldo < var2->sueldo)
    {
        r=-1;
    }
    return r;
}
int ordxHorasdTrab(void* empA,void* empB)
{
    int r=0;
    Employee* var1;
    Employee* var2;
    var2=(Employee*)empB;
    var1=(Employee*)empA;
    if(var1->horasTrabajadas > var2->horasTrabajadas)
    {
            r=1;
    }
    if(var1->horasTrabajadas < var2->horasTrabajadas)
    {
        r=-1;
    }
    return r;
}

