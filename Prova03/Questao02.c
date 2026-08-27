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

typedef struct arvore {
    int info;
    struct arvore* sae;
    struct arvore* sad;
}Arvore;

Arvore* inicializa();
int estaVazia(Arvore* a);
Arvore* criaNo(int n, Arvore* sae, Arvore* sad);
void imprimeSinalIncendio(int caminho, int i, Arvore* raiz);

int main(){
    int caminho = [4, 1, 0, 0, 1];                                       //Esquerda = 0, Direita = 1
    Arvore *D = criaNo(4, inicializa(), inicializa());
    Arvore *E = criaNo(5, inicializa(), inicializa());
    Arvore *F = criaNo(6, inicializa(), inicializa());
    Arvore *G = criaNo(7, inicializa(), inicializa());
    Arvore *B = criaNo(2, D, E);
    Arvore *C = criaNo(3, F, G);
    Arvore *A = criaNo(1, B, C);

    imprimeSinalIncendio(int caminho, 0, A)
    return 0;
}

Arvore* inicializa(){
    return NULL;
}

Arvore* criaNo(int n, Arvore* sae, Arvore* sad){
    Arvore* p = (Arvore*) malloc(sizeof(Arvore));
    p->info = n;
    p->sae = sae;
    p->sad = sad;
    return p;
}

int estaVazia(Arvore* a){
return a == NULL;
}

int busca(Arvore* a, int n){
    if(estaVazia(a)){
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

void imprimeSinalIncendio(int caminho, int i, Arvore* raiz){
    if(raiz == NULL){
        printf("INCÊNDIO FLORESTAL");
    } else {
        if(caminho[i] == 0){
            i++;
            imprimeSinalIncendio(desvios, caminho, i, raiz->sae);
        } else {
            if(caminho[i] == 1){
                i++;
                imprimeSinalIncendio(caminho, i, raiz->sad);
            } else {
                caminho[i] = caminho[i] - 1;
                if(caminho[i] == 0){
                    i++;
                }
                if(caminho[i+1] == 0){
                    imprimeSinalIncendio(desvios, caminho, i, raiz->sae);
                } else {
                    imprimeSinalIncendio(caminho, i, raiz->sad);
                }
            }
        }
    }
}

