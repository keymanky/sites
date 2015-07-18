#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void LeerCadenas(char **,int);
void OrdenarCadenas(char **,int);
void Visualizar_char(char **x, int filas);
void LiberarMem2d_char(char **x, int filas);
main()
{
      char **cadenas=NULL;
      int nfilas;
      printf("Dame el numero de filas <con longitud maxima de 49 caracteres>: ");
      scanf("%d",&nfilas);
      fflush(stdin);                        //limpia el bufer del teclado necesario porq sino se queda el caracter nulo
      
      cadenas=(char **)malloc(nfilas*sizeof(char *));  //el apuntador cadenas declara un arreglo de apuntadores tipo char de tamano nfilas
      LeerCadenas(cadenas,nfilas);                     
      OrdenarCadenas(cadenas,nfilas);
      Visualizar_char(cadenas,nfilas);                 //funcion de la biblioteca
      LiberarMem2d_char(cadenas,nfilas);               //funcion de la biblioteca
      system("PAUSE");
}

void LeerCadenas(char **x,int nfilas)
{
      char cadena[50];
      int i,longitud=0;
      printf("Introducir cadenas de caracteres.\nNo introducir caracteres extranos y las Mayusculas seran convertidas a minusculas\n");
      for(i=0;i<nfilas;i++)
      {
           longitud=strlen(gets(cadena));             //se lee la cadena y se guarda en uno temporal en este caso llamado cadena, luego obtenemos la longitud de esa cadena
           x[i]=(char *)malloc(longitud +1);          //cada apuntador del arreglo apunta a un espacio en memoria de tipo char con caracteres de tamano longitud + 1, Mas 1 por el caracter nulo 
           strcpy(cadena,strlwr(cadena));             //convierte las mayusculas a minusculas si es q hay     (strlwr)
           strcpy(x[i],cadena);                       //copiamos la cadena auxiliar a la matriz
      }
      
      printf("\nLas cadenas ordenadas de a-z son \n\n");
}

void OrdenarCadenas(char **x,int filas)               //compara la fila 1 con la siguinte, despues la 1=siguiente y hace lo mismo, ya acabado vuelve ha hacer lo mismo el numero de filas; para acegurar q comparo todas las cadenas
{
     char *aux;                                       //apuntador auxiliar
     int i,s=1;                                       
     while((s==1) && (--filas>0))                     //ejecute el ciclo si hay filas pendientes  y existio almenos un cambio, si s es igual a cero entonces significa q las cadenas estaban ordenadas alfabeticamente porq la cadena i-1 es siempre menor q la cadena i
     {
          s=0;
          for(i=1;i<=filas;i++)                       //compara las cadenas i-1  y la i 
              if(strcmp(x[i-1],x[i])>0)               //strcmp compara lexicograficamente las cadenas y devuelve <0 =0 o >0 si es menor,igual o mayor la cadena 1 (primer parametro) contra la 2 (segundo parametro)
              {                                       //si la cadena de arriba va despues q la cadena de abajo (i)
                   aux=x[i-1];                      
                   x[i-1]=x[i];                       //intercambia, dejando la menor hasta arriba
                   x[i]=aux;
                   s=1;                               //s muestra si existio almenos una permutacion,
              }
     }
}
void Visualizar_char(char **x, int filas)
{
     int f;
     for(f=0;f<filas;f++)
         puts(x[f]);
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
