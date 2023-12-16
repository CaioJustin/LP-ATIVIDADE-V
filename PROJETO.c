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
    
    printf("\n---Menu de Opção---");
    printf("\n====================");
    printf("\n1| Adicionar um Item ao Estoque");
    printf("\n2| Efetuar uma compra");
    printf("\n3| Verificar o Estoque");
    printf("\n4| Exibir Nota Fiscal");
    printf("\n5| Sair do Programa");

    printf("\n=======================");
    printf("\nDigite Uma Opção:");
    scanf("%d",&opcao);

    fflush(stdin);
    
    switch (opcao)
    {
    case 1:
        printf("\n==================================");
        printf("\n------ Adicione o Produto ------");
        printf("\n==================================");
        printf("\nDigite o nome do produto:");
        gets(box.nome);
        printf("-------------------------------------");
        fflush(stdin);

        printf("\nDigite o preco do produto:");
        scanf("%f",&box.preco);
        printf("-------------------------------------");
        fflush(stdin);

        printf("\nDigite a quantidade do produto:");
        scanf("%d",&box.quantidade);
        printf("-------------------------------------");
        printf("\n==================================");

        totalv(box);
        system("cls");
        break;
    case 2:
        printf("\n===========================================");
        printf("\n------Quantidades de Itens Retirados ------");
        printf("\n===========================================");
            printf("\nQuantos foram Retirados: ");
            scanf("%d",&quantidade);
            comprar(&box, quantidade);

        break;    
    case 3 :
        printf("\n============================================");
        printf("\n\t----Estoque de Mercadoria----");
        printf("\n|Nome do produto  |Quantidade do Estoque | Preço do Produto|");
        printf("\n|       %s        |     %d               |  %.1f           |",box.nome,box.quantidade,box.preco);
        printf("\n============================================");      
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