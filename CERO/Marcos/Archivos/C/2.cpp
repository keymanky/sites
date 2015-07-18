/*USO DE ENUMERADOS*/
#include<stdio.h>
#include<stdlib.h> 
int main ()
{
    enum tipos_coches//nombre de la lista enumerados este servira para declarar variables tipo enumerado
    {
         Nissan,
         Voskvawen,
         Ford,
         Mazda,
         Mitsubisi,// se podria escribir Mitsubis=0 o 1 o 57 un valor entero x, y el siguiente de la lista, en este caso Chevrolet valdra 1 mas que Mitsubisi
         Chevrolet,
         Onda,
         Pagani};
    
    enum tipos_coches carrox;  //declaracion de variable carrox de tipo enum correspondiente a tipos_coches
    
    printf("DAME EL NUMERO DE COCHE");
    scanf("%d",&carrox);
    int x=carrox;
    printf("EL CARRO %d, PERTENECE A: %d\n",x,carrox); //se guarda como entero por lo que saldra entero, no saldra el 
    //nombre de carro,  los tipos enumerados ayudan a acercar mas el lenguaje de alto nivel a nuestra forma de expresarnos
    //en este caso nissan vale 1, voskvawen 2 y asi hasta 8 con pagani.
    system("PAUSE");
    return 0;
}
