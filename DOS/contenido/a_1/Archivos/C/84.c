
//metodo de newton encontrar raiz d polinomio
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{

	double xn,xn1,fxn,f1xn,a,errel,t,p;
	int x;

    printf("JORGE SALGADO MENDOZA\n");
	printf("\nmetodo de NEWTON\nEJERCICIO B)	F(X)=-2x^3-4x^2+4x+4 presicion 0.000001\n	");
	printf("\nxn \t\t f(Xn) \t\t f(Xn+1)\t\t Xn+1 \t\tErrorel\n");	//CABECERA
	a=1;//valor inicial
	for(x=1; x<10000; x++)
	{
	xn=a;
	printf("\n%f\t",xn);
	fxn= -(2*pow(xn,3))-(4*pow(xn,2))+(4*xn)+4;//funcio evaluada
	printf("%f\t",fxn);
	f1xn= -6*pow(xn,2)-8*xn+4; //derivada evaluada
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
