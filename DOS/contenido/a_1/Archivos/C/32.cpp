/************LEER UNA LISTA DE NOMBRE Y ORDENARLOS*****************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct
{
         float r;                                                               //parte real
         float i;                                                               //parte imaginaria
}tcomplejo;

typedef struct
{
         int filas;                                                               
         int columnas;                                                              
         tcomplejo c[MAX][MAX];                                                 //matriz de complejos
}tmatriz;

tmatriz LeerMatriz()
{
        tmatriz m;
        int f=0,c=0,r=0;
        do{
            printf("\nDame el NuMero de filas");
            r=scanf("%d", &m.filas);
            fflush(stdin);
          }while(r!=1 || m.filas>MAX);

        do{
            printf("\nDame el NuMero de columnas");
            r=scanf("%d", &m.columnas);
            fflush(stdin);
          }while(r!=1 || m.columnas>MAX);          

                                                                                //leer los datos de la matriz
        printf("\nIntroducir los datos de la forma: a  bi<no introducir la i>\nRecuerde q la parte a es la real y la b es la imaginaria\n");
        
        for(f=0;f<m.filas;f++)
        {
        for(c=0;c<m.columnas;c++)
        {
           do{
               printf("elemento[%d][%d]=",f,c);
               r=scanf("%f %f", &m.c[f][c].r, &m.c[f][c].i);
               fflush(stdin);                                                   //limpia el bufer
               }while(r!=2);
        }
        }
        return m;
}

void VisualizarMatriz(tmatriz m)
{
     int f,c;
     printf("\n");
     for(f=0;f<m.filas;f++)
     {
         for(c=0;c<m.columnas;c++)
             printf("%8.2f%+8.2fj", m.c[f][c].r, m.c[f][c].i);
         printf("\n");
     }
}

tcomplejo MulCompl(tcomplejo a,tcomplejo b)
{
    tcomplejo c;
    c.r=a.r * b.r - a.i * b.i;
    c.i=a.r* b.i + a.i * b.r;
    return c;
}

tcomplejo SumCompl(tcomplejo a,tcomplejo b)
{
    tcomplejo c;
    c.r=a.r + b.r;
    c.i=a.i+b.i;
    return c;
}

tmatriz Multiplicar(tmatriz a, tmatriz b)
{
    tmatriz m;
    int f,c,k;
    if(a.columnas !=b.filas)
    {
        printf("No se pueden multiplicar las matrices\n");
        system("PAUSE");
        exit(-1);
    }
    
    m.filas=a.filas;
    m.columnas=b.columnas;
                                                                                //multiplicar matrices
    for(f=0;f<m.filas;f++)
    {
        for(c=0;c<m.columnas;c++)
        {
            m.c[f][c].r=0;
            m.c[f][c].i =0;
            for(k=0;k<a.columnas;k++)
               m.c[f][c]=SumCompl(m.c[f][c], MulCompl(a.c[f][k], b.c[k][c]));
        }
    }
    return m;
}

main()
{
      static tmatriz a,b,c;
      a=LeerMatriz();
      b=LeerMatriz();
      c=Multiplicar(a,b);
      VisualizarMatriz(c);
      system("PAUSE");
}
        
