// Aluna: Sophia Agnes de Machado Ferreira
// Prova B
// Questão 01

/*    Faça um programa recursivo que calcule a divis˜ao exata. Por exemplo: 66 / 3 = 22. Considere que os dados inseridos
      pelo usuário sempre ser˜ao de uma divis˜ao exata, ou seja, x e y tal que x > y e x é múltiplo de y. (recursividade-002)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int divisaoExata(int valor1, int valor2);

int main(){
    printf("66 / 3 = %d\n", divisaoExata(66, 3));
    printf("10 / 5 = %d\n", divisaoExata(10, 5));
    printf("400 / 8 = %d\n", divisaoExata(400, 8));
}

int divisaoExata(int valor1, int valor2){
    if(valor1 - valor2 < 0){
        return 0;                                                   // Não é mais possivel dividir
    } else {
        return divisaoExata(valor1 - valor2, valor2) + 1;           // É possivel dividir mais
    }
}
