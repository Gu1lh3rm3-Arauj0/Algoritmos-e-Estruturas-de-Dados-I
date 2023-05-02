/*
 * Guilherme Araújo Mendes de Souza
 * UNIFESP - ICT
 * AED 1
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Intercala (int p, int q, int r, int v[]) {
	int i, j, k, *w;
	w = malloc ((r-p) * sizeof (int));
	i = p; j = q; k = 0;
	while (i < q && j < r) {
		if (v[i] <= v[j]) w[k++] = v[i++];
		else w[k++] = v[j++];
	}
	while (i < q) w[k++] = v[i++];
	while (j < r) w[k++] = v[j++];
	for (i = p; i < r; i++) v[i] = w[i-p];
	free (w);
}

void Mergesort (int p, int r, int v[]) {
	if (p < r - 1) {
		int q = (p + r)/2;
		Mergesort (p, q, v);
		Mergesort (q, r, v);
		Intercala (p, q, r, v);
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
    Mergesort(0, n, vetor);
    fim = clock();

    double tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 15000;
    for(int i = 0; i < n; i++){
    	vetor[i] = rand() % 15000;
    }

    inicio = clock();
    Mergesort(0, n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 10000;
    for(int i = 0; i < n; i++){
      	vetor[i] = rand() % 10000;
    }

    inicio = clock();
    Mergesort(0, n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 5000;
    for(int i = 0; i < n; i++){
       	vetor[i] = rand() % 5000;
    }

    inicio = clock();
    Mergesort(0, n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

    return 0;
}
