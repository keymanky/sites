#include <dos.h> 
#include <process.h>
#include <time.h> 
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

struct tiempoA{
int horas;
int minutos;
int segundos;
};

void actualiza(struct tiempoA *t)
/*struct tiempoA *t; */
{
    (*t).segundos++;
    if((*t).segundos==60)
    {
        (*t).segundos=0;
        (*t).minutos++;
    }
    if((*t).minutos==60)
    {
        (*t).minutos=0;
        (*t).horas++;
    }
    if((*t).horas==24) 
        (*t).horas=0;
    /*delay();*/
}

void visualiza(struct tiempoA *t)
/*struct tiempoA *t;*/
{
    printf("CRONOMETRO\n");
    printf("%d:",(*t).horas);
    printf("%d:",(*t).minutos);
    printf("%d\n",(*t).segundos);
    system("cls");
}

main()
{
      //Inicio del cronometro
    struct tiempoA hora;
    hora.horas=0;
    hora.minutos=0;
    hora.segundos=0;
    
    for(;;)
    {
    actualiza(&hora);
    visualiza(&hora);
    }
}
