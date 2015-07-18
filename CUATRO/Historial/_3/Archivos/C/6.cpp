/*OPERACIONES CON REales*/
#include<stdio.h>
#include<stdlib.h> 
int main ()
{
    float a,b,c,d;
    printf("\nDame el valor de a\n ");
    scanf("%f",&a);
    printf("\nDame el valor de b\n ");
    scanf("%f",&b);
    printf("\nDame el valor de c\n ");
    scanf("%f",&c);   //un error como poner %d en vez de %f podria causar resultados inesperadoros, no necesariamente truncar a entero
    d=(b*b-(4*a*c))/(2*a);
    printf("EL valor de la expresion  (b^2 - 4ac)/2a es %f\n", d);
    system("PAUSE");
    system("cls");
    system("PAUSE"); //LIMPIA LA PANTALLA ; ESTA FUNCION ESTA DENTRO DE STDLIB IGUAL QUE SYSTEM PAUSE
    return 0;
}
