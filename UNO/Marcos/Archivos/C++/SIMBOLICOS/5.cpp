#include<iostream>
#include<conio.h>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

void Por_Referencia(int &);

main()
{
      int a=8;
      cout<<"A vale  "<<a<<endl;
      Por_Referencia(a);
      cout<<"A ahora vale"<<a<<endl;
      getch();
}
void Por_Referencia(int &es_a)
{
     es_a=100;
}
