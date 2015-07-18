/****************Operaciones con estructuras**********************************/
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
        int dia,mes,anyo;
}tfecha;

typedef struct
{
        char nombre[40];
        char direccion[40];
        long telefono;
        tfecha fecha_nacimiento;
}tficha;

main()
{
      tficha persona,otra_persona;
      
      printf("Nombre:             ");
      gets(persona.nombre);
      printf("Direccion:          ");
      gets(persona.direccion);
      printf("Telefono:           ");
      scanf("%1d",&persona.telefono);
      printf("Fecha de Nacimiento:\n");
      printf("  Dia:              ");
      scanf("%d", &persona.fecha_nacimiento.dia);
      printf("  Mes:              ");
      scanf("%d", &persona.fecha_nacimiento.mes);
      printf("  Ano:              ");
      scanf("%d", &persona.fecha_nacimiento.anyo);
      
                                                                                //copiar una estructura en otra
      otra_persona=persona;
      printf("\n\n");
      printf("Nombre:  %s\n", otra_persona.nombre);
      printf("Direccion:  %s\n", otra_persona.direccion);
      printf("Telefono    %1d\n",otra_persona.telefono);
      printf("Fecha de nacimiento:\n");
      printf("  Dia:  %d\n", otra_persona.fecha_nacimiento.dia);
      printf("  Mes:  %d\n", otra_persona.fecha_nacimiento.mes);
      printf("  Ano:  %d\n", otra_persona.fecha_nacimiento.anyo);
      
      system("PAUSE");
}
