/********************PROGRAMA QUE CALCULA UNA SUMATORIA************************/
#include <stdio.h>
#include <stdlib.h>
float sumatoria(int, int, float, float);
main()
{
      int i,s;
      float x,y;
      printf("Dame limite inferior;  Dame limite superior;   Dame x;   Dame y");
      scanf("%d %d %f %f",&i,&s,&x,&y);
      printf("%f",sumatoria(i,s,x,y));
      system("PAUSE");
}
/**************FUNCION QUE EVALUA UNA SUMATORIA********************************/
float sumatoria(int i, int n, float x, float y)//el primer argumento es limite inferior, el segundo es el superior, los otros 2 son personalizados cada vez
{
      float suma=0,b;
      for(i;i<=n;i++)
      {
                     b=(float)1/(x+(i*y));
                     suma= suma+ b;
                     printf("%f\n",suma);
                     }
      return suma;
}      
