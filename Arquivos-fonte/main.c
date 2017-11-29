#include <stdio.h>
#include <stdlib.h>
#include "../Headers/gerenciar-estoque.h"

int main(){
    int temp;
    
    printf("Gerenciamento de funcionarios e de estoque\n");
    printf("------------------------------------------\n");
    printf("[1] Cadastro de Produtos\n");
    printf("[2] Ponto de venda\n");
    printf("[3] Gerenciar estoque\n");
    printf("------------------------------------------\n");
    printf("[0] Sair\n");
    scanf("%d",temp);
    switch(temp){
        case 3:
            printf("[1] Cadastro de produtos");
            printf("[2] Produtos pereiveis\n");
    }
    
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
    // excluiElemLista(&lista, p);

    return 0;
}
