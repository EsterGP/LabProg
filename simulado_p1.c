/* 	Simulado da P1 de LabProg
	itens feitos:
	1)a)
	item em andamento:
	1)b)
*/
#include <stdio.h>

void maiscula(char vet[]){
	int i;
	for(i=0;vet[i] != '\0';i++)
		if(vet[i]>= 'a' && vet[i]<='z')
			vet[i] = vet[i] + 'A' - 'a';
}

void escreve(char vet[]){
	int i;
	for(i=0;vet[i]!='\0';i++) printf("%c",vet[i]);
	printf("\n");
}

void elimina(char vet[]){
	int i,j,k;
	for(i=j=0;vet[i]!='\0';i++)
		if((vet[i]>='A' && vet[i]<='Z')
			|| vet[i]=='.' || vet[i]==',' || vet[i]==' ')
			vet[j++] = vet[i];

	vet[j] = '\0';
}

void main(){
	char vet_base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
	char vet[] = "a.-b A_cD";
	maiscula(vet);
	escreve(vet);
	elimina(vet);
	escreve(vet);
}
