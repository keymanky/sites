/****************EVALUA UN POLINOMIO PREVIAMENTE PROGRAMADO*****************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h> //necesario para funcion pow


main()
{
      float  xi,x,a,b,c,d;
      printf("\nDame el valor de x_a_b_c_d\n");
      scanf("%f %f %f %f %f", &x, &a, &b, &c, &d);
      xi=(a*pow(x,5))-(b*pow(x,3))+(x*c)-d;
      printf("\nEL VALOR DE X EN EL POLINOMI aX^5-bX^3+cX-d %g\n",xi);
      system("PAUSE");
}
