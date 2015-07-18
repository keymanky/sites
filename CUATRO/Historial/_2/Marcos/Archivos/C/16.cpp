/********************PROGRAMA QUE CALCULA EL VALOR DE E************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float exponencial (float);
int factorial (int t);
main()
{
      float x;
       printf("Dame e^x el valor de x");
       scanf("%f",&x);
       printf("La aproximacion %f",exponencial(x));
       system("PAUSE");       
}
/*********************FUNCION QUE CALCULA EL VALOR DE E************************/
float exponencial(float y)
{
      float e,e1,error,ex;
      e=1;
      int c=1;
      do                                                                        //ciclo que calcula e elevado a la 1    
      {
          e1=e+ (float(1)/(factorial(c)));                                      //conversion explicita de 1 a float. Formula de maclaurin
          c++;
          e=e1;
      }while(c<13);                                                             //maximo 12 porque la funcion factorial retorna maximo el factorial de 12       
      ex=pow(e,y);                                                              //con esto se eleva el valor de e a lo que sea
      return ex;
}
/**************FUNCION QUE CALCULA EL FACTORIAL DE UN NUMERO*******************/
int factorial (int t)
{
    if(t>12 || t<0)
            return 0;
    else
    {
    int unsigned a;
    float y=1,multi,x;
    for(x=1; x<=t; x+=1)
	{
	multi=x*y;
	y=multi;
	} 
    a= (int) y;
    return a;
    }
} 
