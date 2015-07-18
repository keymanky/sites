/*********************PROGRAMA QUE LEE UNA LISTA DE NOMBRE*********************/
#include <stdio.h>
#include <stdlib.h>

#define FILAS_MAX 100
#define COLS_MAX 80

main()
{
      char nombre[FILAS_MAX][COLS_MAX];
      int nFilas=0;
      int fila=0;
      char *fin,respuesta;
      
      do
      {
           printf("Numero de filas de la matriz");
           scanf("%d", &nFilas);
      }while(nFilas <1 || nFilas > FILAS_MAX);
      fflush(stdin);
      
      printf("Escriba los nombres que desea introducir");
      
      for(fila=0; fila<nFilas;fila++)
      {
                  printf("Nombre[%d]: ",fila);
                  fin=gets(nombre[fila]);                                       //Cada fila es una cadena, el conjunto de filas forman varias cadenas, las columnas representan el numero de caracteres pag199 c++
      }
      nFilas = fila;
      do
      {
             printf("¿Desea visualizar el contenido de la matriz(s/n):");
             respuesta=getchar();
             fflush(stdin);
      }while (respuesta != 's' && respuesta !='n');
      
      if(respuesta=='s')
      {
                        printf("\n");
                        for(fila=0;fila<nFilas; fila++)
                                                printf("%s\n", nombre[fila]);
                        system("PAUSE");
      }
}
