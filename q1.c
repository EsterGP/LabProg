#include <stdio.h>
#include <math.h>
#define N 10

int main(){
	int i;
	float valor[N], media=0, soma = 0, soma_quadrado = 0;
	float dev_padrao = 0;
	
	for(i=0;i<N;i++){
		printf("Entre com o valor %d: ", i+1);
		scanf("%f", &valor[i]);
		soma += valor[i];
		soma_quadrado += valor[i]*valor[i];
	}
	
	
	
	media = soma/N;
	dev_padrao = sqrt((soma_quadrado/N)-(media*media));
	printf("\nMédia: %.2f\n", media);
	printf("Desvio Padrão: %.2f\n", dev_padrao);
	
	return 0;
}
