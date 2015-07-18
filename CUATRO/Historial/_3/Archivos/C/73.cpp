#include<stdio.h>
#include<conio.h>
main()
{
      float X[100],Y[100];
      int i,k,n;
      float x,m=0,p=1;
      printf("/********************  L A G R A N G E  **********************/\n\n\n\n");
      printf("Se creara en el directorio actual un archivo llamado lagrange.txt\nEn este estaran los datos de la tabla.\nCada vez que se corra se sobreescribiran los datos\n\n");      
      printf("Cuantos valores vas a ingresar de x:       ");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
              printf("Dame x[%d]:          ",i);
              scanf("%f",&X[i]);
              printf("Dame f(x)_[%d]:      ",i);
              scanf("%f",&Y[i]);        
      }
      printf("Dame el valor q quieres evaluar por el metodo de lagrange:         ");
      scanf("%f",&x);
            
      printf("\t|        x           |       f(x)         |\n");
      for(i=0;i<n;i++)
      {   
      printf("\t|    %f     |",X[i]);
      printf("\t     %f     |\n",Y[i]);
      }
      for(i=0;i<n;i++)
      {
         p=1;
          for(k=0;k<n;k++)
          {
              
             if(i!=k)
             {
              p=p*((x-X[k])/(X[i]-X[k]));               
              }
          }
          m=p*Y[i]+m;
      }
      printf("\nPara el valor de %g la aproximacion es %f",x,m);
      getch();
      
      FILE *archivo;
      archivo=freopen("lagrange.txt","w",stdout);
      printf("\nMetodos de Interpolacion de lagrange\n\n");
      printf("\t|        x           |       f(x)         |\n");
      for(i=0;i<n;i++)
      {   
      printf("\t|    %f     |",X[i]);
      printf("\t     %f     |\n",Y[i]);
      }
      for(i=0;i<n;i++)
      {
         p=1;
          for(k=0;k<n;k++)
          {
              
             if(i!=k)
             {
              p=p*((x-X[k])/(X[i]-X[k]));               
              }
          }
          m=p*Y[i]+m;
      }
      printf("\nPara el valor de %g la aproximacion es %f",x,m);      
      fclose(archivo); 
      freopen( "CON", "w", stdout );
      fflush(stdin);
}
