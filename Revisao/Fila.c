// Sim é fila, mas eu troquei os nomes

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct sLista{
    int valor;
    struct sLista *proxLista;
} Lista;


Lista* entra(Lista *lista);
void sai(Lista **lista);
void imprime(Lista *lista);

int main(){
    srand(time(NULL));
    Lista *lista = NULL;

    imprime(lista);
    lista = entra(lista);
    lista = entra(lista);
    lista = entra(lista);
    imprime(lista);
    sai(&lista);
    printf("\n");
    imprime(lista);

    free(lista);
}

Lista* entra(Lista *lista){
    Lista *novaLista = (Lista*) malloc(sizeof(Lista));
    if(novaLista){
        printf("Insira um valor: ");
        scanf("%d", &(novaLista->valor));

        if(lista){
            novaLista->proxLista = lista;
        } else {
            novaLista->proxLista = NULL;
        }
        return novaLista;
    } else {
        printf("Falha ao mallocar");
        return NULL;
    }
}

void sai(Lista **lista){
    Lista *copiaLista = *lista;
    Lista *anteriorCopiaLista = (Lista*) malloc(sizeof(Lista));

    while(copiaLista->proxLista != NULL){
        anteriorCopiaLista = copiaLista;
        copiaLista = copiaLista->proxLista;
    }
    anteriorCopiaLista->proxLista = NULL;
    lista = anteriorCopiaLista;
}

void imprime(Lista *lista){
    Lista *copiaLista = lista;
    if(copiaLista){
        while(copiaLista != NULL){
            printf("%d - ", copiaLista->valor);
            copiaLista = copiaLista->proxLista;
        }
    } else {
        printf("\nLista vazia.\n");
    }
}
