/****************RAIZ   CUADRADA   POR MÉTODO  DE  NEWTON****************************/ 
#include<stdio.h> 
#include<stdlib.h>
float raiz_newton (float, float, float);
main () 
{
     float n, ri, ri1;
     float error=0.000001;
     printf("Dame el numero que quieres calcular raiz\n");
     scanf("%f", &n);
     printf("Dame una aproximacion de la raiz del numero que quieres calcular <diferente de 0>\n");
     scanf("%f", &ri);
     system("cls");
     printf("\nLa aproximacion de la raiz cuadrada de: %g es de %g con error tolerado de %g\n",n,raiz_newton(n,ri,error),error);
     system("PAUSE");
}

float raiz_newton (float n, float ri, float t) //tanto numero a calcular como aproximacion deben de ser positivos
{
      float ri1;
      double e,ea;
      int x=0;
      do
      {
            ri1= ((n/ri)+ ri)/2;//formula de newton
            e= (ri1-ri)/ri1;    //e= error relativo
            if(e<0)         //la funcion del valor absoluto tiene problemas creo que solo funciona para enteros int, y si hay error retorna cero, por eso este if
                   e=-1*e;
            ri=ri1;       //intercambio que se usa en metodos iterativos
            x++;
  //          printf("\n%f error=%f", ri1,e);
            if(e<t)
                     break;
      }
      while(x<10000000);//numero maximo de iteraciones
      return ri1;
}
