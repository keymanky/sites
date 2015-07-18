
//metodo de newton encontrar raiz d polinomio
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{

	double xn,xn1,fxn,f1xn,a,errel,t,p;
	int x;

    printf("JORGE SALGADO MENDOZA\n");
	printf("\nmetodo de NEWTON\nEJERCICIO A)	F(X)=X^3-X-1 con tolerancia de .000001\n	");
	printf("\nxn \t\t f(Xn) \t\t f(Xn+1)\t\t Xn+1 \t\tErrorel\n");	//CABECERA
	a=1;
	for(x=1; x<10000; x++)
	{
	xn=a;
	printf("\n%f\t",xn);
	fxn=(pow(xn,3))-xn-1; //funcio evaluada
	printf("%f\t",fxn);
	f1xn= 3*(pow(xn,2))-1; //derivada evaluada
	printf("%f\t",f1xn);
	xn1=xn-(fxn/f1xn);
	a=xn1;
	printf("%f\t",xn1);
    errel=fabs(xn1-xn)/fabs(xn1);
					if (errel<=0.000001)
					{
						printf("se ha alcanzo presion \n la aproximacion es %f",a);
		   	            system("PAUSE");
						exit(0);
                    }
                    else
                    printf("\n\t\t\t\t\t\t\t\t\t%f",errel);//IMPRIME EL ERROR
      }
   	system("PAUSE");
}
