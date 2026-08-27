/* Exercício de Pilha
    Vejam este vídeo: https://pixabay.com/pt/videos/volume-equalizador-m%C3%BAsica-som-6431/
    Isto é um equalizador de som. Ele mostra e intensidade do som em algumas faixas de frequência.
    Vamos fazer um desse, usando apenas pilha e suas funções básicas push e pop.
    Já que Somsso objetivo não é manipulação de tela em modo texto, vamos rotacionar em 90º a representação ("deitá-la"). Ou seja, as barrinhas vão variar na horizontal.
    Vamos trabalhar com 8 faixas de frequência (8 pilhas).
    Gerar randomicamente a intensidade de cada uma das 8 frequências, imprimir as pilhas, dar um delay (sleep) e rodar o loop do programa.
    Cada frequência pode estar em uma escala de zero a 30.
    Cada frequência (que será uma linha impressa na tela), será uma pilha e deverá ser impressa usando a função imprimePilha.
    O conteúdo (ou info ou dado) de cada nó da pilha pode ser um # (além do ponteiro para próximo), pra gerar o gráfico parecido com o do vídeo, porém, deitado.
    Adiantem o programa de pilhas (definição do nó, da estrutura pilha em si, push, pop e imprime). Aí, na aula, apenas usaremos as funções pra criar o programa.  */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define VOL_MAX 10

typedef struct structSom {

    struct structSom *proximoSom;
} Som;

Som* push(Som *som);
void pop(Som **som);
void imprime(Som *som);

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Som *som1 = NULL;
    int *ultimaIntensidade;
    int i;
    *ultimaIntensidade = 0;

    //char barrinha = 'Alt'+219;
    //printf("%s", 219);
    int novaIntensidade = (rand() % VOL_MAX) + 1;
    printf("%d\n", novaIntensidade);
    //system("pause");
    if(*ultimaIntensidade != novaIntensidade){
        if(*ultimaIntensidade < novaIntensidade){

            int diferenca = novaIntensidade - *ultimaIntensidade;
            printf("%d\n", diferenca);
            for(i = 0; i < 4; i++){
                printf("%d\n", i);
                som1 = push(som1);
            }
            //som1 = push(som1);
            //som1 = push(som1);

            //while(i < diferenca){
                //som1 = push(som1);
                //i++;
           // }
        /*} else {
            diferenca = *ultimaIntensidade - novaIntensidade;
            for(int i = 0; i < diferenca; i++){
                pop(som1);printf("OK\n");
            }*/
        }

    }
    imprime(som1);
}

Som* push(Som *som){
    Som *novoSom = (Som*) malloc(sizeof(Som));
    if(novoSom != NULL){
        novoSom->proximoSom = som;
        return novoSom;
    } else {
        printf("Erro ao ligar o som.");
    }
    return NULL;
}

void pop(Som **som){
    if(*som != NULL){
        Som *copiaSom = *som;
        *som = copiaSom->proximoSom;
        return copiaSom;
    } else {
        return NULL;
    }
}

void imprime(Som *som){
    while(som != NULL){
        som = som->proximoSom;
        printf("#");
    }
}
