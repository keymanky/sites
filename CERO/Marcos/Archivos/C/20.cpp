#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int digitos (int n);
void triangulo_pascal(int);
float absoluto (float);
int digito(int numero, int digit);
void numero_arreglo(int m[],int n);
main()
{
      int a=10;
       triangulo_pascal(a);
       system("PAUSE");
}
/********************FUNCION QUE DEVUELVE EL VALOR ABSOLUTO********************/
float absoluto (float n)
{
      if (n<0)
          n=-1*n;
return n;
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
/*******************FUNCION QUE DIBUJA EL TRIANGULO****************************/
void triangulo_pascal(int n)
{
     int x,a,i,nn,y,aa,d,ddx,dx;
     a=0;
     for(x=1;x<=n;x++)
     {
                      for(nn=n;nn>x;nn--)
                                         printf(" ");
                      if(x>9)
                      {
                             dx=digitos(x);
                             ddx=digito(x,dx);
                             y=ddx;
                      }
                      else
                          y=x;
                      for(i=1;i<=x;i++)
                      {
                                       if(y>9)                                  //para que y no se salga de 9 en ciclo interno
                                            y=0;
                                       printf("%d",y);
                                       y++;
                      }
                      if(x>1)
                      {
                             a=2+a;
                             aa=a;
                      }
                      for(i=1;i<x;i++)
                      {
                                      if(aa>=10)
                                      {
                                               d=digitos(aa);
                                               printf("%d",digito(aa,d));
                                               aa--;
                                      }
                                      else
                                      {
                                          printf("%d",aa);
                                          aa--;
                                      }
                      }
                      printf("\n");
     }
}
