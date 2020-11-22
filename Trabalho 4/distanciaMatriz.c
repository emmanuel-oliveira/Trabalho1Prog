#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 2
//Monta a matriz e multiplica por 3


int randomNumber(int minimo, int maximo){
    int num;
    num = (rand() %  (maximo - minimo + 1)) + minimo;
    return num;
}

int main(){

	int linha, coluna;
    int xa, ya, xb,yb;
    float distancia;
    int linhaInv = 0;
	int matriz[MAX][MAX];
	for(linha=0; linha<=MAX-1;linha++){
		for(coluna=0;coluna<=MAX-1;coluna++){
			matriz[linha][coluna] = randomNumber(0, 10);
		}
	}

    for(linha = 0; linha<=MAX-1;linha++){
        for(coluna=0; coluna<=MAX-1;coluna++){
            printf("%d|",matriz[linha][coluna]);
        }
		printf("\n");
	}

     printf("---------------\n");
     printf("---------------\n");
     for(linha = 0; linha<=MAX-1;linha++){
         if(linha == MAX-1){
            printf("");
        }else{
            xa = matriz[linha][0];
            ya = matriz[linha][0];
            printf("%d|",matriz[linha][0]);
            printf("%d|",matriz[linha][1]);
        }
        
        for(linhaInv=0; linhaInv <=MAX-1; linhaInv++){
            if(linha >= linhaInv){
                printf("");
            }else{
                xb = matriz[linha][0];
                yb = matriz[linha][1];
                printf("%d|",matriz[linhaInv][0]);
                printf("%d|",matriz[linhaInv][1]);
                distancia = (pow(xb-xa) + pow(yb-ya);
            }
        printf("\n");
        }
}
}

