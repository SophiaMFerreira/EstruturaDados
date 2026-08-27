/*  Nome: Sophia Agnes de Machado Ferreira
    Turma: B
    Questão: 02
        Considere a ´arvore bin´aria abaixo. Ela representa um sensor de fogo (incˆendio florestal) e uma rede de n´os de comunica¸c˜ao
        sem fio que devem enviar o alarme de incˆendio at´e um ponto de coleta nos limites da floresta, para que a¸c˜oes sejam
        tomadas no combate ao incˆendio. Pode usar o c´odigo de uma das duas outras quest˜oes para criar a ´arvore de testes.
        Ao detectar a presen¸ca de fogo, o sensor j´a tem um rota pronta para enviar a mensagem de alarme. Ela segue o seguinte
        padr˜ao:
        MSG = {4DEED}
        Onde 4 ´e o n´umero de saltos e D e E indicam se a mensagem deve ser encaminhada ao n´o da direita ou da esquerda
        (considere direita e esquerda do nosso ponto de vista (olhando para a ´arvore)).
        A rota correspondente `a mensagem acima est´a destacada no desenho da ´arvore com este s´ımbolo: ⇓
        Fa¸ca um programa que gere uma ´arvore de testes, receba a mensagem e fa¸ca a mensagem trafegar pela rede at´e seu n´o
        destino ou at´e n˜ao haver mais como avan¸car
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

typedef struct no {
    int info;
    struct arvore* sae;
    struct arvore* sad;
}No;

No* criaNo(int n, No* sae, No* sad);
int busca(No* a, int n);
void imprimeSinalIncendio(int caminho, int i, No* raiz);

int main(){
    //int caminho = [4, 1, 0, 0, 1];                                       //Esquerda = 0, Direita = 1
    No *D = criaNo(4, NULL, NULL);
    No *E = criaNo(5, NULL, NULL);
    No *B = criaNo(2, D, E);
    No *C = criaNo(3, D, E);
    No *A = criaNo(1, B, C);

    if (!busca(A, 113)){
    printf("\nInformacao INEXISTENTE!");
    }else{
    printf("\nInformacao ENCONTRADA COM SUCESSO!");
    }

    imprimeIn(A);
    return 0;
}

No* criaNo(int n, No* sae, No* sad){
    No* p = (No*) malloc(sizeof(No));
    p->info = n;
    p->sae = sae;
    p->sad = sad;
    return p;
}

int busca(No* a, int n){
    if(a != NULL){
        return 0;
    }else{
        if (a->info == n){
            return 1;
        }else{
            if (busca(a->sae, n)){
                return 1;
            }else{
                return busca(a->sad, n);
            }
        }
    }
}

void imprimeIn(No* a){
    if(a != NULL){
        imprimeIn(a->sae);
        printf("%d ", a->info);
        imprimeIn(a->sad);
    }
}

