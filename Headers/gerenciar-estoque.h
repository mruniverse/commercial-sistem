#ifndef DUPLAMENTE_H_INCLUDED
#define DUPLAMENTE_H_INCLUDED

#include <stdio.h>

typedef struct produto{
    int codigo;
    int qntd;
    double precoCusto;
    double precoVenda;
    char* nome;
    char* categoria;
    char* validade;
}Produto;

typedef struct aux{
    Produto p;
    struct aux* prox;
    struct aux* ant;
}No;

typedef No* PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}LISTA;


void inicializarLista(LISTA *);
int tamanhoLista(LISTA *);
void exibirLista(LISTA *);
PONT buscaSequencial(LISTA *, int);
PONT buscaSequencialOrd(LISTA *, int);
PONT buscaSequencialExc(LISTA *, int, PONT *);
int inserirElemListaOrd(LISTA *, Produto);
int excluiElemLista(LISTA *, int);



#endif // DUPLAMENTE_H_INCLUDED
