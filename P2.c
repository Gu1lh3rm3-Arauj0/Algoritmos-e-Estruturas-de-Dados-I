#include <stdio.h>
#include <stdlib.h>

// Estrura do No
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar o Nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

// Função para imprimir em PreOrdem
void imprimirPreOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    printf(" %d", raiz->valor);
    imprimirPreOrdem(raiz->esquerda);
    imprimirPreOrdem(raiz->direita);
}

// Função para imprimir em EmOrdem
void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    imprimirEmOrdem(raiz->esquerda);
    printf(" %d", raiz->valor);
    imprimirEmOrdem(raiz->direita);
}

// Função para imprimir em PosOrdem
void imprimirPosOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    imprimirPosOrdem(raiz->esquerda);
    imprimirPosOrdem(raiz->direita);
    printf(" %d", raiz->valor);
}

// Função para Liberar a Arvore
void liberarArvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    int t, n, valor, i;

    scanf("%d", &t);

    for (i = 1; i <= t; i++) {
        No* raiz = NULL;
        scanf("%d", &n);

        while (n--) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);
        printf("Pre.:");
        imprimirPreOrdem(raiz);
        printf("\n");
        printf("In..:");
        imprimirEmOrdem(raiz);
        printf("\n");
        printf("Post:");
        imprimirPosOrdem(raiz);
        printf("\n\n");

        liberarArvore(raiz);
    }

    return 0;
}
