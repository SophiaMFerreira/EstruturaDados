/*  7. Qual será a saída produzida pelo trecho de código abaixo? Considere a variável i armazenada no endereço 6422036.

        main(){
            int i = 5, *p = &i;
            printf(“%d %d %d”, p, *p+2, 3**p);
        }

        R.:6422036 7 15
*/

main(){
	int i = 5, *p = &i;

	printf("Endereco de i :%d", &i);
	printf("\n%d %d %d", p, *p+2, 3**p);
}
