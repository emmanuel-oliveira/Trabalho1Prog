#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int randomNumber(int minimo, int maximo){
    int num;
    num = (rand() %  (maximo - minimo + 1)) + minimo;
    return num;
}


int main(){

    int i,j, intervalo, aux, trocado;
    int tamanho;
    srand(time(NULL));


    tamanho = randomNumber(2,100);
    printf("Tamanho %d\n", tamanho);
    
    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = randomNumber(-100, 100);
    }

    trocado = 1;
    intervalo = tamanho;

    while(intervalo > 1 ||  trocado == 1){
        intervalo = intervalo * 10/13;
        if(intervalo ==9 || intervalo == 10){
            intervalo = 11;
        }
        if(intervalo < 1){
            intervalo = 1;
        }
        trocado = 0;

        for (i = 0, j = intervalo; j < tamanho; i++, j++)
        {
            if (vetor[i] > vetor[j]) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            trocado = 1;
            }
        }

    }
    printf("xxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("[");
    for(int i=0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("]");
    printf("\n");
}