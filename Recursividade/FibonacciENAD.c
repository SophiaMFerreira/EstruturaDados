//  3 - Resolva a questão abaixo manualmente. Depois, coloque um contador de chamadas recursivas para validar a sua solução.

int fibonacciENADE (int posicao);
int chamadas = 0;

main(){
    printf("\nChamadas de fibonacci ate %d:", 5);
    fibonacciENADE (5);
    printf("\n%d", chamadas);
}

int fibonacciENADE (int posicao){
    int soma;
    if(posicao == 0){
        chamadas += 1;
        return 0;
    }
    if(posicao == 1){
        chamadas += 1;
        return 1;
    } else {
        chamadas += 1;
        return fibonacciENADE(posicao - 1) + fibonacciENADE(posicao - 2);
    }
}
