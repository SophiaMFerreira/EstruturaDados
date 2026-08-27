/*      5) Faça um programa em C que conte quantos pares de números em um vetor (lista) de
        tamanho n possuem soma igual a um valor k. Qual a complexidade de tempo? Conte as
        instruções que são função de n e compare os resultados.

        Exemplo: vetor = {1, 5, 7, -1, 5}
                 k = 6
                 Resposta: 3: (1, 5), (1, 5), (7, -1)

R.: O(n^2) - Teorico = 100
    O(n^2) - Pratico = 3*10

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 5

void montaVetor(int *vetor);
int encontraParesSoma(int *vetor, int valSoma, int *oN);
int calculaOnMedio (int *vetor, int valSoma, int *oN);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *vetor = (int *) malloc(sizeof(int)* N);
    int *oN = (int *) malloc(sizeof(int));
        *oN = 0;

    srand(time(NULL));

    printf("Vetor");
    montaVetor(vetor);
    for(int i = 0; i < N; i++){
        printf("\n%d - %d", i, *(vetor + i));
    }

    printf("\n\n");
    printf("Numero pares é: %d", encontraParesSoma(vetor, 6, oN));
    printf("\n\nO(n) é: %d", *oN);

    printf("\n\nO(n) médio é: %d", calculaOnMedio(vetor, 0, oN));
}

void montaVetor(int *vetor){
    for(int i = 0; i < N; i++){
        *(vetor + i) = rand() % N;
    }
}

int encontraParesSoma(int *vetor, int valSoma, int *oN){
    int soma = 0, pares = 0;                                                            // 1
    for(int i = 0; i < N; i++){                                                         // N
        for(int j = i+1; j < N; j++){                                                   // N * (N - 1) / 2
            soma = *(vetor + i) + *(vetor + j);                                         // 1
            if(soma == valSoma){
                printf("(%d + %d)\n", *(vetor + i), *(vetor + j));
                pares++;
                (*oN)++;
            }
            (*oN)++;
        }
        (*oN)++;
    }
    return pares;
}

int calculaOnMedio (int *vetor, int valSoma, int *oN){
    int soma = 0;
    for(int i = 0; i < 100; i++){
            int val = rand() % N;
            encontraParesSoma(vetor, val, oN);
            soma += *oN;
        }
        return (soma / 100);
}
                                                                                        // TOT: N^2 + 3N + 1

