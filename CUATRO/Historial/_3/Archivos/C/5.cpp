/*OPERACIONES CON ENTEROS */
#include<stdio.h>
#include<stdlib.h> 
int main ()
{
    int a, b, c, d, e, f;
    printf("Dame el valor de a, b , c , d \n Separados por espacion");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    e=a+b+c+d;
    f=e/4;
    printf("EL valor de la suma es de %10d y el promedio es de %20d",e,f); //notose que el promedio se trunca por la divison entre 4 podria dar un flotante y la variable f es entera
    system("PAUSE");
    system("cls");
    system("PAUSE"); //LIMPIA LA PANTALLA ; ESTA FUNCION ESTA DENTRO DE STDLIB IGUAL QUE SYSTEM PAUSE
    return 0;
}
