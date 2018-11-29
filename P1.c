#include <stdio.h>
#define AVANCA 1
#define RECUA 0

void leTexto(char vetor[]);
void escreve(char vetor[]);
void criptografa(char vetor[], int vet_num[]);
void maiuscula(char vetor[], int c);
void minuscula(char vetor[], int c);
void avancar();
void recuar();

int main(){
	char textoIn[3000];
	int vet_num[12]; //porque a matricula tem 12 dígitos
	leTexto(textoIn, 3000);
	criptografa(textoIn, vet_num);
	escreve(textoIn);
	
	return 0;
}

/* Lê o texto */
void leTexto(char vetor[], int max){
	int lim = 100; //limite de entrada por linha
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
	int i, max = 80;
	for(i=0;vetor[i]!='\0';i++){
		if((i+1)%max == 0) printf("\n");
		printf("%c",vetor[i]);
	}
	printf("\n");
}

void criptografa(char textoIn[], int vet_num[]){
	int i;
	sentido = AVANCA;
	for(i=0;vetor[i]!='\0';i++){
		if()
	}
}

void maiuscula(char vetor[], int c){
	char base[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

void minuscula(char vetor[], int c){
	char base[] = " abcdefghijklmnopqrstuvwxyz";
}

void avancar(){
}

void recuar(){
}
