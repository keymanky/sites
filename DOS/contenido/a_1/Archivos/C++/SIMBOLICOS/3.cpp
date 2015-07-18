#include<iostream>
#include<conio.h>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
//Defincion de la clase
class Clase1
{
      public:
             int y;
             Clase1(int);
             void Eleva();
};
//Operador  ::  en funciones de una clase
Clase1 :: Clase1(int nuevo=0)
{
       y=nuevo;
}
void Clase1 :: Eleva()
{
     y=y*y;
}


void Funciony();


//variable global y
int y=10;
//


main()
{
      Funciony();     
      getch();
}

void Funciony()
{
     int y=100;
     cout<<"La variable global y "<<::y<<endl;
     cout<<"La variable local  y "<<y<<endl;
}
