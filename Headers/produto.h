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



int excluiElemLista(LISTA *, TIPOCHAVE);
int inserirElemListaOrd(LISTA *, REGISTRO);
PONT buscaSequencialExc(LISTA *, TIPOCHAVE, PONT *);
PONT buscaSequencialOrd(LISTA *, TIPOCHAVE);
PONT buscaSequencial(LISTA *, TIPOCHAVE);
void exibirLista(LISTA *);
int tamanhoLista(LISTA *);
void inicializarLista(LISTA *);


#endif // DUPLAMENTE_H_INCLUDED