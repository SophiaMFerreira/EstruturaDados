// 1 - Faça o fatorial recursivo.

int calculaFatorial (int n);

main(){
    int n;
    printf("Escolha um numero: ");
    scanf("%d", &n);

    printf("\nFatorial de %d e %d", n, calculaFatorial(n));
}

int calculaFatorial (int n){
    if(n == 1){
        return 1;
    } else {
        return calculaFatorial(n - 1) * n;
    }
}
