#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>



class pico    //Aqui se dibuja el pico
{
	private:
	float xi,yi,sa,ea,r;
	int ver;
	public:
	pico(float oxi,float oyi,float osa, float oea,float or)
	{
	 xi=oxi;
	 yi=oyi;
	 sa=osa;
	 ea=oea;
	 r=or;
	 ver=0;
	 }

	 void Dibuja()
	 {
	 pieslice(xi,yi,sa,ea,r);
	 ver=1;
	 }

	 };


void main()
{


	  pico Pi1 (170,175,150,170,30);

	  int a,b,i;
	  a=DETECT;
	  initgraph(&a,&b," ");

	Pi1.Dibuja();


	  getch();
	  closegraph();
}
