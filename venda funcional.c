#include <stdio.h>
#include <stdlib.h>

struct Produto
{
    char nome[200];
    float preco;
    int estoque;
};

float calcularValor(struct Produto pro)
{
    return pro.preco * pro.estoque;
}

void comprar(struct Produto *pro, int quantidade)
{
    if (quantidade > 0 && quantidade <= pro->estoque)
    {
        pro->estoque -= quantidade;
        printf("Compra realizada com sucesso!\n");
    }
    else
    {
        printf("Quantidade invalida ou insuficiente em estoque.\n");
    }
}

int main()
{
    struct Produto pro;
    int opcao, quantidade;

    pro.estoque = 0;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Realizar uma compra\n");
        printf("3 - Consultar estoque\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            printf("Digite o nome do produto: ");
            scanf("%s", pro.nome);
            printf("Digite o preco do produto: R$ ");
            scanf("%f", &pro.preco);
            printf("Digite a quantidade em estoque: ");
            scanf("%d", &pro.estoque);
            break;

        case 2:
            printf("Digite a quantidade a ser comprada: ");
            scanf("%d", &quantidade);
            comprar(&pro, quantidade);
            break;

        case 3:
            printf("Nome: %s\n", pro.nome);
            printf("Preço: R$ %.2f\n", pro.preco);
            printf("Quantidade em estoque: %d\n", pro.estoque);
            printf("Valor total em estoque: R$ %.2f\n", calcularValor(pro));
            break;

        case 4:
            printf("Saindo do programa.\n");
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");

        }

    } while (opcao != 4);

    return 0;
}