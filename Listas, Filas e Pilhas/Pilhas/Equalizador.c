/*
        Exercício de Pilha
    Vejam este vídeo: https://pixabay.com/pt/videos/volume-equalizador-m%C3%BAsica-som-6431/
    Isto é um equalizador de som. Ele mostra e intensidade do som em algumas faixas de frequência.
    Vamos fazer um desse, usando apenas pilha e suas funções básicas push e pop.
    Já que nosso objetivo não é manipulação de tela em modo texto, vamos rotacionar em 90º a representação ("deitá-la"). Ou seja, as barrinhas vão variar na horizontal.

    Vamos trabalhar com 8 faixas de frequência (8 pilhas).
    Gerar randomicamente a intensidade de cada uma das 8 frequências, imprimir as pilhas, dar um delay (sleep) e rodar o loop do programa.
    Cada frequência pode estar em uma escala de zero a 30.
    Cada frequência (que será uma linha impressa na tela), será uma pilha e deverá ser impressa usando a função imprimePilha.
    O conteúdo (ou info ou dado) de cada nó da pilha pode ser um # (além do ponteiro para próximo), pra gerar o gráfico parecido com o do vídeo, porém, deitado.
    Adiantem o programa de pilhas (definição do nó, da estrutura pilha em si, push, pop e imprime). Aí, na aula, apenas usaremos as funções pra criar o programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define VOL_MAX 30
#define IMPRESSOES 50

typedef struct structSom {
    struct structSom *proximoSom;
} Som;

typedef struct structMusica {
    struct structSom *som;
    int ultimaIntensidade;
} DadosSom;

Som* push(Som *som);
void pop(Som **som);
void imprime(Som *som);
void novaIntensidade(DadosSom musica);

main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Som *som1 = NULL;
    Som *som2 = NULL;
    Som *som3 = NULL;
    Som *som4 = NULL;
    Som *som5 = NULL;
    Som *som6 = NULL;
    Som *som7 = NULL;
    Som *som8 = NULL;

    DadosSom musica1;
        musica1.som = som1;
        musica1.ultimaIntensidade = 0;
    DadosSom musica2;
        musica2.som = som2;
        musica2.ultimaIntensidade = 0;
    DadosSom musica3;
        musica3.som = som3;
        musica3.ultimaIntensidade = 0;
    DadosSom musica4;
        musica4.som = som4;
        musica4.ultimaIntensidade = 0;
    DadosSom musica5;
        musica5.som = som5;
        musica5.ultimaIntensidade = 0;
    DadosSom musica6;
        musica6.som = som6;
        musica6.ultimaIntensidade = 0;
    DadosSom musica7;
        musica7.som = som7;
        musica7.ultimaIntensidade = 0;
    DadosSom musica8;
        musica8.som = som8;
        musica8.ultimaIntensidade = 0;


    for(int j = 0; j < IMPRESSOES; j++){
        novaIntensidade(musica1);
        novaIntensidade(musica2);
        novaIntensidade(musica3);
        novaIntensidade(musica4);
        novaIntensidade(musica5);
        novaIntensidade(musica6);
        novaIntensidade(musica7);
        novaIntensidade(musica8);

        Sleep(700);
        system("cls");
    }
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
        free(copiaSom);
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
void novaIntensidade(DadosSom musica){
    int novaIntensidade = rand() % (VOL_MAX + 1);
        if(musica.ultimaIntensidade != novaIntensidade){
            if(musica.ultimaIntensidade < novaIntensidade){
                int diferenca = novaIntensidade - musica.ultimaIntensidade;
                for(int i = 0; i < diferenca; i++){
                    musica.som = push(musica.som);
                }
            } else{
                int diferenca = musica.ultimaIntensidade - novaIntensidade;
                for(int i = 0; i < diferenca; i++){
                    pop(&(musica.som));
                }
            }
        }
        musica.ultimaIntensidade = novaIntensidade;
        imprime(musica.som);
        printf("\n");
 }
