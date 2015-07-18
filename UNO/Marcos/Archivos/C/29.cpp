/******CALCULA EL % DE APROBADOS Y SUSPENDIDOS UTILIZA ESTRUCTURAS*************/
#include<stdio.h>
#include<stdlib.h>
#define NA 100

typedef struct
{
        char nombre[60];
        float nota;
        }tficha;

main()
{
      static tficha alumno[NA];                                                 //matriz de estructuras o registros
      int n=0, i=0,lim;
      char *fin=NULL;                                                           //para almacenar el valor debuelto por gets
      int aprobados=0, suspendidos=0;
      
                                                                                //entrada de datos
      printf("Cuantos datos");
      scanf("%d",&lim);
      printf("Empieza ya");
      fin=gets(alumno[n].nombre);
      while (n<NA && n != lim)
      {
            printf("Nota: ");
            scanf("%f",&alumno[n++].nota);
            fflush(stdin);
                                                                                //siguiente alumno
            printf("Nombre:");
            fin=gets(alumno[n].nombre);
      }
      
                                                                                //contar los aprobados y suspendidos
      for(i=0;i<n;i++)
       if(alumno[i].nota>=5)
          aprobados++;
       else
          suspendidos++;
          
          
                                                                                //escribir resultados
      printf("Aprobados:  %.4g %%\n", (float)aprobados/n*100);
      printf("Suspendidos:  %.4g %%\n", (float)suspendidos/n*100);
      system("PAUSE");
}
                                                                                                                                                                                                        
