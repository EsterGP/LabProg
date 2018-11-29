#include <stdio.h>
#define AVANCA 1
#define RECUA 0

void leTexto(char vetor[], int max);
void escreve(char vetor[]);
void criptografa(char vetor[], int vet_num[]);
void maiuscula(char textoIn[], int sentido, int i, int num);
void minuscula(char textoIn[], int sentido, int i, int num);

int main(){
	int max = 3000;
	char textoIn[] = "Celacanto provoca maremoto? Sim.";
	int vet_num[12] = {1,9,9,1,1,2,3,4,0,5,6,7}; //porque a matricula tem 12 dígitos
	escreve(textoIn);
	
//	leTexto(textoIn, max);
	criptografa(textoIn, vet_num);
	escreve(textoIn);
	
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
		if((i+1)%max == 0) printf("\n");
		printf("%c",vetor[i]);
	}
	printf("\n");
}

void criptografa(char textoIn[], int vet_num[]){
	int i;
	int sentido = AVANCA;
	for(i=0;textoIn[i]!='\0';i++){
		//saber o sentido que vai andar
		if(textoIn[i] == ' ' && sentido == AVANCA)
			sentido = RECUA;
		else if(textoIn[i] == ' ' && sentido == RECUA)
			sentido  = AVANCA;
		
		//andar
		if(textoIn[i]>= 'a' && textoIn[i]<='z')
			minuscula(textoIn, sentido, i, vet_num[(i%12)]);
		else if(textoIn[i]>= 'A' && textoIn[i]<='Z')
			maiuscula(textoIn, sentido, i, vet_num[(i%12)]);
			
	}
}

//maiuscula receberá o vetor,
//pra onde ela andará e o indice da letra
void maiuscula(char textoIn[], int sentido, int i, int num){
	char base[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int k;
	
	for(k=0;base[k] != '\0' && base[k] != textoIn[i];k++)
		;
	
	if(base[k] != '\0'){
		if(sentido == AVANCA)
			textoIn[i] = base[(k+num)%27];
		else if(sentido == RECUA)
			textoIn[i] = base[(k-num)%27];
	}
}

//minuscula receberá o vetor,
//pra onde ela andará e o indice da letra
void minuscula(char textoIn[], int sentido, int i, int num){
	char base[] = " abcdefghijklmnopqrstuvwxyz";
	int k;
	
	for(k=0;base[k] != '\0' && base[k] != textoIn[i];k++)
		;
		
	if(base[k] != '\0'){
		if(sentido == AVANCA)
			textoIn[i] = base[(k+num)%27];
		else if(sentido == RECUA)
			textoIn[i] = base[(k-num)%27];
	}
}
