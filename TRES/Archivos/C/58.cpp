#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
/****************************DEFINICION DE LA PILA*/
typedef struct P
{
     char cadena[100];                                                          //SI se pone char *cadena, hay problemas con el compilador
     int parentesis;
     int corchetes;
     int llaves;
     struct P *sig;
}PILA;
/***************************INTERFAZ DE LA PILA*/
void error()
{
     printf("Insuficiente Memoria\n");
     system("PAUSE");
     exit(1);
}
PILA* NuevoElemento()                                                           //Retorna puntero al nuevo espacio en memoria
{
      PILA *nuevo=(PILA *)malloc(sizeof(PILA));
      if(!nuevo)
         error();
      nuevo->parentesis=0;
      nuevo->corchetes=0;
      nuevo->llaves=0;
      nuevo->sig=NULL;
      return nuevo;
}
void Push(PILA **tope, char *info)                                              //Recibe por referencia el apuntador de la pila
{
     PILA *clon= *tope;                                                                  //creamos un clon del apuntador por referencia
     PILA *nuevo=NuevoElemento();
     strcpy(nuevo->cadena,info);
     if(clon == NULL)
          nuevo->sig=NULL;
     else
          nuevo->sig=clon;
     
     clon=nuevo;
     *tope=clon;                                                                         //hasta el ultimo modificamos el apuntador por referencia
}
void Pop(PILA **tope)                                                           //Recibe por referencia el apuntador de la pila
{
     PILA *clon= *tope;                                                                  //creamos un clon para evitar problemas
     if(clon != NULL)
     {
     PILA *aux=clon;
     clon=clon->sig;
     free(aux);
     *tope=clon;
     }
}
void Elimina(PILA **tope)
{
     PILA *clon= *tope;                                                         //creamos un clon para evitar problemas . trabajaremso con el clon
     while(clon != NULL)
     {
          Pop(&clon);
     }
     *tope=clon;                                                                //modificamos el apuntador original pasado por referencia
}
void Imprime(PILA *tope)                                                        //El apuntador de la pila no es pasado por referencia porq no se modifica
{
     if(tope != NULL)
     while(tope != NULL)
     {
          printf("%s--->",tope->cadena);
          tope=tope->sig;
     }
     else
          printf("Pila vacia\n");
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
/***********************CONVIERTE POSICION POSFIJA A INFIJA SI PRODECE*/
int Pos_Inf(char *pos)    //transforma el contenido de la cadena a posicion infija, y devuelve 1; si no es valida la poscicion posfija entonces no hace nada y retorna 0
{
    Limpia_Espacios(pos,1);                                                     //elimina espacio no deseados, maximo 1 espacio intermedio para separar variables
    int i=0, espacio =0, caracter=0, operandos=0, indice=0;
    PILA *tope=NULL;
    char caden[strlen(pos)+1], temporal[2]={'!', '\0'};                         //en caden almacenara las variables
    char caden3[2]={'!','\0'};                                                  //caden2 es de [100] porq se va concatenar y debe tener el espacio sufiente para soportar una expresion grande, la caden3 se concatena despues
    char caden2[100];        
    while(pos[i] != '\0')                                                       //Recorre la cadena pos caracter por caracter hasta el nulo
    {
         if(pos[i]==' ')                                                        //si es un espacio.El espacio tiene como funcion separara variables, si hay variable sin meter en pila, entonces q la meta ya
         {
              if(caracter>0)
              {
                   caden[indice]='\0';                                               //agrega el caracter nulo a la cadena para despues meterla en la pila
                   Push(&tope,caden);   
                   operandos++;                                                 //lleva el conteo de los elementos en la pila
                   caracter=0;                                                  //lleva el conteo de la longitud de las variables en espera
                   indice=0;                                                    //lleva el conteo del indice valido para caden
              }
         }
         else if(pos[i] == '^'|| pos[i] == '*'|| pos[i] == '/'|| pos[i] == '+'|| pos[i] == '-')     //si es un operador,Tiene como funcion 2 cosas, si hay variables pendientes de meter en pila q las meta y sino y/o despues efectue la operacion
         {
              if(caracter>0)                                                    //actue como un espacio, es decir q lo meta en pila
              {
                   caden[indice]='\0';
                   Push(&tope,caden);
                   operandos++;
                   caracter=0;
                   indice=0;
              }
              if(operandos>1)                                                   //si hay almenos 2 varibles o expresiones en la pila q efectue el algoritmo
              {
                   caden2[1]='\0';
                   if((tope->parentesis==0 && tope->sig->parentesis==0) ||(tope->llaves>1 || tope->sig->llaves>1)) //si no hay parentesis en ningun operado, o almenos un operando ya tiene llaves; significa que cierre la expresion con parentesis, e indique en el operando q va quedar en la pila q contiene parentesis
                   {
                        caden2[0]='(';
                        caden3[0]=')';
                        tope->sig->parentesis=1;                                //este va a quedar en la pila. El apuntado por tope se va a fusionar con este.
                   }
                   else if((tope->parentesis==1 || tope->sig->parentesis==1) && (tope->corchetes==0 && tope->sig->corchetes==0))//si ya existe un parentesis en almenos 1 de los operandos , y,ninguno tiene corchetes ; entonces procede a poner corchetes
                   {
                        caden2[0]='[';
                        caden3[0]=']';
                        tope->sig->corchetes=1;                                 //este va a quedar en la pila.El tope se concatenara con este
                   }
                   else                                                         //Significa q van las llaves
                   {
                       caden2[0]='{';
                       caden3[0]='}';
                       tope->sig->llaves++;                                     //indiq q hay llaves
                       tope->sig->parentesis=0;                                 //resetea de todo nuevamente
                       tope->sig->llaves=0;
                   }
                   
                   temporal[0]=pos[i];                                          //el arreglo temporal contiene el operador, NOTA el temporal[1]='\0' siempre            
                   strcat(tope->sig->cadena,temporal);                          //concatena cadena q esta en la pila(una antes del tope) con el operador
                   strcat(tope->sig->cadena,tope->cadena);                      //vuelve a contatenar ahora con la cadena que esta en el tope
                   Pop(&tope);                                                  //saque el ultimo y por ende resta uno al contador de la pila         
                   operandos--; 
                   //esto q sigue anade los parentesis llaves o corchetes
                   strcat(caden2,tope->cadena);
                   strcat(caden2,caden3);
                   strcpy(tope->cadena,caden2);       
              }
              else                                                              //si solo hay 1 operador o menos entonces error ya que no tiene con q operandos efectuar la operacion
                   return 0;
         }
         else
         {
              caden[indice]=pos[i];                                             //En otro caso es una letra y que la meta en caden
              indice++;                                                         //El indice cambia
              caracter++;                                                       //Hay una variables de por lo menos 1 caracter en espera
         }
         i++;                                                                   //Cambia i y continua con el siglo
    }//fin del while
    if(operandos>1 || tope==NULL)                                               //Ya fuera del ciclo pregunta, si hay mas de 1 operando o expresion, si la hay significa que faltaron operadores y no es valido eso, o, pregunta si la pila esta vacia; este caso significa que nunca inserto nada
         return 0;
         
    else                                                                        //si entra aca es porq todo va bien solo falta eliminar los caracteres separadores<<< ( [ { >>>del principio y del final y listo
         {
         caden3[0]='(';                                                         //reutilizamos caden3 y le ponemos ( porq hay conflicto en el if con el parentesis
         if(tope->cadena[0]== caden3[0] || tope->cadena[0]=='[' || tope->cadena[0]== '{') //evalua si el primer caracter es un separador y si lo es debemos eliminarlo
         {
              tope->cadena[0]=' ';                                              //lo sobreescribe con espacio
              for(i=0;tope->cadena[i]!='\0';i++);                               //lleva hasta el ultimo (tambien hay q eliminarlo)
              tope->cadena[i-1]=' ';
              Limpia_Espacios(tope->cadena,0);                                  //limpia los espacio primero y ultimo.
         }
         
         strcpy(pos,tope->cadena);                                              //la cadena esta lista, es la apuntada por tope; la copie en la cadena pasada por referencia                         
         Elimina(&tope);                                                        //liberamos el contenido de la pila                                         
         return 1;                                                              
         }
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

main()
{
      Imprime_Encabezado("PROYECTO POSFIJA INFIJA");
      printf("Siga las instrucciones\nCaracteres Soportados\n\t^\n\t*\t/\n\t+\t-\nPara separar variables use por lo menos un espacio y/o un operador\nEjemplo... Entrada->ab c+ ... Salida->ab+c\n\n\n");
      
      char pos[100], respuesta[10], r[2]={'n','\0'};
      do{
      printf("Introduce la notacion Posfija:      ");
      gets(pos);
      if(Pos_Inf(pos))     //si la conversion fue exitosa
            puts(pos);
      else
            printf("Introdusca una notacion postfija valida\n");
      printf("Desea continuar <s/n>.......");
      gets(respuesta);
      printf("\n");
      strcpy(respuesta,strlwr(respuesta));
      }while(strcmp(respuesta,r));
}
