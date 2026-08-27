/* 1) Faça um programa em C para encontrar o maior elemento de um vetor (lista) com n
elementos aleatórios não ordenados. Qual a complexidade de tempo? Conte as instruções
que são função de n e compare os resultados.

R.: O(n!) - Teorico
    O(n) - Pratico

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 5

void montaVetor(int *vetor);
int encontraMaior(int *vetor, int *oN);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *vetor = (int *) malloc(sizeof(int)* N);
    int *oN = (int *) malloc(sizeof(int));
    *oN = 0;
    srand(time(NULL));

    montaVetor(vetor);
    for(int i = 0; i < N; i++){
        printf("\n%d - %d", i, *(vetor + i));
    }

    printf("\n\n O maior é: %d", encontraMaior(vetor, oN));
    printf("\n\n O(n) é: %d", *oN);
}

void montaVetor(int *vetor){
    for(int i = 0; i < N; i++){
        *(vetor + i) = rand();
    }
}

int encontraMaior(int *vetor, int *oN){                             // ---------- O(?) ----------
    int maior = *vetor;                                             // 1
    for(int i = 1; i < N; i++){                                     // N
        (*oN)++;                                                    // N
        if(maior < *(vetor + i)){                                   // A n2 = (n!/(n-2)!
            maior = *(vetor + i);                                   // A n2 = (n!/(n-2)!
        }
    }

    return maior;                                                   // 1
}
                                                                    // TOT: 2N + 2(n!/(n-2)! = O(n!)
