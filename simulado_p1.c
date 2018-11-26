/* 	Simulado da P1 de LabProg
	itens feitos:
	1)a)b)
	item em andamento:
	1)c)
*/
#include <stdio.h>
#include <string.h>

void escreve(char vet[]);
void maiscula(char vet[]);
void elimina(char vet[]);
void exclui(char vet[], int posicao);

void main(){
	char vet_base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
	char vet[] = "a.-b A_cD";
	maiscula(vet);
	escreve(vet);
	elimina(vet);
	escreve(vet);
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
		for(j=0;j<i-1;j++)
			if(vet[i]==vet[j]) tem = 1;
		if(tem){
			exclui(vet,i);
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
