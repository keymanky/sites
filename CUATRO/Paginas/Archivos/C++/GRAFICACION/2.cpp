#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>


class Elipse
{
      private:
	      float x,y,rx,ry;
	      int ver;
      public:
	      //constructor
	      Elipse(float ox, float oy, float orx,float ory)
	      {
		  x=ox;
		  y=oy;
		  rx=orx;
		  ry=ory;
		  ver=0;
	      }

      void Dibujar()
      {
	   fillellipse(x,r,rx,ry);
	   ver=1;
      }

      void Ocultar()
      {
	   unsigned guardacolor;
	   guardacolor= getcolor();
	   setcolor(getbkcolor());
	   ver=0;
	   fillellipse(x,r,rx,ry);
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

     Elipse E1(50,70,100,70)
     int a,b,i;
     a=DETECT;
     initgraph(&a,&b," ");
     for(i=0;i<640;i++)
     {
	E1.Mover(15+i,15+i);
	delay(1);
     }
     getch();
     closegraph();
}
