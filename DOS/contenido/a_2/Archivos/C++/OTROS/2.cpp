//Ejemplo de toda una clase amiga
#include<iostream.h>
#include<conio.h>
class Amiga;
class Dejada
{
      int valor;
      public:
             void Imprime()
             {cout<<"El valor es "<<valor<<endl;}
             Dejada(int n=100)
             { valor=n;}
             friend class Amiga;
};

class Amiga
{
      public:
      void Destruye_valor(Dejada x)
      { x.valor=0;}
};

void main()
{
     clrscr();
     
     Dejada Obj1;
     Obj1.Imprime();
     
     Amiga Obj2;
     Obj2.Destruye_valor(Obj1);
     Obj1.Imprime();
     
     getch();
}
