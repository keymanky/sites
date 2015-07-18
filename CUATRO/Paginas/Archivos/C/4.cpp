/*FORMATO DE IMPRESION O STDOUT*/
#include<stdio.h>
#include<stdlib.h> 
int main ()
{

    printf("\nENCABEZADO DE LA LISTA\n");
    int a=1,b=7, c=9,   d=20;   //el exceso de espacioS en blanco no importa
    printf("VALOR DE A=1\nen decimal %d\nen octal %o\nen hexadecimal %x\nen exponencial %e\n %cen caracter ",a,a,a,a,a); //ver expecificadores de formato en pagina 96
    
    printf("\n");
    
    printf("\nVALOR DE B=7\nen decimal %#d\nen octal %#o\nen hexadecimal %#x\nen exponencial %#e\nen caracter%#c ",b,b,b,b,b);//notese #
    
    printf("\n");
    
    printf("\nVALOR DE C=9\nen decimal %#d\nen octal %#o\nen hexadecimal %#x\nen exponencial %#e\nen caracter%#c ",c,c,c,c,c);//notese #
    
    printf("\n");
    
    printf("\nVALOR DE d=20\nen decimal %10d\nen octal %10o\nen hexadecimal %10x\nen exponencial %10e\nen caracter\t%c ",d,d,d,d,d);//notese %10 y \t
    system("PAUSE");
    return 0;
}
