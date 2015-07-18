#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
int Menor_d(double *x,int p);
int Mayor_d(double *x,int p);
double Suma_Fila_d(int n,double **x,int cols);
double Suma_Columna_d(int n,double **x,int filas);
void AsignarMem2d_d(double ***x, int filas, int cols);
void LiberarMem2d_d(double **x, int filas);
void Visualizar_d(double **x, int filas, int cols);
void AsignarMem2d_char(char ***x, int filas, int cols);
void LiberarMem2d_char(char **x, int filas);
void Visualizar_char(char **x, int filas);
void Imprime_Encabezado(char *p);
void Inicializar2d_char(char **,int, char *); 
main()
{
//imprime los datos de autores
      Imprime_Encabezado("Arreglos");      
//Declaramos variables a utilizar      
      int filas=12, cols=5,f,g;
      double **m=NULL;
      char **c=NULL;
      char **depto=NULL;
      AsignarMem2d_char(&c,13,13);
      AsignarMem2d_char(&depto,6,13);
      Inicializar2d_char(depto,1,"Produccion");
      Inicializar2d_char(depto,2,"Contabilidad");
      Inicializar2d_char(depto,3,"Recursos H");
      Inicializar2d_char(depto,4,"Sistemas");     
      Inicializar2d_char(depto,5,"Mercadotecnia");             
      Inicializar2d_char(c,0,"Error");      
      Inicializar2d_char(c,1,"Enero");
      Inicializar2d_char(c,2,"Febrero");
      Inicializar2d_char(c,3,"Marzo");
      Inicializar2d_char(c,4,"Abril");
      Inicializar2d_char(c,5,"Mayo");
      Inicializar2d_char(c,6,"Junio"); 
      Inicializar2d_char(c,7,"Julio");                                   
      Inicializar2d_char(c,8,"Agosto");      
      Inicializar2d_char(c,9,"Septiembre");      
      Inicializar2d_char(c,10,"Octubre");      
      Inicializar2d_char(c,11,"Noviembre");      
      Inicializar2d_char(c,12,"Diciembre");
      double Suma_F[12];
      double *sf=Suma_F;
      double Suma_C[5];
      double *sc=Suma_C;
      double sa=0;
//creamos la matriz para manipularla con memoria dinamica
      AsignarMem2d_d(&m,filas,cols);
//inicializamos la matriz
      m[0][0]=2;
      m[0][1]=3;
      m[0][2]=0;
      m[0][3]=0;
      m[0][4]=1;
      m[1][0]=4;
      m[1][1]=5;
      m[1][2]=6;
      m[1][3]=5;
      m[1][4]=0;
      m[2][0]=6;
      m[2][1]=0;
      m[2][2]=9;
      m[2][3]=4;
      m[2][4]=3;
      m[3][0]=0;
      m[3][1]=0;
      m[3][2]=7;
      m[3][3]=4;
      m[3][4]=0;      
      m[4][0]=3;
      m[4][1]=0;
      m[4][2]=6;
      m[4][3]=5;
      m[4][4]=0;      
      m[5][0]=1;
      m[5][1]=2;
      m[5][2]=1;
      m[5][3]=0;
      m[5][4]=3;  
      m[6][0]=7;
      m[6][1]=4;
      m[6][2]=1;
      m[6][3]=0;
      m[6][4]=2;          
      m[7][0]=8;
      m[7][1]=2;
      m[7][2]=2;
      m[7][3]=0;
      m[7][4]=4;      
      m[8][0]=10;
      m[8][1]=1;
      m[8][2]=3;
      m[8][3]=1;
      m[8][4]=8;      
      m[9][0]=0;
      m[9][1]=1;
      m[9][2]=0;
      m[9][3]=2;
      m[9][4]=2;      
      m[10][0]=9;
      m[10][1]=1;
      m[10][2]=0;
      m[10][3]=3;
      m[10][4]=1;    
      m[11][0]=0;
      m[11][1]=2;
      m[11][2]=3;
      m[11][3]=7;
      m[11][4]=0;        
//PREGUNTA 1 FORMATO DE IMPRESION 
      printf("\n1.-Representar el numero de proyectos de cada departamento en forma de tabla\n\n");
      printf("%s  %s  %s  %s  %s\n",depto[1],depto[2],depto[3],depto[4],depto[5]);
      for(f=0;f<filas;f++)
      {
         for(g=0;g<cols;g++)
             printf("%10g", m[f][g]);
         printf("\t\t");
         puts(c[f+1]);
      }
      printf("\n");
      system("PAUSE");
      system("cls");
//SUMA TODAS LAS FILAS Y LO ALMACENA EN SUMA_F[f] y imprime
      printf("4.-:\n");
       for(f=0;f<12;f++)
       {
      Suma_F[f]=Suma_Fila_d(f,m,cols);
      printf("En el mes de %s se terminaron %g proyectos\n",c[f+1],Suma_F[f]);
      }
      system("PAUSE");
      system("cls");
//SUMA TODAS LA COLUMNAS Y LO ALMACENA EN SUMA_C [F]
       for(f=0;f<5;f++)
       {
       Suma_C[f]=Suma_Columna_d(f,m,filas);
       //printf("%g\t",Suma_C[f]);
       }
//BUSCAMOS ELEMENTO MAYOR DE SUMA_F  
      printf("\n\n2.-El mes q huvo mas proyectos es:\n");
      puts(c[Mayor_d(sf,12)+1]);
//BUSCAMOS ELEMENTO MENOR DE SUMA_F
      printf("\n3.-El mes q huvo menos proyectos es:\n");
      puts(c[Menor_d(sf,12)+1]);
//BUSCAMOS ELEMENTO MAYOR DE SUMA_C Y IMPRIMIMOS ESE SUBINDICE EN EL VECTOR DEPTO 
      printf("\n5.-El departamento con  mas proyectos fue:\n");
      puts(depto[Mayor_d(sc,5)+1]);
//OBTENEMOS EL NUMERO DE PROYECTOS TERMINADOS POR ANO
      for(f=0;f<12;f++)
          sa=sa+Suma_F[f];
      printf("\n6.-El numero de proyectos terminados en el ano fue de:%g\nLo q indica q en promedio cada departamento aporto: %g proyectos al ano\n\n\n",sa,sa/5);
//LIBERAMOS LA MEMORIA DE TODAS LA MATRICES 2 DIMENSIONES     
      LiberarMem2d_d(m,filas);
      LiberarMem2d_char(depto,6);
      LiberarMem2d_char(c,13);
system("PAUSE");
}
/**********COPIA UNA CADENA EN UN RENGLON ESPECIFICO DE UNA MATRIZ DE CARACTERES*/
void Inicializar2d_char(char **matriz,int x, char *y)
{
 	 strcpy(matriz[x],y);
}
/**********DEVUELVE LA POSICION DEL ELEMENTO MENOR DE UN ARREGLO DOUBLE 1D*****/
int Menor_d(double *x,int p) 
{
    int i,z=0;
    for(i=0;i<p-1;i++)
    {
        if(x[z]>x[i+1])
             z=i+1;
    }
    return z;
}
/**********DEVUELVE LA POSICION DEL ELEMENTO MAYOR DE UN ARREGLO DOUBLE 1D*****/
int Mayor_d(double *x,int p) 
{
    int i,z=0;
    for(i=0;i<p-1;i++)
    {
        if(x[z]<x[i+1])
             z=i+1;
    }
    return z;
}
/************SUMA LA FILA N DE UNA MATRIZ DOUBLE DE COLUMNAS COLS**************/
double Suma_Fila_d(int n,double **x,int cols)
{
     int i;
     double suma=0;
     for(i=0;i<cols;i++)
     {
        suma=suma+x[n][i];
     }
     return suma;
}  
/************SUMA LA columna N DE UNA MATRIZ DOUBLE DE filas filas*************/
double Suma_Columna_d(int n,double **x,int filas)
{
     int i;
     double suma=0;
     for(i=0;i<filas;i++)
     {
        suma=suma+x[i][n];
     }
     return suma;
}
/****************CREA MATRIZ DINAMICA 2 DIMENSIONES DOUBLE*********************/
void AsignarMem2d_d(double ***x, int filas, int cols)
{
     double **p=NULL;
     int f=0;
     p=(double**)malloc(filas*sizeof(double*));
     if(p==NULL)
                return ;
     memset(p,0,filas*sizeof(double*));
     for(f=0;f<filas;f++)
     {               
         p[f]=(double *)malloc(cols * sizeof(double));
         if(p[f]==NULL)
         {
            LiberarMem2d_d(p,filas);
            *x=NULL;
            return;
         }
     memset(p[f],0,cols * sizeof(double));
     }
     *x=p;
}
/****************LIBERA LA MEMORIA DINAMICA 2 DIM DOUBLE **********************/
void LiberarMem2d_d(double **x, int filas)
{
     int f=0;
     for(f=0;f<filas;f++)
     {
         free(x[f]);
     }
     free(x);
}
/*****************VISUALIZA EL CONTENIDO DE LA MATRIZ DINAMICA 2 DIMES DOUBLE**/
void Visualizar_d(double **x, int filas, int cols)
{
     int f,c;
     for(f=0;f<filas;f++)
     {
         for(c=0;c<cols;c++)
             printf("%10g", x[f][c]);
         printf("\n");
     }
}
/****************CREA MATRIZ DINAMICA 2 DIMENSIONES CHAR  *********************/
void AsignarMem2d_char(char ***x, int filas, int cols)
{
     char **p=NULL;
     int f=0;
     p=(char**)malloc(filas*sizeof(char*));
     if(p==NULL)
                return ;
     memset(p,'a',filas*sizeof(char*));
     for(f=0;f<filas;f++)
     {               
         p[f]=(char *)malloc(cols * sizeof(char));
         if(p[f]==NULL)
         {
            LiberarMem2d_char(p,filas);
            *x=NULL;
            return;
         }
     memset(p[f],'a',cols * sizeof(char));
     }
     *x=p;
}
/****************LIBERA LA MEMORIA DINAMICA 2 DIM DOUBLE **********************/
void LiberarMem2d_char(char **x, int filas)
{
     int f=0;
     for(f=0;f<filas;f++)
     {
         free(x[f]);
     }
     free(x);
}
/*****************VISUALIZA EL CONTENIDO DE LA MATRIZ char de 2 DIMES char*****/
void Visualizar_char(char **x, int filas)
{
     int f;
     for(f=0;f<filas;f++)
         puts(x[f]);
}                
/**********************IMPRIME EL ENCABEZADO **********************************/
void Imprime_Encabezado(char *p)
{
     printf("\n\t\tUNIVERSIDAD NACIONAL AUTONOMA DE MEXICO");
     printf("\n\t\tFES ACATLAN");
     printf("\n\t\tLIC. MATEMATICAS APLICADAS Y COMPUTACION");
     printf("\n\n\n\t\tIntegrantes:");
     printf("\n\t\tHernandez Hernandez Elihu");
     printf("\n\t\tRodriguez Ordaz Omar");
     printf("\n\t\tSalgado Mendoza Jorge");
     printf("\n\n\n\n\t\tEstructura de Datos\n\t\tTEMA: ");
     puts(p);
     printf("\n\n\n\t\tGrupo 1352");
     printf("\n\t\t2010-2\n\n\n\n\n");
     system("PAUSE");
     system("cls");
}
