#include<iostream>
//En borland o TC no es necesario agregar todo esto
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::flush;
// Y si es necesario en borlan o TC poner iostream.h

main()
{
      char cadena[100];
      cout<<"Escribe lo que sea"<<endl;
      cin>>cadena;
      cout<<endl;
      cout<<flush;
      cout<<"Tu escribiste   "<<cadena<<endl;
      cin>>cadena;
}
