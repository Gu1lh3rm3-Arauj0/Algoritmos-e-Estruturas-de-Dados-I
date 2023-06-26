#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noh{
  char letra;
  struct noh *esq;
  struct noh *dir;
};

typedef struct noh nohArvore;
typedef nohArvore *TipoArv;

int Vazia(TipoArv arvore){
  return arvore==NULL;
}

TipoArv Inicia(){
  return NULL;
}

TipoArv Destroi(TipoArv arvore){
  if(!Vazia(arvore)){
    Destroi(arvore->esq);
    Destroi(arvore->dir);
    free(arvore);
  }
  return NULL;
}

TipoArv Instancia(TipoArv arvore, char letra){
  arvore= (TipoArv) malloc (sizeof(TipoArv));

  arvore->esq=NULL;
  arvore->dir=NULL;
  arvore->letra=letra;

  return arvore;
}

TipoArv Buscar(TipoArv arvore, char letra){

  if(!Vazia(arvore)){
    if(arvore->letra > letra){
      arvore->esq= Buscar(arvore->esq, letra);
    }
    if(arvore->letra < letra){
      arvore->dir= Buscar(arvore->dir, letra);
    }
  }
  else{
    arvore= Instancia(arvore, letra);
  }

  return arvore;
}

void imprimeArvorePreOrdem(TipoArv arvore, char help){

  if(!Vazia(arvore)){
      printf("%c", arvore->letra);
    imprimeArvorePreOrdem(arvore->esq, help);
    imprimeArvorePreOrdem(arvore->dir, help);
  }
  return;
  }

void imprimeArvoreEmOrdem(TipoArv arvore, char help){

  if(!Vazia(arvore)){
    imprimeArvoreEmOrdem(arvore->esq, help);
    printf("%c", arvore->letra);
    imprimeArvoreEmOrdem(arvore->dir, help);

  }
  return;
}

void imprimeArvorePosOrdem(TipoArv arvore, char help){

  if(!Vazia(arvore)){
    imprimeArvorePosOrdem(arvore->esq, help);
    imprimeArvorePosOrdem(arvore->dir, help);
    printf("%c", arvore->letra);
  }
  return;
}

int VerificaExistencia(TipoArv arvore, char letra){

  while(!Vazia(arvore)){
    if(arvore->letra == letra){
      return 1;
    }
    if(arvore->letra > letra){
      arvore= arvore->esq;
    }
    if(arvore->letra < letra){
      arvore= arvore->dir;
    }
  }
  return 0;
}

TipoArv Insere(TipoArv arvore, char novo, int pp, int pia, int pi, int raiz){

  if(!Vazia(arvore)){
      if(pi<raiz){
        //printf("%c-esq. %d-pi. %d-raiz. %d-pia. %d-pp\n", novo, pi, raiz, pia, pp);
        raiz=pia;
        arvore->esq=Insere(arvore->esq, novo, pp, pia, pi,raiz);
      }
      else{
        //printf("%c-dir. %d-pi. %d-raiz. %d-pia. %d-pp\n", novo, pi, raiz, pia, pp);
        raiz=pia;
        arvore->dir=Insere(arvore->dir, novo, pp, pia, pi,raiz);
      }
    }
    else{
      arvore= Instancia(arvore, novo);
      }
  return arvore;
}

int main(void) {
  TipoArv arvore;
  int casos, cont, cont1, pia=0,pi, pp/*posicao da raiz*/, qnt;
  char prefixa[99];
  char infixa[99];
  char raiz, novo;

      scanf("%d", &casos);

    for(cont=0; cont<casos; cont++){

      arvore=Inicia();

      scanf("%d", &qnt); // quantos elementos na arvore

      scanf("%s", prefixa);
      scanf("%s", infixa);

      for(pp=0; pp<qnt; pp++){

        for(cont1=0; infixa[cont1] != prefixa[0]; cont1++);
        raiz=cont1;

        for(pi=0; infixa[pi] != prefixa[pp]; pi++);
        novo=infixa[pi];
        arvore= Insere(arvore,novo, pp, pia,  pi,raiz);
        pia=pi;
      }

      raiz=arvore->letra;

      imprimeArvorePosOrdem(arvore, raiz);
      printf("\n");
    }

  return 0;
}
