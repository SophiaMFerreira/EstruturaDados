/*  17.     Codificar um programa para armazenar as temperaturas diárias de um determinado
            mês (considere o mês com 30 dias) e produzir o seguinte relatório:
            a. A temperatura mínima no mês.
            b. A temperatura máxima no mês.
            c. A temperatura média do mês.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define DIAS_MES 30


float *armazenaTemperaturas();
float calculaTemperaturaMin (float *temperaturas);
float calculaTemperaturaMax (float *temperaturas);
float calculaTemperaturaMedia (float *temperaturas);

int main(){
    setlocale(LC_ALL, "Portuguese");
    float *temperaturas = armazenaTemperaturas();

    float tMin = calculaTemperaturaMin (temperaturas);
    float tMax = calculaTemperaturaMax (temperaturas);
    float tMedia = calculaTemperaturaMedia (temperaturas);

    printf("\nA temperatura mínima foi: %.2f", tMin);
    printf("\nA temperatura máxima foi: %.2f", tMax);
    printf("\nA temperatura média foi: %.2f", tMedia);
}

float *armazenaTemperaturas(){
    float *temperaturas;
    temperaturas = (float *) malloc(sizeof(float) * DIAS_MES);

    for(int i = 0; i < DIAS_MES; i += 1){
        printf("Indique o temperatura do dia:");
        scanf("%f", (temperaturas + i));
    }

    return temperaturas;
}

float calculaTemperaturaMin (float *temperaturas){
    float tMin = *temperaturas;
    for(int i = 0; i < DIAS_MES; i++){
        if(tMin > *(temperaturas + i)){
            tMin = *(temperaturas + i);
        }
    }

    return tMin;
}


float calculaTemperaturaMax (float *temperaturas){
    float tMax = *temperaturas;
    for(int i = 0; i < DIAS_MES; i++){
        if(tMax < *(temperaturas + i)){
            tMax = *(temperaturas + i);
        }
    }

    return tMax;
}

float calculaTemperaturaMedia (float *temperaturas){
    float tMedia = 0;
    for(int i = 0; i < DIAS_MES; i++){
        float somaTemp;
        somaTemp += *(temperaturas + i);
        tMedia = somaTemp / DIAS_MES;
    }

    return tMedia;
}
