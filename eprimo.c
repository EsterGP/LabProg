#include <stdio.h>
#include <math.h>
#define sim 1
#define nao 0

int primo(int num){
	int i, eprimo = sim;
	for(i=2;i<=(sqrt(num)) && eprimo==sim;i++){
		if((num%i) == 0) eprimo = nao;
	}
	
	if(eprimo == sim){
		printf("%d\t", num);
		return sim;
	}
	
	return nao;
}

void main(){
	int i, nprimo,eprimo = nao;
	for(i=2;nprimo < 1000;i++) if((eprimo = primo(i)) == sim) ++nprimo;
}
