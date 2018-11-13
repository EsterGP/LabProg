#include <stdio.h>
#include <math.h>
#define sim 1
#define nao 0
#define N 1000

int primo(int num, int primos[]){
	int i, eprimo = sim;
	for(i=0;primos[i]<=(sqrt(num)) && eprimo==sim;i++)
		if((num%primos[i]) == 0) eprimo = nao;
	
	if(eprimo == sim){
		printf("%d\t", num);
		return sim;
	}
	return nao;
}

int main(){
	int i, eprimo = nao, primos[N];
	int nprimo = 0;
	
	primos[0] = 2;
	printf("%d\t", primos[0]);
	
	for(i=3;nprimo < N-1;i++)
		if((eprimo = primo(i,primos)) == sim)	primos[++nprimo] = i;
	return 0;
}
