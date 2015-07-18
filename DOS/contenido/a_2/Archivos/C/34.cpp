#include<stdio.h>
#include<stdlib.h>
void Funcion_1();                //prototipos de funciones 
int Funcion_2();
float Funcion_3(float);

main()
{
      float n=2;
      int (*pf2) ();      //se declara un puntero a funcion. Se pone int porque la funcion devuelve un int. Se pone () porq no tiene parametros
      pf2=&Funcion_2;     //el puntero a funcion apunta a la funcion 2 que devuelte int y no tiene parametros como fue declarado el puntero.
      pf2();              //pf2(); llama a la funcion 2, por lo tanto son equivalentes pf2() y Funcion_2();
      
      void(*pf1) ();      //void porq apunta a una funcion q no devuelve nada, () porq apunta a una funcion sin parametros
      pf1=&Funcion_1;     //se inicializa el puntero a la funcion 1 
      pf1();              //llama a la funcion pf1
      
      float(*pf3) (float);
      pf3=&Funcion_3;
      pf3(n);
      printf("%f",pf3(n));
        
      system("PAUSE");
}
/*******************************FUNCION 1 *************************************/
void Funcion_1()
{
     printf("Esto es la funcion 1\n");     
}
/*******************************FUNCION 2 *************************************/
int Funcion_2()
{
     printf("Esto es la funcion 2\n");
     return 2;
}
/*******************************FUNCION 1 *************************************/
float Funcion_3(float x)
{
     printf("Esto es la funcion 3\n");
     return x;
}
