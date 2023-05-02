#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct nome{
	char nome[30];
};
typedef struct nome string;

void Insercao (int n, string *aluno){
	int i=1, j, a;
	string aux;
	while (i < n){
		j = i-1;
		aux = aluno[i];
		while  (j >= 0 && strcmp(aluno[j].nome, aux.nome) > 0){
			aluno[j+1] = aluno[j];
			j--;
		}
		aluno[j+1] = aux;
		i++;
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	string aluno[n];

	for(int i = 0; i < n; i++){
		scanf("%s", aluno[i].nome);
	}

	Insercao(n, aluno);

	printf("%s\n", aluno[k-1].nome);

    return 0;
}
