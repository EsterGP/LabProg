#include <stdio.h>
#define sim 1
#define nao 0
int AcharCaracter(char s[], int c){
	int i;
	for(i=0;s[i] != '\0';i++){
		if(s[i] == c) return i;
	}
	return -1; 
}

int AcharCaracteres(char s[], char t[]){
	int i, indiceAnt=10, indiceAtu, achou=nao;

	for(i=0;t[i]!='\0';i++){
		indiceAtu = AcharCaracter(s, t[i]);

		if(indiceAtu !=-1 && indiceAtu<indiceAnt){
			indiceAnt=indiceAtu;
			achou = sim;
		}
	}
	if(achou==sim) return indiceAtu;
	else return -1;
}

void main(){
	char texto1[] = "ABBABZ";
	char texto2[] = "ZB";
	printf("%d\n", AcharCaracteres(texto1,texto2));
	
}
