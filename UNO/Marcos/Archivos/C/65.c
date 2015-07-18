//Imprime los lados enteros de todos los triangulos
//que su hipotenusa se menor a 500  
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
int h,y,x,contador;
printf("LADO 1 \t\t\t\t LADO 2\t\t\t\tHIPOTENUSA CUADRADA\n");
contador=0;
for(x=1; x<500; x++)
	for(y=1; y<500; y++)
	{
	h=(x*x)+(y*y);
	if (h<=250000)
		{
		printf("%d%30d%30d\n",x,y,h);
		contador=contador+1;
		}
	}
printf("\nEN TOTAL FUERON %d triangulos\n",contador);
system("PAUSE");
return 0;
}


