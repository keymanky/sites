#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

class Mamifero {   //LA CLASE MAMIFERO ES ABSTRACTA PORQUE NO SE PUEDEN INSTANCIAR DE ELLA . TIENE UN METODO VIRTUAL PURO
   public:
     Mamifero(char *n) { strcpy(nombre, n); }
     virtual void Mostrar() const = 0;
   protected:
     char nombre[30];
};

class Humano : public Mamifero {
   public:
     Humano(char *n, int s) : Mamifero(n), sonido(s) {}
     void Mostrar() const;
     int Leesonido() const { return sonido; }
     void Modificasonido(int s) { sonido = 1; }
   protected:
     int sonido;
};

void Humano::Mostrar() const {
    cout<< "Humano: " << nombre << ", Habla: "  << endl;
}

class Perro : public Mamifero {
   public:
     Perro(char *n, int s) : Mamifero(n), sonido(s) {}
     void Mostrar() const;
     float Leesonido() const { return sonido; }
     void Modificasonido(int s) { sonido = 2; }
   protected:
     float sonido;
};

void Perro::Mostrar() const {
    cout << "Perro: " << nombre 
         << ", Ladra: " << endl;
}

class Gato : public Mamifero {
   public:
     Gato(char *n, int s) : Mamifero(n), sonido(s) {}
     void Mostrar() const;
     float Leesonido() const { return sonido; }
     void Modificasonido(int s) { sonido = 3; }
   protected:
     float sonido;
};

void Gato::Mostrar() const {
    cout << "Gato: " << nombre 
         << ", Maulla: " << endl;
}

class Leon : public Mamifero {
   public:
     Leon(char *n, int s) : Mamifero(n), sonido(s) {}
     void Mostrar() const;
     float Leesonido() const { return sonido; }
     void Modificasonido(int s) { sonido = 4; }
   protected:
     float sonido;
};

void Leon::Mostrar() const {
    cout << "Leon: " << nombre 
         << ", Ruge: " << endl;
}

class Caballo : public Mamifero {
   public:
     Caballo(char *n, int s) : Mamifero(n), sonido(s) {}
     void Mostrar() const;
     float Leesonido() const { return sonido; }
     void Modificasonido(int s) { sonido = 5; }
   protected:
     float sonido;
};

void Caballo::Mostrar() const {
    cout << "Caballo: " << nombre 
         << ", Relincha: " << endl;
}

class Hipopotamo : public Mamifero {
   public:
     Hipopotamo(char *n, int s) : Mamifero(n), sonido(s) {}
     void Mostrar() const;
     float Leesonido() const { return sonido; }
     void Modificasonido(int s) { sonido = 6; }
   protected:
     float sonido;
};

void Hipopotamo::Mostrar() const {
    cout << "Hipopotamo: " << nombre 
         << ", Bramido: " << endl;
}

class Ballena : public Mamifero {
   public:
     Ballena(char *n, int s) : Mamifero(n), sonido(s) {}
     void Mostrar() const;
     float Leesonido() const { return sonido; }
     void Modificasonido(int s) { sonido = 6; }
   protected:
     float sonido;
};

void Ballena::Mostrar() const {
    cout << "Ballena: " << nombre 
         << ", Canta: " << endl;
}

int main() {
    int op;
    char n[30];
    
              Mamifero *persona = new Humano("Jose",1); // (1)
              Mamifero *perro = new Perro("Zury",2);
              Mamifero *gato = new Gato("Bobo",3); 
              Mamifero *leon = new Perro(" ",4); 
              Mamifero *caballo = new Caballo(" ",5);
              Mamifero *hipo = new Hipopotamo(" Wippo",6);
              Mamifero *ballena = new Ballena(" ",7);
     persona->Mostrar();         
     perro->Mostrar(); 
     gato->Mostrar();
     leon->Mostrar();
     caballo->Mostrar();
     hipo->Mostrar();
     ballena->Mostrar();
   delete persona;
   delete perro;
    getch();
   //return 0;
}
