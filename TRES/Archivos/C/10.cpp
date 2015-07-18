/****************DEVUELVE LOS ANOS VIVIDOS O SEA TU EDAD*****************************/
#include<stdio.h>
#include<stdlib.h>

int edad (int,int);

main()
{
      int actual,nacimiento;
      char nombre[30];
      printf("\nDame nombre\n");
      gets(nombre);
      printf("\nDAME EL ANO ACTUAL y ANO DE NACIMIENTO\n");
      scanf("%d %d", &actual, &nacimiento);
      printf("\nEdad es %d %s\n", edad(actual,nacimiento),nombre);

      system("PAUSE");
}

int edad (int a, int n)
{
    if(a<n)
    {
            printf("Error");
            system("PAUSE");
            exit (0);
    }
    return a-n;
}
