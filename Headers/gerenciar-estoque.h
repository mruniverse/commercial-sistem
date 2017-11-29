#ifndef DUPLAMENTE_H_INCLUDED
#define DUPLAMENTE_H_INCLUDED

#include <stdio.h>

typedef struct produto{
    int codigo;
    int qntd;
    float precoCusto;
    float precoVenda;
    char* fornecedor;
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
PONT buscaSequencial(LISTA *, Produto);
PONT buscaSequencialOrd(LISTA *, Produto);
PONT buscaSequencialExc(LISTA *, Produto, PONT *);
int inserirElemListaOrd(LISTA *, Produto);
int excluiElemLista(LISTA *, Produto);



#endif // DUPLAMENTE_H_INCLUDED
