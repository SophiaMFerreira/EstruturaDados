
/*      Faça um programa para gerenciar 3 filas (FIFO) de atendimento ao público.
        As filas 1 e 2 são comuns.
        A fila 3 é para atendimento preferencial.

        As chamadas para atendimento são feitas assim:
        1. Chama uma pessoa de uma fila comum (alternando entre as duas) (1, 2, 1, 2, 1, etc).
        2. Chama uma pessoa da fila preferencial.
        3. Volta ao passo 1

        Se a fila estiver vazia, chama a próxima pessoa, segundo o critério acima.
        A chegada de pessoas deve ser feita aleatoriamente. Cada nova pessoa que chegar
        terá um identificador único (inteiro crescente de um em um).

        Use um temporizador para o programa rodar “lentamente”. 3 segundos, por exemplo.
        A cada ação de chegada de pessoa ou chamada na fila, imprima as 3 filas na tela segundo o padrão abaixo:

        Fila 1: 12 → 9 → 4 → 2 → Guichê de atendimento
        Fila 2: 14 → 8 → 1 → Guichê de atendimento
        Fila 1: 10 → 6 → 3 → Guichê de atendimento

        Não precisa prever a desistência, ou seja, alguém desistir e sair da fila. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM_MAX 1000
#define FILAS 3

void entraNaFila(int fila, int *pessoa);
void bornPeople();
int chegaPessoa(int *pessoa);

typedef struct struct_fila {
    int posicaoNaFila;
} Fila;

/////////////
chamaAlguem(){
    if(FilaPreferencial){
        free(FilaPreferencial)
    }else()
    if(Fila1->posicao < Fila2->posicao){
        free(Fila1);
    }
    }
}
////////////////

int main(){
    srand(time(NULL));


    int **fila1Comum = (*int) malloc(sizeof(int));
        fila1Comum -> NULL;

    int **fila2Comum = (*int) malloc(sizeof(int));
        fila2Comum -> NULL;

    int **fila3Preferencial = (*int) malloc(sizeof(int));
        fila3Preferencial -> NULL;

    free(fila1Comum);
    free(fila2Comum);
    free(fila3Preferencial);
}

void bornPeople(){
    int *pessoa = (*int) malloc(sizeof(int));
    pessoa = rand() % TAM_MAX;
}

int chegaPessoa(int *pessoa){
    bornPeople();
    return rand() % (FILAS + 1);                //fila
}

void entraNaFila(int fila, int *pessoa){
    switch (fila){
    case 1:                                     // fila1Comum
        fila1Comum[]
        //fila1Comum ->

        [01][pessoa]
        [02]
        break;
    case 2:                                     // fila2Comum
        /////
        break;
    case 3:                                     // fila3Preferencial
        /////
        break;
    default:
        printf("ERRO AO ENTRAR NA FILA");
        break;
    }
}
