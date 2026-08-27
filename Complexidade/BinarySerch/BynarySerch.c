/*
    1. Use a lista ordenada do exercício anterior.
    2. Implemente a busca binária.
    3. Qual a complexidade? O(log n)
    4. Contar as instruções relevantes e confrontar com a complexidade informada no item 3. - As informações batem (log 10  na base 2)
    5. Rode várias vezes e tire a média. = 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO_VET 1024

void montaVetor(int *apontaVetor);
void bubleSort(int *apontaVetor);
int binarySearch(int chave, int *apontaVetor);
float complexidadeMedia(int *apontaVetor, int repeticoes);

main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int vetor = (int *) malloc(sizeof(int)* TAMANHO_VET);
    int *apontaVetor = vetor;

    //printf("\nComplexidade binária (5x): %.2f", complexidadeMedia(apontaVetor, 5)); // Valores entre 4 e 6
    //printf("\nComplexidade binária (10x): %.2f", complexidadeMedia(apontaVetor, 10)); // APOX 6
    printf("\nComplexidade binária (100x): %.2f", complexidadeMedia(apontaVetor, 100)); // 4 ou 5 - com 1000 também
    free(vetor);
}

void montaVetor(int *apontaVetor){
    int intRand;
    for(int i = 0; i < TAMANHO_VET; i++){
        intRand = rand() % TAMANHO_VET;
        *(apontaVetor + i) = intRand;
    }
}

void bubleSort(int *apontaVetor){
    for(int i = 0; i < TAMANHO_VET - 1; i++){
        for(int j = 1; j < TAMANHO_VET - i; j++){
            if(*(apontaVetor + j) < *(apontaVetor + (j - 1))){
               int auxiliar = *(apontaVetor + (j - 1));
                *(apontaVetor + (j - 1)) = *(apontaVetor + j);
                *(apontaVetor + j) = auxiliar;
            }
        }
    }
}

int binarySearch(int chave, int *apontaVetor){
        int fim = TAMANHO_VET;
        int inicio = 0;
        int meio = 0;
        int contadorComplex = 0;

        do{
            contadorComplex++;
            meio = (fim + inicio) / 2;

            if(*(apontaVetor + meio) == chave){
                return contadorComplex;
            }else{
                if(*(apontaVetor + meio) > chave){
                    fim = meio - 1;
                }else{
                    inicio = meio + 1;
                }
            }
        }while(meio != inicio && meio != fim);
        return contadorComplex + 1;
}

float complexidadeMedia(int *apontaVetor, int repeticoes){
    int somaComplexidade = 0;

    for(int i = 0; i < repeticoes; i++){
        montaVetor(apontaVetor);
        bubleSort(apontaVetor);

        int chave = rand() % TAMANHO_VET;
        somaComplexidade += binarySearch(chave, apontaVetor);
    }
    return (float) somaComplexidade / repeticoes;
}
