/*  6) Faça um programa em C que calcule o produto de matrizes quadradas de ordem n. Qual
    a complexidade de tempo? Conte as instruções que são função de n e compare os
    resultados.

R.: O(n^3) - Teorico
    O(n^3) - Pratico

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 5

void montaMatriz (int **matriz);
void ProdutoMatrizes (int **matriz, int **matriz2, int *oN);

main(){
    setlocale(LC_ALL, "Portuguese");
    int **matriz = (int *) malloc(sizeof(int) * N);
    int **matriz2 = (int *) malloc(sizeof(int) * N);
    int **matriz3 = (int *) malloc(sizeof(int) * N);
    int *oN = (int *) malloc(sizeof(int));
    *oN = 0;

    srand(time(NULL));

    montaMatriz (matriz);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j == 0 && i != 0){
                printf("\n");
            }
            printf("%2d ", matriz[i][j]);
        }
    }
    printf("\n\n");
    montaMatriz (matriz2);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j == 0 && i != 0){
                printf("\n");
            }
            printf("%2d ", matriz2[i][j]);
        }
    }

    printf("\n\n\n");
    ProdutoMatrizes (matriz, matriz2, oN);
    printf("\n\n\n");
    printf("O(n)= %2d ", *oN);
}

void montaMatriz (int **matriz){
    for(int i = 0; i < N; i++){
        matriz[i] = (int *) malloc(sizeof(int) * N);
        for(int j = 0; j < N; j++){
            matriz[i][j] = rand() % 10;
        }
    }
}

void ProdutoMatrizes (int **matriz, int **matriz2, int *oN){
    int soma;                                                               // 1
    for(int i = 0; i < N; i++){                                             // N + 1
        for(int j = 0; j < N; j++){                                         // N + 1
            for(int k = 0; k < N; k++){                                     // N + 1
                soma = soma + (matriz[i][k] * matriz2[k][j]);               // N
                (*oN)++;                                                    // N
            }
            printf("%3d ", soma);                                           // N
            soma = 0;                                                       // N
       }
    printf("\n");                                                           // N-1
    }                                                                       // TOT: (N+1)^3 + 4N
}


/*void ProdutoMatrizes (int **matriz, int **matriz2, int **matriz3, int *oN){
    for(int i = 0; i < N; i++){
       for(int j = 0; j < N; j++){
            int soma = 0;
            for(int k = 0; k < N; k++){
                matriz3[i][j] = matriz3[i][j] + (matriz[i][k] * matriz2[k][i]);
            }
            (*oN)++;
       }
    }
}*/
