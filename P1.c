#include <stdio.h>
#define AVANCA 1
#define RECUA 0

void leTexto(char vetor[], int max);
void leMatricula(char vet_num[]);
void escreve(char vetor[]);
void criptografa(char vetor[], char vet_num[]);
void maiuscula(char textoIn[], int sentido, int i, int num);
void minuscula(char textoIn[], int sentido, int i, int num);

int main(){
	const int max = 3000;
	char textoIn[max];
	char vet_num[12];
	printf("Digite a Mensagem: \n");
	leTexto(textoIn, max);
	leMatricula(vet_num);
	criptografa(textoIn, vet_num);
	printf("Mensagem Criptografada: \n");
	escreve(textoIn);
	
	return 0;
}

/* Lê o texto */
void leTexto(char textoIn[], int max){
	int lim = 100; //limite de entrada por linha
	int i, j, k=0, c, inicio = 0;
	
	c=getchar();
	for(i=0;c!=EOF && k<3000;i++){
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


void leMatricula(char vet_num[]){
	int lim = 12;
	int i,c;
	printf("Digite sua matricula de 12 digitos: ");
	
	for(i=0; i<lim-1&&(c=getchar())!=EOF && c!='\n'; i++){
		if(c >= '0' && c <= '9')
			vet_num[i] = c - '0';
		else i--;
	}
}

void escreve(char vetor[]){
	int i, max = 80;
	for(i=0;vetor[i]!='\0';i++){
		if((i+1)%max == 0) printf("\n");
		printf("%c",vetor[i]);
	}
	printf("\n");
}

void criptografa(char textoIn[], char vet_num[]){
	int i, c;
	int sentido = 1;
	
	for(i=0; (c = textoIn[i]) != '\0';i++){
		//andar
		if( textoIn[i] == ' ' || (textoIn[i] >= 'a' && textoIn[i] <='z'))
			minuscula(textoIn, sentido, i, vet_num[(i%12)]);
		else if(textoIn[i] >= 'A' && textoIn[i] <='Z')
			maiuscula(textoIn, sentido, i, vet_num[(i%12)]);
			
		//saber o sentido que o proximo vai andar
		if (c == ' '){
			if(sentido == AVANCA) sentido = RECUA;
			else if(sentido == RECUA) sentido  = AVANCA;
		}
	}
}

//minuscula receberá o vetor, pra onde ela andará,
//o indice da letra e o numero de casas q andará
void minuscula(char textoIn[], int sentido, int i, int num){
	char base[] = " abcdefghijklmnopqrstuvwxyz";
	int k;
	for(k=0;base[k] != '\0' && base[k] != textoIn[i];k++)
		;
		
	if(base[k] != '\0'){
		if(sentido == AVANCA){
			textoIn[i] = base[(k+num)%27];
		}
		else if(sentido == RECUA){
			if(k-num < 0) textoIn[i] = base[(27+k-num)%27];
			else	textoIn[i] = base[(k-num)%27];
		}
	}
}


//maiuscula receberá o vetor, pra onde ela andará,
//o indice da letra e o numero de casas q andará
void maiuscula(char textoIn[], int sentido, int i, int num){
	char base[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int k;
	
	for(k=0;base[k] != '\0' && base[k] != textoIn[i];k++)
		;
	
	if(base[k] != '\0'){
		if(sentido == AVANCA)
			textoIn[i] = base[(k+num)%27];
		else if(sentido == RECUA){
			if(k-num < 0) textoIn[i] = base[(27+k-num)%27];
			else	textoIn[i] = base[(k-num)%27];
		}
	}
}
