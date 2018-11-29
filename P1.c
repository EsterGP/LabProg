#include <stdio.h>

void avancar();
void recuar();
void leTexto(char vetor[]);
void leLinha(char vetor[], int lim);
void escreve();

void main(){
	
}

/* Lê o texto chamando a função leLinha
 * a cada linha nova
 */
void leTexto(char vetor[]){
	int lim = 100;
	int i;
	
	for(i=0;vetor[i]!=EOF;i++){
		
	}
}
/* Trata cada linha e trunca quem tem mais de 100 caracteres
 * Dar uma mensagem de erro ao ultrapassar
 */
void leLinha(char vetor[], int lim){
	int c, i;

	for(i=0; i<lim-1&&(c=getchar())!=EOF && c!='\n'; ++i){
		vet[i] = c;
	}
}
