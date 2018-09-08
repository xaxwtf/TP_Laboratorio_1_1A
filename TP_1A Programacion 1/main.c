#include <stdio.h>
#include <stdlib.h>
#include "S_Ariel.h"
#define TAM 4

int main()
{
    int opcion= 20;
    char sub_op={'z'};
    float num;
    float num2;
    int resl=-1;
    float valores[TAM];
    float factorA=1;
    float factorB=1;
    int estado[5];
    int i;
    num2=0;
    num=0;
    inizArray(estado,5,-1,0);
    do{
        printf("---CALCULADORA V 1.0--- \n 1-Ingresar 1er Operando(A=  %.2f). \n 2-Ingresar 2do Operando(B=  %.2f).\n 3-Calcular Todas las Operaciones.\n 4-Informar Resultados.\n 5-Salir \n ",num,num2);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                do{
                    resl=getFloat(&num,"\n Indique un Numero: ","Error,el Numero Indicado esta fuera del rango",-999999999,99999999);
                }while(resl!=1);
                break;
            case 2:
                do{
                    resl=getFloat(&num2,"\n Indique un Numero: ","Error,el Numero Indicado esta fuera del rango",-9999999,999999);
                }while(resl!=1);

                break;
            case 3:
                do{
                        printf("\n a) Calcular la Suma de A + B \n b) Calcular la Resta de A - B \n c) Calcular la Divicion de A / B \n d) Calcular la Multiplicacion de A * B \n e) Calcular el Factorial de (A) \n f)Salir. \n");
                        fflush(stdin);
                        scanf("%c",&sub_op);
                        switch(sub_op)
                        {
                        case 'a':
                            valores[0]=num+num2;
                            estado[0]=1;
                            break;
                        case 'b':
                            valores[1]=num-num2;
                            estado[1]=1;
                            break;
                        case 'c':
                            if(num2!=0)
                            {
                                valores[2]=num/num2;
                                estado[2]=1;
                            }
                            break;
                        case 'd':
                            valores[3]=num*num2;
                            estado[3]=1;
                            break;
                        case 'e':
                            if(num==0)
                            {
                                factorA=1;
                                estado[4]=1;
                            }
                            else if(num<0)
                            {
                                factorA=0;
                            }
                            else
                            {
                            for(int i=num;i>=1;i--)
                                {
                                    factorA=factorA*i;
                                }
                                estado[4]=1;
                            }

                            if(num2==0)
                            {
                                factorB=1;
                                estado[5]=1;
                            }
                            else if(num2<0)
                            {
                                factorB=0;
                            }
                            else
                            {
                            for(i=num2;i>=1;i--)
                                {
                                    factorB=factorB*i;
                                }
                                estado[5]=1;
                            }
                            break;
                        }

                }while(sub_op!='f');

                break;
            case 4:
                do{
                    printf("\n Reultados: \n a)suma \n b)resta \n c)divicion\n d)multiplicacion \n e)Factorial \n f)salir \n");
                        fflush(stdin);
                        scanf("%c",&sub_op);
                        switch(sub_op)
                        {
                        case 'a':
                            if(estado[0]!=-1)
                            {
                                printf("El resultado de la Suma A+B es: %.2f",valores[0]);
                            }
                            else{
                                printf("No hay Resultados");
                            }
                            break;
                        case 'b':
                            if(estado[1]!=-1)
                            {
                                printf("El resultado de la resta A-B es: %.2f",valores[1]);
                            }
                            else{
                                printf("No hay Resultados");
                            }
                            break;
                        case 'c':
                            if(estado[2]!=-1)
                            {
                                printf("\n El resultado de la Divicion A/B es: %.2f",valores[2]);
                            }
                            else{
                                printf("\n No se Puede Dividir por Cero");
                            }
                            break;
                        case 'd':
                            if(estado[3]!=-1)
                            {
                                printf("\n El resultado de la Multiplicacion A*B es: %.2f",valores[3]);
                            }
                            else{
                                printf("\n No hay Resultados");
                            }
                            break;
                        case 'e':
                            if(estado[4]!=-1)
                            {
                                printf("\n El Factorial de A es: %.2f",factorA);
                            }
                            else{
                                printf("\n no Existe el Factorial de Numeros Negativos o Fracciones ");
                            }
                            if(estado[5]!=-1)
                            {
                                printf("  El Factorial de B es: %.2f",factorB);
                            }
                            else
                            {
                                printf("\n no Existe el Factorial de Numeros Negativos o Fracciones ");
                            }
                            break;
                       }
                }while(sub_op!='f');
        }
}while(opcion!=5);
    return 0;
}

