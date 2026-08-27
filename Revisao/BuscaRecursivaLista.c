// Implementar a busca recursiva em uma lista encadeada não ordenada.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MAX 10

typedef struct sLista{
    int valor;
    struct sLista *proxLista;
} Lista;

Lista* insere(Lista *lista);
void imprime(Lista *lista);
int consulta(Lista *lista, int valor);

int main(){
    srand(time(NULL));
    Lista *lista = NULL;

    lista = insere(lista);
    for(int i = 0; i < MAX; i++){
        lista = insere(lista);
    }
    imprime(lista);
    printf("\n\n");

    int valor = 0;
    printf("Buscar o valor: ");
    scanf("%d", &valor);
    int retorno = consulta(lista, valor);
    if(retorno != -1){
        printf("\n\nRetorno: %d", retorno);
    } else {
        printf("\n\nAchou nao man :(");
    }


    free(lista);
}


Lista* insere(Lista *lista){
    Lista *itemLista = (Lista*) malloc(sizeof(Lista));
    itemLista->valor = rand() % MAX;
    itemLista->proxLista = lista;
    return itemLista;
}

void imprime(Lista *lista){
    while (lista->proxLista != NULL){
        printf("%d, ", lista->valor);
        lista = lista->proxLista;
    }
}

int consulta(Lista *lista, int valor){
    if(lista != NULL){
        if(lista->valor == valor){
            return lista->valor;
        } else {
            return consulta(lista->proxLista, valor);
        }
    } else
        return -1;
}


