/* 4. Qual a instrução que deve ser adicionada ao programa abaixo para que ele funcione corretamente?
        main(){
            int *p;
            *p = 3;
            printf("Parte de valor de p: %d", *p);
            printf("\nParte de posição de p: %d", p);
        }
        R.: Deve ser adcinodao após a linha "int *p;" -> p = (int*) malloc(sizeof(int));
*/

#include <locale.h>

main(){
    setlocale(LC_ALL, "Portuguese");

    int *p;
    p = (int*) malloc(sizeof(int));
    *p = 3;
    printf("Parte de valor de p: %d", *p);
    printf("\nParte de posição de p: %d", p);
}
