/*
 * Guilherme Araújo Mendes de Souza
 * UNIFESP - ICT
 * AED 1
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsereEmHeap (int m, int v[]) {
	int f = m+1;
	while (f > 1 && v[f /2] < v[f ]) {
		int t = v[f /2]; v[f /2] = v[f ]; v[f ] = t;
		f = f /2;
	}
}

void SacodeHeap (int m, int v[]) {
	int t, f = 2;
	while (f <= m) {
		if (f < m && v[f ] < v[f +1]) ++f ;
		if (v[f /2] >= v[f ]) break;
		t = v[f /2]; v[f /2] = v[f ]; v[f ] = t;
		f *= 2;
	}
}

void Heapsort (int n, int v[]) {
	int m;
	for (m = 1; m < n; m++)
		InsereEmHeap (m, v);
	for (m = n; /*X*/ m > 1; m--) {
		int t = v[1]; v[1] = v[m]; v[m] = t;
		SacodeHeap (m-1, v);
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
    Heapsort(n, vetor);
    fim = clock();

    double tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 15000;
    for(int i = 0; i < n; i++){
    	vetor[i] = rand() % 15000;
    }

    inicio = clock();
    Heapsort(n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 10000;
    for(int i = 0; i < n; i++){
      	vetor[i] = rand() % 10000;
    }

    inicio = clock();
    Heapsort(n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

/************************************************************************************************************************************************/

    n = 5000;
    for(int i = 0; i < n; i++){
       	vetor[i] = rand() % 5000;
    }

    inicio = clock();
    Heapsort(n, vetor);
    fim = clock();

    tempo_decorrido = (((double) (fim - inicio)) / CLOCKS_PER_SEC)*1000;
    printf("Tempo com %d posições no vetor: %f milessegundos\n", n, tempo_decorrido);

    return 0;
}
