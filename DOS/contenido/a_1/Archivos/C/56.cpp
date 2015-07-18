#include<stdio.h>
#include<stdlib.h>
main ()
{
     printf("Examen parte practica\n\nRealizo Salgado Mendoza Jorge\nResendiz Mendoza Victor Hugo\n");
     int n,m,l,k,j,i,contador=1;
     system("PAUSE");
     do{
     system("cls");
     printf("La matriz es de 3*3*3*3*3\nCuantos datos quieres introducir (entre 0 y 242)\n");
     scanf("%d", &n);
     }while(n<0 || n>242);
     
      //printf("%d",n);
      int arreglo[3][3][3][3][3];
      
      for(m=0;m<=2;m++)
          for(l=0;l<=2;l++)
              for(k=0;k<=2;k++)
                  for(j=0;j<=2;j++)
                      for(i=0;i<=2;i++)
                      {
                      if(contador <= n)
                      {
                      printf("Dame el elemento [%d][%d][%d][%d][%d]: ", m,l,k,j,i);
                      scanf("%d", &arreglo[m][l][k][j][i]);
                      contador++;
                      }
                      }
                      contador=0;
      for(m=0;m<=2;m++)
          for(l=0;l<=2;l++)
              for(k=0;k<=2;k++)
                  for(j=0;j<=2;j++)
                      for(i=0;i<=2;i++)
                      {
                      if(contador < n)
                      {
                      printf("EL elemento  [%d][%d][%d][%d][%d]: es  %d \n", m,l,k,j,i,arreglo[m][l][k][j][i]);
                      contador++;
                      }
                      }     
      
      system("PAUSE");
}
