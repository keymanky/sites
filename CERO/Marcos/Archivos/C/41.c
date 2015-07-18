#include <stdlib.h>
#include <stdio.h>
main()
{
int     *p_int;
float   *mat;
p_int = (int *)  malloc(sizeof(int));
mat   = (float *)calloc(20,sizeof(float));
if ((p_int==NULL)||(mat==NULL))
                {
                printf ("\nNo hay memoria");
                exit(1);
                }
system("PAUSE");
}
