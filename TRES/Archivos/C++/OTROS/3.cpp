#include<stdio.h>
#include<iostream.h>
#include<conio.h>
template<class T>
class PILA
{
  typedef struct nodito
  {
   T num;
   struct nodito *p;
  }n;
  n *tope;

   public:
	PILA();
	void push(T);
	void pop();
	void eliminapila();
	void buscar();
	void vercontenido();
	void verultimo();
	~PILA();
};

template<class T>PILA<class T>::PILA()
{
 tope=NULL;
}


template<class T> void PILA<class T>::push(T nd)
{
 n *nvo;
 if((nvo=new n)!=NULL)
  {
   nvo->num=nd;
   if(tope==NULL)
    {
      nvo->p=NULL;
      tope=nvo;
    }
   else
    {
      nvo->p=tope;
      tope=nvo;
    }
  }
 else
  {
   cout<<"Ya no hay memoria para crear nodos";
  }
}


template<class T> void PILA<class T>::pop()
{
  n *aux=tope;
  if( tope==NULL)
    {
     cout<<"La pila est  vacia";
    }
  else
    {
     cout<<"Sale: "<<aux->num;
     tope=aux->p;
     delete(aux);
    }
}


template<class T> void PILA<class T>::eliminapila()
{
  while(tope!=NULL)
   {
    pop();
   }
}


template<class T> void PILA<class T>::vercontenido()
{
  n *aux=tope;
  while(aux!=NULL)
   {
     cout<<aux->num<<endl;
     aux=aux->p;
   }
}

template<class T> PILA<class T>::~PILA()
{
 eliminapila();
}


void main()
{
 clrscr();

 PILA<int> P1;
 PILA<float> P2;
 PILA<char> P3;
 P1.push(10);
 P1.push(20);
 P1.push(30);
 P2.push(2.5);
 P2.push(3.1416);
 P3.push('A');
 P3.push('B');
 P3.push('C');
 P1.vercontenido();
 P2.vercontenido();
 P3.vercontenido();
 getch();
 P1.pop();
 P2.pop();
 P1.vercontenido();
 P2.vercontenido();
 getch();
 }

