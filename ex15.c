#include <stdio.h>

int main(int argc, char *argv[]){
// cria dois vetores
	int idades[] = {23, 43, 12, 89, 2};
	char *nomes[] = { "Alan", "Fernando", "Maria", "José", "Lisa"};

// Obt ́em os tamanhos de idades de forma segura
	int contador = sizeof(idades) / sizeof(int);
	int i = 0;

// Primeiro modo: usando  ́ındices
	for(i = 0; i < contador; i++) {
		printf("%s tem %d anos.\n", nomes[i], idades[i]);
	}
	printf("---\n");

// Aponta os ponteiros para o in ́ıcio dos vetores
	int *idade_atual = idades;
	char **nome_atual = nomes;

// Segundo modo: usando ponteiros
	for(i = 0; i < contador; i++) {
		printf("%s viveu %d anos.\n", *(nome_atual+i), *(idade_atual+i));
	}
	
	printf("---\n");

// Terceiro modo: ponteiros s~ao apenas vetores
	for(i = 0; i < contador; i++) {
		printf("%s tem %d anos novamente.\n", nome_atual[i], idade_atual[i]);
	}
	printf("---\n");

// Quarto modo: com ponteiros, mas de maneira complexa
	for(nome_atual = nomes, idade_atual = idades;
		(idade_atual - idades) < contador;
		nome_atual++, idade_atual++){
		printf("%s viveu %d anos até agora.\n", *nome_atual, *idade_atual);
	}
	return 0;
}
