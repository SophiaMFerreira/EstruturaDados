/*
    1. Criar uma lista com números aleatórios.
    2. Implementar o método de ordenação bubble sort interativo.
    3. Qual a complexidade? R.:O(n^2)
    4. Contar as instruções relevantes e confrontar com a complexidade informada no item 3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO_VET 100

void montaVetor(int *apontaVetor);
int bubleSort(int *apontaVetor);

main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int vetor = (int *) malloc(sizeof(int)* TAMANHO_VET);
    int *apontaVetor = vetor;

    montaVetor(apontaVetor);
    for(int i = 0; i < TAMANHO_VET; i++){
        printf("\n %d - %d", i, *(apontaVetor + i));
    }

    printf("\n\n BUBLE:");
    bubleSort(apontaVetor);
    for(int i = 0; i < TAMANHO_VET; i++ ){
         printf("\n %d - %d", i, *(apontaVetor + i));
    }
    printf("\n\nComplexidade Buble: %d", bubleSort(apontaVetor));
    free(vetor);
}

void montaVetor(int *apontaVetor){
    int intRand;
    for(int i = 0; i < TAMANHO_VET; i++){
        intRand = rand() % TAMANHO_VET;
        *(apontaVetor + i) = intRand;
    }
}

int bubleSort(int *apontaVetor){
    int complexidade = 0;
    for(int i = 0; i < TAMANHO_VET - 1; i++){
        for(int j = 1; j < TAMANHO_VET - i; j++){
            if(*(apontaVetor + j) < *(apontaVetor + (j - 1))){
               int auxiliar = *(apontaVetor + (j - 1));
                *(apontaVetor + (j - 1)) = *(apontaVetor + j);
                *(apontaVetor + j) = auxiliar;
            }
            complexidade++;
        }
        complexidade++;
    }
    return complexidade;
}
