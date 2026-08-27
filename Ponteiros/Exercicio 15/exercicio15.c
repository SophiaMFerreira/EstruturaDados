/*  15. Codificar uma função capaz de calcular o faturamento total obtido com as vendas
        realizadas. A função deve receber como parâmetro os valores de todas as vendas
        realizadas.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N_VENDAS 5

int *armazenaVendas();
int calculaFaturamento (int *vendas);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int faturamento = calculaFaturamento(armazenaVendas());
    printf("\nO faturamento foi de R$%d", faturamento);
}

int *armazenaVendas(){
    int *vendas;
    vendas = (float *) malloc(sizeof(float) * N_VENDAS);

    for(int i = 0; i < N_VENDAS; i++){
        printf("Indique o valor da venda:");
        scanf("%d", (vendas + i));
    }

    return vendas;
}

int calculaFaturamento (int *vendas){
    int faturamento = 0;
    for(int i = 0; i < N_VENDAS; i++){
        faturamento = faturamento + *(vendas + i);
    }
    return faturamento;
}
