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
#include <unistd.h>

#define N_FILAS 3
#define MAX 10

typedef struct struct_fila {
    int id;
    struct struct_fila *proximaPessoa;
} PessoaFila;

void entraNaFila(PessoaFila **filaComum1, PessoaFila **filaComum2, PessoaFila **filaPrioridade3, int numeroFila, int *identificador);
int atendePessoa(PessoaFila **filaComum1, PessoaFila **filaComum2, PessoaFila **filaPrioridade3, int vezFilaComum);
void exibeFila(PessoaFila *filaComum1, PessoaFila *filaComum2, PessoaFila *filaPrioridade3);

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    PessoaFila *filaComum1 = NULL;
    PessoaFila *filaComum2 = NULL;
    PessoaFila *filaPrioridade3 = NULL;
    int *identificador;
        *identificador = 0;
    int vezFilaComum = 1;
    int contador = 0;

    do{
        int numeroFila = (rand() % N_FILAS) + 1;
        entraNaFila(&filaComum1, &filaComum2, &filaPrioridade3, numeroFila, identificador);
        //exibeFila(filaComum1, filaComum2, filaPrioridade3);
       //vezFilaComum = atendePessoa(&filaComum1, &filaComum2, &filaPrioridade3, vezFilaComum);
        sleep(3);
        //exibeFila(filaComum1, filaComum2, filaPrioridade3);
        contador++;
    }while(contador < MAX);

    free(filaComum1);
    free(filaComum2);
    free(filaPrioridade3);
}

void entraNaFila(PessoaFila **filaComum1, PessoaFila **filaComum2, PessoaFila **filaPrioridade3, int numeroFila, int *identificador){
    PessoaFila *novaPessoa = (PessoaFila*) malloc(sizeof(PessoaFila));
    if(novaPessoa != NULL){
        novaPessoa->id = *identificador;
            (*identificador)++;
        novaPessoa->proximaPessoa = NULL;
        PessoaFila *copiaFila = (PessoaFila*) malloc(sizeof(PessoaFila));

        if(numeroFila == 1){
            copiaFila = *filaComum1;
        } else{
            if(numeroFila == 2){
                copiaFila = *filaComum2;
            }else{
                copiaFila = *filaPrioridade3;
            }
        }
        if(copiaFila != NULL){
            while(copiaFila->proximaPessoa != NULL){
                copiaFila = copiaFila->proximaPessoa;
                printf("mei\n", numeroFila);
            }
            copiaFila->proximaPessoa = novaPessoa;
            printf("OK - %d a \n", numeroFila);
        } else {
            if(numeroFila == 1){
                filaComum1 = novaPessoa;
            } else{
                if(numeroFila == 2){
                    filaComum2 = novaPessoa;
                }else{
                    filaPrioridade3 = novaPessoa;
                }
            }
                printf("%d Vazia \n", numeroFila);
        }
    } else {
        printf("Falha ao alocar uma nova pessoa.");
    }
}

int atendePessoa(PessoaFila **filaComum1, PessoaFila **filaComum2, PessoaFila **filaPrioridade3, int vezFilaComum){
    if(filaPrioridade3 != NULL){
        PessoaFila *copiaFila = *filaPrioridade3;
        *filaPrioridade3 = copiaFila->proximaPessoa;
    } else {
        if(vezFilaComum == 1){
            PessoaFila *copiaFila = *filaComum1;
            if(filaComum1 != NULL){
                *filaComum1 = copiaFila->proximaPessoa;
                return 2;
            }
        }
        PessoaFila *copiaFila = *filaComum2;
        if(filaComum2 != NULL){
            *filaComum2 = copiaFila->proximaPessoa;
        }

        return 1;
    }
}

void exibeFila(PessoaFila *filaComum1, PessoaFila *filaComum2, PessoaFila *filaPrioridade3){
    printf("\n Preferencial: ");
        while(filaPrioridade3->proximaPessoa != NULL){
            printf("%d - ", filaPrioridade3->id);
            filaPrioridade3 = filaPrioridade3->proximaPessoa;
        }
        printf("%d", filaPrioridade3->id);

    printf("\n Fila 1: ");
        while(filaComum1->proximaPessoa != NULL){
            printf("%d - ", filaComum1->id);
            filaComum1 = filaComum1->proximaPessoa;
        }
         printf("%d", filaComum1->id);

    printf("\n Fila 2: ");
        while(filaComum2->proximaPessoa != NULL){
            printf("%d - ", filaComum2->id);
            filaComum2 = filaComum2->proximaPessoa;
        }
         printf("%d \n\n", filaComum2->id);
}

