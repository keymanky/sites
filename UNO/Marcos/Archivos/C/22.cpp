/**********PROGRAMA CUENTA LA FRECUENC CON QUE LAS LETRAS APARECEN EN TEXTO****/
#include <stdio.h>
#include <stdlib.h>
#define  N_ELEMENTOS 'z' - 'a'+1                                                //numero de elementos
main()
{
       int c[N_ELEMENTOS];                                                      //matriz c
       char car;                                                                //indice
                                                                                //Pone los elementos de la matriz a cero
       for(car= 'a'; car<= 'z'; car++)
                c[car - 'a']=0;
                                                                                //Entrada de dtos y calculo de tabla de frecuncias
       printf("Introducir texto\n Para finalizar pulse enter            \n\n");
       while((car=getchar())!='\n')
       {
                                                                                //Si el caracter leido esta entre la 'a' y la 'z' incrementa el contador correspondiente en el arreglo
       if(car>='a' && car<= 'z')
                   c[car - 'a']++;
       }
                                                                                //Escribir la tabla de frecuecias
       for(car='a'; car<='z'; car++)
                    printf("  %c", car);
       printf("\n ----------------------------------------"
                  "--------------------------------------\n");
                  
       for(car = 'a'; car<= 'z'; car++)
               printf("%3d", c[car - 'a']);
       printf("\n\n");
       system("PAUSE");
}

