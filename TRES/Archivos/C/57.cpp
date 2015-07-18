#include<stdio.h>
#include<stdlib.h>
typedef struct STACKNODE{
       int data;
       struct STACKNODE *nextptr;
       }STACKNODEPTR;

void push(STACKNODEPTR **,int);                                                 //al anadir el puntero se debe pasar por referencia (se anade al principio), por eso aumenta un nivel de indireccion
int vacia(STACKNODEPTR **);                                                      
void imprime(STACKNODEPTR *);                                                   //no modifica el puntero solo lo imprime
void menu();

main()
{
      STACKNODEPTR *stackptr=NULL;
      int opcion, valor;
      menu();
      printf("Teclea una opcion del menu\n");
      scanf("%d", &opcion);
      while(opcion != 3)
      {
           switch(opcion)
           {
                case 1:
                     {
                         printf("Introdusca un entero ");
                         scanf("%d", &valor);
                         push(&stackptr,valor);
                         imprime(stackptr);
                         break;
                     }
                case 2:
                     {
                         printf("Se elimina el primer elemento por ser una pila\n");
                         vacia(&stackptr);
                         imprime(stackptr);
                         break;
                     }
                default:
                     {
                         printf("Opcion incorrecta\n");
                         break;
                     }
                     
                printf("Fin del programa");
                system("PAUSE");
           }
           fflush(stdin);
           menu();
           printf("Teclea una opcion del menu\n");
           scanf("%d", &opcion);
      }
}

void menu()
{
     printf("1.insertar elemento\n2.eliminar elemento\n3.Salir");
}
void push(STACKNODEPTR **topptr, int info)
{
     STACKNODEPTR *copia=*topptr;
     STACKNODEPTR *newptr=NULL;   
     newptr= new STACKNODEPTR;
     newptr =(STACKNODEPTR *)malloc(sizeof(STACKNODEPTR));
     if(newptr != NULL)
     {
          newptr->data=info;
          if(*topptr==NULL)
              newptr->nextptr=NULL;
          else
              newptr->nextptr= copia;
          copia=newptr;
          *topptr=copia;
     }
     else
          printf("No hay memoria disponible\n");
}

void imprime(STACKNODEPTR *currentptr)
{
     if(currentptr == NULL)
          printf("La pila esta vacia\n");
     else
     {
     while(currentptr != NULL)
     {
          printf("%d-->",currentptr->data);
          currentptr=currentptr->nextptr;
     }
     }
     printf("\n");
}

int vacia(STACKNODEPTR **tope)
{
    if(tope != NULL)
       {
            STACKNODEPTR *doble=*tope;
            doble=doble->nextptr;
            free(*tope);
            *tope=doble;
       }
}
