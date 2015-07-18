/******************************************************************************/
/***********M O D U L O 3  G E N E R A  C O D I G O   D E   V E N T A**********/
/******************************************************************************/

/******************************************************************************/
/*INTEGRANTES DEL EQUIPO  MATERIA PROGRAMACION Y LENGUAJES DE PROGRAMACION  2254
-	José Javier Ascencio Sánchez
-	Elihu Hernández Hernández
-	Omar Rodríguez Ordaz
-	Jorge Salgado Mendoza
-	Daniel Sánchez Ferriz
*/

#include <stdio.h>
#include <stdlib.h>

void GeneraCod();     
int verifica_ean(char codi[13]); 


main() //EMULANDO LA MAIN PRINCIPAL DEL PRYECTO
{
      int n;
      printf("MENU PRINCIPAL\n1.- Para funcion generacod\n2.- Salir\n");
      scanf("%d", &n);
      if(n==1)
         {
         GeneraCod(); 
         main();//FORZOZO PONER DEBAJO DE LLAMAR A LA FUNCION
         }
      
}

void GeneraCod()//FUNCION DESARROLLADO POR EQUIPO 3
{
     FILE *archivo;
     char cad[1];
     archivo=fopen("VentaBatch.txt","a");
     //fprintf(archivo,"CODIGO \t ARTICULOS\n");
     fclose(archivo);
     int x,b,i;
     do{
     struct VtaBatch{
           char ean[13];
           int vtaB;
           }VtaBch;
     printf("DAME EL CODIGO DE BARRAS\n");
     scanf("%s",VtaBch.ean);
     b = verifica_ean(VtaBch.ean); 
     if(b==1)
        {
        cad[0]=VtaBch.ean[0];
        i=atoi(cad);
        if(i==2)
                VtaBch.vtaB=0;
        else
        {
        printf("\nDAME EL NUMERO DE ARTICULOS VENDIDOS\n");
        scanf("%d",&VtaBch.vtaB);
        }
        archivo=fopen("VentaBatch.txt","a");
        fprintf(archivo,"%s \t%d\n",VtaBch.ean,VtaBch.vtaB);
        fclose(archivo);
        printf("\nSE ANADIO CORRECTAMENTE a VentaBatch.txt\n");
        }
     else
        {
         printf("\n\tERROR DE CODIGO\n");
        // main();
        }
     printf("\n\tDesea anadir otro registro (presione 1) sino presione otro numero\n");
     scanf("%d",&x);
     }while(x==1);
}
     

int verifica_ean(char codi[13]) //EMULANDO LA FUNCION DEL EQUIPO 1
{
    printf("\n\tDENTRO DE VERIFICA_EAN %s\n\t", codi);//comprobar que se paso corrrectamente el codigo
    return 0;//LO QUE RETORNARA si es valido se puede cambiar para probar que este modulo funciona tanto para 0 y para 1
}
