/**********PROGRAMA CONVIERTE CADENA DE MINUSCULAS A MAYUSCULAS****/
#include <stdio.h>
#include <stdlib.h>
#define  LONG_MAX 81                                                            //Longitud maxima de la cadena
void MinusculasMayusculas(char []);

main()
{
      char cadena[LONG_MAX];      
      printf("Introducir una cadena:");
      gets (cadena);
      MinusculasMayusculas(cadena);
      puts(cadena);
      system("PAUSE");
}
/************CONVIERTE DE MINUSCULAS A MAYUSCULAS SIN HACER USO DE FUNCIONES DE C*/
void MinusculasMayusculas(char str[])
{
     int i, desp= 'a' - 'A';                                                    //El juego de caracteres ASCII, hay una diferencia contante entre la a "minuscular"  y la "mayuscula" de igual forma esta diferencia es constante entre todas las letras menos las especiales como las acentuadas o la ñ
     for (i=0; str[i] != '\0'; i++)                                             //El final de toda cadena es el caracter nulo que es \n
         if(str[i] >= 'a' && str[i] <= 'z')                                     //Si las letras de la cadena estan entre la a y la z, las convierte
                   str[i]=str[i]-desp;                                          //Las minusculas tiene un rango mas alto en valor decimal qu las mayusculas cuando se escribe 'a' se hacer referencia al valor entero de la letra
}
