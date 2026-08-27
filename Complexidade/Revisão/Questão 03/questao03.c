/*      3) Faça um programa em C para calcular a matriz transposta de uma matriz quadrada de
        ordem n. Qual a complexidade de tempo? Conte as instruções que são função de n e
        compare os resultados.

R.: O(n!) - Teorico
    O(n^2) - Pratico

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 4

void montaMatriz(int **matriz);
void calculaTransposta(int **matriz, int *oN);

main(){
    setlocale(LC_ALL, "Portuguese");
    int **matriz = (int *) malloc(sizeof(int) * N);
    int *oN = (int *) malloc(sizeof(int));
    *oN = 0;
    srand(time(NULL));

    montaMatriz(matriz);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j == 0 && i != 0){
                printf("\n");
            }
            printf("%2d ", matriz[i][j]);
        }
    }

    printf("\n\n\n\n");

    calculaTransposta(matriz, oN);
        for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j == 0 && i != 0){
                printf("\n");
            }
            printf("%2d ", matriz[i][j]);
        }
    }

    printf("\n\nO(n) = %d ", *oN);
}

void montaMatriz(int **matriz){
    int  auxiliar = 0;
    for(int i = 0; i < N; i++){
        matriz[i] = (int *) malloc(sizeof(int) * N);
        for(int j = 0; j < N; j++){
            //matriz[i][j] = rand() % N;
            matriz[i][j] = auxiliar;
            auxiliar++;
        }
    }
}

void calculaTransposta(int **matriz, int *oN){
    int auxiliar;                                                                    // 1
    for(int i = 0; i < N; i++){                                                      // N+1
        for(int j = 0; j < N; j++){                                                  // (N+1)^2
            if(i < j){
                auxiliar = matriz[i][j];
                matriz[i][j] = matriz[j][i];
                matriz[j][i] = auxiliar;
            }
            (*oN)++;                                                                 // (N+1)^2

        }
    }
}
                                                                    /// TOT: 2 + N +2(N + 1)^2
