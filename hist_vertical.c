#include<stdio.h>
#define FORA 1 		//dentro de uma palavra
#define DENTRO 0 	//fora de uma palavra
#define N 100

void main(){
	int i = 0, j = 0, c, np=0, nc[N], estado;
	int iMax = 0;	//tamanho da maior palavra
	int hMax = 0;	//altura máxima do histograma
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
	
	//verificando a altura máxima do histograma
	for(i=0;i<=iMax;i++){
		if(nc[i]>hMax){
			hMax = nc[i];
		}
	}

	printf("\nTotal de Palavras: %d\n\n", np);
	printf("\n - - - - - H I S T O G R A M A - - - - - \n");
	
	for (i=hMax; i>0; i--) {
    	for (j=1; j<=iMax; j++){
    		if (nc[j] >= i)
    			printf(" * ");
      		else
      			printf("   ");
		}
    	printf("\n");
	}
	for(i=1;i<=iMax;i++){
		printf(" %d ",i);
	}

	printf("\n");
}