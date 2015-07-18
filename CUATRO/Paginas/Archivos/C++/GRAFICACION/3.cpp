#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>


class Linea
{
      private:
	      float x,y,x1,y1;
	      int ver;
      public:
	      //constructor
          Linea (float ox, float oy, float ox1,float oy1)
	      {
		  x=ox;
		  y=oy;
		  x1=ox1;
		  y1=oy1;
		  ver=0;
	      }

      void Dibujar()
      {
	   line(x,y,x1,y1);
	   ver=1;
      }

      void Ocultar()
      {
	   unsigned guardacolor;
	   guardacolor= getcolor();
	   setcolor(getbkcolor());
	   ver=0;
	   line(x,y,x1,y1);
	   setcolor(guardacolor);
      }

      void Mover(n)
      {
	   if(ver)
	   {
		  Ocultar();
		  x=x+n;
		  y=y+n;
		  Dibujar();
	   }
	   else
	   {
		  x=x+n;
		  y=y+n;
		  Dibujar();
	   }

      }
};


void main()
{

     Linea L1(50,80,180,200);
     int a,b,i;
     a=DETECT;
     initgraph(&a,&b," ");
     for(i=0;i<640;i++)
     {
	L1.Mover(i+3,50);
	delay(1);
     }
     getch();
     closegraph();
}
