/*   8. Qual a saída produzida pelo código abaixo.
        main(){
            int x, *p1, *p2;
            x = 10;
            p1 = &x;
            p2 = p1;
            printf("%d", *p2);
        }

        R.: 10
*/

main(){
    int x, *p1, *p2;
    x = 10;
    p1 = &x;
    p2 = p1;
    printf("%d", *p2);
}
