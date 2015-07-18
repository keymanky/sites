/****************VARIABLES TIPO CHAR  *****************************/
#include<stdio.h>
#include<stdlib.h>

main()            //cuando se pone char x='int y' se guarda en la tabla de ancii su valor caracter o su valor entero como lo imprimamos, pero el char siempre sera caracter aunque lo podamos imprimir como entero
{
      char car1= 'A', car2=65, car3=0;
      car3=car1+'a' - 'A';//es a porque se suma y resta'A'
      printf("%d %c\n", car3, car3);                                //iguales
      car3=car2+32;//es igual a 97 que es la lecha minuscula a
      printf("%d %c \n", car3,car3);                                //iguales
      system("PAUSE");
}
