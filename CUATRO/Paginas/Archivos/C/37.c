//PROPORCIONA EL SALARIO DE 4 TIPOS DE EMPLEADOS 
#include<stdio.h>
int main(void)
{
int w,c,h,v,a;
float comision,ex,s,t,t2;
printf("INGRESA TU CODIGO DE EMPLEADO");
scanf("%d", &c);
w=c;
if(c<=0)
	printf("\nNUMERO NO VALIDO");
if(c>4)
	printf("\nNUMERO NO VALIDO");
else
	for(w; w==c; c=c+8)
		{
		if (c==1)
			{
			printf("\nERES GERENTE POR LO QUE TU SALARIO ES 5000");
			}
		if (c==2)
			{
			printf("\nINGRESA TUS HORAS TRABAJADAS");
			scanf("%d",&h);
			printf("\nINGRESA TU TARIFA X HORA");
			scanf("%f",&t);
			if (h>40)
				{
				ex=h-40;
				t2=t*1.5;
				s=(t*40)+(t2*ex);
			        }
			else
				s=h*t;
			printf("\nTU SALARIO ES %f",s);
			}
		if(c==3)
			{
			printf("INGRESA TUS VENTAS");
			scanf("%d",&v);
			comision=(5.7*v)/100;			
			s=comision+250;
			printf("\nTU SALARIO ES %f",s);
			}
		if(c==4)
			{
			printf("INGRESA TUS ARTICULOS");
			scanf("%d",&a);
			s= a*15;
			printf("\nTU SALARIO ES %f",s);
			}
		}
return 0;
}


