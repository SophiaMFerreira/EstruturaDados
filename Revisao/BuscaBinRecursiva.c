//Implementar a busca binária recursiva.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define TAMANHO_VET 10

binarySearch(int *vetor, int valor, int inicio, int fim);

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int j = 0;

    int *vetor = (int*) malloc(sizeof(int) * TAMANHO_VET);
    for(int i = 0; i < TAMANHO_VET; i++){
       j = j + 2;
       *(vetor + i) = j;
    }

    int retorno = binarySearch(vetor, 16, 0, TAMANHO_VET - 1);
    printf("Busca de valor existente: %d\n", retorno);

    retorno = binarySearch(vetor, 7, 0, TAMANHO_VET - 1);
    printf("Busca de valor inexistente: %d\n", retorno);
    free(vetor);
}

int binarySearch(int *vetor, int valor, int inicio, int fim){
    int meio = ((fim - inicio) / 2) + inicio;

    if(*(vetor + meio) == valor){
        return valor;
    } else {
        if(valor < *(vetor + meio)){
            return binarySearch(vetor, valor, inicio, meio);
        }else{
            if(inicio == meio){
                return -1;
            } else {
                return binarySearch(vetor, valor, meio, fim);
            }
        }
    }
}
