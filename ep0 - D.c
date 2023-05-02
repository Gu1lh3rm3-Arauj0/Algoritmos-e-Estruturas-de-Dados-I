#include <stdio.h>
#include <string.h>

int main(){

	char A[50], B[50], resp[100];
	int qtd, cont, menor, maior, g;

	scanf("%i", &qtd);

	for(int i=0; i<qtd; i++){
		scanf("%s", A);
		scanf("%s", B);

		cont=0;

		if(strlen(A)>strlen(B)){
			menor= strlen(B);
			maior= strlen(A);
			}else{
			menor= strlen(A);
			maior= strlen(B);
		}
		for(g=0; g<=maior; g++){
			if(g<menor){
				resp[cont]= A[g];
				cont++;
				resp[cont]= B[g];
				cont++;
			}
			else if(strlen(A)<strlen(B)){
				resp[cont]= B[g];
				cont++;
			}
			else{
				resp[cont]= A[g];
				cont++;
			}

		 }
		printf("%s\n", resp);
	}

	return 0;
	}
