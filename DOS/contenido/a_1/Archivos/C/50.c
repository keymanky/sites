
//metodo de SECANTE encontrar raiz d polinomio
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{

	double a,b,xn1,fxn,f1xn,fxnuno,xn,xnuno,errel,t,xnmas;
	int x;

    printf("JORGE SALGADO MENDOZA\n");
	printf("\nmetodo de sEcAnTe\nEJERCICIO D)	F(X)=F(X)=EX+2-X+2COSX-6  0.000001 presicion\n	");
	printf("\nxn\t f(Xn) \t\txn-1\t\tf(xn-1)\t\txn+1\t\tErrorel\n");	//CABECERA
	xn=-7;          //intervalo
	xnuno=2;
    errel=100;	
    
    
    for(x=1; x<10000; x++)
	{
	if(x>1)
	       errel=fabs(xn-xnuno)/fabs(xn);
    
    
    fxn=pow(2.71828,xn)+ pow(2,-xn)+2*cos(xn)-6;;
	fxnuno=pow(2.71828,xnuno)+ pow(2,-xnuno)+2*cos(xnuno)-6;
	a=fxn*(xn-xnuno);
	b=fxn-fxnuno;
	xnmas=xn-(a/b);
	
	xnuno=xn;
	xn=xnmas;
	printf("\n%f**",xn);
	printf("%f\t",fxn);
	printf("%f\t",xnuno);
	printf("%f\t",fxnuno);
	printf("%f\t",xnmas);
	printf("%f",errel);//IMPRIME EL ERROR
					if (errel<=0.000001)
					{
						printf("se ha alcanzo presion \n la aproximacion es %f",xn);
		   	            system("PAUSE");
						exit(0);
                    }

      }
   	system("PAUSE");
}
