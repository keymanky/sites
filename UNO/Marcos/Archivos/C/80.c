
//metodo de bisesion
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
	double xi,xs,fxi,fxs,fxm,xm,v,edid,edis,e;
	int x;
	float p;
	xi=0;
	xs=1;
	printf("JORGE SALGADO MENDOZA\n");
	printf("\nmetodo de bisesion\nEJERCICIO c)	F(X)=x-2^-x\n		PRESICION 1 MILESIMA	10000 ITIENERACIONES\n\n");
	printf("\ndame presicion como .1 0 .00001\n");
	scanf("%f",&p);
    printf("\nNO. \t\t XI \t\t\t XS \t\t XM \t\tE REL\n");	//CABECERA
	system("PAUSE");


	fxi= xi-(pow(2,-xi));		//ECUACION
	fxs= xs-(pow(2,-xs));
	v=fxi*fxs;		//COMPROBACION DE XI Y XS
	if (v<= 0)
	{
		for(x=1;x<=10000; x++)			//ITINERACIONES QUE SON 10000 MAXIMO
		{
			xm=(xi+xs)/2;
			fxi= xi-(pow(2,-xi));	//SE EVALUA LA ECUACION EN XI Y XM
			fxm= xm-(pow(2,-xm));
			printf("\n%d \t %f \t\t %f \t\t %f",x,xi,xs,xm);	//IMPRIME LA ITINERACION,EL XI, EL XS Y EL XM
			if ((fxi*fxm)==0)
			{
				printf("\nla raiz es:%f",xm);//SI ES RAIZ
				system("PAUSE");
				exit(0);
			}
			if ((fxi*fxm)<0)//NEGATIVO
			{
				xi=xi;
				xs=xm;
				if(x>1)		//CALCULAR EL ERROR
				{
					edid=fabs(xm-xi);//XI =XM VIEJO
					edis=fabs(xm);
					e=(edid/edis);
					printf("\t%f",e);//IMPRIME EL ERROR
					if (e<=p)
						goto presicion;
				}
			}
		
			if ((fxi*fxm)>0)//SI ES POSITIVO
			{
				xi=xm;
				xs=xs;
				if(x>1)//CALCULAR EL ERROR
				{
					edid=fabs(xm-xs);//XS =XM VIEJO
					edis=fabs(xm);
					e=edid/edis;
					printf("\t%f",e);//IMPRIME EL ERROR
					if (e<=p)
						goto presicion;
				}
			}//IF CUANDO EL PRODUCTO ES POSITIVO
		}//CIERRA EL CICLO
	}//CIERRA EL PRIMER IF
	else
	printf("ERROR DE PROGRAMA");

presicion:
	printf("SE A ALCANZADO LA PRESICION\n La aproximacion de raiz es %f\n",xm);
system("PAUSE");
}

