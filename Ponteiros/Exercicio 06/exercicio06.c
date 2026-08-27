/* 6. Considere as seguintes instruções:
        int i = 3, j = 5;
        int *p = &i, *q = &j;

        Qual o valor das seguintes expressões:
            a) p == &i -> True
            b) *p - *q -> -2
*/

main(){
    int i = 3, j = 5;
    int *p = &i, *q = &j;

    int respostaA = p == &i ? 1 : 0;
    printf("p == &i : %d", respostaA);

    int respostaB = *p - *q;
    printf("\n*p - *q : %d", respostaB);
}
