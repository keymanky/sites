
//metodo de bisesion
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
	double xi,xs,fxi,fxs,fxm,xm,v,edid,edis,e;
	int x;
	xi=-3;
	xs=-2;
	printf("JORGE SALGADO MENDOZA\n");
	printf("\nmetodo de falsa posicion\nEJERCICIO unico	F(X)=x^3+x+16\n	10000 ITIENERACIONES\n\n");
	printf("\nNO. \t\t XI \t\t\t XS \t\t XM \t\tE REL\n");	//CABECERA

	fxi= (pow(xi,3))+xi+16;	//ECUACION
	fxs= (pow(xs,3))+xs+16;
	v=fxi*fxs;		//COMPROBACION DE XI Y XS
	if (v<= 0)
	{
		for(x=1;x<=10000; x++)			//ITINERACIONES QUE SON 10000 MAXIMO
		{
			fxi= (pow(xi,3))+xi+16;	
			fxs= (pow(xs,3))+xs+16;	
            fxm= xs-((fxs*(xs-xi))/(fxs-fxi));
			printf("\n%d \t %f \t\t %f \t\t %f",x,xi,xs,xm);	//IMPRIME LA ITINERACION,EL XI, EL XS Y EL XM
			if ((fxi*fxm)==0)
			{
				printf("\nla raiz es:%f",xm);//SI ES RAIZ
				system("PAUSE");
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
					if (e<=0.001)
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
					if (e<=0.001)
						goto presicion;
				}
			}//IF CUANDO EL PRODUCTO ES POSITIVO
		}//CIERRA EL CICLO
	}//CIERRA EL PRIMER IF
	else
	printf("ERROR DE PROGRAMA");

presicion:
	printf("SE A ALCANZADO LA PRESICION\n");
system("PAUSE");
}

