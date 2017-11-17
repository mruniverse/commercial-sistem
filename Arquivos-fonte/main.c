#include <stdio.h>
#include <stdlib.h>
#include "../Headers/gerenciar-estoque.h"

int main(){
    LISTA lista;
    Produto p;

    int codigo;
    int qntd;
    double precoCusto;
    double precoVenda;
    char* nome;
    char* categoria;
    char* validade;

    inicializarLista(&lista);

    p.codigo = 1;
    p.qntd = 10;
    p.nome = "Suco";
    inserirElemListaOrd(&lista, p);
    p.codigo = 2;
    p.qntd = 123;
    p.nome = "Abacate";
    inserirElemListaOrd(&lista, p);
    exibirLista(&lista);

    return 0;
}
