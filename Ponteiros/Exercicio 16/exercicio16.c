/*  16. Crie um programa para registrar as pontuações que juízes de uma determinada prova
        esportiva atribuíram a um atleta (valores compreendidos entre 0 e 10 inclusive). Crie
        funções para determinar os seguintes valores:

        a. A média obtida pelo atleta.
        b. A melhor pontuação obtida pelo atleta.
        c. A pior pontuação obtida pelo atleta.
        d. A porcentagem de pontuações acima da média do atleta.
        e. A porcentagem de pontuações abaixo da média do atleta.
        f. Determine a quantidade de juízes que atribuíram a melhor nota ao atleta.
        g. Determine a quantidade de juízes que atribuíram a pior nota ao atleta.
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N_JUIZES 5

double media(int *notas);
double melhor_pontuacao(int *notas);
double pior_pontuacao(int *notas);
double acima_media(int *notas);
double abaixo_media(int *notas);
int qnt_melhores_pontuacoes(int *notas);
int qnt_piores_pontuacoes(int *notas);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int *notas = (int*) malloc(sizeof(int) * N_JUIZES);

    for(int i = 0; i < N_JUIZES; i++){
        printf("\nNota %d:", (i + 1));
        scanf("%d", (notas + i));
        setbuf(stdin, NULL);
    }

    printf("\n\nA média obtida pelo atleta: %.3f", media(notas));
    printf("\nA melhor pontuação obtida pelo atleta: %.2f", melhor_pontuacao(notas));
    printf("\nA pior pontuação obtida pelo atleta: %.2f", pior_pontuacao(notas));
    printf("\nA porcentagem de pontuações acima da média do atleta: %.2f porcento", acima_media(notas));
    printf("\nA porcentagem de pontuações abeixo da média do atleta: %.2f porcento", abaixo_media(notas));
    printf("\nDetermine a quantidade de juízes que atribuíram a melhor nota ao atleta: %d", qnt_melhores_pontuacoes(notas));
    printf("\nDetermine a quantidade de juízes que atribuíram a pior nota ao atleta: %d", qnt_piores_pontuacoes(notas));

}

double media(int *notas){
    double Pontuacao_media;
    double Pontuacao_soma;
    for(int i = 0; i < N_JUIZES; i++){
        Pontuacao_soma += *(notas + i);
    }
    Pontuacao_media = Pontuacao_soma / N_JUIZES;
    return Pontuacao_media;
}

double melhor_pontuacao(int *notas){
    double maior_pontuacao = *(notas);
    for(int i = 0; i < N_JUIZES; i++){
        if(maior_pontuacao < *(notas + i)){
            maior_pontuacao = *(notas + i);
        }
    }
    return maior_pontuacao;
}

double pior_pontuacao(int *notas){
    double menor_pontuacao = *(notas);
    for(int i = 0; i < N_JUIZES; i++){
        if(menor_pontuacao > *(notas + i)){
            menor_pontuacao = *(notas + i);
        }
    }
    return menor_pontuacao;
}

double acima_media(int *notas){
    double pontuacao_media = media(notas);
    int contador = 0;
    for(int i = 0; i < N_JUIZES; i++){
        if(pontuacao_media < *(notas + i)){
            contador++;
        }
    }
    double maiores_porcentagem = (contador  * 100) / N_JUIZES;
    return maiores_porcentagem;
}
double abaixo_media(int *notas){
    double pontuacao_media = media(notas);
    int contador = 0;
    for(int i = 0; i < N_JUIZES; i++){
        if(pontuacao_media > *(notas + i)){
            contador++;
        }
    }
    double menores_porcentagem = (contador  * 100) / N_JUIZES;
    return menores_porcentagem;
}

int qnt_melhores_pontuacoes(int *notas){
    double maior_pontuacao = melhor_pontuacao(notas);
    int contadorJuizes = 0;
    for(int i = 0; i < N_JUIZES; i++){
        if(maior_pontuacao == *(notas + i)){
            contadorJuizes++;
        }
    }
    return contadorJuizes;
}
int qnt_piores_pontuacoes(int *notas){
double menor_pontuacao = pior_pontuacao(notas);
    int contadorJuizes = 0;
    for(int i = 0; i < N_JUIZES; i++){
        if(menor_pontuacao == *(notas + i)){
            contadorJuizes++;
        }
    }
    return contadorJuizes;
}
