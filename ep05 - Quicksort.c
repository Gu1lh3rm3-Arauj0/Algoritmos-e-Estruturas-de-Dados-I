/*
 * Guilherme Araújo Mendes de Souza
 * UNIFESP - ICT
 * AED 1
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa (int p, int r, int v[]) {
	int c, j, k, t;
	c = v[r]; j = p;
	for (k = p; k < r; k++)
		if (v[k] <= c) {
			t = v[j], v[j] = v[k], v[k] = t;
			j++;
		}
	v[r] = v[j], v[j] = c;
	return j;
}

void Quicksort (int p, int r, int v[]) {
	int j;
	if (p < r) {
		j = Separa (p, r, v);
		Quicksort (p, j - 1, v);
		Quicksort (j + 1, r, v);
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
    Quicksort(0, n, vetor);
    fim = clock();

    double tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 15000;
    for(int i = 0; i < n; i++){
    	vetor[i] = rand() % 15000;
    }

    inicio = clock();
    Quicksort(0, n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 10000;
    for(int i = 0; i < n; i++){
      	vetor[i] = rand() % 10000;
    }

    inicio = clock();
    Quicksort(0, n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 5000;
    for(int i = 0; i < n; i++){
       	vetor[i] = rand() % 5000;
    }

    inicio = clock();
    Quicksort(0, n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

    return 0;
}
