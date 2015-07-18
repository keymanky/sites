#include<stdio.h>
#include<stdlib.h>
void calendario_2(int ano);
void calendario(int mes, int ano);
int bisiesto (int ano);
main()
{
 	  int ano,mes;
 	  printf("Ingrese un ano para ver el calendario: ");
 	  scanf("%d", &ano);
	  calendario_2(ano);
 	  system("PAUSE");
 	  system("cls");
 	  printf("Ingrese un mes: ");
 	  scanf("%d", &mes);
 	  printf("Ingrese un ano: ");
 	  scanf("%d", &ano);
 	  calendario(mes, ano); 
 	  system("PAUSE");
}
void calendario(int mes, int ano)                                               //el primer dia de 1990 fue lunes en base a ello se asigno 1 al lunes, hasta 7 domingo. Con ello se inciaron 2 ciclos que cuentan los dias transcurridos de 1990 hasta un mes antes del solicitado. y a esta cantidad le resta de 7 en 7 hasta obtener un numero en rango del 1al7.Si es 1 el numero significa que el MES ANTERIOR AL SOLICITADO ACABO EN LUNES, y el CALENDARIO debe de empezar en Martes;POR ESO le sumo 1 a la cantidad total de dias antes de restarle multiplos de 7.Finalmente resta imprimir en forma de tabla.
{
     if(mes<1||mes>12)
           printf("Mes invalido\n");
     else if (ano<1990|| ano>100000)
           printf("Ano invalido\n");
     else                                                                       //ejecuta el proceso completo
     {
         int mes_predeterminado[12]={31,0,31,30,31,30,31,31,30,31,30,31};       //dias que tienen los meses, 0 para febrero porque no se si es 28 o 29, lo averiguare con la funcion bisiesto
         int suma_anos=0,suma_meses=0,ano_predeterminado=1990,diferecia,contador=1,x,y,diferencia,suma_total,dias_imprimir;
         
         for(ano_predeterminado;ano_predeterminado<ano;ano_predeterminado++)    //ciclo que cuenta cuantos anos han pasado desde 1990 hasta 1 antes del solicitado, y por cada ano suma 365 o 366 en funcion del ano                                                                                      
         {
              if(bisiesto(ano_predeterminado)==1)
                   suma_anos=suma_anos+366;
              else
                   suma_anos=suma_anos+365;
         }
         
         for(x=0;x<mes-1;x++)                                                   //ciclo que suma los dias de los meses hasta 1 antes del solicitado
         {
              if(x==1)
              {
                      y=bisiesto(ano);
                      if(y==1)
                              mes_predeterminado[1]=29;
                      else
                              mes_predeterminado[1]=28;
              }
              suma_meses=suma_meses+ mes_predeterminado[x];
         }
         
         suma_total=suma_anos+suma_meses;
         diferencia=suma_total+1;                                               //suma 1 para que empieze en el dia solicitado
         
         while(diferencia>7)                                                    //ciclo que resta de 7 en 7 hasta obtener un numero del 1-7 y ver en que dia empieza dicho mes
               diferencia=diferencia-7;
               
         printf("L\tM\tMi\tJ\tV\tS\tD\n");
         for(x=1;x<diferencia;x++)                                              //ciclo que imprime tabulaciones dependiendo del dia inicial del mes
         {
               printf("\t");
               contador++;
         }
         
         dias_imprimir=mes_predeterminado[mes-1];                               //determina si imprime 28 o 29
         if(dias_imprimir==0)
              dias_imprimir=bisiesto(ano)+28;
         
              
         for(x=1;x<=dias_imprimir;x++)                                          //ciclo que imprime el mes
         {
              printf("%d\t",x);
              if(contador%7==0)
                   printf("\n");
              contador++;
         }
         printf("\n");
     }
}
//78
//FUNCION QUE IMPRIME EL CALENDARIO DE UN ANO
void calendario_2(int ano)
{
int x;
      for(x=1;x<=12;x++)
      {
         switch(x)
         {
                  case 1:
                  {
                        printf("\nENERO\n");
                        break;
                  }
                  case 2:
                  {
                        printf("\nFEBRERO\n");
                        break;
                  }
                  case 3:
                  {
                        printf("\nMARZO\n");
                        break;
                  }
                  case 4:
                  {
                        printf("\nABRIL\n");
                        break;
                  }
                  case 5:
                  {
                        printf("\nMAYO\n");
                        break;
                  }
                  case 6:
                  {
                        printf("\nJUNIO\n");
                        break;
                  }
                  case 7:
                  {
                        printf("\nJULIO\n");
                        break;
                  }
                  case 8:
                  {
                        printf("\nAGOSTO\n");
                        break;
                  }
                  case 9:
                  {
                        printf("\nSEPTIEMBRE\n");
                        break;
                  }
                  case 10:
                  {
                        printf("\nOCTUBRE\n");
                        break;
                  }
                  case 11:
                  {
                        printf("\nNOVIEMBRE\n");
                        break;
                  }
                  case 12:
                  {
                        printf("\nDICIEMBRE\n");
                        break;
                  }
         }
         calendario(x,ano);
      }
      system("PAUSE");
}
int bisiesto (int ano)
{                                                                               //un ano bisiesto es aquel divisible por 4, excepto si es divisible por 100 pero si por 400 
    if (ano % 4 == 0)
       {
            if (ano %100==0)
            {
                    if(ano%400==0)
                       return 1;
                    else
                       return 0;
            }
            else
               return 1;
       }
    else
       return 0;
}
