
//tarea 2 subtarea ejecutable que trunca el sistema flotante


#include<stdio.h>
#include <stdlib.h>

main()
{

int k,c,dec;
float i,sis2,sis,sure,r;
float rea,susis,ya;
sure=0;			//variables que hacen la sumatoria
susis=0;

printf("JORGE SALGADO MENDOZA\nSUMATORIA EN SISTEMA REAL Y FLOTANTE\nTAREA 2\n");

printf("DAME EL NUMERO K\n");
scanf("%d", &k);
for(i=1;i<=k; i++)
{
rea=1/i;		//formala de sumatoria
sure=sure+rea;		//"numero real"
sis=rea*1000;				//desde aqui
dec=sis;
r=sis-dec;
ya=sis-r;
sis2=ya/1000;				//hasta aca es para truncar
susis=susis+sis2;//"numero del sistema"
printf("\n%f",i);
printf("\t\t%f",rea);
printf("\t\t%f",sis2);
}
printf("\nla real suma es%f",sure);
printf("\nla suma del sistema flotante es%f\n",susis);
system("PAUSE");
}