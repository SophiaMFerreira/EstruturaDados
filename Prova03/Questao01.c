/*  Nome: Sophia Agnes de Machado Ferreira
    Turma: B
    Questão: 01

    Faça um programa que insira 12 valores aleatórios entre 0 e 10 em uma árvore binária de busca e depois percorra a árvore em ordem, ou seja, imprima a árvore em ordem.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct no {
    int valor;
    struct no *noEsquerda;
    struct no *noDireita;
} No;

No* incluiNo(No* raiz, int valor);
void incluiNoEsquerda(No* raiz, int valor);
void incluiNoDireita(No* raiz, int valor);
void imprimeInOrndem(No* raiz);

int main(){
    No* raiz = NULL;
    srand(time(NULL));

    for(int i = 0; i < 12; i++){
        raiz = incluiNo(raiz, (rand() % MAX)+ 1);
    }
    imprimeInOrndem(raiz);
    free(raiz);
}

No* incluiNo(No* raiz, int valor){
    if(raiz == NULL){
        No* novoNo = (No*) malloc(sizeof(No));
        novoNo->noDireita = NULL;
        novoNo->noEsquerda = NULL;
        novoNo->valor = valor;
        return novoNo;
    } else {
        if(valor < raiz->valor){                                         // cai p esquerda, nó menor que a raiz
           incluiNoEsquerda(raiz->noEsquerda, valor);
        } else{
            incluiNoDireita(raiz->noDireita, valor);
        }
    }
}

void incluiNoEsquerda(No* raiz, int valor){
    if(raiz == NULL){
        No* novoNo = (No*) malloc(sizeof(No));
        novoNo->noDireita = NULL;
        novoNo->noEsquerda = NULL;
        novoNo->valor = valor;
        raiz = novoNo;
    } else {
        if(valor < raiz->valor){                                                                // cai p esquerda, nó menor que a raiz
            incluiNoEsquerda(raiz->noEsquerda, valor);
        } else {                                                                                // cai p direita, nó menor que a raiz
            incluiNoDireita(raiz->noDireita, valor);
        }
    }
}

void incluiNoDireita(No* raiz, int valor){
    if(raiz == NULL){
        No* novoNo = (No*) malloc(sizeof(No));
        novoNo->noDireita = NULL;
        novoNo->noEsquerda = NULL;
        novoNo->valor = valor;
        raiz = novoNo;
    } else {
        if(valor < raiz->valor){                                                                // cai p esquerda, nó menor que a raiz
            incluiNoEsquerda(raiz->noEsquerda, valor);
        } else {                                                                                // cai p direita, nó menor que a raiz
            incluiNoDireita(raiz->noDireita, valor);
        }
    }
}

void imprimeInOrndem(No* raiz){
    if(raiz != NULL){
        imprimeInOrndem(raiz->noEsquerda);
        printf("%d\t", raiz->valor);
        imprimeInOrndem(raiz->noDireita);
    }
}
