/*TAMANO DE BYTES DE LOS TIPOS DE DATOS PRIMITIVOS*/
#include<stdio.h>
#include<stdlib.h> 
int main ()
{
    char d;
    printf("Tamano de char es: %d bytes\n", sizeof(d));//sizeof devuelte el tamano en bytes del argumento NOTA :recordar que el tamano de bytes es entero por eso %d
    short e;
    printf("Tamano de short es: %d bytes\n", sizeof(e));
    int a;
    printf("Tamano de int es: %d bytes \n", sizeof(a));
    float b;
    printf("Tamano de float es: %d bytes\n", sizeof(b));
    long f;
    printf("Tamano de long es: %d bytes\n", sizeof(f));
    double c;
    printf("Tamano de double es: %d bytes\n", sizeof(c));
    long unsigned g;
    printf("Tamano de long unsigned es: %d bytes\n", sizeof(g));

    system("PAUSE");
    return 0;
}
