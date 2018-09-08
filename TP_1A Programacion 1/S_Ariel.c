#include <stdio.h>
#include "S_Ariel.h"
int getInt(int *dir,char msg[], char Emsg[],int Linf, int Lsup)
{
    int i=1;
    int num;
    printf(msg);
    scanf("%d",&num);
    if(num>=Linf&&num<=Lsup)
    {
        *dir=num;
    }
    else{
        printf(Emsg);
        i=-1;
    }
    return i;
}
int getFloat(float *dir,char msg[],char Emsg [], float Linf,float Lsup)
{
    int i=-1;
    float num;
    printf(msg);
    scanf("%f",&num);
    if(num>=Linf&&num<=Lsup)
    {
        *dir=num;
        i=1;
    }
    else{
        printf(Emsg);
    }
    return i;
}
int getChar(char *dir,char msg[],char Emsg[],char linf,char lsup)
{
    int i=1;
    char c;
    printf(msg);
    fflush(stdin);
    scanf("%c",&c);
    if(c>=linf&&c<=lsup)
    {
       *dir=c;
    }
    else
    {
        printf(Emsg);
        i=-1;
    }
    return i;
}
float dividir(float numA,float numB)
{
    float resultado;
    if(numB!=0)
    {
       resultado=numA/numB;
    }
    else
    {
        printf("ERROR,No se puede dividir por 0\n");
        resultado=0;
    }


    return resultado;
}
void inizArray(int vector[],int tam,int valor,int desde)
{
    int i;
    for(i=desde; i<tam; i++)
    {
        vector[i]=valor;
    }
}
