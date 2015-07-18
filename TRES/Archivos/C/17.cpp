/********************PROGRAMA QUE SIMULA UNA CALCULADORA***********************/
#include <stdio.h>
#include <stdlib.h>
int sumar(int,int);
int restar(int,int);
int dividir(int,int);
int multiplicar(int,int);
int menu2();
main()
{
       int op,a,b;
       op=menu2();
       system("cls");
       printf("Dame a y b");
       scanf("%d %d",&a,&b);
       switch (op)
       {
              case 1:
                   {
                   printf("%d",sumar(a,b));
                   break;
                   }
              case 2:
                   {
                   printf("%d",restar(a,b));
                   break;
                   }
              case 3:
                   {
                   printf("%d",multiplicar(a,b));
                   break;
                   }
              case 4:
                   {
                   printf("%d",dividir(a,b));
                   break;
                   }
              case 5:
                   {
                   exit(0);
                   break;
                   }
       }
       system("PAUSE");       
}
/*************************FUNCION MENU*****************************************///FUNCION A DESARROLLAR CON ARGUMENTOS VARIABLES
int menu2 ()
{
    char m[20];
    int x;
    do
    {
          system("cls");                                                        //da el efecto de borrar solo que lo no esta en las opciones
          printf("\n LEE EL MENU\n 1.-SUMAR\n 2.-RESTA\n 3.-MULTIPLICAR\n 4.-DIVIDIR\n 5.-Salir\n");
          gets (m);                                                             //gets lee los del teclado hasta una marca de EOF y lo guarda como cadena de caracters en alrreglo m
          x=atoi(m);                                                            //a x se le asigna el valor numerico de la cadena en int                                                   
    }
    while (x<=0 || x>5);
    return x;
}
/********FUNCIONES BASICA QUE NO ESTAN EN LIBRERIA, SON PARA EJEMPLIFICAR******/
int sumar(int a,int b)
{
     return a+b;
}
int restar(int a,int b)
{
     return a-b;
}
int dividir(int a,int b)
{
     return a/b;
}
int multiplicar(int a,int b)
{
     return a*b;
}
