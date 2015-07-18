#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>


class Rectangulo
{
      private:
	      float base,altura,x,y;
	      int ver;
      public:
	      //constructor
	      Rectangulo (float ob, float oa, float ox,float oy)
	      {
		  base=ob;
          altura=oa;
		  x=ox;
		  y=oy;
		  ver=0;
	      }

      void Dibujar()
      {
	   rectangulo(x,y,x+base,y+altura);
	   ver=1;
      }

      void Ocultar()
      {
	   unsigned guardacolor;
	   guardacolor= getcolor();
	   setcolor(getbkcolor());
	   ver=0;
	   rectangle(x,y,x+base,y+altura);
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

     Rectangulo Rec1(20,30,100,150);
     int a,b,i;
     a=DETECT;
     initgraph(&a,&b," ");
     for(i=0;i<640;i++)
     {
	Rec1.Mover(15,15);
	delay(1);
     }
     getch();
     closegraph();
}
