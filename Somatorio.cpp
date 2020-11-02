#include <stdio.h>
#include <math.h>

int main(){

    int quant_numeros_na_sequentcia = 5;
    int numerador = 2;
    int divisor = 2;
    //int contador = 0;

    int numeradorDisplay; 
    int divisorDiplay = divisor;

    double somatorio = 0.0;
    double aux = 0.0;


    for(int j = 0; j<= quant_numeros_na_sequentcia -2; j++){
        divisorDiplay = divisorDiplay *(3+j);
    }

    int i = 0;
    for(i; i <= quant_numeros_na_sequentcia - 1; i++){

        if(aux==0){
            aux = numerador / (divisor * 1.0);
        }else{
            aux = aux - numerador / (divisor * 1.0);
        }


      
        if (i % 2 == 1) {
           somatorio = somatorio + aux;
           aux=0;
        }
        
        if(i >= 0){
            numerador = numerador * 2;
            divisor = divisor * (3+i);
        }   
    }
    

    if (aux != 0){
        somatorio += aux;
    }


    printf("\n-----------------------Somatorio-----------------------\n");
    numeradorDisplay = pow(2, quant_numeros_na_sequentcia);
    printf("%d/%d\n", numeradorDisplay, divisorDiplay);
    printf("%lf \n", somatorio);

}