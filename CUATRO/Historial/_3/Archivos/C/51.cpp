#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Lee(char *);
main()
{
      int j,p,entero=0;
      double flotante=0;
      char cadena[100];
      for(j=1;j<=21;j++)
      {
           printf("Escribe  ");
           gets(cadena);
           p=Lee(cadena);
           if(p==0)
           {
              entero=atoi(cadena);           
              printf("Es un entero es : %d\n", entero);
           }
           if(p==1)
           {
              flotante=atof(cadena);
              printf("Es un double es %f\n", flotante);
           }
           if(p==2)
           {
              printf("Es una cadena sin numeros. Es :");
              puts(cadena);
           }
           if(p==3)
           {
              printf("Es un alfanumerico. Es : ");
              puts(cadena);
           }
           fflush(stdin);
           system("PAUSE");
           system("CLS");
      }
}
/***********************FUNCION Q RETORNA Q TIPO DE DATO LEYO DEL TECLADO******/   //0 para enteros, 1 para double , 2 para cadenas, 3 alfanumericos
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
