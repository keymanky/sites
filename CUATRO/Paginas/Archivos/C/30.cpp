/*****************Valor minimo y maximo de una lista***************************/
#include<stdio.h>
#include<stdlib.h>
#define NMAX 100
main()
{
      float dato[NMAX];                                                        //matriz de datos
      float max,min;                                                            //valor maximo y minimo
      int nElementos=0;                                                         //numero de elementos de la matriz leidos
      int i=0,n;                                                                  //indices
                                                                                //entrada de datos
      printf("Introducir numero de datos");
      scanf("%d",&n);
      for(i=0;i<=n;i++)
      {
         printf("Dame el elemento [%d]", i);
         scanf("%f", &dato[i]);
      }
      
                                                                                //encontra los valores maximos y minimos
     nElementos=i;
     if(nElementos>0)
     {
        max=min=dato[0];
        for(i=0;i<nElementos; i++)
        {
             if(dato[i]>max)
             max=dato[i];
             if(dato[i]<min)
             min=dato[i];
        }
        
                                                                                //escribir los datos
       printf("Valor maximo: %g, valor minimo: %g\n",max,min);
     }
     else
       printf("No hay datos");
     
     system("PAUSE");
}                                                                                                                                                                                                                                              
