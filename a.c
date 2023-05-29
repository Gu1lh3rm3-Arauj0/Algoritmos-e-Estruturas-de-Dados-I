#include <stdio.h>
#include <stdlib.h>
#define true 1
#define fase 0
typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia {
    int vertice; // vertice de destino
    TIPOPESO peso; // peso associado a aresta que leva ao vertice de destino
    struct adjacencia *prox; // O próximo elemento da lista de adjacencias
}ADJACENCIA;

typedef struct vertice {
    /* Dados armazenados vão aqui */
    ADJACENCIA *cab; //possui apenas a cabeça da lista de adjacencia (linha 16)
}VERTICE;

typedef struct grafo {
    int vertice; // numero de vertice total do grafo     /*Apesar de não ser nescessario guardar o numero de vertices  e arestas, o fazemos, pois caso quisermos*/
    int arestas; // numero de arestas totais do grafo  	/*saber desta informação, teriamos que percorrer toda a estrutura. Parece melhor perder 8bits de memória salvando isto ;)*/
    VERTICE *adj; // Arranjo de vertices da estrutura (linha 22)
}GRAFO;

void GRAPHcptD1(GRAFO G, VERTICE s, VERTICE *pa, int *dist){

   bool mature[1000];
   for (VERTICE v = 0; v < G->V; ++v)
      pa[v] = -1, mature[v] = false, dist[v] = INT_MAX;
   pa[s] = s, dist[s] = 0;

   while (true) {
      // escolha de y:
      int min = INT_MAX;
      vertex y;
      for (vertex z = 0; z < G->V; ++z) {
         if (mature[z]) continue;
         if (dist[z] < min)
            min = dist[z], y = z;
      }
      if (min == INT_MAX) break;
      // atualização de dist[] e pa[]:
      for (link a = G->adj[y]; a != NULL; a = a->next) {
         if (mature[a->w]) continue;
         if (dist[y] + a->c < dist[a->w]) {
            dist[a->w] = dist[y] + a->c;
            pa[a->w] = y;
         }
      }

      mature[y] = true;
   }
}

int main()
{
   int nc, nr, rotas;
   int A, B;
   int C, R, E;
   int grafo[0][0];
   //nc Arraestas (1h) do grafo e nr os vertices

   while (getchar()!= EOF) {
	   scanf("%d", &nc);
	   scanf("%d", &nr);

	   grafo[nr][nr];
	   for(int i = 0; i < nc; i++){
		   for(int j = 0; j < nc; j++){
			   grafo[i][j]=0;
		   }
	   }

	   for(int i = 0; i < nc; i++){
		   scanf("%d", &A);
		   scanf("%d", &B);
		   grafo[A][B]=1;
		   grafo[B][A]=1;
	   }

	   scanf("%d %d %d", &C, &R, &E);
	   for(int j = 0; j < nc; j++){
		   grafo[E][j]=0;
	   }
	   for(int i = 0; i < nc; i++){
		   grafo[i][E]=0;
	   	}
   }

   int origem = C; // Vértice de origem

   funçãoa(nr, grafo, origem);

   return 0;
}
