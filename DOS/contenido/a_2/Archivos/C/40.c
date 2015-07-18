#include <stdio.h>
#include <stdlib.h>
int main() 
{
		float *V, *ptr; /* ptr es para acceder al array V por punteros */
		int N, i;
		printf("Número de valores: "); 
		scanf ("%d",&N);
		if ((V=(float *) malloc(N*sizeof(float))) == NULL) 
			printf("No hay suficiente memoria.\n");
		else {
			for(i=0,ptr=V; i<N; i++,ptr++) 
			{
				printf("Valor >> ");
				scanf("%f",ptr /* o &V[i] */);
			}
			for(i=0,ptr=V;i<N;i++, ptr++)
				printf("\nValor %d >> %f", i, *ptr /* o V[i] */);
			free(V);
		
		}
		system("PAUSE");
	}
	