/* Quest˜ao 1: [2 pontos]
        Complete o programa 1 abaixo conforme as instru¸c˜oes.
        Programa 1: Programa incompleto
        void calculaMedia ( PARAMETROS ) {
            CODIGO
        }
i n t main ( ) {
Alocar mem´oria para 3 v a r i ´a v e i s r e a i s
Receber o v al o r de duas d elas , via t e cl ad o
Usar a fun¸c˜ao acima para c a l c u l a r a m´edia das duas e
armazenar e s t a m´edia na t e r c e i r a v a r i ´a v e l
Imprimir o v al o r da m´edia
Lib er ar mem´oria
}


*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void calculaMedia ( float *val1 , float *val2,  float *val3);
main(){
    setlocale(LC_ALL, "Portuguese");

    float *val1 = (float*) malloc(sizeof(float));
    float *val2 = (float*) malloc(sizeof(float));
    float *val3 = (float*) malloc(sizeof(float));

    printf("Digite um número: ");
    scanf("%f", val1);
    printf("Digite um número: ");
    scanf("%f", val2);

    calculaMedia (val1, val2, val3);
    printf("\nA média é: %.2f", *val3);

    free(val1);
    free(val2);
    free(val3);
}

void calculaMedia ( float *val1 , float *val2,  float *val3) {
    *val3 = (*val1 + *val2) / 2;
}
