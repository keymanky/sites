//factorial
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
int t,x,y,multi;
printf("EL NUMERO FACTORIAL DE:");
scanf("%d",&t);
y=1;
for(x=1; x<=t; x+=1)
	{
	multi=x*y;
	y=multi;
	}
printf("\n%dES:\n%d\n",t,y);
system("PAUSE");
return 0;
}


