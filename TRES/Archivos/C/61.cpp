#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int digitos (int n);
void numero_cadena(char m[],int n);
float absoluto (float n);
main()
{
 	  int n;
 	  char arreglo[10];
 	  printf("Dame un numero entero :  ");
 	  scanf("%d",&n);
 	  printf("El numero sera convertido a cadena\n");
 	  numero_cadena(arreglo, n);
 	  puts(arreglo);
 	  system("PAUSE");
 	  
}
void numero_cadena(char m[],int n)
{
     int suma=0,d,x,y,i;
     d=digitos(n);
    // m[d+1]='\0';
     m[d]='\0';                                                                 //el ultimo es caracter nulo en toda cadena
     for(x=1;x<=d;x++)
     {
                      y=(n/pow(10,d-x)) - suma;
                      m[x-1]=y;
                      suma= suma + m[x-1];                                      //en suma se iran sumando los numero por eso solo multiplico por 10 cada vez
                      suma=suma*10;
     }
    for(x=1;x<=d;x++)
     {
                      switch (m[x-1])
                      {
                                  case 0:
                                  {
                                  m[x-1]=48;
                                  break;
                                  }
                                  case 1:
                                  {     
                                  m[x-1]=49;
                                  break;
                                  }
                                  case 2:
                                  {
                                  m[x-1]=50;
                                  break;
                                  }
                                  case 3:
                                  {
                                  m[x-1]=51;
                                  break;
                                  }
                                  case 4:
                                  {
                                  m[x-1]=52;
                                  break;
                                  }
                                  case 5:
                                  {
                                  m[x-1]=53;
                                  break;
                                  }
                                  case 6:
                                  {
                                  m[x-1]=54;
                                  break;
                                  }
                                  case 7:
                                  {
                                  m[x-1]=55;
                                  break;
                                  }
                                  case 8:
                                  {
                                  m[x-1]=56;
                                  break;
                                  }
                                  case 9:
                                  {
                                  m[x-1]=57;
                                  break;
                                  }
                      }
     }
}  
int digitos (int n)
{
    int ceros, d;
    n=int(absoluto((float)n));
    ceros=10;
    d=1;
    do
    {
        if(ceros>n)
        {
                   return d;
                   exit (0);
        }
        ceros=ceros*10;
        d++;
    }while (d<=20);
return 0;
}
float absoluto (float n)
{
      if (n<0)
          n=-1*n;
return n;
}
