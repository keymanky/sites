#include<iostream>
#include<stdio.h>
#include<conio.h>
//
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
//

void Parametros(int x=10, char *cadena="Por default");
main()
{
      puts("Parametros por omision");
      
      Parametros();
      Parametros(5,"Utilizo parametros"); 
      Parametros(0);
      getch();
}
void Parametros(int x, char *c)
{
     int i=0;
     for(i=0;i<x;i++)
         cout<<c<<endl;
         
}
