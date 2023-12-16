#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct dados_produtos{
    char nome[200];
    float valor;
    int estoque;
};

float calculoValor(struct dados_produtos prod){
    return prod.valor * prod.estoque;  
}

void compraprod(struct dados_produtos *prod,int quantidade){
    if(quantidade > 0 && quantidade <= prod->estoque){
        prod->estoque -= quantidade;
        printf("\nCompra Realizada com Sucesso!!");
    }else{
        printf("Produto Indisponivel ou Indisponivel no estoque!\n");
    }
}