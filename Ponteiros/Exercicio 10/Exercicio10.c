/*   10. Quais as saídas produzidas pelo código abaixo.
	main(){
		int x, *p1, *p2;
		x = 10;
		p1 = &x;
		p2 = p1;
		printf("%d", *p2 -10);
	}

    R.: 0
*/

main(){
    int x, *p1, *p2;
    x = 10;
    p1 = &x;
    p2 = p1;
    printf("%d", *p2 -10);
}
