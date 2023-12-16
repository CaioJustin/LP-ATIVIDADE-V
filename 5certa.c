#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct produto
{
    char nome[100];
    float preco;
    int quantidade;
};

float totalv(struct produto box){
    return box.preco*box.quantidade;
};

void comprar(struct produto *box, int quantidade)
{
    if (quantidade > 0 && quantidade <= box->quantidade)
    {
        box->quantidade -= quantidade;
        printf("Compra realizada com sucesso!\n");
    }
    else
    {
        printf("Quantidade invalida ou insuficiente em estoque.\n");
    }
}


int main (){

int opcao;
int quantidade;
setlocale(LC_ALL,"portuguese");

struct produto box;

do
{
    printf("\nMENU DE OPCAO");
    printf("\n1 ADICIONAR PRODUTO");
    printf("\n2 REALIZAR UMA COMPRA");
    printf("\n3 CONSULTAR ESTOQUE");
    printf("\n4 Nota Fiscal");
    printf("\n5 Sair do Programa");

    printf("\n\nDigite a opcao:");
    scanf("%d",&opcao);

    fflush(stdin);
    
    switch (opcao)
    {
    case 1:
        
        printf("\n========Cadastre o Produto no Estoque ===========");
        printf("\nDigite o nome do produto:");
        gets(box.nome);

        fflush(stdin);

        printf("\nDigite o preco do produto:");
        scanf("%f",&box.preco);

        fflush(stdin);

        printf("\nDigite a quantidade do produto:");
        scanf("%d",&box.quantidade);

        totalv(box);
        system("cls");
        break;
    case 2:
            printf("\n============Compre o seu Produto=========");
            printf("\nDigite o produto que voce deseja comprar:");
            scanf("%d",&quantidade);
            comprar(&box, quantidade);

        break;    
    case 3 :
        
        printf("\nEstoque de Mercadoria");
        printf("\n|Nome do produto  |Quantidade do | Preco |Valor total|");
        printf("\n|       %s        |     %d       |  %.1f   |%.1f    |",box.nome,box.quantidade,box.preco,totalv(box));      
        break;
    case 4: 
        system("cls");
        printf("\n==========NOTA FISCAL=========\n");
        printf("\nNome do produto: %s",box.nome);
        printf("\nQuantidade: %d",box.quantidade);
        printf("\nValor Total do Produto: %.2f",box.preco);
        printf("\n============================\n");
        printf("\nQuantidade Comprada: %d",quantidade);
        printf("\nPreço Unitário: R$%.2f",(box.preco/quantidade));
        printf("\n=============================\n");


        break;
    default:
      printf("\nEssa opcao nao Tente Novamente!");
        break;
    }
   
} while (opcao != 5 );

    return 0;
}