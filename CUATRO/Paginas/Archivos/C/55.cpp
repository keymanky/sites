#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Imprime_Encabezado(char *);
int Lee(char *);
void Limpia_Espacios(char *,int);
void Limpia_Ceros(char *);
int Numeros_Punto(int, char *);  
void AsignarMem2d_char(char ***, int, int );
void LiberarMem2d_char(char **, int );
void Visualizar_char(char **, int );
main()
{
    Imprime_Encabezado("Numeros-Letras");
    int n=11,i=0,k=20,tipo,indices,espera=0,posicion,aux,contenido=0,antes_punto,imprimio=1,ceros=0;
    char ***control, num[30];                                                   //Puntero principal y num es donde vamos a almacenar el numero leido desde el teclado
    control=(char***)malloc(n*sizeof(char**));                                  //el puntero principal apunta a un arreglo, el arreglo es de punteros q apuntan a matriz dinamica de 2 dimensiones tipo char (cadenas de caracteres)
    for(i=0;i<n;i++)                                                            //creamos las matrices de caracteres
         AsignarMem2d_char(&control[i],10,15);
//Asignacion de cadenas claves//
    control[1][0]=" ";
    control[1][1]="uno ";
    control[1][2]="dos ";
    control[1][3]="tres ";
    control[1][4]="cuatro ";
    control[1][5]="cinco ";
    control[1][6]="seis ";
    control[1][7]="siete ";
    control[1][8]="ocho ";
    control[1][9]="nueve ";
    control[2][0]=" ";
    control[2][1]="diez y ";
    control[2][2]="veinty y ";
    control[2][3]="treinta y ";
    control[2][4]="cuarenta y ";
    control[2][5]="cincuenta y ";
    control[2][6]="sesenta y ";
    control[2][7]="setenta y ";
    control[2][8]="ochenta y ";
    control[2][9]="noventa y ";
    control[3][0]=" ";
    control[3][1]="ciento ";
    control[3][2]="doscientos ";
    control[3][3]="trescientos ";
    control[3][4]="cuatrocientos ";        
    control[3][5]="quinientos ";    
    control[3][6]="seiscientos ";    
    control[3][7]="setecientos ";    
    control[3][8]="ochocientos ";    
    control[3][9]="novecientos ";  
    for(i=0;i<n-1;i++)
    {
         control[4][i]="mil ";
         control[7][i]="millones ";
         control[10][i]="billones ";
    }  
    char **control2;
    AsignarMem2d_char(&control2, 11, 20);
    control2[0]=" ";
    control2[1]=" Decimas";
    control2[2]=" Centesimas";    
    control2[3]=" Milesimas";
    control2[4]=" Diez Milesimas";
    control2[5]=" Cien Milesimas";            
    control2[6]=" Millonesimas";    
    control2[7]=" Diez Millonesimas";    
    control2[8]=" Cien Millonesimas";    
    control2[9]=" Billonesimas";   
    control2[10]=" Diez Billonesimas"; 
    printf("Dame un numero entre:\n1 y 9 999 999 999.999 999 999 9\nNota el 10,20,30... se representa como \"diez y\" respectivamente.\n");
    do{//para repetir el proceso 20 veces
       gets(num);
       Limpia_Espacios(num,0);                                                  //elimina todos los espacios q solo estorban
       Limpia_Ceros(num);                                                       //elimina los ceros no significativos
       tipo=Lee(num);
       if(tipo==0 || tipo==1)                                                   //valida que el numero introducido sea una entero o flotante
       {
            if(strlen(num)>21 || Numeros_Punto(1,num)>10 || Numeros_Punto(0,num)>10)
            {   
                printf("El numero supera el limite\n");    
            }
            else                                                                //si entra aca es un numero valido y soportado !!!!!!!!!!!!!!
            {   
                antes_punto=Numeros_Punto(1,num);                               //devuelve el #de digitos antes del punto
                indices=strlen(num);
                //ciclo q barre los digitos antes del punto
                control[1][0]=" ";
                control[2][0]=" ";
                control[3][0]=" ";
                for(i=0;i<antes_punto;i++)                                      //este es el ciclo principal parte 1. barre digito por digito hasta llegar al ultimo digito
                {
                      contenido=(int)num[i]-48;                                 //contenido contiene un numero de 1 digito que corresponde a la casilla especifica
                      posicion=antes_punto-i;                                   //la posicion empieza en el numero de digitos, conforme avanza el ciclo va disminuyendo
                      if(posicion>3)                                            //si el numero es de mas de 3 cifras
                      {
                           aux=posicion;
                           do{                                                  //a un auxiliar se le resta de 3 en 3 hasta obtener un numero entre 3-1
                              aux=aux-3;
                             }while(aux>3);
                           if(aux>1)                                            //si el auxiliar es 2 0 3 entonces que se espere para imprimer las cifras miles, millones o billones
                               espera=1;
                           else
                               espera=0;
                           printf("%s",control[aux][contenido]);                //imprime de acuerdo a la posicion y de acuerdo al contendio de tal posicion
                           if(num[i]=='0')
                               ceros++;
                           else
                               ceros=0;
                      } 
                      else
                          ceros=0;         
                      if(!espera && ceros<3)
                           printf("%s",control[posicion][contenido]);           //si es valido que imprima los miles, millones, billones , etc
                }//fin del proceso parte 1
                //ciclo q barre los digitos despues del punto
                antes_punto=Numeros_Punto(0,num);                               //ahora antes del punto tiene el # de digitos despues del punto
                i++;                                                            //i es el indice, le sumamos para que salte el "."
                ceros=0;
                control[1][0]="cero ";
                control[2][0]="cero ";
                control[3][0]="cero ";
                for(i;i<indices;i++)                                            //indices es el limite de la cadena
                {
                      if(imprimio)
                           printf(" PUNTO ");
                      contenido=(int)num[i]-48;                                 //contenido contiene un numero de 1 digito que corresponde a la casilla especifica
                      posicion=indices-i;                                       //la posicion empieza en el numero de digitos, conforme avanza el ciclo va disminuyendo
                      if(posicion>3)                                            //si el numero es de mas de 3 cifras
                      {
                           aux=posicion;
                           do{                                                  //a un auxiliar se le resta de 3 en 3 hasta obtener un numero entre 3-1
                              aux=aux-3;
                             }while(aux>3);
                           if(aux>1)                                            //si el auxiliar es 2 0 3 entonces que se espere para imprimer las cifras miles, millones o billones
                               espera=1;
                           else
                               espera=0;
                           printf("%s",control[aux][contenido]);                //imprime de acuerdo a la posicion y de acuerdo al contendio de tal posicion
                           if(num[i]=='0')
                               ceros++;
                           else
                               ceros=0;
                      }
                      if(num[i]!=0)
                           ceros=0;
                      if(posicion<=3)
                           printf("%s",control[posicion][contenido]);           //si es valido que imprima los miles, millones, billones , etc
                      imprimio=0;
                }//fin del proceso
                printf("%s",control2[antes_punto]);
                printf("\n");
                imprimio=1;
                ceros=0;
            }
       }
       else
       {    puts(num);
            printf("Error escriba bien el numero\n");
       }
    k--;
    }while(k>0);//repite 20 veces el proceso
    for(i=0;i<n;i++)
         LiberarMem2d_char(control[i],10);
    LiberarMem2d_char(control2,10);
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
/*****************************ELIMINA ESPACIOS NO DESEADOS*/
void Limpia_Espacios(char *a,int max_espacios)                                  //Recibe como parametro un apuntador a cadena y elimina los espacio juntos que superen el mas_espacio. Los espacio del principio y fin de la cadena se eliminan siempre
{
     int i, letra=0, espacio=0, dim_arreglo=0, dim_arreglo2=0,indice=0;
     dim_arreglo=strlen(a)+1;
     char arreglo_nuevo[dim_arreglo];                                           //declaramos un arreglo de la misma dimension
     if(max_espacios>=0)
     {
     for(i=0;i<=dim_arreglo-1;i++)                                               //lo hacemos menos 1 veces porq no nos interesa el caracter nulo         
     {
          if(a[i] != ' ')                                                       //si el indice no es espacio, q lo copie
          {
               arreglo_nuevo[indice]=a[i];
               letra=1;
               espacio=0;                                                       //no hay espacioos juntos
               indice++;
          }
          else
          {
              espacio++;
              if(!letra)                                                        //si no ha escrito ninguna letra entoces son los primeros espacios, q los elimine
                 continue;
              else
              {
              if(espacio<=max_espacios)                                         //copia solo los espacios validos                                      //
                 {
                 arreglo_nuevo[indice]=a[i];
                 indice++;   
                 }
              }
          }
     }
     arreglo_nuevo[indice]='\0';                                                //pone el caracter nulo
     dim_arreglo2=strlen(arreglo_nuevo);
     if(espacio>0)                                                              //si hay espacios al FINAL q los borre
          arreglo_nuevo[(dim_arreglo2-espacio)]='\0';
     strcpy(a,arreglo_nuevo);                                                   //q copie la cadena
     }
}

int Numeros_Punto(int opcion, char *numero) //retorna el numero de digitos antes o despues del punto decimal , esto lo decide el parametro opcion , si es 1 (el numero de digitos antes del punto decimal) en otro caso sera despues. Nota debe ser un numero valido y almacenado en caradena de caracters correctamente
{
int digitos=strlen(numero);
int contador=0,existe=0,nume,punto=0,i=0;
             for(i=0; i<=digitos; i++)
             {
                          if(numero[i]=='.')
                               {
                                   existe=1;
                                   break;
                               }
             }
             if(opcion==1)
             {
                  if(existe)
                       return i;
                  else
                       return digitos;
             }
             else
             {
                   if(existe)
                       return digitos-i-1;
                   else
                       return 0;
             }
}
/*********************ELIMINA LOS CEROS NO SIGNIFICATIVOS**********************/
void Limpia_Ceros(char *numero)
{
     int max=strlen(numero),nume=0,j=0,borrar=0,ultimo=-1,i,punto=0;
     char nuevo[max+1];
     for(i=0;i<=max;i++)
     {
             if(numero[i] =='0' && !nume) //para los primeros ceros
             {
             }
             else if(numero[i]!='0' && numero[i]!='\0')      //un numero valido
             {
                  nume=1;
                  if(numero[i]=='.')
                       punto=1;
                  nuevo[j]=numero[i];
                  j++;
                  borrar=0;
             }
             else                         //para los ultimos ceros
             {
                 //nume=1;
                 nuevo[j]=numero[i];
                 j++;
                 if(borrar==0)
                      ultimo=j;           //guarda el ultimo indice valido
                 borrar++;
             }
     }
     if(borrar>0 && punto ==1)
         nuevo[ultimo-1]='\0';
      strcpy(numero,nuevo);     
}
/****************CREA MATRIZ DINAMICA 2 DIMENSIONES CHAR  *********************/
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
     p[f][cols]='\0';
     }
     *x=p;
}
/****************LIBERA LA MEMORIA DINAMICA 2 DIM DOUBLE **********************/
void LiberarMem2d_char(char **x, int filas)
{
     int f=0;
     for(f=0;f<filas;f++)
     {
         free(x[f]);
     }
     free(x);
}
/*****************VISUALIZA EL CONTENIDO DE LA MATRIZ char de 2 DIMES char*****/
void Visualizar_char(char **x, int filas)
{
     int f;
     for(f=0;f<filas;f++)
         puts(x[f]);
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
