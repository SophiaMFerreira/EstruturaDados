/* Complexidade O(?)
    1. Usar funções.
    2. Usar passagem de vetor como referência.
    3. Não use variáveis globais.
    4. A função busca retorna a posição onde está o valor ou -1 se ele não existir na lista.
    5. Conte o número de “loops” dentro da função “busca” usando ponteiro.
    6. Use “define” para o tamanho da lista e para o número de buscas para calculo da média de rodadas do loop da busca.
    7. Gerar um vetor de números aleatórios sem repetição.
    8. Fazer uma busca linear (busca sequencial) neste vetor.
    9. Repetir esta busca várias vezes e calcular a média de vezes que o loop principal da busca é executado.

    10. Qual a complexidade do algoritmo de busca? O(n)
    11. Qual foi o valor médio encontrado pelo seu programa? 49.48
    12. Os 2 valores acima são da mesma ordem de grandeza? Sim
    13. Se há um valor maior entre a complexidade assintótica e a média encontrada, qual a explicação?
        O valor encontrado está dentro do esperado, pois ao calcular várias vezes a complexidade dos vetores temos
        m*O(n), ou seja a complexidade se mantém O(n).

    Aluna: Sophia Ferreira
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO_VET 100
#define REPETICOES 100000

void montaVetor(int *apontaVetor);
int verificaOcorrenciaVetor(int intRand, int *apontaVetor, int limite);
int buscaChave(int chave, int *apontaVetor);
float complexidadeMedia(int *apontaVetComplex, int *apontaVetor);

main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); // Deve ser colocado na main, pois sua geração é única, já o rand é criado a cada chamada

    int vetor = (int *) malloc(sizeof(int)* TAMANHO_VET);
    int *apontaVetor = vetor;
    int vetorComplexidade = (int *) malloc(sizeof(int)* REPETICOES);
    int *apontaVetComplex = vetorComplexidade;

    printf("Complexidade média: %.2f", complexidadeMedia(apontaVetComplex, apontaVetor));

    free(vetor);
    free(vetorComplexidade);
}

int verificaOcorrenciaVetor(int intRand, int *apontaVetor, int limite){
    for(int j = 0; j < limite; j++){
        if(intRand == *(apontaVetor + j)){
            return 1;
        }
    }
    return 0;
}

void montaVetor(int *apontaVetor){              //Outra solução seria pegar um vetor ordenado que será embaralhado
    int intRand;
    for(int i = 0; i < TAMANHO_VET; i++){
        do{
            intRand = rand() % TAMANHO_VET;
        } while(verificaOcorrenciaVetor(intRand, apontaVetor, i));
        *(apontaVetor + i) = intRand;
    }
}

int buscaChave(int chave, int *apontaVetor){
    int complexidade = 0;

    while(chave != *(apontaVetor + complexidade)){
        complexidade++;
        if(complexidade > TAMANHO_VET){
            return -1;
        }
    }
        return complexidade;
}

float complexidadeMedia(int *apontaVetComplex, int *apontaVetor){
    for(int i = 0; i < REPETICOES; i++){
        montaVetor(apontaVetor);

        int chave = rand() % TAMANHO_VET;       //As chaves são geradas no mesmo intervalo que o vetor, logo não retorna -1
        *(apontaVetComplex + i) = buscaChave(chave, apontaVetor);
    }

    float somaMedia;
    for(int i = 0; i < REPETICOES; i++){
        somaMedia = somaMedia + *(apontaVetComplex + i);
    }
    return somaMedia / REPETICOES;
}


