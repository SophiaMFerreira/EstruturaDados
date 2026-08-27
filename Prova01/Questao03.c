/*  Quest˜ao 3a: [5 pontos]
    Complexidade esperada: O(n);

    int calculaPotencia(int a, int n, int *On){
    int potencia = a;                                   //1
    for(int i = 1; i < n; i++){                         //n
        potencia = potencia * a;                        //n - 1
        (*On)++;                                        //1
    }
    return potencia;                                    //1
                                                        //TOT: 2n + 2 = O(n)

}


    Complexidade retornada por *On: n - 1 = O(n);
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int calculaPotencia(int a, int n, int *On);


main(){
    setlocale(LC_ALL, "Portuguese");

    int *On = (int*) malloc(sizeof(int));
    *On = 0;
    srand(time(NULL));

    printf("%d ^%d = %d\n", 5, 2, calculaPotencia(5,2, On));
    printf("\nCmplexidade: %d",*On);
    *On = 0;
    printf("\n\n\%d ^%d = %d", 3, 3, calculaPotencia(3,3, On));
    printf("\nCmplexidade: %d",*On);
    *On = 0;
    printf("\n\n\%d ^%d = %d", 2, 4, calculaPotencia(2,4, On));
    printf("\nCmplexidade: %d",*On);

    free(On);
}

int calculaPotencia(int a, int n, int *On){
    int potencia = a;
    for(int i = 1; i < n; i++){
        potencia = potencia * a;
        (*On)++;
    }
    return potencia;

}
