/*  Quest˜ao 2: [3 pontos]
    Faca um programa que tenha uma func˜ao que retorna void e que preenche um vetor com 20 n´umeros inteiros; outra
func˜ao que tamb´em retorna void e que dobra os valores armazenados neste vetor; e uma ´ultima fun¸c˜ao que imprime este
vetor. A fun¸c˜ao main deve alocar mem´oria para este vetor, chamar a fun¸c˜ao que preenche o vetor, chamar a fun¸c˜ao que
imprime o vetor, chamar a fun¸c˜ao que dobra os elementos do vetor, chamar novamente a fun¸c˜ao que imprime o vetor,
liberar a mem´oria alocada. N˜ao use colchetes para indexar o vetor.



*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define N 5   //Vetor com 20 posições (-0,1)
#define INTERVALO 10

void imprime( int *vetor);
void preenche( int *vetor);
void dobra( int *vetor);


main(){
    setlocale(LC_ALL, "Portuguese");

    int *vetor = (int*) malloc(sizeof(int) * N);
    srand(time(NULL));

    printf("Vetor original\n");
    preenche(vetor);
    imprime(vetor);

    printf("\nVetor dobrado\n");
    dobra(vetor);
    imprime(vetor);


    free(vetor);
}

void preenche( int *vetor){
    for(int i = 0; i < N; i++){
        // Preenchiento por entrada
        //printf("Digite um numero: ");
        //scanf("%d", *(vetor + i));

        // Preenchiento aleatório
        *(vetor + i) = rand() % INTERVALO;


    }
}
void dobra( int *vetor){
    for(int i = 0; i < N; i++){
        *(vetor + i) = (*(vetor + i)) * 2;
    }
}

void imprime( int *vetor){
    for(int i = 0; i < N; i++){
        printf("%d - %d\n", i, *(vetor + i));
    }
}

