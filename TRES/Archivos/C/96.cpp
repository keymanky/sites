#include <stdio.h>
#include <stdlib.h>
main()
{
       FILE *archivo;
       char cadena[100];
       printf("ESCRIBE LO QUE QUIERAS (maximo 100)\n");
       gets(cadena);
       if (!(archivo=fopen("96.-CODIGO.txt","w")))
       {
              printf("Error al abrir el archivo\n");
              system("PAUSE");
              exit(0);
       }
       else
       {
              fputs(cadena,archivo);
              fclose(archivo);
       }
       system("PAUSE");
}
