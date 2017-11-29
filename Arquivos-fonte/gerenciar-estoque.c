#include <stdio.h>
#include <stdlib.h>
#include "../Headers/gerenciar-estoque.h"

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
    printf("Lista: \n");
    while(end!=NULL){
      printf("----------------------------------\n");
      printf("%d Unidade(s) de ", end->p.qntd);
      printf("%s\n", end->p.nome);
      printf("Preço de custo: R$ %.2f\n", end->p.precoCusto);
      printf("Preço de venda: R$ %.2f\n", end->p.precoVenda);
      printf("Fornecedor: %s\n", end->p.fornecedor);
      printf("Catgoria: %s\n", end->p.categoria);
      printf("Validade: %s\n", end->p.validade);
      printf("----------------------------------\n");
      end = end->prox;
    }
}


PONT buscaSequencial(LISTA *l, Produto p){
    int ch = p.codigo;
    PONT pos = l->inicio;

    while(pos != NULL){
        if(pos->p.codigo == ch) return pos;
        pos = pos->prox;
    }

    return NULL;
}


PONT buscaSequencialOrd(LISTA *l, Produto p){
    int ch = p.codigo;
    PONT pos = l->inicio;
    while(pos != NULL && pos->p.codigo < ch) pos = pos->prox;
    if(pos!=NULL && pos->p.codigo == ch) return pos;
    return NULL;
}


PONT buscaSequencialExc(LISTA *l, Produto p, PONT *ant){
    int ch = p.codigo;
    *ant = NULL;
    PONT atual = l->inicio;
    while (atual != NULL  &&   atual->p.codigo < ch) {
        *ant = atual;
        atual = atual->prox;
    }
    if(atual != NULL   &&   atual->p.codigo == ch) return atual;
    return NULL;
}


int inserirElemListaOrd(LISTA *l, Produto p){
    int ch = p.codigo;
    PONT ant, i;
    i = buscaSequencialExc(l, p, &ant);
    if(i != NULL) return -1;
    i = (PONT) malloc(sizeof(No));
    i->p = p;
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


int excluiElemLista(LISTA *l, Produto p){
    int ch = p.codigo;
    PONT ant, i;
    i = buscaSequencialExc(l, p, &ant);
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
