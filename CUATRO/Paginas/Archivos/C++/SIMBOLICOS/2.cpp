#include<conio.h>
#include<iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

class circulo
{
      private:
              int x,y,radio;
      public:
             int n;
             circulo(int nradio=1, int nx=0, int ny=0)
             {
                         x=nx; y=ny; radio=nradio;
                         n=0;
             }
             int Dar_x()
             {return x;}
             int Dar_y()
             {return y;}
             int Dar_radio()
             {return radio;}
};
//La pelota se compone de un objeto circulo
class Pelota
{
      public:
              int color;
              circulo C;
      public:
             Pelota(int nr, int nx, int ny, int ncolor)
             {
                        circulo C(nr,nx,ny);
                        color=ncolor;
             }
};

main()
{
      Pelota Mi_Pelota(1,2,3,4);
      //Observece q todos los componentes de la pelota son publicos
      cout<<"Ejemplo de composicion "<<Mi_Pelota.C.n<<endl; //Mi pelota es un objeto q se compone de el objeto c que tiene sus propios metodos; observe q n es publico
      int Radio= Mi_Pelota.C.Dar_radio(); //Necesario hacer esta asignacion para luego imprimirla
      cout<<"El radio de la pelota es "<<Radio<<endl;
      getch();
}
