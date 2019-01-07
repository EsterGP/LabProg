#include <stdio.h>
#include <stdlib.h>


void trocalinha(int valores[], int n);
void direita(int valores[], int n);
void girahorario(int valores[], int n);
void resolve(int valores[]);


int escreve_cubo(int valores[]){
	printf("-----------------\n");
	printf("| %d | %d | %d | %d |\n",valores[0],valores[1],valores[2],valores[3]);
	printf("|---+---+---+---|");
	printf("\n| %d | %d | %d | %d |\n",valores[4],valores[5],valores[6],valores[7]);
	printf("-----------------\n");
	
	return 0;
}

int main(){
	int tamanho_entrada = 8;
	int entrada[] = {1,2,3,4,5,6,7,8};
	int op;
//	int i=0, c;
/*
	FILE *arq = fopen( "arquivo.txt" , "r" ); 
	
	while( (c = fgetc(arq)) != EOF){
		if(c != ' ')
			entrada[i++] = c;
	}
	
	printf("%s", entrada);
*/

	escreve_cubo(entrada);

	printf("A: trocar de linha\nB: girar para a direita\nC: girar os 4 elementos centrais no sentido horario\nQ: Sair\n");

	while((op=getchar())){
		switch(op){
			case 'A': case 'a':
				trocalinha(entrada, tamanho_entrada);
				break;
			case 'B': case 'b':
				direita(entrada, tamanho_entrada);
				break;
			case 'C': case 'c':
				girahorario(entrada, tamanho_entrada);
				break;
			case 'Z': case 'z':
				resolve(entrada);
				break;
			case 'Q': case 'q':
				exit(0);
				break;
			default: printf("Digite um comando válido!\n"); break;
		}
		system("clear");
		escreve_cubo(entrada);
		printf("A: trocar de linha\nB: girar para a direita\nC: girar os 4 elementos centrais no sentido horario\nQ: Sair\n");
	}
	return 0;
}

void trocalinha(int valores[], int n){
	int temp[n];
	int i;
	
	for(i=0;i<n;i++){
		temp[i] = valores[i];
	}
	
	for(i=0;i<n/2;i++){
		valores[i] = temp[i+n/2];
		valores[i+n/2] = temp[i];
	}
}

void direita(int valores[], int n){
	int temp[n];
	int i;
	
	for(i=0;i<n;i++){
		temp[i] = valores[i];
	}
	
	valores[0] = temp[3];
	valores[1] = temp[0];
	valores[2] = temp[1];
	valores[3] = temp[2];
	valores[4] = temp[7];
	valores[5] = temp[4];
	valores[6] = temp[5];
	valores[7] = temp[6];
}

void girahorario(int valores[], int n){
	int temp[n];
	int i;
	
	for(i=0;i<n;i++){
		temp[i] = valores[i];
	}
	
	valores[1] = temp[5];
	valores[2] = temp[1];
	valores[5] = temp[6];
	valores[6] = temp[2];	
}

void resolve(int valores[]){
	
}
