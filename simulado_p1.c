/* 	Simulado da P1 de LabProg
	itens feitos:
	1)a)b)c)
	item em andamento:
	2)
*/
#include <stdio.h>

void escreve(char vetor[]);
void maiscula(char vet[]);
void elimina(char vet[]);
void exclui(char vet[], int posicao);
void completa(char vet[], char vet_base[], char vet_chave[]);

void main(){
	char vet_base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
	char vet[] = "Celacanto provoca maremoto";
	char vet_chave[29];
	char vet_frase[] = "CELACANTO PROVOCA MAREMOTO";

	maiscula(vet);
	escreve(vet);
	elimina(vet);
	escreve(vet);
	completa(vet,vet_base,vet_chave);
	escreve(vet_chave);
}

void escreve(char vet[]){
	int i;
	for(i=0;vet[i]!='\0';i++) printf("%c",vet[i]);
	printf("\n");
}

void maiscula(char vet[]){
	int i;
	for(i=0;vet[i] != '\0';i++)
		if(vet[i]>= 'a' && vet[i]<='z')
			vet[i] = vet[i] + 'A' - 'a';
}

void elimina(char vet[]){
	int i,j,k;
	int tem = 0;
	for(i=j=0;vet[i]!='\0';i++)
		if((vet[i]>='A' && vet[i]<='Z')
			|| vet[i]=='.' || vet[i]==',' || vet[i]==' ')
			vet[j++] = vet[i];

	vet[j] = '\0';

	for(i=1;vet[i] != '\0';i++){
		for(j=0;!tem && j<i;j++)
			if(vet[i]==vet[j]) tem = 1;
		if(tem){
			exclui(vet,i--);
			tem = 0;
		}
	}	
}

void exclui(char vet[], int posicao){
	int i;
	for(i=posicao;vet[i]!='\0';i++){
		vet[i] = vet[i+1];
	}
}

void completa(char vet[], char vet_base[], char vet_chave[]){
	int i,j,k=0;
	int tem = 0;
	for(i=0;vet[i]!='\0';i++)
		vet_chave[i] = vet[i];
	k=i;
	
	for(i=0;vet_base[i] != '\0';i++){
		for(j=0;vet[j] != '\0' && !tem;j++)
			if(vet_base[i]==vet[j]) tem = 1;
		if(!tem){
			vet_chave[k++] = vet_base[i];
		}
		tem = 0;
	}
	vet_chave[k] = '\0';
}
