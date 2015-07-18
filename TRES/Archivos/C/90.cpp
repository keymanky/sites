#include<stdio.h>
#include<conio.h>

 
 main()
{ 
      int i,j,k, suma,n,h,t,p;
      float J,A,m;
      printf("\tOBTENER DETERMINANTES CON GAUSS JORDAN\n");
      printf("Ingrese el tamano de la matriz cuadrada ");
      scanf("%d",&n);
      
      float  a[n][n];
      printf("Ingrese los elementos de la matriz por fila\n ");
      for(i=0;i<n;++i)
        for(j=0;j<n+1;++j)
        {      
        printf("Ingrese el elemento a[%d][%d]\n",i+1,j+1);
        scanf("%f",&a[i][j]);
        }
//primero triangulamos con algoritmo de triangulacion de gauss.
//int a[n][n+1];//matriz aimpliada n+1 significa que le agrego una columna mas no?

for(j=0;j<=n-2;++j)
//if(a[j][j]==0)//pivotea..hay que intercambiar filas.
//pivotear;
for(i=j+1;i<n;++i)
{                  
    m = -a[i][j]/a[j][j];
    for(k=j;k<=n;++k)
    a[i][k] = a[i][k]+ m*a[j][k];
}
A=1;
for(p=0;p<n;p++)
{
    J=a[p][p];
    A=A*J;
}

printf("DETERMINANTE DE LA MATRIZ ES %f",A);


/*     float x[n];
     for(i=n-1;i>=0;i=i-1)

{     suma=0;
      for(j=i+1;j<n;++j)
           suma=suma+a[i][j]*x[j];
      x[i] = (a[i][n] - suma) / a[i][i];
}
*/
       printf("\tJORGE SALGADO MENDOZA \n");             
getch();
}

