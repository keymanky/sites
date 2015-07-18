#include<stdio.h>
#include<stdlib.h>
int suma_cuadrados_n(int);
main()
{
      int n;
      printf("REALIZO: JORGE SALGADO MENDOZA\nGRUPO 1352\nESTRUCTURA DE DATOS\n");
      system("PAUSE");
      system("CLS");
      printf("Dame hasta que numero quieres calcular la serie de 1^2 + 2^2....n\nDame n\n");
      scanf("%d",&n);
      printf("La suma de las serie de los cuadrados hasta n es:\n%d",suma_cuadrados_n(n));
      system("PAUSE");
}

int suma_cuadrados_n(int n)
{
    int resultado=1;
    if(n==0)                                                                    //PARA EL CASO DE CERO          
        return resultado-1;
    if(n==1)                                                                    //CONDICION DE TERMINO          
        return resultado;
    else
        return ((n*n)+(suma_cuadrados_n(n-1)));                                 //PROCESO RECURSIVO                                      
}
