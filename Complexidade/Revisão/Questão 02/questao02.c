/* 2) Faça um programa em C para encontrar o maior elemento de um vetor (lista) com n
        elementos aleatórios ordenados de forma crescente. Qual a complexidade de tempo?
        Conte as instruções que são função de n e compare os resultados.


R.: O(n) - Teorico
    O(n) - Pratico

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 5

void montaVetor(int *vetor);
int achaMaior(int *vetor, int *oN);

main(){
    setlocale(LC_ALL, "Portuguese");

    int *vetor = (int*) malloc(sizeof(int) * N);
    int *oN = (int*) malloc(sizeof(int));
    *oN = 0;

    montaVetor(vetor);
    for(int i = 0; i < N; i++){
        printf("\n%d - %d", i, *(vetor + i));
    }
    printf("\nMaior: %d", achaMaior(vetor,oN));
    printf("\nO(N)- %d", *oN);

}

void montaVetor(int *vetor){
    int parametro = 0;
    for(int i = 0; i < N; i++){
        int nAtual;
        do{
            nAtual = rand();
        }while(parametro > nAtual);

        *(vetor + i) = nAtual;
        parametro = *(vetor + i);
    }
}

/*int achaMaior(int *vetor, int *oN){
    int maior = 0;
    int auxiliar = 0;
    for(int i = 1; trunc((N / pow(2, i)) != 0); i++){
        int indice = (N / pow(2, i)) + auxiliar;
        if(maior < *(vetor + indice)){
            maior = *(vetor + indice);
            auxiliar = indice;
            (*oN)++;
        }
        (*oN)++;
    }
    return maior;
}*/

int achaMaior(int *vetor, int *oN){
    int maior = *vetor;                                 // 1
    int auxiliar = 0;                                   // 1
    for(int i = 1; i < N; i++){                         // N
        if(maior < *(vetor + i)){                       // N - 1
            maior = *(vetor + i);
            (*oN)++;
        }
        (*oN)++;
    }
    return maior;
}                                                       // 2N + 1
