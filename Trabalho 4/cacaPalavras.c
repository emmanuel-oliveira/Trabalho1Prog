#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_matriz(int tamanho, char grid[tamanho][tamanho+1]) {
	int i;
	int j; 
	printf("\n   "); 
	for (i = 0; i< tamanho; i++){
		printf("%2d  ", i+1);
	}
	printf("\n");
	for (i=0; i < tamanho; i++){
		printf("%2d| ",i+1);
		for (j=0; j<tamanho; j++){
			printf("%c   ", grid[i][j]);
		}
		printf("\n");
	}	
}



void reverso_string(int comprimento, char reverso[comprimento])
{
    char temp [comprimento];
    int i;
    for (i = 0; i< comprimento; i++)
        temp [i] = reverso [comprimento - i];
    reverso = temp;
}

void cria_matriz (int n, char palavras[n][n+1], int numpalavras, int coordPalavras[numpalavras][3], char grid[n][n+1]){
	
	int linhas_usadas[n];	
	memset (linhas_usadas, 0, sizeof(linhas_usadas));
	int i;
	int j; 
	
	for (i=0; i < n*n; i++)
		grid[i/n][i%n] = '0'; 
	for (i=0; i<numpalavras; i++)
		for (j=0; j<3; j++)
			coordPalavras[i][j] = 0;   
	for (i=0; i < n; i++)
		grid[i][n] = '\0'; 
	
	
	for (i=0; i < numpalavras; i++) {
	    int wordLen = strlen(palavras[i]);
	    int reverso = rand() % 2;
	    if (reverso == 1)
	        reverso_string(wordLen, palavras[i]);
		int palavra_x = rand() % (n-wordLen);
		int palavra_y = rand() % n;     
		if (linhas_usadas[palavra_y] == 0){
			strncpy(&grid[palavra_y][palavra_x], palavras[i], wordLen); 
			linhas_usadas[palavra_y] = 1; 
		}
		else{
			while (linhas_usadas[palavra_y] == 1){
				palavra_y = rand() % n; 
			}
		}
		strncpy(&grid[palavra_y][palavra_x], palavras[i], wordLen);  	
		
		coordPalavras[i][0] = palavra_x+1; 	
		coordPalavras[i][1] = palavra_y+1; 						
	}
	for (i=0; i < n*n; i++) {
		if (grid[i/n][i%n] == '0')
			grid[i/n][i%n] = 'A' + rand() % ('Z'-'A'); 
	}	
}


int main(){	 
	
	
	
	int n = 15;
	
	int numpalavras = 10;
	
	char palavras[n][n+1];
	strcpy(palavras[0], "PAYSANDU");
	strcpy(palavras[1], "VASCO");
	strcpy(palavras[2], "FLAMENGO");
	strcpy(palavras[3], "MANAUS");
	strcpy(palavras[4], "FLUMINENSE");
	strcpy(palavras[5], "BOTAFOGO");
    strcpy(palavras[6], "CORINTHIANS");
    strcpy(palavras[7], "CRUZEIRO");
    strcpy(palavras[8], "CRICIUMA");
    strcpy(palavras[9], "BANGU");

	srand(time(NULL));
	int coordPalavras[numpalavras][2];
	char listaFinal[n][n+1]; 
	
	
	
	cria_matriz(n, palavras, numpalavras, coordPalavras, listaFinal);
	print_matriz(n, listaFinal);

	return 0;
}