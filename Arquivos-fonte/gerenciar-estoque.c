#include <stdio.h>
#include "produto.h"

Struct no{
  Produto p;
  int qntd;
  Struct no *prox;
  Struct no *ant;
}No;

void inicializarLista(LISTA *l){
   l->inicio=NULL;
   l->fim=NULL;
}

int tamanhoLista(LISTA *l){
    PONT end = l->inicio;
    int tam = 0;
    while(end!=NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}


void exibirLista(LISTA *l){
    PONT end = l->inicio;
    printf("\nLista: \" ");
    while(end!=NULL){
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf(" \"\n ");
}


PONT buscaSequencial(LISTA *l, TIPOCHAVE ch){
    PONT pos = l->inicio;

    while(pos != NULL){
        if(pos->reg.chave == ch) return pos;
        pos = pos->prox;
    }

    return NULL;
}


PONT buscaSequencialOrd(LISTA *l, TIPOCHAVE ch){
    PONT pos = l->inicio;
    while(pos != NULL && pos->reg.chave < ch) pos = pos->prox;
    if(pos!=NULL && pos->reg.chave == ch) return pos;
    return NULL;
}


PONT buscaSequencialExc(LISTA *l, TIPOCHAVE ch, PONT *ant){
    *ant = NULL;
    PONT atual = l->inicio;
    while (atual != NULL  &&   atual->reg.chave < ch) {
        *ant = atual;
        atual = atual->prox;
    }
    if(atual != NULL   &&   atual->reg.chave == ch) return atual;
    return NULL;
}


int inserirElemListaOrd(LISTA *l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if(i != NULL) return -1;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    i->prox=NULL;
    i->ant=NULL;
    if(l->inicio ==NULL){
        l->inicio=i;
        l->fim =i;
    }
    else if(ant == NULL){ //inicio da lista
        i->prox = l->inicio;
        l->inicio->ant = i;
        l->inicio = i;
    }
    else{
        i->prox = ant->prox;
        i->ant=ant;
        if(ant->prox==NULL) {
            l->fim=i;
        }
        else ant->prox->ant = i;
        ant->prox=i;
    }
    return 0;
}


int excluiElemLista(LISTA *l, TIPOCHAVE ch){
    PONT ant, i;
    i = buscaSequencialExc(l, ch, &ant);
    if(i == NULL) return -1;
    if(ant == NULL){
      l->inicio = i->prox;
      l->inicio->ant=NULL;
    }
    else if(i->prox==NULL){
      l->fim=i->ant;
      i->ant->prox=NULL;
    }
    else{
       ant->prox = i->prox;
       i->prox->ant=ant;
    }
    free(i);
    return 0;
}



void reinicializaLista(LISTA *l){
    PONT end = l->inicio;
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
    l->fim = NULL;
}

