/************LEER UNA LISTA DE NOMBRE Y ORDENARLOS*****************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define FILAS_MAX 100
#define COLS_MAX 80

void ordenar(char[][COLS_MAX], int);

main()
{
      char nombre[FILAS_MAX][COLS_MAX];
      int nFilas=0;
      int fila =0;
      char *fin, respuesta;
      
      do{
           printf("Numero de filas de las matriz:(1-100):  ");
           scanf("%d", &nFilas);
      }while(nFilas<1||nFilas>FILAS_MAX);
      fflush(stdin);
      
      printf("Escribba los nombres a introducir \n");
      for(fila=0;fila<nFilas;fila++)
      {
        printf("Nombre[%d]: ",fila);
        gets(nombre[fila]);
      }
      
      nFilas=fila;
      
      ordenar(nombre,nFilas);
      
      do{
         printf("Desea visualizar el contenido<s/n>");
         respuesta=tolower(getchar());
         fflush(stdin);
         }while(respuesta !='s' && respuesta !='n');
         
         if(respuesta=='s')
         {
             printf("\n");
             for(fila=0;fila<nFilas;fila++)
                printf("%s\n",nombre[fila]);
         }
         system("PAUSE");
}
/***********FUNCION QUE ORDENA MATRIZ DE CARACTERES****************************/
void ordenar(char cad[][COLS_MAX],int nc)
{
     char aux[COLS_MAX];
     int i, s=1;
     while((s==1) && (nc>0))
     {
     nc--;
     s=0;
     for(i=1;i<=nc;i++)
       if(strcmp(cad[i-1],cad[i])>0)
       {
           strcpy(aux,cad[i-1]);
           strcpy(cad[i-1],cad[i]);
           strcpy(cad[i],aux);
           s=1;
       }
     }
}
