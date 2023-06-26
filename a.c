#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
    int chave;
    char letra;
    struct cel* esq;
    struct cel* dir;
};
typedef struct cel no;

typedef no* arvore;

arvore Inicia() {
    return NULL;
}

void Erd(arvore r, char help) {  // infixa
    if (r != NULL) {
        Erd(r->esq, help);
         if(r->letra == help){
        	 printf("%c", r->letra);
         }
          else{
        	  printf(" %c", r->letra);
          }
        Erd(r->dir, help);
    }
}


void Red(arvore r, char help) {  // prefixa
    if (r != NULL) {
    	if(r->letra == help){
    		printf("%c", r->letra);
    	}
    	else{
    		printf(" %c", r->letra);
    	}
        Red(r->esq, help);
        Red(r->dir, help);
    }
}

void Edr(arvore r, char help) {  // posfixa
    if (r != NULL) {
        Edr(r->esq, help);
        Edr(r->dir, help);
        if (r->letra == help) {
            printf("%c", r->letra);
        } else {
            printf("%c ", r->letra);
        }
    }
}

arvore Insere(arvore r, char letra) {
    if (r == NULL) {
        no* novo = malloc(sizeof(no));
        novo->letra = letra;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (letra < r->letra) {
        r->esq = Insere(r->esq, letra);
    } else if (letra > r->letra) {
        r->dir = Insere(r->dir, letra);
    }

    return r;
}

no* Busca(arvore r, char letra) {
    if (r == NULL || r->letra == letra) {
        return r;
    }
    if (letra < r->letra) {
        return Busca(r->esq, letra);
    } else {
        return Busca(r->dir, letra);
    }
}

int main() {
    char op[10];
    char elemento, help1, help2;
    arvore arv, aux;

    arv = Inicia();

    while (scanf("%s", op) != EOF) {
    	aux = arv;

        if (strcmp(op, "I") == 0) {
            scanf(" %c", &elemento);
            arv = Insere(arv, elemento);
        }
        help1= arv->letra;

        if (strcmp(op, "P") == 0) {
            scanf(" %c", &elemento);
            if (Busca(arv, elemento) != NULL) {
            	printf("%c existe\n", elemento);
            } else {
                printf("%c nao existe\n", elemento);
            }
        }

        if (strcmp(op, "INFIXA") == 0) {
            aux = arv;
            while (aux->esq != NULL) {
                aux = aux->esq;
            }
            help2 = aux->letra;
            Erd(arv, help2);
            printf("\n");
        }

        if (strcmp(op, "PREFIXA") == 0) {
            Red(arv, help1);
            printf("\n");
        }

        if (strcmp(op, "POSFIXA") == 0) {
            Edr(arv, help1);
            printf("\n");
        }
    }

    return 0;
}
