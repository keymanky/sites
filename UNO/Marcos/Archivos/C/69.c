//calcular el valor de serien infinita 4/3+4/5...O PI para valores mayores a mil
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
float a,x,contador,pi;
pi=4;
printf("NUMERO DEL DENOMINADOR:");
scanf("%f",&a);
contador=1;
for(x=3; x<=a; x+=2)
	{
	contador=-contador;
	pi=((4/x)*contador)+pi;
	}
printf("\nEL RESULTADO ES\n%f\n",pi);
system("PAUSE");
return 0;
}

//PARA UNA CONSIDERABLE APROXIMACION SERA 12000MIL EL VALOR DE DENOMINADOR O 50000


