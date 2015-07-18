#include<stdio.h>
#include<conio.h> 
#include<stdlib.h> 
#include <math.h>
 main()
{ 
      int l,n,m,p,i,j,k;
      float suma=0;
      double errel;
      printf("\tMETODO JACOBI \nIMPORTANTE SE CREE QUE LA MATRIZ ES DIAGONAL Dominante 20 Itineraciones\n");
      printf("Ingrese el tamano de la matriz cuadrada estrictamente diagonal dominante");
      scanf("%d",&n);
      m=n+1;
      float a[n][m];
      float z[n];
      float x[n];
/***************ESCANEA MATRICES****************************************/      
      for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
           {
                printf("Dame elemento A (%d %d) \t",i,j);
                scanf("%f",&a[i][j]);
                printf("\n");
                x[i]=0;
                z[i]=0;
           } 
/*****************IMPRIME MATRIZ***************************************/

      for(i=1;i<=n;i++)
      {
           for(j=1;j<=m;j++)
                printf("%f\t",a[i][j]);
           printf("\n");
      }
      system("PAUSE");
/******************************METODO**************************/
printf("\nX1\tX2\t\t\t...XN");
system("PAUSE");
for(k=1;k<20;k++)
{
     for(i=1;i<=n;i++)
     {
          for(j=1;j<=m;j++)
          {
               if(i==j)
                    suma=suma;
               else
                    suma=suma+(a[i][j])*x[j];//*x[j]
          }
          
          for(l=1;l<=m;l++)
              z[l]=x[l];
          x[i]=(a[i][m]-suma)/(a[i][i]);
          suma=0;             
     }    
         /*if(k>1)
         {
           errel=fabs(x[1]-z[1])/fabs(x[1]);
           printf("%f\n",errel);
           if(errel<0.00001)
           {
                for(p=1;p<=n;p++)
                     printf("Aproximacion x %d %f: \n", p,x[p]);
                system("PAUSE");
                exit(0);
           }
         }*/
         
         for(l=1;l<=n;l++)
             printf("%f\t", x[l]);
         printf("\n");
}    
system("PAUSE");
}
