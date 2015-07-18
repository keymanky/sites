#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
void AsignarMem2d_d(double ***x, int filas, int cols);
void Inicializa_Ts(double **x,int n);
void Transforma_Ts(double **x,int n,double *m);
int Dimension_2d_Ts(int n); 
void Construye_Ts(double ** x,double *y,int n);
int Busca_TS(int i,int j, int n);
void Visualizar_d(double **x, int filas, int cols);
void LiberarMem2d_d(double **x, int filas);
main()
{
//incializamos variables y declaramos
      int n,i,j,r=1;
      printf("Dame la dimension de la matriz: ");
      scanf("%d",&n);
      double **ts=NULL;         //ts puntero a matriz triangular superior de 2 dimensiones
      
      int dim_1d;
      dim_1d= (((n*n)-n)/2)+n;  //dim_1d va a ser igual al numero de elementos de la matriz de 1d. esa formula calcula el numero de elementos diferentes de cero
      
      double Triangular[dim_1d];     //matriz triangular superior de 1 dimension
      double *p1d= Triangular;  //puntero a la matriz 1 dimension
      
      AsignarMem2d_d(&ts,n,n);  //reservamos memoria para la matriz triangular superior  2 dim.Referenciada por ts
      Inicializa_Ts(ts,n);      //inicializamos la matriz triangular superior de acuerdo a la definicion de una triangular superior
      
      printf("La matriz triangular superior q usted introdujo fue:\n");
      Visualizar_d(ts, n,n);     //visualizamos la matriz triangular superior de 2 dimensiones
      Transforma_Ts(ts,n,p1d);  //Convertimos la matriz de 2d a 1d 
      LiberarMem2d_d(ts, n);    //destruimos la memoria de 2dimensiones 
      
      
      //imprimimos la matriz 1 dimension q es la 2d triangular superior
      printf("La matriz reducida de 1 dimension q es igual a la triangular superior es:\n");
      for(i=0;i<dim_1d;i++)
          printf("%g\t",Triangular[i]);
       printf("\n\n");
      
      //EL usuario nos da los subindices del elemento de la matriz triangular superior y nosotros lo buscamos en el arreglo de 1d 
       while(r)
       {
       do{
                  printf("Que posicion de la matriz triangular superior quieres buscar\n");  
                  printf("Dame el indice i: ");
                  scanf("%d", &i);
                  printf("Dame el indice j: ");
                  scanf("%d", &j);
                  if((i>j) || (i>n || j>n) || (i<=0|| j<=0) )                           //por si no existe tal elemento en la triangular superior     
                           printf("\tError intentemos de Nuevo, esa posicion no existe\n");
                  else
                           printf("El elemento es: %g ",Triangular[Busca_TS(i,j,n)]);          //la funcion busca devuelve el indice correspondiente de la matriz de 1 dimension
                  if(i>j && j!=0)         //por si la posicion es valida dentro de la matriz pero sabemos q es cero
                           printf("\tSabemos q esa posision es cero\n");
       }while((i>n || j>n)|| (i<=0 || j<=0));                            //ciclo q continua hasta q nos den unos subindices validos
       
       fflush(stdin);     //limpia el bufer de entrada , sin el no guarda lo q pregutamos en r
       printf("\nPara salir presione <cero> o para continuar otro numero <diferente> de cero\n");
       scanf("%d", &r);
       }
       /*//construimos a partir de la matriz de 1 d; la matriz 2d
      dim_2d= Dimension_2d_Ts(dim_1d);
      AsignarMem2d_d(&ts,dim_2d,dim_2d);
      
      Construye_Ts(ts,p1d,dim_2d);
      printf("La matriz construida apartir de la matriz de 1 dimension es:\n");    
      Visualizar_d(ts, dim_2d,dim_2d);        
      LiberarMem2d_d(ts, dim_2d); */

        
      //system("PAUSE");
}
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
/*************INICIALIZA POR MEDIO DEL USUARIO UNA MATRIZ TRIANGULAR SUPERIOR**/
void Inicializa_Ts(double **x,int n)
{
     int i,j;
     float a;
     for(i=0;i<n;i++)
         for(j=0;j<n;j++)
         {
             if(i<=j)
             {
                   do{
                   printf("Dame el elemento de la matriz <%d> <%d>: ",i+1,j+1);
                   scanf("%f",&a);
                   }while(a==0);
                   x[i][j]=(double)a;
             }
         }
}
/*******TRANSFORMA UNA MATRIZ TRIANGULAR SUPERIOR A UNA 1D T.S*****************/
void Transforma_Ts(double **x,int n,double *m)
{
     int a=0,i,j;
     for(i=0;i<n;i++)
         for(j=0;j<n;j++)
             if(i<=j)
             {
                     m[a]=x[i][j];
                     a++;
             }
}
/*****FUNCION Q DEVUELVE LA DIMENSION DE UNA MATRIZ 2D TRIANGULAR SUPERIOR*****/
int Dimension_2d_Ts(int n)
{
    int i,suma=0;
    for(i=0;i<n;i++)
    {
      suma=suma+i;
      if(suma>=n)
         break;
    }
    return i;
}
/*******TRANSFORMA UNA MATRIZ DE 1D A UNA MATRIZ TRIANGULAR SUPERIOR DE 2D*****/
void Construye_Ts(double ** x,double *y,int n)
{
     int i,j,a=0;
     int pos;
     for(i=1;i<=n;i++)               //i=1 y j=1 para poder usar la formula y por eso resto i-1 y j-1 ya q las matrizes en la commputadora se almacenan desde 0,0
         for(j=1;j<=n;j++)
         {
              if(i<=j)               //para sacar todas las posibles posiciones validas
              {
                      //x[i][j]=y[a];        mas facil sin usar toda esta formula
                      pos=1+((n*(i-1))-(((i-2)*(i-1))/2)+(j-i));         //aca la formula que calcula la posicion del arreglo bidimensiona 
                      x[i-1][j-1]=y[pos-1];     //pasamor el valor de la matriz unidimensional a la dibimensional en su respectivo lugar
                      //a++;
              }
         }
}
/***********BUSCA ELEMENTO DE LA MATRIZ T.SUPERIOR EN SU MATRIZ DE 1D**********/
int Busca_TS(int i,int j, int n)
{
       int pos; //posicion del arreglo unidimensional
       pos=0+((n*(i-1))-(((i-2)*(i-1))/2)+(j-i));
       return pos;
}
//
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
//
//
void LiberarMem2d_d(double **x, int filas)
{
     int f=0;
     for(f=0;f<filas;f++)
     {
         free(x[f]);
     }
     free(x);
}
