#include <stdio.h>
#include <stdlib.h>

int pega_valores(int vet[], int argc, char *argv[]);
void comparar(int vet[], int n);
int procura(int vet_entrada[], int vet_temp[], int n, int tentativa);
void gera_aleatorio(int vet[], int n);
void calcula();
void ordena(int v[], int n);
void escreve(int valores[], int n);

int main(int argc, char *argv[]){
	int n = 6, flag = 0;
	int entrada[n];

	if(argc == 7){
		flag = pega_valores(entrada, argc, argv);
	}
	else if(argc < 7){
		printf("Faltam %d números\n", 7-argc);
	}
	else{
		printf("Você entrou %d números a mais\n", argc-7);
	}
	
	if(flag){
		ordena(entrada, n);
		
		printf("Sua entrada: ");
		escreve(entrada, n);
		comparar(entrada, n);
	}
	return 0;
}

int pega_valores(int vet[], int argc, char *argv[]){
	int i;
	
	//pega os argumentos da linha de comando
	for(i=0;--argc > 0;i++){
		if(*argv[i+1] != '0' ){ //verifica se o digito começa com 0
			vet[i] = *argv[i+1] - '0';
			if(*++argv[i+1] != '\0'){
				vet[i] = 10*vet[i] + *argv[i+1] - '0';
			}
			if(vet[i] > 60){
				printf("***Você precisa entrar com valores entre 1 e 60!***\n");
				return 0;
			}
		}
		else{
			vet[i] = *++argv[i+1] - '0';
		}
	}
	return 1;
}

void comparar(int vet[], int n){
	int i, temp[n], sena = 0; //encontrou sena 1, não encontrou sena 0
	
	for(i=0;!sena;i++){
		gera_aleatorio(temp, n);
		sena = procura(vet, temp, n, i);
	}
	if(sena){
		printf("PARABÉNS! Você conseguiu acertar a SENA depois de %d tentativas!\n", i);
		calcula(i);
	}
}

int procura(int vet_entrada[], int vet_temp[], int n, int tentativa){
	int i, j;
	int conta = 0;
	
	for(i=0; i<n;i++){
		for(j=0;j<n;j++)
			if(vet_entrada[i] == vet_temp[j])
				conta++;
	}
	
	if(conta == 4){
		printf("Você conseguiu uma QUADRA depois de %d tentativas!\n", tentativa);
		calcula(tentativa);
	}
	if(conta == 5){
		printf("Você conseguiu uma QUINA depois de %d tentativas!\n", tentativa);
		calcula(tentativa);
	}
	
	if(conta == 6)
		return 1;
	else
		return 0;
}

void gera_aleatorio(int vet[], int n){
	int i, j, temp, tem = 0;
	
	for(i=0;i<n;i++){
		temp = 1 + rand()%60;
		for(j=i;!tem && j>=0;j--){
			if(vet[j] == temp) tem = 1;
		}
		if(!tem) vet[i] = temp;
		else     i--;
		tem = 0;
	}
	ordena(vet,n);
}

void ordena(int v[], int n){
	int i, trocou = 1, aux;
	while(trocou){
		trocou = 0;
		for(i=0;i<n-1;i++){
			if(v[i]>v[i+1]){
				trocou = 1;
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
	}
}

void calcula(int quant){
	float preco_unitario = 3.5, preco_total = 0;
	int anos = 0, meses = 0, semanas = 0;
	preco_total = preco_unitario*quant;
	printf("Custo: R$ %.2f ", preco_total);
	
	semanas = quant/2;
	meses = semanas/4;
	anos = meses/12;
	
	meses = meses - anos*12;
	semanas = semanas - (anos*12 + meses)*4;
	printf("em %d anos %d meses %d semanas\n\n",anos, meses, semanas);
}

void escreve(int v[], int n){
	int i;
	
	for(i=0; i<n ;i++){
		printf("%d  ", v[i]);
	}
	printf("\n\n");
}
