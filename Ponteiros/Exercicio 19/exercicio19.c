/*  19. Codificar uma função de nome tamanhoString que seja capaz de calcular o tamanho de
    uma string. Sugestão de protótipo:

        int tamanhoString(char *s);
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define T_MAX 50
int tamanhoString(char *s);

int main(){
    setlocale(LC_ALL, "Portuguese");

    char *s = (char*) malloc(sizeof(char) * T_MAX);

    int i = 0;
    while((i < T_MAX) && *(s + (i-1))!= '*'){
        *(s + i) = getche();
        setbuf(stdin, NULL);
        i++;
    }
    i--;
    *(s + i) = NULL;

    printf("\n\nA string tem %d caracteres de tamanho.", tamanhoString(s));

}

int tamanhoString(char *s){
    int length = 0;
    while(*(s + length) != '\0'){
        length++;
    }
    return length;
}
