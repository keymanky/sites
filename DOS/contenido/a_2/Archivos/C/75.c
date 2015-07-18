#include <stdio.h>
int main (void)						
{
float n,r,j;		//n es #original. r es la parte decimal del numero. J ES UN #FLOTANTE
int i,m,f,coc,mit,dif,con,cont, h;		//COC=COCIENTE, MIT=MITAD, N=NUMERO , i es la parte entera de r
int A[100] = {0};			//declaro 2 arreglos que van a ser para guardar la parte entera y la decimal
int B[100] = {0};
printf(" ==CONVIERTE DECIMALES a BINARIO==\n");		//LETREROS
printf("\nSOPORTA HASTA 100 DIGITOS BINARIOS\n");
printf("REALIZO JORGE SALGADO MENDOZA 2254 METODOS\n\n\n\n");
printf("\n--SiGuE lAs InStRuCcIoNeS--\n");
printf("\n1.- LA PARTE DESPUES DEL PUNTO DEBE SER (.5/Z) DONDE Z ES MULTIPLO DE 2");
printf("\n1.- LA PARTE DESPUES DEL PUNTO DEBE SER (1.5/X) DONDE X ES MULTIPLO DE 2");
printf("\nTECLEA EL NUMERO DECIMAL COMPLETO\n");
scanf("%f",&n);
m=n;	//M RESCATA LA PARTE ENTERA DEL NUMERO PARA LA PARTE 1 DEL PROGRAMA
r=n-m;	//R ES LA PARTE DECIMAL DEL NUMERO
j=1;	//J UN NUMERO FLOTANTE QUE USARE EN LA PARTE 2
coc=m;
con=0;
cont=1;




/*PARTE 1*/
//	LAS SIGUINETE PARTE DEL CODIGO SOLO CALCULA EL BINARIO DE LA PARTE ENTERA
for(coc; coc>= 1; )						//CICLO QUE HACE DIVISIONES EL VALOR DEL COC CAMBIA
	{
	mit=coc/2;							//LA DIFERENCIA MANDA UN CERO O UN 1
	dif=m-(mit*2);
	coc=mit;							//CAMBIA EL VALOR DEL COCIENTE YA QUE YA SE DIVIDIO
	con=con +1;							//UN CONTADOR
	m=coc;
	A[con-1]= dif;						//EL CERO O UNO SE ALMACENA EN EL ARRERGLO SUBINDICE CONTADOR
	}
for(con; con>=0; con--)					
printf("%d", A[con]);					//IMPRIME A SUBINDICE CONTADOR NOTECE QUE QUE 
										//EMPIEZA DE CONTADOR Y VA RESTANDO UNO



printf(".");



/*PARTE 2*/
//LA SIGUIENTE PARTE CALCULA LA PARTE DE LA MATISA
if(r==0.5)
{
	cont=2;
	B[2]= 1;
}
else
{
while (cont++)
{
	r=r*2;
	i=r;
	B[cont-1]= i;
	if (r>1)
		r=r-1;
	if (r==j) break;
}
}


for(h=2;cont>=h ; h++)			//IMPRIME LA PARTE DECIMAL DEL #BINARIO
printf("%d", B[h]);				//EMPEZANDO POR EL PRIMERO


printf("\n\n\n\n\tteclea  para terminar");	//de aqui en adelante es para esperar y visualizar el resultado
scanf("%d", &f);

return 0;
}

	
