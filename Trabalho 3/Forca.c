#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>


int randomNumber(int minimo, int maximo){
    int num;
    num = (rand() %  (maximo - minimo + 1)) + minimo;
    return num;
}

const char* readWord(){
    int i = 0;
    int numPalavras = 0;
    char* palavras[50];
    char line[50];
    int size = 0;
    FILE *arquivo;
    arquivo = fopen("palavras.txt", "r");

    if (arquivo == NULL)
        return "false";

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        palavras[i] = strdup(line);

        i++;

        numPalavras++;
    }

    int j;
    srand(time(NULL));
    int escolha = randomNumber(0, numPalavras-1);
    for (j = 0; j < numPalavras -1; j++){
        size = strlen(palavras[j]); 
        palavras[j][size-1] = '\0';
     }

    fclose(arquivo);
    
    return palavras[escolha];

}

int main() {
	char voltar;
	char palavra[12];
	char acertos[12];
	char palpite;
    int contemPalpite =0;
	int opc = 0;
    int menor_quantidade = 9999;

	while (opc != 2) {

		char letrasUsadas[26];
		int numLetrasUsadas = 0;
		int usada;
		int erros = 0;

		do {

			system("cls");

			for (int i = 0; i < strlen(letrasUsadas); i++) {
				letrasUsadas[i] = '*';
			}

			printf(
					"#################################### Forca #####################################");
			printf("\n\n 1- Jogar: ");
			printf("\n\n 2 - Sair: ");
			printf("\n\n Escolha: ");
			scanf("%d", &opc);

			if (opc == 1) {

                const char* aux = readWord();
                strcpy(palavra, aux);

				for (int i = 0; i < strlen(palavra); i++) {
					palavra[i] = toupper(palavra[i]);
				}

			} else if (opc == 2) {
				break;
			}

		} while (opc != 1 && opc != 2);

		if (opc != 2) {

			for (int i = 0; i < strlen(palavra); i++) {
				acertos[i] = '*';
			}

			acertos[strlen(palavra)] = '\0';

			while (strcmp(palavra, acertos) != 0 && erros != 5) {

				system("cls");

				printf(
						"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX Forca XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
				printf("\n\n  Letras usadas: ");

				for (int i = 0; i < numLetrasUsadas; i++) {
					printf("%c ", letrasUsadas[i]);

				}
                printf("Erros: %d", erros);

				switch (erros) {
				case 0:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####            \n");
					printf("  ####            \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 1:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 2:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 3:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|    \n");
					printf("  ##       / |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 4:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\  \n");
					printf("  ##       / | \\ \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 5:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *X X*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\   \n");
					printf("  ##       / | \\  \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##        / \\   \n");
					printf("  ##       /   \\  \n");
					break;
				}
				printf("  ##               \n");
				printf("  #######################\n\n  ");

				for (int i = 0; i < strlen(palavra); i++) {
					if (acertos[i] == '*') {
						printf("_ ");
					} else {
						printf("%c ", acertos[i]);
					}
				}

				if (strcmp(palavra, acertos) != 0 && erros != 5) {

					usada = 0;

					printf("\n\n  Digite seu letra: ");
					scanf(" %c", &palpite);
					palpite = toupper(palpite);

					for (int i = 0; i < 26; i++) {
						if (letrasUsadas[i] == palpite) {
							usada = 1;
						}
					}

					if (usada == 0) {
						letrasUsadas[numLetrasUsadas] = palpite;
						numLetrasUsadas++;

						contemPalpite = 0;

						for (int i = 0; i < strlen(palavra); i++) {
							if (palpite == palavra[i]) {
								acertos[i] = palpite;
								contemPalpite = 1;
							}
						}

						if (contemPalpite == 0) {
							erros++;
						}
					}

				}

			}

			if (erros >= 5) {
                printf("\n  Erros:%d\n", erros);
				printf("\n  Você perdeu! =(\n  A palavra era %s", palavra);
			} else {
                printf("\n  Erros:%d\n", erros);
				printf("\n  Você ganhou! :D A palavra era %s", palavra);
                if(erros <= menor_quantidade){
                    menor_quantidade = erros;
                    printf("\n  Você bateu o recorde, parabéns");
                }else{
                    printf("\n  Recorde atual: %d", menor_quantidade);
                }
			}

			printf("\n\n  Digite 0 para voltar ao menu: ");
			scanf(" %c", &voltar);
		}

	}

	return 0;
}