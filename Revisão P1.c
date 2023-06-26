#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Listas encadeadas
struct cel {
int conteúdo;
struct cel *seg; /* seguinte */
};
typedef struct cel célula;

// Imprime sem cabeça
void Imprima (célula *lst) {
célula *p;
for (p = lst; p != NULL; p = p->seg)
printf ("%d\n", p->conteúdo);
}

// Imprime com cabeça
void Imprima (célula *lst) {
célula *p;
for (p = lst->seg; p != NULL; p = p->seg)
printf ("%d\n", p->conteúdo);
}

célula *Busca (int x, célula *lst) {
célula *p;
p = lst->seg;
while (p != NULL && p->conteúdo != x)
p = p->seg;
return p;
}

célula *BuscaR (int x, célula *lst) {
if (lst->seg == NULL)
return NULL;
if (lst->seg->conteúdo == x)
return lst->seg;
return BuscaR (x, lst->seg);
}

void Remove (célula *p) {
célula *lixo;
lixo = p->seg;
p->seg = lixo->seg;
free (lixo);
}

void Insere (int y, célula *p) {
célula *nova;
nova = malloc (sizeof (célula));
nova->conteúdo = y;
nova->seg = p->seg;
p->seg = nova;
}

void BuscaERemove (int x, célula *lst) {
célula *p, *q;
p = lst;
q = lst->seg;
while (q != NULL && q->conteúdo != x) {
p = q;
q = q->seg;
}
if (q != NULL) {
p->seg = q->seg;
free (q);
}
}

void BuscaEInsere (int y, int x, célula *lst) {
célula *p, *q, *nova;
nova = malloc (sizeof (célula));
nova->conteúdo = y;
p = lst;
q = lst->seg;
while (q != NULL && q->conteúdo != x) {
p = q;
q = q->seg;
}
nova->seg = q;
p->seg = nova;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Fila

int Remove (célula **es, célula **et) {
célula *p;
int x;
p = *es;
/* p aponta o primeiro elemento da fila */
//x = p->valor;
*es = p->seg;
free (p);
if (*es == NULL) *et = NULL;
return x;
}

void Insere (int y, célula **es, célula **et) {
célula *nova;
nova = malloc (sizeof (célula));
//nova->valor = y;
nova->seg = NULL;
if (*et == NULL) *et = *es = nova;
else {
(*et)->seg = nova;
*et = nova;
}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pilhas

typedef struct cel {
int valor;
struct cel *seg;
} célula;


void Empilha (int y, célula *p) {
célula *nova;
nova = malloc (sizeof (célula));
nova->valor = y;
nova->seg = p->seg;
p->seg = nova;
}

int Desempilha (célula *p) {
int x; célula *q;
q = p->seg;
x = q->valor;
p->seg = q->seg;
free (q);
return x;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Busca Ordenada

int BuscaSeqüencial (int x, int n, int v[]) {
int j = 0;
while (j < n && v[j] < x) ++j;
return j;
}

int BuscaBinária (int x, int n, int v[]) {
int e, m, d;
e = -1; d = n;
while (/*X*/ e < d - 1) {
m = (e + d)/2;
if (v[m] < x) e = m;
else d = m;
}
return d;
}


//Versão recursiva
int BuscaBinária2 (int x, int n, int v[]) {
return BuscaBinR (x, -1, n, v);
}

int BuscaBinR (int x, int e, int d, int v[]) {
if (e == d-1) return d;
else {
int m = (e + d)/2;
if (v[m] < x)
return BuscaBinR (x, m, d, v);
else
return BuscaBinR (x, e, m, v);
}
}




int main(){

	// Pilha vazia
	célula cabeça;
	célula *p;
	p = &cabeça; /* p->seg é o topo da pilha */
	p->seg = NULL;

  return 0;
}
