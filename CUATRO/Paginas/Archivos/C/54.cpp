#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int menu();
int Lee(char *);
void Imprime(int , int [], int [], char **);
void Imprime_Encabezado(char *);
main()
{
      Imprime_Encabezado("Arreglos Paralelos");
      int n=10,indice=0,encontrado=0,j,x;
      char temporal[100];
      char **carrera=NULL;
      carrera=(char **)malloc(n* sizeof(char *));
      for(j=0;j<n;j++)
           carrera[j]=(char *)malloc(100* sizeof(char));
      int num_alum[n];
      int num_prof[n];
      do{
      switch (menu())
             {
                    case 1:
                         {
                                if(indice<n)
                                {
                                     printf("Ingresa la carrera:   ");
                                     gets(carrera[indice]);
                                     printf("Ingresa el numero de alumnos:    ");
                                     scanf("%d",&num_alum[indice]);
                                     printf("Ingresa el numero de profesores:    ");
                                     scanf("%d", &num_prof[indice]);
                                     indice++;
                                }
                                else
                                    printf("Ya esta llenos los arreglos paralelos\n");
                                
                                system("PAUSE");
                                break;
                         }
                    case 2:
                         {
                                printf("\nDame el dato que quieres buscar:   ");
                                gets(temporal);
                                if(Lee(temporal)==0)                            //es un entero
                                {
                                     x=atoi(temporal);
                                     //q busque en arreglos de enteros
                                     for(j=0;j<n;j++)
                                     {
                                          if(x==num_alum[j])
                                          {
                                               encontrado=1;
                                               Imprime(j,num_alum,num_prof,carrera);
                                          }
                                          if(x==num_prof[j])
                                          {
                                               encontrado=1;
                                               Imprime(j,num_alum,num_prof,carrera);
                                          }
                                     }
                                     //si encontro el dato que rescate todos los datos
                                     if(!encontrado)
                                     {
                                         printf("Lo siento no se encontro\n");
                                         system("PAUSE");
                                     }
                                     encontrado=0;
                                }
                                else
                                {
                                    //q busque en arreglos caracteres
                                    for(j=0;j<n;j++)
                                         if(strcmp(temporal,carrera[j])==0)
                                         {
                                              encontrado=1;
                                              Imprime(j,num_alum,num_prof,carrera);
                                         }
                                    
                                    if(!encontrado)
                                    {
                                              printf("Lo siento no se encontro\n");
                                              system("PAUSE");
                                    }
                                }
                                encontrado=0;
                                break;
                         }
                    case 3:
                         {
                                printf("Carrera\t\tAlumnos\t\tProfesores\n");
                                for(j=0;j<indice;j++)
                                {
                                     printf("%s\t\t%d\t\t%d\n",carrera[j],num_alum[j],num_prof[j]);         
                                }
                                printf("\n");
                                system("PAUSE");
                                break;
                         }
             }
      
      }while(1);
}
int menu ()
{
    char m[20];
    int x;
    do
    {
          system("cls");                                                        //da el efecto de borrar solo que lo no esta en las opciones
          printf("\n LEE EL MENU\n 1.-Nuevo\n 2.-Busca\n 3.-Imprime todo\n 4.-Salir\n  ");
          gets (m);                                                             //gets lee los del teclado hasta una marca de EOF y lo guarda como cadena de caracters en alrreglo m
          x=atoi(m);                                                            //a x se le asigna el valor numerico de la cadena en int                                                   
          if (x==4)                                                          
             exit(0);
    }
    while (x!=1 && x!=2 && x!=3);
    return x;
}

int Lee(char *cadena)
{
           int digitos,i,entero=0,alfanumerico=0, punto=0,espacio=0,menos=0,mas=0,caracter=0;    
           digitos=strlen(cadena);             //obtenemos el numero de caracteres menos el nulo
           for(i=0; i<digitos;i++)             //Barremos toda la cadena menos el nulo
           {
                  if(cadena[i] == ' ')         //*******************************no hace nada si es espacio
                     espacio++;
                  else if(cadena[i] == '.')    //*******************************en caso de que sea punto
                  {
                     punto++;
                     if(punto>1)
                     {              //hay mas de 1 punto
                        caracter++;
                        if(entero)            //existian numeros antes y hay 2 puntos
                        {
                           alfanumerico=1;
                           break;
                        }
                     }
                  }
                  else if(cadena[i] >= 48 && cadena[i] <= 57) //****************en caso de que sea un numero
                  {
                     entero++;
                     if(caracter>0)           //si hay un caracter
                        {
                        alfanumerico=1;
                        break;
                        }
                  }
                  else if(cadena [i]== '-')      //*****************************en caso de que menos
                  {
                     menos++;
                     if((menos >1) || (mas>0 || punto>0))     //el operador debe ir al principio o hay mas de 1
                        caracter++;
                     if(entero>0)                             //En caso de q haya un entero antes del operador 
                        {
                           alfanumerico=1;
                           break;
                        }
                  } 
                  else if(cadena [i]== '+')      //*****************************en caso de que sea mas
                  {
                     mas++;
                     if((mas >1) || (menos>0 || punto>0))     //el operador debe ir al principio o has mas de 1
                        caracter++;
                     if(entero>0)               //En caso d q haya entero antes del operador
                        {
                           alfanumerico=1;
                           break;
                        }                     
                  }      
                  else                        //********************************No es operador ni numero
                  {
                     if(entero>0)             //si hay algun numero antes
                     {
                       alfanumerico=1;
                       break;
                     }
                     caracter++; 
                  }
           }                               
           
           
           
           if(alfanumerico)
              return 3;                                   //En caso q no lo sea solo puede haber o letra o numeros. No mescla
           else
           {
              if(caracter>0 || (entero==0 && (mas>0 || menos>0 || punto>0)))    //Si hay letras,  entonces no puede haber enteros; lo q dice que hay operadores solos 
                 return 2;
              else if(caracter==0 && entero==0 && mas==0 && menos==0  && punto==0)     //Si solo hay espacios
                 return 2;
              else if(punto)                                                    //Si hay numeros no hay letras, Si hay punto es flotante
                 return 1;
              else                                                              //Solo hay numeros
                 return 0; 
           }
}
void Imprime(int pos, int alum[], int prof[], char **carrera)
{
printf("\nLos datos encontrados son:\n");
puts(carrera[pos]);
printf("\tNumero de alumnos: %d\n",alum[pos]);
printf("\tNumero de Profesores: %d",prof[pos]); 
printf("\n");
system("PAUSE");
}
void Imprime_Encabezado(char *p)
{
     printf("\n\t\tUNIVERSIDAD NACIONAL AUTONOMA DE MEXICO");
     printf("\n\t\tFES ACATLAN");
     printf("\n\t\tLIC. MATEMATICAS APLICADAS Y COMPUTACION");
     printf("\n\n\n\t\tIntegrantes:");
     printf("\n\t\tHernandez Hernandez Elihu");
     printf("\n\t\tRodriguez Ordaz Omar");
     printf("\n\t\tSalgado Mendoza Jorge");
     printf("\n\n\n\n\t\tEstructura de Datos\n\t\tTEMA: ");
     puts(p);
     printf("\n\n\n\t\tGrupo 1352");
     printf("\n\t\t2010-2\n\n\n\n\n");
     system("PAUSE");
     system("cls");
}
