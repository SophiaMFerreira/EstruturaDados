// Fila Simples

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define PORCENTAGEM 100

typedef struct structProcesso {
    int numeroProcesso;
    int porcentConclusao;
    int contexto;
    struct structProcesso *proximoProcesso;
} Processo;

int exibeMenu();

void iniciaNovoProcesso(Processo **fila, int *numProc);
Processo* finalizaProcesso(Processo **fila);
void imprimeProcessos(Processo *fila);
void imprimeUltimoProcesso(Processo *fila);
Processo* finalizaTodos(Processo *fila);

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *numProc;
    *numProc = 0;
    Processo *fila = NULL;
    Processo *exclui = NULL;

    int opcao;
    do{
        opcao = exibeMenu();
        switch(opcao){
            case 1:
                iniciaNovoProcesso(&fila, numProc);
            break;
            case 2:
                exclui = finalizaProcesso(&fila);
                if(exclui != NULL){
                    printf("Processo %d finalizado.", exclui->numeroProcesso);
                }else{
                    printf("\nNenhum processo ativo.");
                }
                free(exclui);
            break;
            case 3:
                imprimeUltimoProcesso(fila);
            break;
            case 4:
                imprimeProcessos(fila);
            break;
            case 5:
                fila = finalizaTodos(fila);
            break;
            default:
                if(opcao != 0)
                    printf("\nOpção inválida!");
            break;
        }
    }while(opcao != 0);

    free(numProc);
    free(fila);
    free(exclui);
}

void iniciaNovoProcesso(Processo **fila, int *numProc){
    Processo *novoProcessoAtivo = (Processo*) malloc(sizeof(Processo));
    Processo *antProces = (Processo*) malloc(sizeof(Processo));

    if((novoProcessoAtivo != NULL) && (antProces != NULL)){
        novoProcessoAtivo->numeroProcesso = *numProc;
        novoProcessoAtivo->porcentConclusao = rand() % PORCENTAGEM;
        novoProcessoAtivo->contexto = rand();
        novoProcessoAtivo->proximoProcesso = NULL;
        (*numProc)++;

        if(*fila == NULL){
            *fila = novoProcessoAtivo;
            printf("Novo processo em execução.");
        }else{
            antProces = *fila;
            while(antProces->proximoProcesso != NULL){
                antProces = antProces->proximoProcesso;
            }
            antProces->proximoProcesso = novoProcessoAtivo;
            printf("Novo processo aguardado para ser executado...");
        }
    } else {
        printf("\nPouca memória, tente iniciar novamente mais tarde.");
    }
}

Processo* finalizaProcesso(Processo **fila){
    Processo *finishProcess = NULL;
    if(*fila != NULL){
        finishProcess = *fila;
        *fila = finishProcess->proximoProcesso;
    }
    return finishProcess;
}

void imprimeProcessos(Processo *fila){
    if(fila != NULL){
        printf("\n----------------= Gerenciador de Tarefas =----------------");
        while(fila != NULL){
            printf("\n Processo %02d : %d%% concuído - context %d", fila->numeroProcesso, fila->porcentConclusao, fila->contexto);
            fila = fila->proximoProcesso;
        }
        printf("\n----------------------------------------------------------");
    } else {
           printf("\nNenhum processo em execução.");
    }
}

void imprimeUltimoProcesso(Processo *fila){
    if(fila != NULL){
        while(fila->proximoProcesso != NULL){
            fila = fila->proximoProcesso;
        }
        printf("\n Processo %02d : %d%% concuído - context %d", fila->numeroProcesso, fila->porcentConclusao, fila->contexto);
    } else {
           printf("\nNenhum processo em execução.");
    }
}

Processo* finalizaTodos(Processo *fila){
    if(fila != NULL){
        return fila = NULL;
    } else {
           printf("\nNão há processos em execução para serem finalizados.");
    }
    return NULL;
}


int exibeMenu(){
    printf("\n\n ===============================");
    printf("\n 1 - Novo Processo");
    printf("\n 2 - Finaliza Processo");
    printf("\n 3 - Status Processo");
    printf("\n 4 - Gerenciador de Tarefas");
    printf("\n 5 - Fechar todos");
    printf("\n 0 - Desligar");
    printf("\n ===============================\n");

    int opcao;
    scanf("%d", &opcao);
    return opcao;
}
