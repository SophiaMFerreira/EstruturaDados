/*      14. Faça um programa que tenha como único objetivo alocar dinamicamente espaço na
        memória para 10.000 números inteiros. O programa deverá informar se alocação foi
        realizada como sucesso ou não. Caso a alocação de memória tenha sido bem-sucedida o
        programa deverá informar também o primeiro e último endereços alocados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    #define N_INTEIROS 10000

    setlocale(LC_ALL, "Portuguese");

    int *numeros;
    numeros = (int *) malloc(sizeof(int) * N_INTEIROS);

    if(numeros != NULL){
        printf("Alocação de memória realizada com suceso!");
        printf("\n\nO início do endereçamento começa em %d e termina em %d", numeros, numeros + N_INTEIROS);
    }else{
        printf("Alocação de memória interrupta!");
    }
}
