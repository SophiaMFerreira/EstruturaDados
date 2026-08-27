/*      5. Assumindo que o endereço da variável x fora atribuído a um ponteiro px, escreva uma
        expressão matemática que não use x, mas que divida x por 5.

        R.: *px / 5;
*/
main(){
    int x = 70;
    int *px;
    px = &x;
    printf("X vale : %d", x);
    x = *px / 5;
    printf("\nNovo valor de x: %d", x);
}
