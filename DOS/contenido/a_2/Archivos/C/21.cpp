/*********************PROGRAMA QUe USA EL SWITCH*******************************/
#include <stdio.h>
#include <stdlib.h>
int menu();

main()
{
      int op,fijo=100,km,tone;
      op=menu();
      switch (op)
      {
             case 1:
                  {
                               printf("Importe a pagar $%d",fijo);
                               break;                                           //necesario poner porque sino se sigue con 2 o 3 aunque no se verdadero el caso
                  }
             case 2: case 3:                                                    //2 casos juntos
                  {
                               printf("KM");
                               scanf("%d",&km);
                               printf("Importe a pagar $%d",km*30);
                               break;
                  }
             case 4:
                  {
                               printf("Damme kilometros y toneladas");
                               scanf("%d %d",km,tone);
                               printf("Importe a pagar %d",(km*30)+25);
                               break;
                  }
             default  :                                                          //si no se cumple ningun caso entonces se cumple esta
                  {
                               exit(0);
                  }
      
      }
      system("PAUSE");
}

/*************************FUNCION MENU*****************************************///FUNCION A DESARROLLAR CON ARGUMENTOS VARIABLES
int menu ()
{
    char m[20];
    int x;
    do
    {
          system("cls");                                                        //da el efecto de borrar solo que lo no esta en las opciones
          printf("\n LEE EL MENU\n 1.-BICICLETA\n 2.-MOTO\n 3.-COCHES\n 4.-CAMION\n 5.-Salir\n");
          gets (m);                                                             //gets lee los del teclado hasta una marca de EOF y lo guarda como cadena de caracters en alrreglo m
          x=atoi(m);                                                            //a x se le asigna el valor numerico de la cadena en int                                                   
    }
    while (x<=0 || x>5);
    return x;
}
