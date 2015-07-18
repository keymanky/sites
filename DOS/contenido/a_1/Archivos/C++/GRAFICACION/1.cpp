#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
//#include <winbgim.h>

class Circulo
{
      private:
	      float radio;
	      float x,y;
	      float pi;
	      int ver;
      public:
	      //constructor
	      Circulo(float orad, float ox, float oy)
	      {
		  radio=orad;
		  x=ox;
		  y=oy;
		  pi=3.14159;
		  ver=0;
	      }

      float Area()
      {
	    return (pi*radio*radio);
      }

      float Perimetro()
      {
	    return (pi*2*radio);
      }

      void Dibujar()
      {
	   circle(x,y,radio);
	   ver=1;
      }

      void Ocultar()
      {
	   unsigned guardacolor;
	   guardacolor= getcolor();
	   setcolor(getbkcolor());
	   ver=0;
	   setcolor(guardacolor);
      }

      void Mover(float nx, float ny)
      {
	   if(ver)
	   {
		  Ocultar();
		  x=nx;
		  y=ny;
		  Dibujar();
	   }
	   else
	   {
		  x=nx;
		  y=ny;
		  Dibujar();
	   }

      }
};


void main()
{

     Circulo Cir1(80,100,120);
     Circulo Cir2(120,300,250);
     int a,b,i;
     a=DETECT;
     initgraph(&a,&b," ");
     Cir1.Dibujar();
     Cir1.Area();
     Cir1.Perimetro();
     Cir2.Dibujar();
     for(i=0;i<300;i++)
     {
	Cir1.Mover(100+i,120);
	delay(50);
     }
     getch();
     closegraph();
}
