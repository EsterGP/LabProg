#include<stdio.h>
#define FORA 1 		//dentro de uma palavra
#define DENTRO 0 	//fora de uma palavra
#define N 100

void main(){
	int i = 0, j = 0, c, np=0, nc[N], estado;
	int iMax = 0;	//tamanho da maior palavra
	estado = FORA;
	
	for(i=0;i<N;i++){
		nc[i] = 0;
	}
	
	i = 0;
	
	while((c=getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			estado = FORA;
		}
		else if(estado == FORA){
			estado = DENTRO;
			++np;
		}
		if(estado == DENTRO)
			i++;
		else{
			if (i>iMax){
				iMax=i;
			}
			++nc[i];
			i=0;
		}
	}
	printf("\niMax = %d\n\n", iMax);
	printf("\nTotal de Palavras: %d\n", np);
	printf("\n - - - - - H I S T O G R A M A - - - - - \n");
	
	for(i=1;i<=iMax;i++){
		printf("Palavras com %d letras:\t", i);
		for(j=1;j<=nc[i];j++){
			printf("*");
		}
		printf("\n");
	}
}