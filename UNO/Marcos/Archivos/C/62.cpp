#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void numero_romano(int numero,char arreglo[]);
int digitos (int n);
int digito(int numero, int digit);
float absoluto (float n);
void numero_arreglo(int m[],int n);
main()
{
 	  int i=0;
 	  char romano[20];
 	  for(i=0;i<100;i++)
		    {
	  		numero_romano(i,romano); 	   
	  		printf("%d\t\t%s\n", i, romano);
			}
      system("PAUSE");
}
void numero_romano(int numero,char arreglo[])
{
     if(numero>99 || numero<1)
                  arreglo[0]='\0';
     else
     {
     int contador;
     int x,y,digitosn,ndigiton;
     char unidad,cinco,decena;
     digitosn=digitos(numero);
     contador=0;
     for(x=1;x<=digitosn;x++)                                                   //FOR++++++++++++++++++++ciclo principal, lo repite 2 0 1 vez; dependiendo del numero decimal
     {
          if((digitosn-x)>0)                                                    //REPRESENTAR LA POSICION DEL DIGITO+++++++++++++si el numero es mayor a 10. Aca se define el algoritmo y logica de numeros romano
          {
                unidad= 'X';
                cinco= 'L';
                decena= 'C';
          }
          else if ((digitosn-x)==0)                                             //si el numero es menor a 10 o si se ejecuto el ciclo principall por segunda vez
          {
               unidad= 'I';
               cinco= 'V';
               decena= 'X';
          }          
          ndigiton=digito(numero,x);                                            //separa el digito de izquierda a derecha
          switch (ndigiton)                                                     //REGLA UNIVERSAL  ++++++++++++++++++++se deja que el usuario las interprete con ayuda del apartado de "representar la posicon del digito"
          {
                case 1: case 2: case 3:                                         //siempre que sea 1 2 0 3 se ejecutara sin importar que represente a decenas o unidad; es decir sin importar que el numero decimal tenga 2 o un digito
                     {
                             for(y=1;y<=ndigiton;y++)
                             {
                                   arreglo[contador]= unidad;                   //se va aguardando en el arreglo char
                                   contador++;
                             } 
                             break;                                             //necesario por definicion del switch
                     }
                case 4:                                                         //la misma logica para el cuadro, lo que cambia para decir que son decenas o unidades son los if del inicio del ciclo
                     {
                             arreglo[contador]=unidad;
                             contador++;
                             arreglo[contador]=cinco;
                             contador++;
                             break;
                     }
                case 5:
                     {
                             arreglo[contador]=cinco;
                             contador++;
                             break;
                     }
                case 6: case 7: case 8:
                     {
                             arreglo[contador]=cinco;
                             contador++;
                             for(y=1;y<=ndigiton-5;y++)
                             {
                                  arreglo[contador]=unidad;
                                  contador++;
                             }
                             break;
                     }
                case 9:
                     {
                             arreglo[contador]=unidad;
                             contador++;
                             arreglo[contador]=decena;
                             contador++;
                             break;
                     }
          }
     }
     arreglo[contador]='\0';                                                    //finaliza la cadena cuado acabo el ciclo for principal
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
int digito(int numero, int digit)
{
    int dig,x;
    dig=digitos(numero);
    if(digit>dig || digit<=0)
    {
       return 0;
       exit(0);
    }
    int cadena[dig];
    numero_arreglo(cadena,numero);  
    return cadena[digit-1];
}
float absoluto (float n)
{
      if (n<0)
          n=-1*n;
return n;
}
void numero_arreglo(int m[],int n)
{
     int suma=0,d,x,y,i;
     d=digitos(n);
     for(x=1;x<=d;x++)
     {
                      y=(n/pow(10,d-x)) - suma;
                      m[x-1]=y;
                      suma= suma + m[x-1];                                      //en suma se iran sumando los numero por eso solo multiplico por 10 cada vez
                      suma=suma*10;
     }
}
