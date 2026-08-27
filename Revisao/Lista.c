// Lista encadeada (Não precisa usar recursividade)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 100

typedef struct itemLista {
    int valor;
    struct itemLista *proximoNo;
} Lista;

Lista* insereInicio(Lista *lista, int valor);
void insereMeio(Lista **lista, int valor, int posicao);
void insereFim(Lista **lista, int valor);

Lista* removeInicio(Lista *lista);
void removeMeio(Lista **lista, int posicao);
void removeFim(Lista **lista);

void imprime(Lista *lista);


int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Lista *lista = NULL;

    //printf("Ins I ");
    lista = insereInicio(lista, rand() % MAX);
    //imprime(lista);

    //printf("Ins F ");
    insereFim(&lista, rand() % MAX);
    //imprime(lista);

    insereFim(&lista, rand() % MAX);
    insereFim(&lista, rand() % MAX);
    insereFim(&lista, rand() % MAX);
    //imprime(lista);

    //printf("Ins M0 ");
    insereMeio(&lista, rand() % MAX, 0);
    //imprime(lista);

    //printf("Ins M3 ");
    insereMeio(&lista, rand() % MAX, 3);
    //imprime(lista);

    //printf("Rem I ");
    lista = removeInicio(lista);
    imprime(lista);

    printf("Rem M0 ");
    removeMeio(lista, 0);
    imprime(lista);

    printf("Rem M3 ");
    removeMeio(lista, 3);
    imprime(lista);

    printf("Rem F ");
    removeFim(&lista);
    imprime(lista);

    free(lista);
}

Lista* insereInicio(Lista *lista, int valor){
    Lista *novaLista = (Lista*) malloc(sizeof(Lista));

    if(novaLista == NULL){
        printf("Falha ao malocar\n");
        return NULL;
    }else{
        novaLista->valor = valor;
        novaLista->proximoNo = lista;
        return novaLista;
    }
}

void insereMeio(Lista **lista, int valor, int posicao){
    Lista *novaLista = (Lista*) malloc(sizeof(Lista));
    Lista *anteriorCopiaLista = NULL;
    Lista *copiaLista = *lista;

    if(novaLista == NULL){
        printf("Falha ao malocar\n");
    } else {

        novaLista->valor = valor;
        if(posicao == 0){
            novaLista->proximoNo = *lista;
            *lista = novaLista;
        } else {
            int i = 0;
            while(copiaLista->proximoNo != NULL && i < posicao){
                i++;
                anteriorCopiaLista = copiaLista;
                copiaLista = copiaLista->proximoNo;
            }
            if(i == posicao){
                anteriorCopiaLista->proximoNo = novaLista;
                novaLista->proximoNo = copiaLista;
            } else {
                printf("Existe não, botei foi no final\n");
                novaLista->proximoNo = NULL;
                copiaLista->proximoNo = novaLista;
            }
        }
    }
}

void insereFim(Lista **lista, int valor){
    Lista *novaLista = (Lista*) malloc(sizeof(Lista));
    Lista *copiaLista = *lista;

    if(novaLista == NULL){
        printf("Falha ao malocar\n");
    } else {
        novaLista->valor = valor;
        novaLista->proximoNo = NULL;

        while(copiaLista->proximoNo != NULL){
            copiaLista = copiaLista->proximoNo;
        }
        copiaLista->proximoNo = novaLista;
    }
}

Lista* removeInicio(Lista *lista){
    return lista->proximoNo;
}

void removeMeio(Lista **lista, int posicao){
    Lista *copiaLista = *lista;
    Lista *anteriorCopiaLista = NULL;

    if(posicao == 0){
            printf("Bruh\n");
        *lista = (*lista)->proximoNo;
    } else {
        int i = 0;
        while(copiaLista->proximoNo != NULL && i < posicao){
            anteriorCopiaLista = copiaLista;
            copiaLista = copiaLista->proximoNo;
            i++;
        }
        if(i == posicao){
            anteriorCopiaLista->proximoNo = copiaLista->proximoNo;
        } else {
            printf("Existe não\n");
        }
    }
}

void removeFim(Lista **lista){
    Lista *copiaLista = *lista;
    Lista *anteriorCopiaLista = NULL;
    while(copiaLista->proximoNo != NULL){
        anteriorCopiaLista = copiaLista;
        copiaLista = copiaLista->proximoNo;
    }
        anteriorCopiaLista->proximoNo = NULL;
}


void imprime(Lista *lista){
    while(lista != NULL){
        printf("%d,", lista->valor);
        lista = lista->proximoNo;
    }
    printf("\n\n");
}
