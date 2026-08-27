/*   11. Seja a seguinte sequência de instruções:
	int *pti;
	int i = 10;
	pti = &i;

Qual afirmativa é falsa?
	a) pti armazena o endereço de i.
	b) *pti é igual a 10.
	c) Ao se executar *pti = 20; i passará a ter o valor 20.
	d) Ao se alterar o valor de i, *pti será modificado.
	e) pti é igual a 10.

	R.: e) pti é igual a 10. -> pti guarda a posição de memória de I
*/
#include <locale.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    int *pti;
	int i = 10;
	pti = &i;

	printf("a) pti armazena o endereço de i. - \n %d", pti);
	printf("\n\nb) *pti e igual a 10. - \n %d", *pti);

	*pti = 20;
	printf("\n\nc) Ao se executar *pti = 20; i passara a ter o valor 20. -  \n *pti =%d, i =%d", *pti, i);

    *pti*4;
	printf("\n\nd) Ao se alterar o valor de i, *pti sera modificado. \n *pti =%d, i =%d", *pti, i);
	printf("\n\ne) pti é igual a 10. \n pti =%d\n", pti);
}
