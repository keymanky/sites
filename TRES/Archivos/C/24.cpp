/*cuenta palabras, caracteres y lineas de un texto*/
#include <stdio.h>
#include <stdlib.h>

main()
{
      const int SI= 1;
      const int NO= 0;
      char car;
      int palabras=NO;
      int ncaracteres=0, npalabras =0, nlineas=0;
      printf("Introducir texto.");
      printf("Pulse Entrar despues de cada linea.\n");
      
      while((car=getchar()) !='\n')                                             //Para archivos se puede utilizar !=EOF diferente del final de fichero
      {
                            ++ncaracteres;                                      //Contador de caracteres con espacios en blanco
                            if(car==' ' || car == '\n' || car=='\t')            //Elimina espacio en blanco,tabuladores y nueva linea
                                      palabras=NO;
                            else if(palabras==NO)                               //Comienzo de una palabra
                            {
                                 ++npalabras;                                   //Contador de palabras
                                 palabras=SI;
                            }
                            if(car=='\n')                                       //Finaliza cada linea
                                         ++nlineas;                             //contador de lineas
      }
      printf("%d %d %d\n",ncaracteres, npalabras,nlineas);
      system("PAUSE");
}







