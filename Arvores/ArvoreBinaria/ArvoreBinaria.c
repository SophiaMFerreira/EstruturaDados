#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct structNo {
    struct structNo *noEsquerda;
    int valor;
    struct structNo *noDireita;
} Arvore;

Arvore* inserirFolha(Arvore **arvore, int valor);
void printNED(Arvore *arvore);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Arvore *arvore = NULL;
    arvore = inserirFolha(arvore, 7);
    arvore = inserirFolha(arvore, 3);
    arvore = inserirFolha(arvore, 6);
    arvore = inserirFolha(arvore, 9);
    arvore = inserirFolha(arvore, 19);
    printNED(arvore);
}

Arvore* inserirFolha(Arvore **arvore, int valor) {
    Arvore *novaFolha = (Arvore*) malloc(sizeof(Arvore));
    Arvore *copiaArvore = *arvore;
    if(novaFolha){
        novaFolha->valor = valor;
        if(copiaArvore == NULL){
            return novaFolha;
        } else {
            if( valor > copiaArvore->valor){
                return inserirFolha(copiaArvore->noDireita, valor);
            } else {
                return inserirFolha(copiaArvore->noEsquerda, valor);
            }
        }
    }
    else{
        printf("A foia caiu.");
    }
}

void printNED(Arvore *arvore) {
    if(arvore) {
        printf("%d - %d - %d\n", arvore->noEsquerda->valor, arvore->valor, arvore->noDireita->valor);
        return printNED(arvore->noEsquerda);
    } else{
        printf("Árvore morreu");
    }
}
