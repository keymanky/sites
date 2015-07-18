#include<iostream>
#include<conio.h>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

void Muestra(int x=8);
void Muestra(int, float);

main()
{
      int a=10;
      float k=20.3;
      Muestra();
      Muestra(a);
      Muestra(a,k);
      getch();
}
void Muestra(int x)
{
     cout<<"El contenido es"<<x<<endl;
}
void Muestra(int x, float y)
{
     cout<<"El contendio es   "<<x<<" y  "<<y<<endl;
}
