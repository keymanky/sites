#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>


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
	   circle(x,y,radio);
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
	   fillellipse(x,y,rx,ry);
	   ver=1;
      }

      void Ocultar()
      {
	   unsigned guardacolor;
	   guardacolor= getcolor();
	   setcolor(getbkcolor());
	   ver=0;
	   fillellipse(x,y,rx,ry);
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
	   rectangle(x,y,x+base,y+altura);
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

      void Mover(float n)
      {
	   if(ver)
	   {
		  Ocultar();
		  x=x+n;
		  x1=x1+n;
		  Dibujar();
	   }
	   else
	   {
		  x=x+n;
		  x1=x1+n;
		  Dibujar();
	   }

      }
};


void main()
{
     int ci=0;
     Linea L1(ci,380,ci,430);
     Linea L2(ci+20,380,ci+20,430);
     Circulo Cir1(20,20,20);
     Circulo Cir2(60,60,60);
     Elipse E1(0,0,40,60);
     Rectangulo Rec1(25,60,0,0);
     int a,b,i;
     a=DETECT;
     initgraph(&a,&b," ");
     for(i=0;i<640;i++)
     {
	Cir1.Mover(i+10,120);
	E1.Mover(10+i,330);
	Cir2.Mover(i,150);
	Rec1.Mover(i-5,210);
	L1.Mover(1);
        L2.Mover(1);
	if(i==0)
	   getch();

	delay(1);
     }
     getch();
     closegraph();
}
