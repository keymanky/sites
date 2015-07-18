/****************CALCULAR EL VOLUMEN DE UNA ESFERA*****************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float volumen_esfera (float);
main()
{
      float radio;
      printf("\nDAME RADIO DE LA ESFERA \n");
      scanf("%f", &radio);
      printf("EL volumen de la esfera es de %g\n unidades cubicas", volumen_esfera(radio));
      system("PAUSE");
}

float volumen_esfera (float r)
{
      float volume;
      volume= pow(r,3)*12.5664;//multiplique pi * 4 para despues solo dividirlo
      volume= volume/float(3);//aca lo dividi
      return volume;
}
