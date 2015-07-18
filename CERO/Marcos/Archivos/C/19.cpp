#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int fecha_valida(int ano, int mes, int dia);
int digitos (int n);
int digito(int numero, int digit);  
int bisiesto (int ano);
float absoluto (float n);
void numero_arreglo(int m[],int n);
int numero_tarot(int,int,int);
main()
{
      int ano,mes,dia,f;
      do
      {
                   printf("Dame ano nacimiento\n");
                   scanf("%d", &ano);
                   printf("Dame mes nacimiento\n");
                   scanf("%d", &mes);
                   printf("Dame dia nacimiento\n");
                   scanf("%d", &dia);
                   f=fecha_valida(ano,mes,dia);
                   if(f==1)
                           break;
                   system("cls");
      }while (1);
      printf("El numero de tarot es %d\n", numero_tarot(ano,mes,dia));
      system("PAUSE");
}
/********************FUNCION QUE DEVUELVE EL VALOR ABSOLUTO********************/
float absoluto (float n)
{
      if (n<0)
          n=-1*n;
return n;
}
/***************FUNCION QUE CALCULA EL NUMERO DE TAROT DE UNA PERSONA**********/
int numero_tarot(int ano, int mes, int dia)
{
    int n,suma,d,x,a;
    n= ano+mes+dia;
    d=digitos(n);
    suma=0;
    for(x=1;x<=d;x++)
    {
                     suma=suma + digito(n,x);
    }
    if(suma>9)
                     suma=numero_tarot(suma,0,0);                               //de chiripa le atine que suma=
    return suma;
}
/**************************FUNCION QUE DICE SI LA FECHA EXISTE*****************/
int fecha_valida(int ano, int mes, int dia)
{
    int v;
    if(ano<=0 || ano>=3000)
    {
              return 0;
              exit(0);
    }
    if(mes<=0 || mes>12)
    {
              return 0;
              exit(0);
    }    
    if(dia<=0 || dia>31)
    {
              return 0;
              exit(0);
    }
    switch (mes)
    {
           case 1:
                {
                      return 1;
                      exit(0);
                }
           case 2:
                {
                      if(dia<=28)
                      {
                      return 1;
                      exit(0);
                      }
                      if(dia>29)
                      {
                      return 0;
                      exit(0);
                      }
                      if(dia==29)
                      {
                                 v=bisiesto(ano);
                                 if(v==1)
                                 {
                                         return 1;
                                         exit(0);
                                 }
                                 else
                                 {
                                     return 0;
                                     exit(0);
                                 }
                      }
                }
           case 3:
                {
                      return 1;
                      exit(0);
                }
           case 4:
                {
                      if(dia<=30)
                      {
                      return 1;
                      exit(0);
                      }
                      else
                      {
                      return 0;
                      exit(0);
                      }
                }
           case 5:
                {
                      return 1;
                      exit(0);
                }
           case 6:
                {
                      if(dia<=30)
                      {
                      return 1;
                      exit(0);
                      }
                      else
                      {
                      return 0;
                      exit(0);
                      }
                }
           case 7:
                {
                      return 1;
                      exit(0);
                }
           case 8:
                {
                      return 1;
                      exit(0);
                } 
           case 9:
                {
                      if(dia<=30)
                      {
                      return 1;
                      exit(0);
                      }
                      else
                      {
                      return 0;
                      exit(0);
                      }
                }
           case 10:
                {
                      return 1;
                      exit(0);
                }
           case 11:
                {
                      if(dia<=30)
                      {
                      return 1;
                      exit(0);
                      }
                      else
                      {
                      return 0;
                      exit(0);
                      } 
                }
           case 12:
                {
                      return 1;
                      exit(0);
                }

     }
}
/**********************FUNCION QUE CUENTA EL NUMERO DE DIGITOS maximo 10*******/
int digitos (int n)
{
    int ceros, d;
    n=int(absoluto((float)n));
    ceros=10;
    d=1;
    do
    {
        if(ceros>n)
        {
                   return d;
                   exit (0);
        }
        ceros=ceros*10;
        d++;
    }while (d<=20);
return 0;
}
/****************FUNCION QUE RETORNA EL DIGITO ESPECIFICADO DE UN NUMERO INT***/
int digito(int numero, int digit)
{
    int dig,x;
    dig=digitos(numero);
    if(digit>dig || digit<=0)
    {
       return 0;
       exit(0);
    }
    int cadena[dig];
    numero_arreglo(cadena,numero);  
    return cadena[digit-1];
}
/*********************FUNCION DICE SI UN ANO ES BISIESTO***********************/
int bisiesto (int ano)
{                                                                               //un ano bisiesto es aquel divisible por 4, excepto si es divisible por 100 pero si por 400 
    if (ano % 4 == 0)
       {
            if (ano %100==0)
            {
                    if(ano%400==0)
                       return 1;
                    else
                       return 0;
            }
            else
               return 1;
       }
    else
       return 0;
}
/************FUNCION QUE PASA UN ENTERO A CADENA maximo 10 digitos*************/
void numero_arreglo(int m[],int n)
{
     int suma=0,d,x,y,i;
     d=digitos(n);
     for(x=1;x<=d;x++)
     {
                      y=(n/pow(10,d-x)) - suma;
                      m[x-1]=y;
                      suma= suma + m[x-1];                                      //en suma se iran sumando los numero por eso solo multiplico por 10 cada vez
                      suma=suma*10;
     }
}
