#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int randomNumber(int minimo, int maximo){
    int num;
    num = (rand() %  (maximo - minimo + 1)) + minimo;
    return num;
}


int main(){
     int n1,n2,n3;
     int condicao = 0;
     float valor_aposta = 0;
	 float inicio_dinheiro = 100;
     int opcao_aposta;
   
    while(condicao == 0){
    	
    printf("Seu saldo: %.2lf\n", inicio_dinheiro);
    printf("Qual valor deseja apostar ?\n");
    printf("1- R$ 1,00\n");
    printf("2- R$ 2,00\n");
    printf("3- R$ 5,00\n");
    printf("4- R$ 10,00\n");
    printf("5- R$ 20,00\n");
    printf("6- R$ 50,00\n");
    printf("7- R$ 100,00\n");
    printf("8- Sair\n");
    scanf("%d", & opcao_aposta);
    	switch (opcao_aposta)
    {
        case 1:
        	valor_aposta = 1;
            inicio_dinheiro = inicio_dinheiro - valor_aposta;
        break;
        case 2:
            valor_aposta = 2;
            inicio_dinheiro = inicio_dinheiro - valor_aposta;
        break;
        case 3:
            valor_aposta = 5;
            inicio_dinheiro = inicio_dinheiro - valor_aposta;
        break;
        case 4:
            valor_aposta = 10;
            inicio_dinheiro = inicio_dinheiro - valor_aposta;
        break;
        case 5:
            valor_aposta =  20;
            inicio_dinheiro = inicio_dinheiro - valor_aposta;
        break;
        case 6:
            valor_aposta = 50;
            inicio_dinheiro = inicio_dinheiro - valor_aposta;
        break;
        case 7:
            valor_aposta = 50;
            inicio_dinheiro = inicio_dinheiro - valor_aposta;
        break;
		case 8:
        	 return 0;
        break;
        default:
            printf("Opcao invalida \n");
            return 0;
    }
    
    printf("Seu saldo: %.2lf\n", inicio_dinheiro);
    printf("-------------------------------\n");
     srand(time(NULL));
     while(!kbhit()){ 
      n1 = randomNumber(0,9);
      n2 = randomNumber(0,9);
      n3 = randomNumber(0,9);
      printf("%d|%d|%d\n", n1, n2, n3);
    }
    
    
    if(n1 == 1 && n2 == 1 && n3 == 1){
    	printf("Voce ganhou 2X\n");
    	valor_aposta = valor_aposta * 2;
    	inicio_dinheiro = inicio_dinheiro + valor_aposta;

	}
    if(n1 == 2 && n2 == 2 && n3 == 2){
    	printf("Voce ganhou 3X\n");
        valor_aposta = valor_aposta * 3;
		inicio_dinheiro = inicio_dinheiro + valor_aposta;
	}
    if(n1 == 3 && n2 == 3 && n3 == 3){
    	printf("Voce ganhou 4X\n");
    	valor_aposta = valor_aposta * 4;
		inicio_dinheiro = inicio_dinheiro + valor_aposta;
	}
    if(n1 == 4 && n2 == 4 && n3 == 4){
    	printf("Voce ganhou 5X\n");
    	valor_aposta = valor_aposta * 5;
		inicio_dinheiro = inicio_dinheiro + valor_aposta;

	}
    if(n1 == 5 && n2 == 5 && n3 == 5){
    	printf("Voce ganhou 6X\n");
    	valor_aposta = valor_aposta * 6;
		inicio_dinheiro = inicio_dinheiro + valor_aposta;

	}
    if(n1 == 6 && n2 == 6 && n3 == 6){
    	printf("Voce ganhou 7X\n");
    	valor_aposta = valor_aposta * 7;
		inicio_dinheiro = inicio_dinheiro + valor_aposta;

	}
    if(n1 == 7 && n2 == 7 && n3 == 7){
    	printf("Voce ganhou 8X\n");
    	valor_aposta = valor_aposta * 8;
		inicio_dinheiro = inicio_dinheiro + valor_aposta;

	}
    if(n1 == 8 && n2 == 8 && n3 == 8){
    	printf("Voce ganhou 9X\n");
    	valor_aposta = valor_aposta * 9;
		inicio_dinheiro = inicio_dinheiro + valor_aposta;

	}
    if(n1 == 9 && n2 == 9 && n3 == 9){
    	printf("Voce ganhou 10X\n");
    	valor_aposta = valor_aposta * 10;
		inicio_dinheiro = inicio_dinheiro + valor_aposta;
	}
	  if(n1 == 0 && n2 == 0 && n3 == 0){
	  	printf("Voce ganhou 1000\n");
		inicio_dinheiro = inicio_dinheiro + 1000;
	}
	  if(n1 == n2 || n1 == n3 || n2 == n3){
	  	printf("Voce ganhou 1.5\n");
    	valor_aposta = valor_aposta * 1.5;
		inicio_dinheiro = inicio_dinheiro + valor_aposta;
	}
	else{
		printf("Nao ganhou\n");
	}
	printf("------------------------\n");
    getch();
    fflush(stdin);
	}
    

    return 0;
}