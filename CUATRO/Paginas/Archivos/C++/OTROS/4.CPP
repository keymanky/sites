#include <iostream.h>
#include <conio.h>
#include <stdio.h>
template <class L>

class LISTAORD
{
	typedef struct nodo
	{
	L n;
	struct nodo *p;
	}sn;


	sn *inic;

	public:
	LISTAORD(){inic=NULL;}
	void insertar(L);
	void sacar(L);
	void borrar(); //Toda la lista
	void imprime();
	~LISTAORD();
};

template<class L>void LISTAORD<class L>::insertar(L nd)
{
sn *aux=inic; //Inicio
sn *nvo;
sn *aux2=NULL;
nvo=new sn;
	nvo->n=nd;
	if(nvo==NULL)
	{
	cout<<"No se pudo crear el nodo";
	return;
	}

	if(inic==NULL)
	{
	inic=nvo;
	nvo->p=NULL;
	}
	else
	{
		while((aux->p!=NULL)&&(nd>aux->n))
		{
		aux=aux->p;
		}
		if(nd>aux->n)
		{
		aux->p=nvo;      //<------FINAL
		nvo->p=NULL;
		}
		else if(nd<aux->n)
		{
			if(aux2!=NULL)
			{
			nvo->p=aux;
			aux2->p=nvo;   //<-------MEDIO
			}
			else
			{
			nvo->p=inic;
			inic=nvo;
			}             //<-------------INICIO
		}
		else
			{
			cout<<"Ya existe el nodo \n";
			}
		}
	}

template<class L>void LISTAORD<class L>::imprime()
{
 sn*aux=inic;
 if(aux==NULL)
 {
 cout<<"Lista vacia";
 }
 else
 {
	cout<<"El contenido de la lista"<<endl;
	while(aux!=NULL)
	{
	cout<<aux->n<<endl;
	aux=aux->p;
	}
 }
}

template<class L>void LISTAORD<class L>::sacar(L y=0)
{
sn*aux=inic;
sn*aux2=NULL;
	if(aux==NULL)
	{
	cout<<"La lista esta vacia";
	}
	else if(y==0)
	{
	cout<<"Sale:"<<aux->n<<endl;
	inic=aux->p;
	delete(aux);
	}
	else
	{
	   while(aux!=NULL)
	   {
	      if(aux->n == y)
	      {
		 aux2->p=aux->p;
		 delete(aux);
	      }
	   aux2=aux;
	   aux=aux->p;
	   }
	}
}

template <class L>void LISTAORD<class L>::borrar()
{
//sn*aux=inic;
while(inic!=NULL)
{
   sacar(0);

}
}
template<class L>LISTAORD<class L>:: ~LISTAORD()
{ borrar();   }


void main()
{
clrscr();
cout<<"LISTA DE ENTEROS"<<endl;
LISTAORD <int> L1;
L1.insertar(9);
L1.insertar(1);
L1.insertar(-3);
L1.insertar(12);
L1.imprime();
getch();
//L1.sacar();
//L1.sacar();
L1.imprime();
cout<<"Borramos la lista ..."<<endl;
L1.borrar();
getch();
L1.imprime();
getch();
cout<<endl;
cout<<"LISTA DE FLOTANTES"<<endl;
LISTAORD <float> L2;
L2.insertar(9.43);
L2.insertar(1.43);
L2.insertar(-3.22);
L2.insertar(12.44);
L2.imprime();
getch();
//L1.sacar();
//L1.sacar();
L2.imprime();
cout<<"Borramos la lista ..."<<endl;
L2.borrar();
getch();
L1.imprime();
getch();
}