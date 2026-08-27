/*  9. Quais as saídas produzidas pelo código abaixo.
        main(){
            int i=5, *p;
            p = &i;
            printf("%d %d %d", p,*p+2,3**p);
        }

        R.: *endereco de I 7 15
*/


main(){
    int i=5, *p;
    p = &i;
	printf("%d %d %d", p,*p+2,3**p);
}

