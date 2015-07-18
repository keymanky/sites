#include<stdio.h>
#include<stdlib.h>     
#include<string.h>                                
typedef struct l
{
        char  nombre[50];
        struct l *sig_nombre;
}Alumno;
typedef struct n
{
        int grupo;
        struct n *sig_grupo;
        Alumno *nombre;
}Grupo;
//Funciones generales
int menu();
void error();
int Lee(char *cadena);
//Funciones para grupo (lista con info un entero y una lista)
void Anadir_Grupo(int, Grupo **);
Grupo * Nuevo_Grupo();
void Imprime_Grupos(Grupo *);
int Borra_Grupo(int, Grupo **);
int Busca_Grupo(int, Grupo *);
Grupo *Este(int, Grupo *);
//Funciones para alumno (lista con info una cadena)
Alumno *Nuevo_Alumno();
void Anadir_Alumno(char *,Alumno **);
void Imprime_Alumno(Alumno *);
int Borra_Alumno(char *,Alumno **);
int Busca_Alumno(char *,Alumno *);

main()
{
int grupo_nuevo=0;
char cadena[50];
Grupo *control= NULL;
//Alumno *control2=NULL; 
Grupo *aca=NULL;
   do{
      switch (menu()) 
      {
         case 1:
         {
            printf("Dame el grupo:    ");
            gets(cadena);
            if(Lee(cadena)==0)                                                  //valida q es un entero
            {
               grupo_nuevo=atoi(cadena);                                        //transforma
               if(grupo_nuevo>0)                                                //no hace nada si el grupo es negativo
                  {
                  if((Busca_Grupo(grupo_nuevo,control)) == -1)
                      {
                      Anadir_Grupo(grupo_nuevo, &control); 
                      printf("Se anadio correctamente\n");
                      }
                  else
                      printf("Error ya existe el grupo\n");
                  }
               else
                  printf("Fijarse que el grupo debe ser positivo\n");
            }
            else
            {
                printf("Introdusca un entero\n");
            }        
            break;
         }
         case 2:
         {
            if(control == NULL)
                 printf("No hay grupos\n");
            else{
            printf("Dame el grupo:    ");
            gets(cadena);
            if(Lee(cadena)==0)                                                  //valida q es un entero
            {
               grupo_nuevo=atoi(cadena);                                        //transforma
               if(grupo_nuevo>0)                                                //no hace nada si el grupo es negativo
                  {
                  if(Borra_Grupo(grupo_nuevo, &control)) 
                      printf("Se borro correctamente\n");
                  else
                      printf("No se pudo borrar, No existe\n");
                  }
               else
                  printf("Fijarse que el grupo debe ser positivo\n");
            }
            else
            {
                printf("Introdusca un entero\n");
            }    
            }    
            break;
         }
         case 3:
         {
              if(control==NULL)
                   printf("Debe crear un grupo antes\n");
              else
              {
              printf("Introduce Grupo:       ");
              gets(cadena);
              grupo_nuevo=atoi(cadena);
              if(Busca_Grupo(grupo_nuevo,control)>=0)                           //si existe el grupo
              {  
                                                                                
                   printf("Introduce un Nombre:   ");
                   gets(cadena);
                   strcpy(cadena,strupr(cadena));                               //convierte a mayusculas
                   fflush(stdin);
                   aca=Este(Busca_Grupo(grupo_nuevo,control),control);          //aca es de tipo Grupo q apunta al especificado !!!!!IMPORTANTEE
                   if(Lee(cadena) == 2 && Busca_Alumno(cadena,aca->nombre) ==-1)//si el nombre es valido y no existe
                   {            
                   Anadir_Alumno(cadena,&aca->nombre);                          //se anade en el grupo CORRESPONDIENTE!!!!!!!!!!!!!!!!!!! IMPORTANTE
                   printf("Se ha anadido\n");
                   }
                   else                                                         //si el nombre no es valido
                       printf("Nombre no valido o duplicado\n");
              }
              else                                                              //si no existe el grupo
                 printf("Error , Verifique el grupo\n");
              }
              break;
         }
         case 4:
         {
            
            if(control == NULL)
                 printf("No hay grupos\n");
            else
            {
                 printf("Introduce Grupo:       ");
                 gets(cadena);
                 grupo_nuevo=atoi(cadena);
                 if(Busca_Grupo(grupo_nuevo,control)>=0)                        //si existe el grupo
                 {
                      aca=Este(Busca_Grupo(grupo_nuevo,control),control);       //aca es de tipo Grupo q apunta al especificado GRUPO!!!!!IMPORTANTEE
                      printf("Dame el alumno:    ");
                      gets(cadena);
                      strcpy(cadena,strupr(cadena));                            //convierte a mayusculas
                      fflush(stdin);
                      if(Lee(cadena)==2)                                        //verifica si la cadena es correcta
                      {
                           if(Borra_Alumno(cadena, &aca->nombre)) 
                                printf("Se borro correctamente\n");
                           else                                                 
                               printf("No se pudo borrar, No existe\n");
                      }  
                      else                                                      //cadena no correcta
                          printf("Introdusca nombre valido\n");
                 }
                 else
                     printf("Verifique el grupo\n");                            //grupo no correcto
            }
            break;
         }
         case 5:
         {
              Imprime_Grupos(control);
              break;
         }
         case 6:
         {
            free(control);
            exit(1);
         }
         default:
         {
            printf("En construccion \n");
         }
                   
      }   
      system("PAUSE");
   }while(1);    
}

/*************************FUNCION MENU*****************************************/
int menu()
{
    char m[20];
    int x;
    do
    {
          system("cls");                                                        //da el efecto de borrar solo que lo no esta en las opciones
          printf("\n LEE EL MENU\n 1.-NUEVO GRUPO\n 2.-BORRA GRUPO\n 3.-NUEVO ALUMNO\n 4.-BORRA ALUMNO\n 5.-IMPRIME\n 6.-EXIT\n");
          gets (m);                                                             //gets lee los del teclado hasta una marca de EOF y lo guarda como cadena de caracters en alrreglo m
          x=atoi(m);                                                            //a x se le asigna el valor numerico de la cadena en int                                                   
    }
    while (x<=0 || x>6);
    return x;
}
/************************FUNCION ERROR*****************************************/
void error()
{
     printf("Insuficiente memoria\n");
     exit(1);         //aborta el programa
}
/**********************CREA EL ESPACIO PARA NUEVO ELEMENTO*********************/
Grupo * Nuevo_Grupo()
{
      Grupo *nuevo =(Grupo *)malloc(sizeof(Grupo));
      if(!nuevo)   //si apunta a null
         error();
      return nuevo;
}
/******************ANADIR UN ELEMENTO ORDEN ***********************************/
void Anadir_Grupo(int e, Grupo **x)
{    
   int insertado=0;
   Grupo *p= *x;                                                                //Se crean apuntadores p(se va a ir moviendo), aux2(apunta al inicio de la lista , es copia de x), aux(apunta al anterior de p), q(tiene los q se va anadir).......Se crea un aux2 ya q si dejamos a x, entonces puede ocurrir cosas inesperadas
   Grupo *aux=NULL, *aux2=*x;
   Grupo *q=Nuevo_Grupo();                                                      //Nuevo aputador q
   q->grupo=e;                                                                  //se anaden el dato
   q->nombre=NULL;
/*CASO DE SEA EL UNICO NODO*/
    if(p==NULL)
    {  
      q->sig_grupo=NULL;                                                        //todo lo demas debe apuntar a NUll
      *x=q;   
   }
   
   else
   {
      int principio=1;
/*CICLO Q COMPARA EL CONTENDIDO PARA ORDENARLO E INSERTARLO ADECUADAMENTE*/
      while(p!=NULL)
      {
         if(e>= p->grupo && principio)                                          //Se anade al principio de la lista si el nuevo dato es mas grande
             {
                q->sig_grupo=p;
                p=q;
                *x=p;                                                           //Modifica a lo q apunta x, es el apuntador pasado por referencia
                insertado=1;                                                    
                break;
             }
         else                                                                   //No se anadio al prncipio, por lo q haremos uso del apuntador aux
             {
                if(e>=p->grupo)
                {
                     q->sig_grupo=p;
                     aux->sig_grupo=q;
                     *x=aux2;                                                   //Se modifica el contenido de x, para q siempre apunte al principio de la lista
                     insertado=1;
                     break;
                }
             }
         aux=p;
         p=p->sig_grupo;
         principio=0;
      }
      if(!insertado)                                                            //Si no se a insertado , signfica q el el menor , Insertar al final de la lista
      {
         aux->sig_grupo=q;                                                      //sabemos q aux apunta a uno antes q p, y p ya apunta a NULL o final de la lista
         q->sig_grupo=NULL;    
      }
   }
}
/**************************BUSCA LA INFO DE UNA LISTA**************************/
int Busca_Grupo(int x, Grupo * recorre)
{
    Grupo *lista = recorre;
    int pos=0;                                                                  //Retorna la posicion q se encuentra en la lista, empieza en cero
    while(lista != NULL)
    {
       if(lista->grupo == x)
          return pos;
       pos++;   
       lista=lista->sig_grupo;
    }
    return -1;                                                                  //Retorna -1 si no se encontro
}
/*******************IMPRIME GRUPOS*********************************************/
void Imprime_Grupos(Grupo *j) //entra como una compia a j
{
     int imprimio=0;
     Alumno *k=NULL;
     while(j != NULL)         //mientra j no apunte a null
     {
        printf("El grupo es : %d\n",j->grupo);
        k=j->nombre;
        while(k != NULL)
        {
             printf("\t\tEl alumno %s esta inscrito en este grupo\n",k->nombre);
             k=k->sig_nombre;
        } 
        j=j->sig_grupo;       //j apunta al siguiente nodo
        imprimio=1;
     }
     if(!imprimio)
        printf("No hay grupos Favor de anadir uno ...\n");
}
/*******************BORRA EL GRUPO ESPECIFICADO********************************/
int Borra_Grupo(int x, Grupo ** puntero)
{
    Grupo *q= *puntero;
    Grupo *aux= NULL;
    Grupo *aux2= *puntero;
    int primero=1,ultimo=0;
    while(q != NULL)
    {
          Alumno *n=q->nombre;                                                        //apunta a la lista de alumnos del grupo
          Alumno *aux5=NULL;
          if(x==q->grupo && primero)                                            //elimina el primer grupo
          {
             while(n !=NULL)
             {
               aux5=n;                                                           //aux apunta al anterior
               n=n->sig_nombre;
               free(aux5);   
             }
             aux=*puntero;
             *puntero =aux->sig_grupo;
             free(aux);
             return 1;
          }
          else if(x==q->grupo && !primero)
          {
             while(n !=NULL)
             {
               aux5=n;                                                           //aux apunta al anterior
               n=n->sig_nombre;
               free(aux5);   
             }
              aux->sig_grupo=q->sig_grupo;
              free(q);
              *puntero =aux2;
              return 1;
          }
          aux=q;
          q=q->sig_grupo;
          primero=0;
    }
    return 0;
}
/**************ASIGNA UN ESPACIO DE MEMORIA PARA LISTA CON CADENA DE INFO******/
Alumno *Nuevo_Alumno()
{
      Alumno *nuevo =(Alumno *)malloc(sizeof(Alumno));
      if(!nuevo)   //si apunta a null
         error();
      return nuevo;
}
/**************INSERTA UN NODO CON INFO CADENA ORDENADAMENTE*******************/
void Anadir_Alumno(char *c,Alumno **x)
{
     Alumno *p=*x;
     Alumno *q=Nuevo_Alumno();
     Alumno *aux2=*x,*aux=NULL;
     int principio=1,insertado=0;
     strcpy(q->nombre,c);
     if(p == NULL)
     {
          q->sig_nombre=NULL;
          *x=q;
     } 
     else
     {
          while(p!=NULL)
          {
               if(strcmp(p->nombre,c) > 0 && principio)
               {
                    q->sig_nombre=p;
                    p=q;
                    *x=p;
                    insertado=1;
                    break;
               }
               else
               {
                    if(strcmp(p->nombre,c) >0)
                    {
                    q->sig_nombre=p;
                    aux->sig_nombre=q;
                    insertado=1;
                    *x=aux2;
                    break;
                    }
               }
               aux=p;
               p=p->sig_nombre;
               principio=0;
          }
          if(!insertado)
          {
               q->sig_nombre=NULL;
               aux->sig_nombre=q;
               *x=aux2;
          }
     }    
}
/**********************IMPRIME LA LISTA DE CADENAS*****************************/
void Imprime_Alumno(Alumno *j)
{
     int imprimio=0;
     while(j != NULL)         //mientra j no apunte a null
     {
        printf("El Alumno es : %s\n",j->nombre);
        j=j->sig_nombre;       //j apunta al siguiente nodo
        imprimio=1;
     }
     if(!imprimio)
        printf("No hay Alumnos Favor de anadir uno ...\n");
}
/************************BORRA EL ELEMENTO ESPECIFICADO************************/
int Borra_Alumno(char *a,Alumno **puntero)
{
    Alumno *q= *puntero;
    Alumno *aux= NULL;
    Alumno *aux2= *puntero;
    int primero=1,ultimo=0;
    while(q != NULL)
    {
          if((strcmp(q->nombre,a)==0) && primero)
          {
             aux=*puntero;
             *puntero =aux->sig_nombre;
             free(aux);
             return 1;
          }
          else if((strcmp(q->nombre,a)==0) && !primero)
          {
              aux->sig_nombre=q->sig_nombre;
              free(q);
              *puntero =aux2;
              return 1;
          }
          aux=q;
          q=q->sig_nombre;
          primero=0;
    }
    return 0;
}
/************BUSCA UN NOMBRE EN LA LISTA***************************************/
int Busca_Alumno(char *a,Alumno *recorre)
{
    Alumno *lista = recorre;
    int pos=0;                                                                  //Retorna la posicion q se encuentra en la lista, empieza en cero
    while(lista != NULL)
    {
       if(strcmp(lista->nombre,a) == 0)
          return pos;
       pos++;   
       lista=lista->sig_nombre;
    }
    return -1;      
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
/*************************RETORNA EL PUNTERO Q APUNTA AL GRUPO ESPECIFICO******/
Grupo * Este(int m, Grupo *full)                                                //recibe un apuntador q apunta al principio de la lista de grupos
{                                                                               //retorna el apuntador al grupo especifico
      Grupo *nuevo= full;
      int i;
      for(i=0;i<m;i++)
      {
           nuevo=nuevo->sig_grupo;
      }      
      return nuevo;
}
