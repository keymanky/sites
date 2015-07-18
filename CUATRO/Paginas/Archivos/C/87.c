
//metodo de SECANTE encontrar raiz d polinomio
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{

	double a,b,xn1,fxn,f1xn,fxnuno,xn,xnuno,errel,t,xnmas;
	int x;

    printf("JORGE SALGADO MENDOZA\n");
	printf("\nmetodo de secante\nEJERCICIO A)	F(X)=X^3-X-1 0.000001 presicion\n	");
	printf("\nxn\t f(Xn) \t\txn-1\t\tf(xn-1)\t\txn+1\t\tErrorel\n");	//CABECERA
	xn=1;
	xnuno=2;
    errel=100;	
    
    
    for(x=1; x<10000; x++)
	{
	if(x>2)
	       errel=fabs(xn-xnuno)/fabs(xn);
    
    
    fxn=(pow(xn,3))-xn-1; //funcion 
	fxnuno=(pow(xnuno,3))-xnuno-1;
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
