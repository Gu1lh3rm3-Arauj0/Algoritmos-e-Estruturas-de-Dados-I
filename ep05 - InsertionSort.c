/*
 * Guilherme Araújo Mendes de Souza
 * UNIFESP - ICT
 * AED 1
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insercao (int n, int v[]){
	int i, j, x;

	for (j = 1; j < n; j++) {
		x = v[j];
		for (i = j-1; i >= 0 && v[i] > x; i--){
			v[i+1] = v[i];
		}
		v[i+1] = x;
	}
}


int main() {
    int n = 20000;
    int vetor[n];
    clock_t inicio, fim;

    for(int i = 0; i < n; i++) {
    	vetor[i] = rand() % 20000;
    }

    inicio = clock();
    Insercao(n, vetor);
    fim = clock();

    double tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 15000;
    for(int i = 0; i < n; i++){
    	vetor[i] = rand() % 15000;
    }

    inicio = clock();
    Insercao(n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 10000;
    for(int i = 0; i < n; i++){
      	vetor[i] = rand() % 10000;
    }

    inicio = clock();
    Insercao(n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 5000;
    for(int i = 0; i < n; i++){
       	vetor[i] = rand() % 5000;
    }

    inicio = clock();
    Insercao(n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

    return 0;
}
