#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
int conteúdo;
struct cel *esq;
struct cel *dir;
};
typedef struct cel nó;

typedef nó *árvore;

void Erd (árvore r) {
if (r != NULL) {
Erd (r->esq);
printf ("%d\n", r->conteúdo);
Erd (r->dir);
}
}

int Altura (árvore r) {
if (r == NULL)
return -1; /* a altura de uma árvore vazia é -1 */
else {
int he = Altura (r->esq);
int hd = Altura (r->dir);
if (he < hd ) return hd + 1;
else return he + 1;
}
}

//Estrutura de nó com campo pai
struct cel {
int conteúdo;
struct cel *pai;
struct cel *esq;
struct cel *dir;
};

nó *Seguinte (nó *x) {
if (x->dir != NULL) {
nó *y = x->dir;
while (y->esq != NULL) y = y->esq;
return y;
}
while (x->pai != NULL && x->pai->dir == x)
x = x->pai;
return x->pai;
}

// Árvores binárias de busca
struct cel {
int chave;
int conteúdo;
struct cel *esq;
struct cel *dir;
};
typedef struct cel nó;

nó *Busca (árvore r, int k) {
if (r == NULL || r->chave == k)
return r;
if (r->chave > k)
return Busca (r->esq, k);
else
return Busca (r->dir, k);
}

árvore Insere (árvore r, nó *novo) {
nó *f, *p;
if (r == NULL) return novo;
f = r;
while (f != NULL) {
p = f;
if (f->chave > novo->chave) f = f->esq;
else f = f->dir;
}
if (p->chave > novo->chave) p->esq = novo;
else p->dir = novo;
return r;
}


árvore RemoveRaiz (árvore r) {
nó *p, *q;
if (r->esq == NULL) q = r->dir;
else {
	p = r; q = r->esq;
	while (q->dir != NULL) {
	p = q; q = q->dir;
	}
	/* q é o nó anterior a r na ordem e-r-d */
	/* p é o pai de q */
	if (p != r) {
	p->dir = q->esq;
	q->esq = r->esq;
	}
	q->dir = r->dir;
}

free (r);
return q;
}

// Remoção do Filho esqurdo
x->esq = RemoveRaiz (x->esq);

// Remoção do Filho direito
x->dir = RemoveRaiz (x->dir);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A estrutura graph representa um grafo. O campo adj é um ponteiro para a matriz de adjacências do grafo. O campo V contém o número de vértices e o campo A contém o número de arcos do grafo. */

struct graph {
   int V;
   int A;
   int **adj;
};

/* Um Graph é um ponteiro para um graph, ou seja, um Graph contém o endereço de um graph. */

typedef struct graph *Graph;

* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 e nenhum arco. */

Graph GRAPHinit( int V) {
   Graph G = malloc( sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função MATRIXint() aloca uma matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe valor val. */

static int **MATRIXint( int r, int c, int val) {
   int **m = malloc( r * sizeof (int *));
   for (vertex i = 0; i < r; ++i)
      m[i] = malloc( c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */

void GRAPHinsertArc( Graph G, vertex v, vertex w) {
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1;
      G->A++;
   }
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHremoveArc() remove do grafo G o arco v-w. A função supõe que v e w são distintos, positivos e menores que G->V. Se não existe arco v-w, a função não faz nada. */

void GRAPHremoveArc( Graph G, vertex v, vertex w) {
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0;
      G->A--;
   }
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHshow() imprime, para cada vértice v do grafo G, em uma linha, todos os vértices adjacentes a v. */

void GRAPHshow( Graph G) {
   for (vertex v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (vertex w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1)
            printf( " %2d", w);
      printf( "\n");
   }
}




/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A estrutura graph representa um grafo. O campo adj é um ponteiro para o vetor de listas de adjacência, o campo V contém o número de vértices e o campo A contém o número de arcos do grafo. */

struct graph {
   int V;
   int A;
   link *adj;
};

/* Um Graph é um ponteiro para um graph. */

typedef struct graph *Graph;

/* A lista de adjacência de um vértice v é composta por nós do tipo node. Cada nó da lista corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista. Um link é um ponteiro para um node. */

typedef struct node *link;
struct node {
   vertex w;
   link next;
};

/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o endereço a de um novo nó tal que a->w == w e a->next == next. */

static link NEWnode( vertex w, link next) {
   link a = malloc( sizeof (struct node));
   a->w = w;
   a->next = next;
   return a;
}

* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 e nenhum arco. */

Graph GRAPHinit( int V) {
   Graph G = malloc( sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (vertex v = 0; v < V; ++v)
      G->adj[v] = NULL;
   return G;
}

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */

void GRAPHinsertArc( Graph G, vertex v, vertex w) {
   for (link a = G->adj[v]; a != NULL; a = a->next)
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}


int main(){

  return 0;
}
