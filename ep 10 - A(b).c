/*
beecrowd | 2528
Cidade Proibida
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INF 0x3f3f3f3f
#define MAX_CIDADES 1000

typedef struct {
    int cidade_a;
    int cidade_b;
} Rota;

typedef struct {
    int cidade_c;
    int cidade_r;
    int cidade_e;
} CasoTeste;

int grafo[MAX_CIDADES][MAX_CIDADES];
int dist[MAX_CIDADES];

void dijkstra(int partida, int num_cidades, int g[MAX_CIDADES][MAX_CIDADES], int *dist) {
    bool visitado[MAX_CIDADES];
    memset(visitado, false, sizeof(visitado));

    memset(dist, INF, (num_cidades + 1) * sizeof(int));
    dist[partida] = 0;

    for (int i = 0; i <= num_cidades; ++i) {
        int v = -1;
        for (int j = 0; j <= num_cidades; ++j) {
            if (!visitado[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        if (dist[v] == INF)
            break;

        visitado[v] = true;
        for (int j = 0; j <= num_cidades; ++j) {
            if (dist[v] + g[v][j] < dist[j])
                dist[j] = dist[v] + g[v][j];
        }
    }
}

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) == 2) {
        memset(grafo, INF, sizeof(grafo));

        for (int i = 0; i < m; ++i) {
            int cidade_a, cidade_b;
            scanf("%d %d", &cidade_a, &cidade_b);
            grafo[cidade_a][cidade_b] = grafo[cidade_b][cidade_a] = 1;
        }

        CasoTeste caso;
        scanf("%d %d %d", &caso.cidade_c, &caso.cidade_r, &caso.cidade_e);

        for (int i = 0; i <= n; ++i)
            grafo[caso.cidade_e][i] = grafo[i][caso.cidade_e] = INF;

        dijkstra(caso.cidade_c, n, grafo, dist);
        printf("%d\n", dist[caso.cidade_r]);
    }

    return 0;
}
