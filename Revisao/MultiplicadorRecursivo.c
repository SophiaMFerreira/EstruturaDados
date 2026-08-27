// Implementar uma função recursiva que multiplica 2 números.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

multiplicador( int percela1, int percela2);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int produto = multiplicador(2, 3);
    printf("%d x %d = %d\n", 2, 3, produto);

    produto = multiplicador(-5, 5);
    printf("%d x %d = %d\n", -5, 5, produto);

    produto = multiplicador(5, -10);
    printf("%d x %d = %d\n", 5, -10, produto);

    produto = multiplicador(-10, -10);
    printf("%d x %d = %d\n", -10, -10, produto);

    produto = multiplicador(0, 3);
    printf("%d x %d = %d\n", 3, -3, produto);

    produto = multiplicador(6, 0);
    printf("%d x %d = %d\n", 6, 0, produto);

    produto = multiplicador(0, 0);
    printf("%d x %d = %d\n", 0, 0, produto);
}

multiplicador( int percela1, int percela2){
    // produto = percela1 + percela1 + percela1 ... + percela1 (percela2 X)

    if(percela2 < 0){
        percela2 = percela2 * -1;
        percela1 = percela1 * -1;
    }

    if(percela1 == 0 || percela2 == 0){
        return 0;
    } else {
        if(percela2 == 1){
            return percela1;
        } else {
            return multiplicador(percela1, percela2 - 1) + percela1;
        }
    }
}
