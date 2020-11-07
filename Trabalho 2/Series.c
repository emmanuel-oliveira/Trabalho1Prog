#include <stdio.h>
#include <math.h>

# define QTD_LOOPS 10000000

# define _USE_MATH_DEFINES

int Leibniz(){
   float pi = 4;
   float operador = -1;

   float i;
   for(i = 0; i < QTD_LOOPS; i++){
      pi += operador*(4/(3+2*i));

      operador *= -1;
   }


   printf("Resultado: %lf\n", pi);
   printf("M_PI: %lf\n", M_PI);
   printf("Diferenca: %lf\n",  pi - M_PI);
   return 0;
}

float fatorial(int termos){
   float aux;
   aux = termos;
   while(termos > 1)
   {
      aux = aux * (termos - 1);
      termos--;
   }    
   return aux;
}

float serieMaclaurinSen(float x, int N){
  printf("Seno de %.0f\n", x);
  
  x = fmod(x, 360);  
  float original = x*M_PI/180;
  
  if (x >= 180) {
    x -= 180;
    x = -x;
  } else if (x <= -180) {
    x += 180;
    x = -x; 
  }

  if (x >= 90) {
    x = 180 - x;
  } else if (x <= -90) {
    x = -180 - x;
  }
   
  x = x*M_PI/180;
  printf("Serie de Maclaurin: %lf\n", x);
  printf("Funcao seno: %lf\n", sin(original));
  printf("Diferenca: %lf", x - sin(original));
}


float serieMaclaurinCos(float x)
{
	printf("Coseno de %.0f\n", x);

    int i, j, aux = 1;
    float angulo, produto, soma = 0.0;
	angulo =  x*M_PI/180;
    
    while (angulo >= (2*M_PI))
        angulo -= (2*M_PI);

    for (i = 0; i < 100; i++)
    {
        produto = 1.0;
        for (j = (2*i); j > 0 ; j--)
            produto *= angulo / j;

        soma +=  produto * aux;
        aux = -aux;
    }
    
	printf("Serie de Maclaurin Coseno: %f\n", soma);
    printf("Funcao coseno: %lf\n", cos(angulo));
    printf("Diferenca: %lf\n", soma - cos(angulo));
}


int main(){
	int escolha = 0;
	printf("1 - Leibniz\n");
	printf("2 - Serie de Maclaurin Seno\n");
	printf("3 - Serie de Maclaurin Coseno\n");
	scanf("%d",& escolha);
	printf("--------------------------------------------\n");
	switch (escolha) {
	    case 1:
	       Leibniz();
	       break;
	    case 2:
	        serieMaclaurinSen(30,5);
	       break;
	    case 3:
	    	serieMaclaurinCos(30);
	    default:
	       return 0;
	 }
}