#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void AsignarMem2d_char(char ***x, int filas, int cols);      
void Inicializar2d_char(char **matriz,int x, char *y);
void LiberarMem2d_char(char **x, int filas);
main()
{

            
      char dia[10];
      char aux[10]; 
      int numero,i,k=0,negativo=1,indice=0;
      char **matriz_dias=NULL;                   //matriz dinamica bidimensional
      AsignarMem2d_char(&matriz_dias,8,10);      //8 filas por 10 columnas
                                                 //inicializamos matriz
      Inicializar2d_char(matriz_dias,1,"lunes");
      Inicializar2d_char(matriz_dias,2,"martes");
      Inicializar2d_char(matriz_dias,3,"miercoles");
      Inicializar2d_char(matriz_dias,4,"jueves");
      Inicializar2d_char(matriz_dias,5,"viernes");
      Inicializar2d_char(matriz_dias,6,"sabado");
      Inicializar2d_char(matriz_dias,7,"domingo");
      Inicializar2d_char(matriz_dias,0,"error");
      
      
      while(1)                                  //ciclo infinito q se ejecute siempre hasta q introduscan la cadena fin
      {
           fflush(stdin);                       //limpia el buffer de entrada <\n>
           printf("Introduce el dia <fin /para salir>:  ");
           gets(aux);                          //almacenamos en un auxiliar;
           strcpy(dia,strlwr(aux));            //CONVERTIMOS A MINUSCULAS LO ESCANEADO DESDE EL TECLADO Y LO ALMACENAMOS EN EL ARREGLO DIA
           
           if(strcmp(dia,"fin")==0)            //Para salir del ciclo y por ende salir del programa
                break;
           else
           {
                for(i=1;i<=7;i++)
                     if(strcmp(matriz_dias[i],dia)==0)      //checa si la cadena del usuario es un dia valido sino repite
                          k=i;                              //donde i es el subindice de la matriz_dias. k Guarda la posicion de la fila del dia q introdujo
                if(k==0)
                     goto repite;
           }
      
      
      
      
                                                            //si se llega a esta parte del programa entonces se introdujo un dia valido
           printf("Introduce Numero:  ");             
           scanf("%d",&numero);
           if(numero<0)                                     //si numero es menor a cero entonces lo vuelve positivo y guarda el signo en negativo
           {
                  numero=-1*numero;
                  negativo=-1;
           }
      
           while(1)                                         //obtiene el dia, restando de 7 en 7 hasta obtener un subidice valido de rango 0-7
           {
                 if(numero<=7)
                       break;  
                 numero=numero-7;
            }
            
            indice=(numero*negativo)+k;                     //numero rango de<0-7> + k
            if(indice>7)                                    //puede ser q numero=7 y k=domingo=7 y por ello indice=14
                 indice-=7;
            if(indice<0)                                    //si el indice es negativo, se regrese (7+indice<negativo>)
                 indice=7+indice;
            if(indice==0)                                   //si es igual con cero significa q es el ultimo o sea 7
                 indice=7;
                 
            printf("%s\n",matriz_dias[indice]); 
            system("PAUSE");
            repite:
            system("cls");
            k=0;
            negativo=1;
            indice=0;
      }
      
      LiberarMem2d_char(matriz_dias,8);
}
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
void Inicializar2d_char(char **matriz,int x, char *y)
{
 	 strcpy(matriz[x],y);
}
void LiberarMem2d_char(char **x, int filas)
{
     int f=0;
     for(f=0;f<filas;f++)
     {
         free(x[f]);
     }
     free(x);
}
