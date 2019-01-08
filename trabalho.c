#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int escreve_cubo(int valores[]);
void trocalinha(int valores[], int n);
void direita(int valores[], int n);
void girahorario(int valores[], int n);
void resolve(int valores[], int n);
void aleatorio(int valores[], int n);
int fimdejogo(int valores[], int n);


int main(int argc, char *argv[]){
	int tamanho_entrada = 8;
	int entrada[tamanho_entrada];
	int op, c;
	int i=0, tem_arg = 0;

	//pega os argumentos da linha de comando
	while (--argc > 0 && (*++argv)[0] == '-'){
		while ((c = *++argv[0])){
			switch (c) {
			case 'r':
				aleatorio(entrada, tamanho_entrada);
				tem_arg = 1;
				break;
			case 'a':
				resolve(entrada, tamanho_entrada);
				break;
			default:
				printf("Paramêtro de entrada inválido: %c\n", c);
				argc = 0;
				break;
			}
		}
	}
	
	//ler arquivo
	if(!tem_arg){
		FILE *arq = fopen( "arquivo.txt" , "r" ); 
	
		while( (c = fgetc(arq)) != EOF){
			if(c != ' ')
				entrada[i++] = c -'0';
		}
	}
	
	do{
		system("clear");
		escreve_cubo(entrada);
		printf("Escolha uma opção:\nA: trocar de linha\nB: girar para a direita\nC: girar os 4 elementos centrais no sentido horario\nZ: Resolver automaticamente\nQ: Sair\n");
		op=getchar();
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
				resolve(entrada, tamanho_entrada);
				break;
			case 'Q': case 'q':
				exit(0);
				break;
			default:
				printf("Digite um comando válido!\n");
				break;
		}
	}while(!fimdejogo(entrada,tamanho_entrada));
	
	printf("\nVocê conseguiu, parabéns! :)\n");
	return 0;
}

int escreve_cubo(int valores[]){
	printf("-----------------\n");
	printf("| %d | %d | %d | %d |\n",valores[0],valores[1],valores[2],valores[3]);
	printf("|---+---+---+---|");
	printf("\n| %d | %d | %d | %d |\n",valores[4],valores[5],valores[6],valores[7]);
	printf("-----------------\n");
	
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

void resolve(int valores[], int n){
	printf("Deveria resolver o Quadro! :)\n");
}

void aleatorio(int valores[], int n){
	int i, j, temp, tem = 0;
	
	srand( (unsigned)time(NULL) );
	
	for(i=0;i<n;i++){
		temp = 1 + rand()%8;
		for(j=i;!tem && j>=0;j--){
			if(valores[j] == temp) tem = 1;
		}
		if(!tem) valores[i] = temp;
		else     i--;
		tem = 0;
	}
}

int fimdejogo(int v[], int n){
	int i, igual=1;
	int base[] = {1,2,3,4,5,6,7,8};
	
	for(i=0;i<n && igual;i++){
		if(v[i] != base[i]) igual = 0;
	}
	return igual;
}
