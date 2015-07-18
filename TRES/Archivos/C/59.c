#include<stdio.h>
#include<stdlib.h>
float maspeque(void);
main()
{
 	  float menor=maspeque();
 	  printf("%g es el numero mas pequeno\n",menor);
 	  system("PAUSE");
}
/*********FUNCION QUE PIDE AL USUARIO N NUMERO Y RETORNA EL MAS PEQUENO********/
float maspeque(void)
{
int w,s,c;
float x,z;
printf("CUANTOS NUMEROS VAS A INTRODUCCIR\n");	
scanf("%d",&s);
for (c=1; c<=s; c++)
	{
	printf("EL NUMERO %d DE LA SECUENCIA ES\n",c);
	scanf("%f",&x);
	if (c>=2)
		if(z<x)
			z=z;
		else
			z=x;
	else
		z=x;
	}  
                                                                                //printf("EL NUMERO MAS PEQUEÑO QUE INTRODUSISTE FUE:%f",z);
                                                                                //system("PAUSE");
system("cls");
return z;
}
