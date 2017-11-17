#ifndef DUPLAMENTE_H_INCLUDED
#define DUPLAMENTE_H_INCLUDED

#include <stdio.h>

Struct produto{
    int codigo;
    double precoCusto;
    double precoVenda;
    string nome;
    string categoria;
    string validade;
}Produto

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
    struct aux* ant;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}LISTA;


void inicializarLista(LISTA *);
int tamanhoLista(LISTA *);
void exibirLista(LISTA *);
PONT buscaSequencial(LISTA *, TIPOCHAVE);
PONT buscaSequencialOrd(LISTA *, TIPOCHAVE);
PONT buscaSequencialExc(LISTA *, TIPOCHAVE, PONT *);
int inserirElemListaOrd(LISTA *, REGISTRO);
int excluiElemLista(LISTA *, TIPOCHAVE);



#endif // DUPLAMENTE_H_INCLUDED
