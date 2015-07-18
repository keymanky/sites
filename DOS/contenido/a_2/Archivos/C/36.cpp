/*********************MATRIZ DINAMICA **(FUNCIONES DE C RALLOC...**************/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

main()
{
      int **m=NULL;                                                             //se declara un doble apuntador q va apuntar a matriz de puntero q a su vez apuntan a matriz dinamica
      int nFilas=0, nCols=0;
      int correcto=0, f=0,c=0;
      
      do{
          printf("Numero de filas de la matriz:");
          correcto=scanf("%d", &nFilas);
          fflush(stdin);
          }while(!correcto||nFilas<1);
          
          do{
             printf("Numero de columnas de la matriz ");
             correcto = scanf("%d",&nCols);
             fflush(stdin);
             }while(!correcto||nCols<1);
             
                                                                                //Asigna memoria para la matriz de punteros CON este if se hace.Notese que el espacio de memoria es int*; y tambien el puntero void de malloc es convertido por un cats a doble apuntador y luego asignado a m
       if((m=(int**)malloc(nFilas * sizeof(int *)))==NULL)
       {
          printf("Insuficiente memoria \n");
          return -1;
       }
       
                                                                                //Asignar memoria para cada una de las filas
       for(f=0;f<nFilas;f++)
       {
           if((m[f]=(int*)malloc(nCols*sizeof(int)))==NULL)                     //Igual q arriba este if reserva memoria, notese q ahora es cols y q el apuntador de tipo void generado por malloc es convertido a *int y no doble, porq se usa para la matriz de punteros anteriormete creada
           {
               printf("Insuficiente memoria\n");
               return -1;
           }
       }
       
                                                                                //Iniciar matriz a cero                                                                                                                                       //                                                                                                                                                                   
       for(f=0;f<nFilas;f++)                                                    //con esto puedeo manipular la matriz 2 dimensiones como si fuera una declaracion normal
          for(c=0;c<nCols;c++)
              m[f][c]=0;

       for(f=0;f<nFilas;f++)                                                    //ver matriz
       {
           for(c=0;c<nCols;c++)
                printf("%d  ",m[f][c]);
           printf("\n");
       }
       
                                                                                //liberar memoria de la matriz
       for(f=0;f<nFilas;f++)                                                    //notese q se libera por cada fila elemento a elemento
           free(m[f]);
           
       free(m);                                                                 //se libera la matriz de punteros
       
       system("PAUSE");                                                                                                                                                                
                                                        
}
