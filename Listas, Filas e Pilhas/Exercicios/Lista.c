// Lista simplesmente encadeada

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MAX 100

typedef struct structNo{
    int valor;
    struct structNo *proximoNo;
}No;

int exibeMenu();
int retornaPosicao();

No* insereInicio(No *lista);
void insereMeio(No **lista, int posicao);
void insereFim(No **lista);

void imprimeNo(No *lista);
void imprimeLista(No *lista);

No* excluiInicio(No *lista);
void excluiMeio(No **lista);
void excluiFim(No **lista);
No* excluiTodos(No *lista);

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    No *lista = NULL;
    int opcao, posicao;

    do{
        opcao = exibeMenu();
        switch(opcao){
            case 1:
                lista = insereInicio(lista);
                break;
            case 2:
                posicao = retornaPosicao();
                insereMeio(&lista, posicao);
                break;
            case 3:
                insereFim(&lista);
                break;
            case 4:
                imprimeNo(lista);
                break;
            case 5:
                imprimeLista(lista);
                break;
            case 6:
                lista = excluiInicio(lista);
                break;
            case 7:
                excluiMeio(&lista);
                break;
            case 8:
                excluiFim(&lista);
            break;
            case 9:
                lista = excluiTodos(lista);
            break;
            default:
                if(opcao != 0)
                    printf("\nOpção inválida!");
            break;
        }
    }while(opcao != 0);

    free(lista);
}

No* insereInicio(No *lista){
    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo != NULL){
        novoNo->valor = rand() % MAX;

        if(lista != NULL){
            novoNo->proximoNo = lista;
        }else{
            novoNo->proximoNo = NULL;
        }
        return novoNo;

    }else{
        printf("\nFalha ao separar espaço para o nó.");
        return NULL;
    }
}

void insereMeio(No **lista, int posicao){
    No *novoNo = (No*) malloc(sizeof(No));
    No *noAnterior = (No*) malloc(sizeof(No));
    No *listaCopia = (No*) malloc(sizeof(No));

    if(posicao == 0){
       return insereInicio(lista);
    } else {

        if((novoNo != NULL) && (noAnterior != NULL) && (listaCopia != NULL)){
            novoNo->valor = rand() % MAX;
            noAnterior = NULL;
            listaCopia = *lista;

            if(lista != NULL){
                int i = 0;
                while((i < posicao) && (listaCopia->proximoNo != NULL)){
                    noAnterior = listaCopia;
                    listaCopia = listaCopia->proximoNo;
                    i++;
                }
                if(i == posicao){
                    novoNo->proximoNo = listaCopia;
                    noAnterior->proximoNo = novoNo;
                } else {
                    listaCopia->proximoNo = novoNo;
                    printf("Esta posição não está na lista. O nó ocupará a última posição");
                }

            }else{
                novoNo->proximoNo = NULL;
            }

        }else{
            printf("\nFalha ao separar espaço para o nó.");
        }
    }
}

void insereFim(No **lista){
    No *novoNo = (No*) malloc(sizeof(No));
    No *listaCopia = (No*) malloc(sizeof(No));

    if((novoNo != NULL) && (listaCopia != NULL)){
        listaCopia = *lista;
        novoNo->valor = rand() % MAX;
        novoNo->proximoNo = NULL;

        if(*lista != NULL){
            while(listaCopia->proximoNo != NULL){
                listaCopia = listaCopia->proximoNo;
            }
            listaCopia->proximoNo = novoNo;
        }
    } else{
        printf("\nFalha ao separar espaço para o nó.");
    }
}


void imprimeNo(No *lista){
    if(lista != NULL){
       int posicao = retornaPosicao();
       int contador = 0;

        while((contador < posicao) && (lista->proximoNo != NULL)){
            lista = lista->proximoNo;
            contador++;
        }

        if(contador ==  posicao){
            printf("\n\tNó %d - conteúdo: %d", posicao, lista->valor);
        } else {
            printf("\nNó inexistente!");
        }
    } else {
        printf("Lista vazia.");
    }
}

void imprimeLista(No *lista){
    if(lista != NULL){
        printf("\n----------------= Lista =----------------");
        int posicao = 0;

        while(lista != NULL){
            printf("\n\tNó %d - conteúdo: %d", posicao, lista->valor);
            lista = lista->proximoNo;
            posicao++;
        }
        printf("\n-----------------------------------------");
    } else {
        printf("Lista vazia.");
    }
}

No* excluiInicio(No *lista){
    if(lista != NULL){
        return lista->proximoNo;
    } else{
        printf("\nLista vazia, não há nada para remover.");
        return NULL;
    }
}

void excluiMeio(No **lista){
    if(lista != NULL){
        int posicao = retornaPosicao();
        if(posicao == 0){
            *lista = excluiInicio(lista);
        } else {
            No *noAnterior = (No*) malloc(sizeof(No));
            No *listaCopia = (No*) malloc(sizeof(No));

            if((noAnterior != NULL) && (listaCopia != NULL)){
                listaCopia = *lista;
                int i = 0;
                while((i < posicao) && (listaCopia->proximoNo != NULL)){
                    noAnterior = listaCopia;
                    listaCopia = listaCopia->proximoNo;
                    i++;
                }
                if(i == posicao){
                    noAnterior->proximoNo = listaCopia->proximoNo;
                    free(listaCopia);
                } else {
                    printf("Esta posição não existe na lista.");
                }

            } else {
                printf("\nFalha ao separar espaço para o nó.");
            }
        }
    } else{
        printf("\nLista vazia, não há nada para remover.");
        return NULL;
    }
}

void excluiFim(No **lista){
    if(lista != NULL){
        No *noAnterior = (No*) malloc(sizeof(No));
        No *listaCopia = (No*) malloc(sizeof(No));
        if((noAnterior != NULL) && (listaCopia != NULL)){
            listaCopia = *lista;
            while((listaCopia->proximoNo != NULL)){
                noAnterior = listaCopia;
                listaCopia = listaCopia->proximoNo;
            }
            noAnterior->proximoNo = NULL;
            free(listaCopia);
        } else {
            printf("\nFalha ao separar espaço para o nó.");
        }
    } else{
        printf("\nLista vazia, não há nada para remover.");
        return NULL;
    }
}

No* excluiTodos(No *lista){
    return NULL;
}

int exibeMenu(){
    printf("\n\n =====================================");
    printf("\n\t 1 - Insere no Inicio");
    printf("\n\t 2 - Insere no Meio");
    printf("\n\t 3 - Insere no Fim");
    printf("\n\t 4 - Consultar Nó");
    printf("\n\t 5 - Cnsultar Lista");
    printf("\n\t 6 - Excluir no Inicio");
    printf("\n\t 7 - Excluir no Meio");
    printf("\n\t 8 - Excluir no Fim");
    printf("\n\t 9 - Excluir Tudo");
    printf("\n\t 0 - Desligar");
    printf("\n =====================================\n");

    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

int retornaPosicao(){
    int posicao;
    printf("\nEm que posição deseja realizar a ação? ");
    scanf("%d", &posicao);
        if(posicao < 0){
            printf("\nA posição não pode ser negativa.");
            posicao = retornaPosicao();
        }
    return posicao;
}
