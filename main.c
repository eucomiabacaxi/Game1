#include <stdio.h>
#define TMAX 100
#define TENTATIVAS 10

void interface() {
	int i;
	for (i = 0; i < 26; i++){
		printf("*");
	}
	putchar('\n');
	printf("*"); printf("\t  M E N U \t"); printf(" *"); putchar('\n');
	printf("*"); printf("\tby:fabioxyz\t"); printf(" *"); putchar('\n');
	printf("*"); printf("\t\t\t *"); putchar('\n');
	printf("*"); printf(" (1) Comecar | (2) Sair "); printf("*"); putchar('\n');
	for (i = 0; i < 26; i++) {
		printf("*");
	}
	putchar('\n');
	putchar('\n');
}

int ler() {
	int e;
		printf(" - ");
		scanf("%d", &e);
	return e;
}

int gerador(int maximo) {
	int numero;
	numero = rand() % maximo;

	return numero;
}

int main() {
	int e, num, n, ch;
	int numcerto;

	interface();
	srand(time(NULL)); // Inicializa o gerador de numeros aleatorios

	do {
		e = ler();
		switch (e) {
		case 1:
			do {
				n = 0;
				numcerto = gerador(TMAX);
				printf("Acerte o numero certo entre 0 a %d\n", TMAX);
				printf("Tentativas restantes : %d\n", TENTATIVAS - n);

				while ((TENTATIVAS - n) != 0) {
					num = ler();
					n++;
					if (num == numcerto) {
						printf("Parabens!!!! Acertou, o numero certo era %d\n\n", num);
						return -1;
					}
					else {
						printf("Errou,agora tem %d tentativas.\n", TENTATIVAS - n);
					}
				}
				printf("\tInfelizmente as suas tentativas esgotaram-se :(\n");
				printf("\t\tO numero certo era %d\n\n", numcerto);
				printf("Recomecar (1) ou sair (2)");
					ch = ler();
					putchar('\n');
			} while (ch != 2);

			printf("\nSaiu.\n\n");

			break;
		case 2: printf("\nSaiu.\n\n");
			return 1; break;
		default: printf("Opcao invalida!\n");
			break;
		}
	} while (e != 1 && e != 2);


	return 0;
}
