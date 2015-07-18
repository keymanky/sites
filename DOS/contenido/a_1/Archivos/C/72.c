#include<stdio.h>
#include<stdlib.h>
int main(void)
{
int doblen,h,num,j,u,niveles;

printf("DE CUANTO NIVELES QUIERES LOS TRIANGULOS");
scanf("%d",&niveles);

doblen=2*niveles;
u=2;
	for (doblen; doblen>=1; doblen--)
		{
		if (doblen<=niveles)
				u=u+1;
		else 				/*PRIMERO SE CUMPLE ESTA CONDICION*/
				u=u-1;

		for(num=1; num>=u; num--)
			printf("*");
		printf(" \n");		
		}
doblen=2*niveles;
u=2;
h=-niveles;
        for (doblen; doblen>=1; doblen--)
                {
                if (doblen<=niveles)
                                {
				u=u+1;
				h=h-1;
				}
                else                            /*PRIMERO SE CUMPLE ESTA CONDICION*/
                                {
				u=u-1;
				h=h+1;	
				}
                for(num=1; num>=u; num--)
                        printf(" ");
		for(num=1; num>=h; num--)
			printf("*");
                printf(" \n");
                }


system("PAUSE");
return 0;
}
