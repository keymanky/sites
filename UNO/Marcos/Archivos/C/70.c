//PROMEDIO DE NUMEROS DADOS POR EL USUARIO
#include<stdio.h>
int main(void)
{
int s,c;
float y,x,z;
y=0;
printf("DE CUANTOS NUMEROS QUIERES CALCULAR EL PROMEDIO\n");	
scanf("%d",&s);
for (c=1; c<=s; c++)
	{
	printf("EL NUMERO %d DE LA SECUENCIA ES\n",c);
	scanf("%f",&x);
	y=x+y;
	}  
z=y/s;
printf("EL PROMEDIO DE  %d NUMEROS ES\n:%f",s,z);
return 0;
}


