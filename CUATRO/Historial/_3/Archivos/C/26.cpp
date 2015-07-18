#include <stdio.h>
#include <stdlib.h>
main()
{
  typedef float temperatura;
  typedef float presion;
 
  temperatura t = 23;
  presion p;
  p = t;
  printf("%f",p);
  system("PAUSE");
}

