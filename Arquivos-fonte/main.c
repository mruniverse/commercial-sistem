#include <stdio.h>
#include <stdlib.h>
#include "../Headers/gerenciar-estoque.h"

int main(){
    int escolha;
    int escolha2;
    int qntd;
    float precoCusto;
    float precoVenda;
    char* nome = malloc(sizeof *nome);
    char* fornecedor = malloc(sizeof *fornecedor);
    char* categoria = malloc(sizeof *categoria);
    char* validade = malloc(sizeof *validade);

    LISTA lista;
    Produto p;

    FILE *f;
    f = fopen("file.txt", "w");

    while(escolha != 0){
        system("reset");
        printf("Gerenciamento de funcionarios e de estoque\n");
        printf("------------------------------------------\n");
        printf("[1] Cadastro de Produtos\n");
        printf("[2] Ponto de venda\n");
        printf("[3] Gerenciar estoque\n");
        printf("------------------------------------------\n");
        printf("[0] Sair\n");
        printf("------------------------------------------\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                inicializarLista(&lista);
                puts("Preencha os campos a seguir:\n");

                puts("Quantidade: ");
                scanf("%d", &qntd);
                p.qntd = qntd;

                puts("\nNome do produto: ");
                scanf("%s", nome);
                fputs(nome, f);
                p.nome = nome;

                puts("\nPreço do custo: ");
                scanf("%f", &precoCusto);
                p.precoCusto = precoCusto;

                puts("\nPreço de venda: ");
                scanf("%f", &precoVenda);
                p.precoVenda = precoVenda;

                puts("\nFornecedor: ");
                fgets(fornecedor, 100, stdin);
                fputs(fornecedor, f);
                p.fornecedor = fornecedor;

                puts("\nCategoria: ");
                scanf("%s", categoria);
                p.categoria = categoria;

                puts("\nValidade(xx/xx/xx): ");
                scanf("%s", validade);
                p.validade = validade;

                puts("\n");
                inserirElemListaOrd(&lista, p);

                break;
            case 3:
                system("reset");
                while (escolha2 != 0){
                    printf("----------------------------------\n");
                    printf("[1] Excluir produtos\n");
                    printf("[2] Listar produtos pereiveis\n");
                    printf("[3] Listar todos os produtos\n");
                    printf("----------------------------------\n");
                    printf("[0] Voltar\n");
                    printf("----------------------------------\n");
                    scanf("%d", &escolha2);

                    system("reset");
                    switch(escolha2) {
                        case 3:
                            exibirLista(&lista);
                            break;
                        default:
                            break;
                    }
                }
            default:
                break;
        }
    }

    fclose(f);

    return 0;
}
