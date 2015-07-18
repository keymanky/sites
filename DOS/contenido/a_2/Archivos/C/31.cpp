/***************TABLA DE FRECUENTCIAS EN UN TEXTO******************************/
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define DIM ('z'-'a'+1)

main()
{
     static int tabla[DIM][DIM];                                                //tabla de contingencias
     char f,c;                                                                  //indices
     char car;                                                                  //caracter actual
     char carant= ' ';                                                          //caracter anterior
     
     printf("Introducir texto. Para finalizar presiona enter\n");
     while((car=getchar())!= '\n')
     {
         car=tolower(car);                                                      //convertir minuscula s si procede
         if((carant>='a' && carant<= 'z') && (car>= 'a' && car<= 'z'))
             tabla[carant - 'a'][car- 'a']++;
             carant=car;
     }
     
                                                                                //escribir la tabla de frecuencias
     printf(" ");
     for(c='a'; c<='z';c++)
         printf("  %c",c);
     putchar('\n');
     
     for(f='a';f<='z';f++)
     {
         putchar(f);
         for(c='a';c<='z';c++)
              printf("%3d", tabla[f-'a'][c-'a']);
         putchar('\n');
     }
     system("PAUSE");
}
