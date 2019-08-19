//gerar um vetor de numeros aletorios com n elementos
//ordenar com shellsorte
//ordenar com bubblesort

#include <stdio.h>
#include <stdlib.h>
#define N 1000

int gera_vetor(int vet[],int n){
	int i;
	for(i=0;i<N;i++) vet[i] = random()%1001;
}

int imprime_vetor(int vet[], int n){
	int i;
	for(i=0;i<n;i++) printf("%d\t",vet[i]);
}

int ordena_vetor(int v[], int n){
	int inter, i, j, temp; 

	for (inter = n/2; inter > 0; inter/=2)
		for (i = inter; i < n; i++)
  			for(j=i-inter; j>=0&&v[j]>v[j+inter];j-=inter) {  
  				temp = v[j];
  				v[j] = v [j + inter];
				v[j + inter] = temp;
  			}
}

int bubblesort(int v[], int n){
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

void main(){
	int vet[N];
	gera_vetor(vet,N);
	printf("---- Sequencia: ----\n");
	imprime_vetor(vet,N);
//	ordena_vetor(vet, N);
	bubblesort(vet, N);
	printf("\n---- Sequencia Ordenada ----: \n");
	imprime_vetor(vet,N);
}
