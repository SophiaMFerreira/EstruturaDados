#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define OPC 2

typedef struct sPilha {
    int valor;
    struct sPilha *proxItem;
} Pilha;



Pilha* push(Pilha *pilha);
Pilha* pop(Pilha *pilha);
void imprime(Pilha *pilha);

int main(){
    srand(time(NULL));
    Pilha *pilha = NULL;

    imprime(pilha);
    pilha = push(pilha);
    pilha = push(pilha);
    imprime(pilha);
    pilha = pop(pilha);
    imprime(pilha);
}

Pilha* push(Pilha *pilha){
    Pilha *novaPilha = (Pilha*) malloc(sizeof(Pilha));
    if(novaPilha){
        printf("Insira um valor: ");
        scanf("%d", &(novaPilha->valor));
        if(pilha){
            novaPilha->proxItem = pilha;

        } else {
            novaPilha->proxItem = NULL;
        }
        return novaPilha;
    } else {
        printf("Falha ao mallocar");
        return NULL;
    }
}

Pilha* pop(Pilha *pilha){
    if(pilha){
        return pilha->proxItem;
    } else {
        printf("\nPilha vazia.\n");
        return NULL;
    }
}

void imprime(Pilha *pilha){
    Pilha *copiaPilha = pilha;
    if(copiaPilha){
        while(copiaPilha != NULL){
            printf("%d - ", copiaPilha->valor);
            copiaPilha = copiaPilha->proxItem;
        }
    } else {
        printf("\nPilha vazia.\n");
    }
}
