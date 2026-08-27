// 2 - Faça um programa recursivo para gerar a sequência de Fibonacci.

int sequenciafibonacci (int posicao);

main(){
    int posicao;
    printf("Escolha um numero: ");
    scanf("%d", &posicao);

    printf("\nSequencia de fibonacci ate %d:", posicao);
    printf("\n%d", sequenciafibonacci(posicao));
}

int sequenciafibonacci (int posicao){
    int soma;
    if(posicao == 1 || posicao == 2){
        return 1;
    } else {
        soma = sequenciafibonacci(posicao - 1) + sequenciafibonacci(posicao - 2);
        return soma;
    }
}

