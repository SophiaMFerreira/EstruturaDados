// Aluna: Sophia Agnes de Machado Ferreira
// Prova B
// Questão 02

/*
    O governo de uma regi˜ao contratou uma empreiteira para construir trechos de uma estrada.
    Quando uma verba é liberada, um novo trecho é contratado e inserido em uma fila. Cada trecho possui o atributo extens˜ao (float).
    Quando termina um trecho, a empreiteira avisa ao governo e o trecho é retirado da fila.
    Faça um programa com um menu que permita:
        1) A inclus˜ao de um novo trecho, quando a verba é liberada;
        2) A remoç˜ao de um trecho, quando a empreiteira concluir o trecho;
        3) O cálculo da extens˜ao total ainda a ser feita;
        4) A impress˜ao de todos os trechos ainda a serem construídos;
        5) Sair do programa. (lista-pilha-fila-002)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct structEstrada {
    float extensaoTrexo;
    struct structEstrada *proximoTrexo;
} Estrada;

int exibeMenu();
void incluirNovoTrexo(Estrada **filaEstrada);
Estrada* removerTrexo(Estrada *filaEstrada);
float calculaExtensaoAFazer(Estrada *filaEstrada);
void imprimirTrexos(Estrada *filaEstrada);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    Estrada *filaEstrada = NULL;

    do{
        opcao = exibeMenu();
        switch(opcao){
            case 1:
                incluirNovoTrexo(&filaEstrada);
                printf("\tTrexo incluído com sucesso");
                break;
            case 2:
                filaEstrada = removerTrexo(filaEstrada);
                break;
            case 3:
                printf("\tRestam %.2f km de estradas a fazer.", calculaExtensaoAFazer(filaEstrada));
                break;
            case 4:
                imprimirTrexos(filaEstrada);
                break;
            default:
                if(opcao != 5){
                    printf("\n\tOpção inválida.");
                }
                break;
        }
    }while(opcao != 5);

    free(filaEstrada);
}

int exibeMenu(){
    printf("\n\n\t------------------------=MENU=-----------------------\n");
    printf("\t\t 1. Novo Trecho\n");
    printf("\t\t 2. Finalizar Trecho\n");
    printf("\t\t 3. Calcular Extensão a Finalizar\n");
    printf("\t\t 4. Imprimir trexos a Finalizar\n");
    printf("\t\t 5. Sair\n");
    printf("\t------------------------------------------------------\n");
    printf("\t");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

void incluirNovoTrexo(Estrada **filaEstrada){
    Estrada *novoTrexo = (Estrada*) malloc(sizeof(Estrada));
    Estrada *copiaFila = *filaEstrada;
    if(novoTrexo){
        printf("\n\tExtensão do novo trexo: ");
        scanf("%f", &novoTrexo->extensaoTrexo);
        novoTrexo->proximoTrexo = NULL;

        if(*filaEstrada){
            while(copiaFila->proximoTrexo != NULL){
                copiaFila = copiaFila->proximoTrexo;
            }
            copiaFila->proximoTrexo = novoTrexo;
        } else {
            *filaEstrada = novoTrexo;
        }
    } else {
        printf("\tErro ao criar novo trexo.");
    }
}

Estrada* removerTrexo(Estrada *filaEstrada){
    if(filaEstrada){
        Estrada *trexoRemovido = filaEstrada;
        filaEstrada = filaEstrada->proximoTrexo;
        free(trexoRemovido);
        printf("\tTrexo finalizado com sucesso");
        return filaEstrada;
    } else {
        printf("\tNão há trexos por fazer.");
        return NULL;
    }
}

float calculaExtensaoAFazer(Estrada *filaEstrada){
    if(filaEstrada){
        float kmRestante = 0;
        while(filaEstrada != NULL){
            kmRestante += filaEstrada->extensaoTrexo;
            filaEstrada = filaEstrada->proximoTrexo;
        }
        return kmRestante;
    } else {
        return 0;
    }
}

void imprimirTrexos(Estrada *filaEstrada){
    if(filaEstrada){
        printf("\n\tTrexos a fazer:");
        int i = 0;
        while(filaEstrada != NULL){
            printf("\n\t\t%d - %.2fkm", i, filaEstrada->extensaoTrexo);
            i++;
            filaEstrada = filaEstrada->proximoTrexo;
        }
    } else {
        printf("\tNão há trexos por fazer.");
    }
}
