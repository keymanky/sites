#include <stdio.h>
#include <stdlib.h>
int main ()
{
int i,n;
int * Data;
printf ("Cantidad de numeros a ingresar: ");
scanf ("%d",&i);
Data = (int*) calloc (i,sizeof(int));
if (Data==NULL) exit (1);
for (n=0;n<i;n++)
{
printf ("Ingresa el numero #%d: ",n);
scanf ("%d",&Data[n]);
}
printf ("Has ingresado\n");
for (n=0;n<i;n++) printf ("%d\n",Data[n]);
system("PAUSE");
return 0;
}
