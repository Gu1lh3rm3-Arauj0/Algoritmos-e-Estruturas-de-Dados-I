#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char palavra[201];
    struct node* esquerda;
    struct node* direita;
} Node;

Node* criarNode(char palavra[]) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    strcpy(novoNode->palavra, palavra);
    novoNode->esquerda = NULL;
    novoNode->direita = NULL;
    return novoNode;
}

Node* inserirNode(Node* raiz, char palavra[]) {
    if (raiz == NULL) {
        return criarNode(palavra);
    }

    int comparacao = strcasecmp(palavra, raiz->palavra);
    if (comparacao < 0) {
        raiz->esquerda = inserirNode(raiz->esquerda, palavra);
    } else if (comparacao > 0) {
        raiz->direita = inserirNode(raiz->direita, palavra);
    }

    return raiz;
}

void imprimirBST(Node* raiz) {
    if (raiz != NULL) {
        imprimirBST(raiz->esquerda);
        printf("%s\n", raiz->palavra);
        imprimirBST(raiz->direita);
    }
}

void liberarBST(Node* raiz) {
    if (raiz != NULL) {
        liberarBST(raiz->esquerda);
        liberarBST(raiz->direita);
        free(raiz);
    }
}

int main() {
    Node* raiz = NULL;
    char linha[201];

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        int i = 0;
        int j = 0;
        char palavra[201];

        while (linha[i] != '\0') {
            char caractere = tolower(linha[i]);

            if (isalpha(caractere)) {
                palavra[j++] = caractere;
            } else if (j > 0) {
                palavra[j] = '\0';
                raiz = inserirNode(raiz, palavra);
                j = 0;
            }

            i++;
        }

        if (j > 0) {
            palavra[j] = '\0';
            raiz = inserirNode(raiz, palavra);
        }
    }

    imprimirBST(raiz);
    liberarBST(raiz);

    return 0;
}
