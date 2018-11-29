#include <stdio.h>

void leTexto(char vetor[]);
void escreve(char vetor[]);
void maiuscula(char vetor[]);
void minuscula(char vetor[]);
void avancar();
void recuar();

int main(){
	char textoIn[3000];
	leTexto(textoIn);
	escreve(textoIn);
	
	return 0;
}

/* Lê o texto */
void leTexto(char vetor[]){
	int lim = 10; //limite de entrada por linha
	int i, j, k=0, c;
	
	c=getchar();
	for(i=0;c!=EOF;i++){
		if(i==0) vetor[k++] = c;
		/* Trata cada linha e trunca quem tem mais de 100 caracteres
		 * Dar uma mensagem de erro ao ultrapassar
		 */
		for(j=0;j<lim && (c=getchar()) != EOF && c != '\n'; ++j){
			if(c == '\n' || c == '\t') c = ' ';
			vetor[k++] = c;
		}
		if(j==lim) while(getchar() != '\n');
		if(c != EOF) vetor[k++] = ' ';
	}
	vetor[k] = '\0';
}

void escreve(char vetor[]){
	int i, max = 8;
	for(i=0;vetor[i]!='\0';i++){
		if((i+1)%max == 0) printf("\n");
		printf("%c",vetor[i]);
	}
	printf("\n");
}
