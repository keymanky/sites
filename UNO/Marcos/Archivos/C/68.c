//1 a 255 , octal,
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
//n=numero normal_____oc,oc1=octal_______

int n,oc1,oc;
oc1=-1;
oc=0;
printf("# DECIMAL		#OCTAL			\n");
for (n=0; n<=255; n++)
	{
	printf("%d\t",n);
	oc1=oc1+1;
	printf("%18d\n",oc1);
	if (oc1==7||oc1-oc==7)
		{
		oc1=oc+9;
		oc=oc+10;
		}
	}
system("PAUSE");
return 0;
}
