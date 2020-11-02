#include<stdio.h>
#include<stdlib.h>
#include <time.h>


int randomNumber(int minimo, int maximo){
    int num;
    num = (rand() %  (maximo - minimo + 1)) + minimo;
    return num;
}

int main(){
    int n_placas = 0;

    printf("Digite o número de placas que deseja: ");
    scanf("%d", &n_placas);    

    srand(time(NULL));
    for(int i=0;i<n_placas;i++){
        printf("%c%c%c-%d%c%d%d%d\n", randomNumber(65,90),randomNumber(65, 90),randomNumber(65, 90),randomNumber(0,10),randomNumber(65, 90),randomNumber(0, 10),randomNumber(0,10),randomNumber(0,10));
    }
    
    return 0;
}