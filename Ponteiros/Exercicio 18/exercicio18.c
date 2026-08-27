/*  18. Uma empresa especializada em produtos agropecuários plantou em um viveiro 5.000
        sementes de uma determinada planta e deseja contratar os seus serviços de
        programador para verificar o grau de germinação de tais sementes.

        Você deverá criar um programa que permita registrar o grau de germinação de cada
        semente como sendo uma nota atribuída por um técnico agropecuário usando uma
        escala de 0 a 10.

        Ao final o programa deverá emitir um relatório contendo o percentual de sementes
        que conseguiram um grau de germinação acima da média.
        Situação exemplo:

            Semente     Grau de germinação      |           Somatório                           30
                1               10              |
                2               5               |           Grau médio de germinação            6
                3               2               |
                4               10              |           Quantidade de sementes com          2
                5               3               |           germinação acima da média
                                                |
                                                |           Percentual de sementes com
                                                |           grau de germinação acima da média   40%
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N_ESPEICMES 5000

void registroGrauGerminacao(int *dados_sementes);
int somatorioGerminacao(int *dados_sementes);
double grauMedioGerminacao(int *dados_sementes);
double percentualGerminacaoAcimaMedia(int *dados_sementes);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int *dados_sementes = (int*) malloc(sizeof(int) * N_ESPEICMES);
    registroGrauGerminacao(dados_sementes);

    printf("\nSomatório: %d", somatorioGerminacao(dados_sementes));
    printf("\nGrau médio de germinação: %.2f", grauMedioGerminacao(dados_sementes));
    printf("\nPercentual de sementes com grau de germinação acima da média: %.2f", percentualGerminacaoAcimaMedia(dados_sementes));
}

void registroGrauGerminacao(int *dados_sementes){
    for(int i = 0; i < N_ESPEICMES; i++){
        printf("\nGrau de germinação da semente %d:", (i + 1));
        scanf("%d", (dados_sementes + i));
        setbuf(stdin, NULL);
    }
}

int somatorioGerminacao(int *dados_sementes){
    int somatorio = 0;
    for(int i = 0; i < N_ESPEICMES; i++){
        somatorio += *(dados_sementes + i);
    }
    return somatorio;
}

double grauMedioGerminacao(int *dados_sementes){
    int somatorioG = somatorioGerminacao(dados_sementes);
    double germinacaoMedia = somatorioG / N_ESPEICMES;
    return germinacaoMedia;
}

double percentualGerminacaoAcimaMedia(int *dados_sementes){
    double germinacaoMedia = grauMedioGerminacao(dados_sementes);
    int contador = 0;
    for(int i = 0; i < N_ESPEICMES; i++){
        if(germinacaoMedia < *(dados_sementes + i)){
           contador++;
        }
    }
    double percentGerminacaoAcimaMed = (contador * 100) / N_ESPEICMES;
    return percentGerminacaoAcimaMed;
}
