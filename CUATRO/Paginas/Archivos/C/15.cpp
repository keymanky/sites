/****************RETORNA LAS RAICES DE UNA ECUACION DE 2DO GRADO****************************/ 
#include<stdio.h> 
#include<stdlib.h>
#include<math.h>

int verifica_raiz(float,float,float);//funcion que verifica que tipo de raices tiene si son complejas retorna cero sino retorna 1
float raiz_real2do(float,float,float,int);
main () 
{
     float a,b,c,raiz;
     int tipo;
     printf("\nResuelve ecuaciones de la forma ax^2 + bx + c =0\nDame coeficiente de a\n");
     scanf("%f", &a);
     printf("Dame coeficiente de b\n");
     scanf("%f", &b);
     printf("Dame el valor de c\n");
     scanf("%f", &c);
     tipo= verifica_raiz(a,b,c);
     raiz= raiz_real2do(a,b,c,2);
     system("cls");
     printf("%d %f",tipo, raiz);
     system("PAUSE");
}

int verifica_raiz(float a,float b,float c)
{
    float verifica;
    verifica= (b*b)-(4*a*c);
    if (verifica<0)
       return 0;
    if (verifica>=0)
       return 1;
}

float raiz_real2do(float a,float b,float c,int d)
{
      float discriminante,x;
      discriminante=(b*b)-(4*a*c);
      if(a==0 && b==0)
      {
              return 0;
              exit(0);
      }
      if(discriminante<0)
      {
              return 0;
              exit (0);
      }
      if (a==0)
      {
              return -c/b;
              exit (0);
      }
      if (d==1)
      {
               x=(-b+(sqrt(discriminante)))/(2*a);
               return x;
               exit(0);
      }
      if (d==2)
      {
               x=(-b-(sqrt(discriminante)))/(2*a);
               return x;
               exit(0);
      }
}
      
        
