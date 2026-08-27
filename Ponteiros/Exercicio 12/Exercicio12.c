/*   12. Considere a seguinte declaração: int pulo[100]. Quais das seguintes expressões referenciam o valor do terceiro elemento do vetor?
        a) *(pulo + 2)
        b) *(pulo + 4)
        c) pulo + 4
        d) pulo + 2
        e) *(pulo + 3)
        f) pulo + 3

    R.: A) *(pulo + 2)
*/

main(){
    int pulo[100];
    pulo[2] = 3;

	printf("a) *(pulo + 2) - %d\n\n", *(pulo + 2));
	printf("b) *(pulo + 4) - %d\n\n", *(pulo + 4));
	printf("c) pulo + 4 - %d\n\n", pulo + 4);
	printf("d) pulo + 2 - %d\n\n", pulo + 2);
	printf("e) *(pulo + 3) - %d\n\n", *(pulo + 3));
	printf("f) pulo + 3 - %d\n\n", pulo + 3);
}
