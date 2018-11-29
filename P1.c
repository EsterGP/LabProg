#include <stdio.h>
#define AVANCA 1
#define RECUA 0

void leTexto(char vetor[], int max);
void escreve(char vetor[]);
void criptografa(char vetor[], int vet_num[]);
int Idxmaiuscula(int c);
int Idxminuscula(int c);
void avancar();
void recuar();

int main(){
	int max = 3000;
	char textoIn[] = "Celacanto provoca maremoto? Sim.";
//	char textoOut[];
	int vet_num[12] = {1,9,9,1,1,2,3,4,0,5,6,7}; //porque a matricula tem 12 dígitos
	escreve(textoIn);
	
//	leTexto(textoIn, max);
	criptografa(textoIn, vet_num);
	
	return 0;
}

/* Lê o texto */
void leTexto(char textoIn[], int max){
	int lim = 100; //limite de entrada por linha
	int i, j, k=0, c, inicio = 0;
	
	c=getchar();
	for(i=0;c!=EOF;i++){
		if(i==0){
			textoIn[k++] = c;
			inicio = 1;
		}
		else inicio = 0;
		/* Trata cada linha e trunca quem tem mais de 100 caracteres
		 * Dar uma mensagem de erro ao ultrapassar
		 */
		for(j=inicio;j<lim && (c=getchar()) != EOF && c != '\n'; ++j){
			if(c == '\n' || c == '\t') c = ' ';
			textoIn[k++] = c;
		}
		if(j==lim) while(getchar() != '\n');
		if(c != EOF) textoIn[k++] = ' ';
	}
	textoIn[k] = '\0';
}

void escreve(char vetor[]){
	int i, max = 80;
	for(i=0;vetor[i]!='\0';i++){
//		if((i+1)%max == 0) printf("\n");
		printf("%c",vetor[i]);
	}
	printf("\n");
}

void criptografa(char textoIn[], int vet_num[]){
	int i;
	int idx = 0;
	int j = 0;
	int sentido = AVANCA;
	for(i=0;textoIn[i]!='\0';i++){
		//saber o sentido que vai andar
		if(textoIn[i] = ' ' && sentido == AVANCA)
			sentido = RECUA;
		else if(textoIn[i] = ' ' && sentido == RECUA)
			sentido  = AVANCA;
		
		//descobrir quanto vai andar
		if(textoIn[i]>= 'a' && textoIn[i]<='z')
			idx = Idxminuscula(textoIn[i]);
		else if(textoIn[i]>= 'A' && textoIn[i]<='Z')
			idx = Idxmaiuscula(textoIn[i]);
			
		//trocar a letra
		if(sentido == AVANCA)
			j = (j+idx)%27;
		else if(sentido == RECUA)
			j = (j-idx)%27;
	}
}

int Idxmaiuscula(int c){
	char base[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	return 0;
}

int Idxminuscula(int c){
	char base[] = " abcdefghijklmnopqrstuvwxyz";
	
	return 0;
}

void avancar(){
}

void recuar(){
}
