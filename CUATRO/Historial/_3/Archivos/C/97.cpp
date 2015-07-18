#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void anadir();
void mirar();
void borrar();

main()
{
  int op,i,n;
  char q;
  printf("1.-A�adir numero telefonico\n2.-Mirar numero ya existente\n3.-Borrar\n");
  printf("digite numero de la opcion ");
  scanf("%d",&op);
  //Valida si la opcion existe
  while(op<1||op>3)
  {
    printf("opcion incorrecta ");
    scanf("%d",&op);
  }
  
  switch(op)
  {
    case 1:
    {
       printf("cuantos numeros vas a aÃ±adir? ");
       scanf("%d",&n);
       for(i=1;i<=n;i++)
         anadir();
    break;        
    }
    case 2:
    {
       mirar();
       printf("salir? s o n %c");
       scanf("salir? s o n %c", &q);
       break;
    }
    case 3:
    {
         borrar();
         break;
    }
  }
}

void anadir()
{
  FILE *fp;
  char nombre[50];
  int numero;
  fp=fopen("telefono.txt","a");
  if(fp==NULL)
  {
    printf("no se puede abrir el archivo ");
    exit(0);
  }
  else
  {
    printf("ingresa nombre y numero de telefono a aÃ±adir ");
    fscanf(stdin,"%s%d",&nombre,&numero);
    fprintf(fp,"%s  %d\n",nombre,numero);
    printf("aÃ±adido con exito\n");
    fclose(fp);
  }
}

void mirar()
{
  FILE *fp;
  char nombre[50],nombre2[50];
  int numero;
  fp=fopen("telefono.txt","r");
  if(fp==NULL)
  {
    printf("no se puede abrir el archivo ");
    exit(0);
  }
  else
  {
    printf("nombre ");
    scanf("%s",&nombre);
    while(!feof(fp)){
      fscanf(fp,"%s%d",&nombre2,&numero);
      if(!strcmp(nombre,nombre2)){
         printf("%s:  %d",nombre,numero);
         /*getchar();*/
         system("pausa");
         break;
         }
     }
  }
}

void borrar()
{
     FILE *fp;
     remove("telefono.txt");
}
