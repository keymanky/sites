#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main( void )
{
   char *directorioPtr, *pathPtr,a[100][100];
   //Obtenemos las rutas activas y la guardamos en pathPrt
   pathPtr = getenv( "PATH" );
   
   puts( "La lista de directorios en el PATH es la siguiente:" );
   //Separamos las rutas que se encuentran en token por ;
   directorioPtr = strtok(pathPtr, ";\n" );
   int j=0,k=0;
   while( (directorioPtr = strtok(NULL, ";\n")) != NULL )
   {	  
	  strcpy(a[j], directorioPtr);
	  j++;              	
   }
   //Las hemos separado y gurdado en el arreglo a

   //Verificamos el contenido de a
   for(k=0;k<=j;k++)
   puts(a[k]);
   
   system("PAUSE");
   return 0;
}
