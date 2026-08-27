/*  Nome: Sophia Agnes de Machado Ferreira
    Turma: B
    Questão: 03

    Faça um programa que crie a seguinte árvore “manualmente”, como fizemos em aula com a primeira árvore criada
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
    int valor;
    struct no *noEsquerda;
    struct no *noMeio;
    struct no *noDireita;
} No;

No* novoNoFunc(int inteiro);

int main(){
    No* raiz = (No*) malloc(sizeof(No));
    raiz->valor = 18;
    raiz->noEsquerda = novoNoFunc(5);
        raiz->noEsquerda->noDireita = novoNoFunc(7);
        raiz->noEsquerda->noEsquerda = novoNoFunc(26);
            raiz->noEsquerda->noEsquerda->noMeio = novoNoFunc(6);
    raiz->noMeio = novoNoFunc(9);
        raiz->noMeio->noEsquerda = novoNoFunc(3);
            raiz->noMeio->noEsquerda->noMeio = novoNoFunc(4);
        raiz->noMeio->noMeio = novoNoFunc(19);
            raiz->noMeio->noMeio->noDireita = novoNoFunc(44);
        raiz->noMeio->noDireita = novoNoFunc(4);
    raiz->noDireita = novoNoFunc(3);
        raiz->noDireita->noMeio = novoNoFunc(22);
}

No* novoNoFunc(int inteiro){
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = inteiro;
    novoNo->noDireita = NULL;
    novoNo->noMeio = NULL;
    novoNo->noEsquerda = NULL;
    return novoNo;
}
