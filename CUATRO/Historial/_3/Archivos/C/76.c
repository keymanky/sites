#include <stdio.h>					//PROGRAMA QUE CONVIERTE BINARIO A DECIMAL
#include <math.h>

int main (void)
{
int di,bi,num,sum,dii,fin,di2,dr,con;
int A[100] = {0};
int B[100] = {0};
float num2,sum2,sumt;
sum=0;
con=0;
sum2=0;

printf("CONVERSION BINARIA A DECIMAL");
printf("\nJORGE SALGADO MENDOZA\n");
printf("METODOS NUMERICOS");

printf("\n\n\nSiGuE lAs InStRuCcIoNeS\n");			//ESTA PRIMERA PARTE TOMA LA PARTE ENTERA DEL BINARIO Y LA TRANSFORMA
printf("\nEL DIGITO 1 ES EL QUE ESTA MAS CERCA DEL PUNTO\n");
printf("\nEL DIGITO MAS GRANDE ES EL QUE ESTA MAS A LA IZQUIERDA\n");
printf("DAME EL NUMERO DE DIGITOS DE LA PARTE ENTERA DEL BINARIO\n");
scanf("%d", &di);
dii=di;
for(di;di>=1;di--)
{
	printf("\n\tEL DIGITO %d es:",di);
	scanf("%d",&bi);
	A[di]= bi;
	if(bi==1)
		num= pow (2,di-1);
	if(bi==0)
		num=0;
	if(bi!=1 && bi!=0)			//SI SE EQUIVOCA Y NO TECLEA UN CERO O UN UNO
		printf("\ntecla bien, se tomara como cero");
	sum=sum+num;
}			//segunda parte calcula la parte decimal o fraccionaria del binario
printf("\n\n\nDAME LA PARTE DECIMAL SIN EL PUNTO\n");
printf("TECLEALA COMO OTRO BINARIO, RECUERDA PONER LOS CEROS CORRESPONDIENTES\n");
printf("SI NO TIENE DECIMAL PON CERO\n");
printf("EL NUMERO DE DIGITO MAS GRANDE ES EL NUMERO MAS CERCANO AL PUNTO\n");
printf("EL DIGITO 1 ES el MAS ALEJADO DEL PUNTO");
printf("\n\n\nEL NUMERO DE DIGITOS DE LA PARTE DECIMAL ES\n");
scanf("%d",&di2);
dr=di2;
for(di2;di2>=1;di2--)
{
	con=con-1;
	printf("\n\tEL DIGITO %d es:",di2);
	scanf("%d",&bi);
	B[di2]= bi;
	if(bi==1)
		num2= pow(2,con);
	if(bi==0)
		num2=0;
	if(bi!=1 && bi!=0)
		printf("\ntecla bien, se tomara como cero");
	sum2=sum2+num2;
}

printf("\nEL BINARIO  ");
							//esta parte imprime el numero binario completo
for(dii;dii>=1;dii--)
printf("%d",A[dii]);
printf(".");
for(dr;dr>=1;dr--)
printf("%d",B[dr]);

sumt=sum+sum2;			//esta sumt es la suma total de los 2 bloques
printf("\n SU EQUIVALENTE DECIMAL ES %f",sumt);


printf("\n\tteclea y fin\n");		//esto solo da una pausa
scanf("%d",&fin);
return 0;
}

