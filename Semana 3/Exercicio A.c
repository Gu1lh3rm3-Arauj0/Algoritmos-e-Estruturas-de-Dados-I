/*
Guilherme Araújo Mendes de Souza - 156437
UNIFESP - ICT
AED 1

beecrowd | 1172
Substituição em Vetor I

*/

#include <stdio.h>

int main() {
    int x[10];
    for (int i = 0; i < 10; i++){ //Laço de repetição para preencher o vetor
	scanf("%d", &x[i]);

		if(x[i]<=0){ // Condição que verifica se o elemento na posição i do vetor é menor ou igual a 0, e no caso de afirmativo altera o valor da posição i para 1
		x[i]=1;
		}
    }
    for (int i = 0; i < 10; i++){
    	printf("X[%d] = %d\n", i, x[i]);
    }

    return 0;
}
