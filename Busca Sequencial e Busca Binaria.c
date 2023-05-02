/* Guilherme Araújo Mendes de Souza - 156437
 * Tamires Morais Rodrigues - 163994
 * UNIFESP - ICT
 * AED 1
 */

#include <stdio.h>
#include <time.h>

int BuscaSequencial (int x, int n, int v[]){
		int j =0;
		while(j < n && v[j] < x){
			j++;
		}
	return j;
}

int BuscaBinaria (int x, int n, int v[]){
	int e, m, d;
	e = -1;
	d = n;

	while (e<d-1){
		m = (e+d)/2;
		if(v[m]<x){
			e = m;
		}
		else{
			d = m;
		}
	}

	return d;
}

int main() {
	int vetor[100000];
	int a;
	clock_t  tini, tfim;

	for(int i = 0; i < 100000; i++){
		vetor[i]=i;
	}
	scanf("%d", &a);

	tini = clock();
	BuscaSequencial(a, 100000, vetor);
    tfim = clock();
    double tempo_decorrido = (((double) (tfim - tini)) / CLOCKS_PER_SEC);
    printf("%f Segundos\n", tempo_decorrido);

	tini = clock();
	BuscaBinaria(a, 100000, vetor);
	tfim = clock();
	tempo_decorrido = (((double) (tfim - tini)) / CLOCKS_PER_SEC);
	printf("%f Segundos\n", tempo_decorrido);


	return 0;
}
