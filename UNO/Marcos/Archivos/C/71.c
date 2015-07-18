/*************************IMPRIME UN ROMBO DE ASTERISCOS UTLIZANDO CICLOS******/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
float z,a,b,n,i,w,r;
int j;
printf("CUANTOS NIVELES #PAR");
scanf("%f", &n);
w=1;
for (i=1; i<=(n/2)+.5; i++)
	{
	for(j=i; j<=n; j++)
		printf(" ");
	for(z=1; z<=w; z+=2)
		printf("*");
	printf("\n");
	w=w+4;
	}
for (i=1; i<=(n/2)+.5; i++)
        {
        for(a=(j/2)+1.5;a>1; a--)
                printf(" ");
	j=j+2;
        for(b=z-1.5; b>1; b-=2)
                printf("*");
	z=z-4;
        printf("\n");
        }
 system("PAUSE");
 return 0;
}
