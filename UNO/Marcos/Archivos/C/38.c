#include<stdio.h>
#include<stdlib.h>
main()
{
      int x=0;
      char jorge='a';
      char jorge2='b';
      char jorge3='c';
      char arreglo[10];
      arreglo[x]=jorge;
      x++;
      arreglo[x]=jorge2;
      x++;
      arreglo[x]=jorge3;
      x++;
      arreglo[x]='\0';
      puts(arreglo);
      system("PAUSE");
}
