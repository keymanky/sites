#include<stdio.h>
#include<conio.h>
#define n 3
//#define reg struct registro

typedef struct reg
{
	int id_lib;
	char titulo [100];
	char autor [60];
	char editorial [30];
}r;
 main()
{
r biblio[n];
int i;
for(i=0;i<n;i++)
{
	printf("\n dar el id. del libro[%d]",i+1);
	scanf("%d",&biblio[i].id_lib);
	printf("\n dar el titulo del libro[%d]",i+1);
	scanf("%s",&biblio[i].titulo);
	printf("\n dar el autordel libro[%d]",i+1);
	scanf("%s",&biblio[i].autor);
	printf("\n dar la editorial del libro[%d]",i+1);
	scanf("%s",&biblio[i].editorial);
}
printf("\nlos libros contenidos en la biblioteca");
for(i=0; i<n; i++)
{
	printf("\n\n%d\t%s\t%s\t%s",biblio[i].id_lib,biblio[i].titulo,biblio[i].autor,biblio[i].editorial);
}
getche();
}
