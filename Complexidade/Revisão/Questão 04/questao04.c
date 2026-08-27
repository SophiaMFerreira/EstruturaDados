/* 4) Faça um programa em C para calcular o fatorial de n. Qual a complexidade de tempo?
        Conte as instruções que são função de n e compare os resultados.

R.: O(n) - Teorico
    O(n) - Pratico

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int calculaFatorial(int n, int *oN);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *oN = (int *) malloc(sizeof(int));
    *oN = 0;

    printf("\n\n Fatorial: %d", calculaFatorial(10, oN));
    printf("\n\n O(n) é: %d", *oN);
}

int calculaFatorial(int n, int *oN){
    int fatorial = n;                                                               // 1
        for(int i = n-1; i != 1; i--){                                              // n
            fatorial = fatorial * i;                                                // n-1
            (*oN)++;                                                                // n-2
        }
    return fatorial;                                                                // 1
}
                                                                                    // TOT: 3N - 1
