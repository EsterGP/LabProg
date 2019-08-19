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

void elimina(char vet[], char vet_base[], int vet_base_cont[]){
	int i,j,k;
	for(i=j=0;vet[i]!='\0';i++)
		if((vet[i]>='A' && vet[i]<='Z')
			|| vet[i]=='.' || vet[i]==',' || vet[i]==' ')
			vet[j++] = vet[i];

	vet[i] = '\0';

	for(i=0;vet_base[i]!='\0';i++)
		for(j=0;vet[j]!='\0';j++)
			if(vet_base[i] == vet[j])
				if(vet_base_cont[i]!=0)
					j--;
				else
					vet_base_cont[i]++;
	vet[j] = '\0';
}

void main(){
	char vet_base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
	int vet_base_cont[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char vet[] = "a.-b A_cD";
	maiscula(vet);
	escreve(vet);
	elimina(vet,vet_base,vet_base_cont);
	escreve(vet);
}
