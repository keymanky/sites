/*******************MI PRIMER PROGRAMA CON FUNCIONES***************************/
#include <stdlib.h>
#include <stdio.h>

void par_impar (int);                                                               //^^^^^DESDE ACA SE DECLARAN EN FUNCIONES, notese que lleva punto y coma
void positivo_negativo (int);                                                       //el void indica que no retorna nada
int cuadrado (int);
int cubo (int);                                                                     // el () indica que no se pasa ningun argumento
int contar ();                                                                      //^^^^^^ACA FINALIZA DECLARACION DE 5 FUNCIONES QUE SU CUERPO ESTARA DESPUES DE LA MAIN

int main()                                                                          //FUNCION PRINCIPAL MAIN
{
    int n;
    printf("\n DAME UN NUMERO ENTERO\n ");
    scanf("%d", &n);
    par_impar (n);
    positivo_negativo (n);
    printf("\n El cuadrado del numero es %d",cuadrado (n));                         //observe que la funcion se anida en el printf, es decir imprime lo que retorne dicha funcion con el argumento pasado n
    printf("\n El cuadrado del numero es %d",cubo (n));
    printf("\n%d",contar());
    printf("\n%d", contar());
    printf("\n%d\n",contar());
    system ("PAUSE");
    return 0;
}

/*********************************FUNCION 1 ***************************************/
void par_impar (int z)                                                              //notese que n de la main esta funcion lo cacha y realiza una copia a la entera z
{                                                                                   //notese que no lleva punto y coma ya que es un bloque como la main
     printf("\nEl numero es %s", (z%2==0)?"par":"impar");                           //ingeniosa idea usando impresion de una cadena con operador ternario
}
/*********************************FUNCION 2 **************************************/
void positivo_negativo (int a)                                                      //ahora n los copia en a y en base a A trabaja con el
{
     printf("\nEl numero es %s", (a>=0)? "positivo":"negativo");                    //se pregunta si a es positivo, si es 1 entonces realiza la primer accion, si no la segunda que en este caso es imprime 'negativo'
}
/********************************FUNCION   3 *************************************/
int cuadrado(int a)
{
    return a*a;
}
/********************************FUNCION  4 *************************************/
int cubo (int jeje)
{
    return jeje*jeje*jeje;
}
/******************************FUNCION    5 ************************************/
int contar ()                                                                     //funcion que no retorna contador
{
    static int contador=1;                                                        //se declara estatic para que despues de finalizar la llamada de la funcion el contador no se destruya y conserve el ultimo valor
    return contador++;
}

