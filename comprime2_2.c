//s[]-t[]
#include <stdio.h>

void comprime(char s[], int c){
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
		if(s[i] != c) s[j++] = s[i];

	s[j] = '\0';
}

void comprime2(char s[], char t[]){
	int i;

	for(i=0;t[i]!='\0';i++){
		comprime(s,t[i]);
	}
	for(i=0;s[i]!='\0';i++)
		printf("%c", s[i]);

	printf("\n");
}

void main(){
	char texto1[] = "ABBABZ";
	char texto2[] = "AB";
	comprime2(texto1,texto2);
}
