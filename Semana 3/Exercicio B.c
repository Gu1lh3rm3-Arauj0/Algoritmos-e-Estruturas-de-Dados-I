/*Guilherme Araújo Mendes de Souza - 156437
 * UNIFESP - ICT
 * AED 1
 *
 * beecrowd | 3160
 * Amigos
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct amigos{
	char nome[30];
	struct amigos *prox;
};
typedef struct amigos lista;

void Insere (char y[], lista *p){
	lista *nova;
	nova = malloc (sizeof (lista));
	for(int i = 0; i<30; i++){
		nova->nome[i] = y[i];
	}
	nova->prox = p->prox;
	p->prox = nova;
}

char Remove (char x[], lista *lst) {
	lista *p, *q;
	char aux[30];
	p = lst;
	q = lst->prox;
	while (q != NULL && 0==(strcmp(q->nome, x))){
		p = q;
		q = q->prox;
	}
	return x;

	if (q != NULL) {
		p->prox = q->prox;
		free (q);
	}
}

void Imprima (lista *lst) {
	lista *p;
	for (p = lst->prox; p != NULL; p = p->prox){
		printf ("%s ", p->nome);
	}
}

int main() {
	lista nomes, *lst;
	char nome[30], novo[30], n[4] = {"nao"}, result[30];

	lst = NULL;
	lst = (lista *) malloc(sizeof(lista));

    gets(nome);
	Insere(nome, lst);
	gets(nome);
	Insere(nome, lst);

	gets(novo);
	if (strcmp(novo, n)){
	    result[30] == Remove (novo, lst);
	    Insere(result, lst);
	    Imprima(lst);
	}else{
	    Imprima(lst);
	}

	return 0;
}
