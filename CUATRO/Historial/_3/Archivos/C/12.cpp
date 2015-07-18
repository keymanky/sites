/****************EJEMPLO SENCILLO DE FUNCIONES GETCHAR Y PUTCHAR CARACTER A CARACTER*****************************/
#include<stdio.h>
#include<stdlib.h>

main()
{
      char car=0;
      printf("Introduzca una cadena de texto\n (Para terminar Ctrl+c\n");
      while((car=getchar())!=EOF)                    //getchar cada vez que se ejecute leera el siguiente caracter del ultimo leido devuelve EOF si detecta el final del fichero
      {
         if (car !='\n')                             //se pone porque getchar antes de devolver EOF lee el caracter \n como caracter valido
            printf("El codigo Ascii de %c es %d\n", car, car);//putchar es para escribir un caracter y getchar para leer
      }
      system("PAUSE");
}
