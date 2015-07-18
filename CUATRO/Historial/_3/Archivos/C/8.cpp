#include <stdio.h>
#include <stdlib.h>

int menu ();
float centigrados_farengati (float);
float farengati_centigrados (float);

int main()
{
    int op;
    float n,inverso;
    op= menu(); 
    system("cls");
    printf("\n Dame la cantidad de Grados\n");
    scanf("%f",&n);
    if (op==2)
       inverso= centigrados_farengati(n);
    if (op==1)
       inverso= farengati_centigrados(n);
    system("cls");   
    printf("\nEstos grados %g corresponden a %g\n",n, inverso);                 //se utliza %g para eliminar los ceros insignificativos del float si existen como 4.0000000000 y solo salga 4
    system("PAUSE");
    return 0;
}


/*************************FUNCION MENU*****************************************///FUNCION A DESARROLLAR CON ARGUMENTOS VARIABLES
int menu ()
{
    char m[20];
    int x;
    do
    {
          system("cls");                                                        //da el efecto de borrar solo que lo no esta en las opciones
          printf("\n LEE EL MENU\n 1.-PARA CONVERTIR DE FARENHEIT A CENTIGRADOS\n 2.-PARA CONVERTIR DE CENTIGRADOS A FARENHEIT\n 3.-SALIR\n   ");
          gets (m);                                                             //gets lee los del teclado hasta una marca de EOF y lo guarda como cadena de caracters en alrreglo m
          x=atoi(m);                                                            //a x se le asigna el valor numerico de la cadena en int                                                   
          if (x==3)                                                          
             exit(0);
    }
    while (x!=1 && x!=2);
    return x;
}

/**********************FUNCION CENTIGRADOS _ FARENGATI*************************/
float centigrados_farengati (float n)
{
      float cen;
      cen=(n*1.8)+32;
      return cen;
}


/**********************FARENGATI _ CENTIGRADOS*********************************/
float farengati_centigrados (float n)
{
      float farengati;
      farengati = (n-32)/1.8;
      return farengati;
}

