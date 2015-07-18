#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int menu();
int Lee(char *);
main()
{
      int n=0,i=0;
      char cadena[5];
      printf("Dame el tamano de las pilas:  ");
      scanf("%d",&n);
      int pilas[n], num=0;    
      int p1=-1;                                                                //apunta(indice) al tope de la pila 1, como no se ha insetado nada, este apunta a fuera de los limites
      int p2=2*n;                                                               //de igual forma. 
      int imprimio1=0,imprimio2=0;
      do{
      switch (menu())
      {
             case 1:
                  {
                      if(p1+1<p2)                                               //se pregunta si esta disponible el siguiente espacio
                         {
                               printf("Dame el elemento:  ");
                               scanf("%d", &num);
                               p1++;                                            //apunta al ultimo elemento anadido (todo es en indices)
                               pilas[p1]=num;
                               printf("Se anadio\n");
                         }
                      else
                         printf("Pila llena\n");
                      break;
                  }
             case 2:
                  {
                      if(p2-1>p1)                                               //se pregunta si el espacio anterior esta disponible
                         {
                               printf("Dame el elemento:  ");
                               scanf("%d", &num);                                 
                               p2--;                                             //apunta al elemento tope
                               pilas[p2]=num;
                               printf("Se anadio\n");
                         }
                      else
                         printf("Pila llena\n");
                      break;
                  }
             case 3:
                  {
                      if(p1>=0)                                                 //Borra el elemento apuntado por tope de la pila 1, 
                      {
                           pilas[p1]=0;
                           p1--;
                           printf("Correcta eliminacion\n");
                      }
                      else
                           printf("Pila vacia\n");
                      break;
                  }
             case 4:
                  {
                      if(p2<=(2*n)-1)                                           //Borra el elemento tope de la pila 2, este no puede ser de 2*n por definicion de los arreglos
                      {
                           pilas[p2]=0;
                           p2++;
                           printf("Correcta eliminacion\n");
                      }
                      else
                           printf("Pila vacia\n");
                      break;
                  }
             case 5:
                  {
                      printf("El maximo numero de elementos es %d\n",2*n);
                      printf("El contenido de las pilas es\n\n\n");
                      printf("Pila 1\t\t\tPila 2\n-----\t\t\t-----\n");
                      int cp1=p1;                                               //se copian los indices topes de las pilas 
                      int cp2=p2;
                      for(i=0;i<2*n;i++)                                        //repite, como maximo 2*n q es el #maximo q puede haber en una pila  
                      {
                           if(cp1>=0)                                           //Si hay elemento en pila 1 de acuerdo con i
                           {
                              printf("%d",pilas[cp1]);
                              cp1--;                                            //se recorre .Tiende a cero
                              imprimio1=1;
                           }  
                           if(!imprimio1)                                       //Dar formato, si no imprimio de la pila 1
                                printf("-");
                           if(cp2<=(2*n)-1)                                     //Si hay elemento en pila 2 de acuerdo con i
                           {
                              printf("\t\t\t%d\n",pilas[cp2]);
                              cp2++;                                            //Tiende a n
                              imprimio2=1;
                           }
                           if(!imprimio2)                                       //Si no se imprimio del lado de la pila 2
                           {
                              printf("\t\t\t-");
                              printf("\n");
                           }
                           imprimio1=0;
                           imprimio2=0;
                      }
                      break;
                  }
             case 6:
                  {
                      exit(1);
                  }
      }
      system("PAUSE");
      system("cls");
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
          printf("\n LEE EL MENU\n 1.-INSERTAR EN PILA 1\n 2.-INSERTAR EN PILA 2\n 3.-ELIMINAR ELEMENTO PILA 1\n 4.-ELIMINAR ELEMENTO PILA 2\n 5.-IMPRIME\n 6.-EXIT\n");
          gets (m);                                                             //gets lee los del teclado hasta una marca de EOF y lo guarda como cadena de caracters en alrreglo m
          x=atoi(m);                                                            //a x se le asigna el valor numerico de la cadena en int                                                   
    }
    while (x<=0 || x>6);
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
