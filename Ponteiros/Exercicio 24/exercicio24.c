/*     24. Codificar uma função que retorne o sobrenome de uma pessoa. Entenda como
           sobrenome todos os nomes após o primeiro nome.  */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#define T_MAX 50

void encontraSobrenome(char *s, char *sobrenome);

int main(){
    setlocale(LC_ALL, "Portuguese");

    char *s = (char*) malloc(sizeof(char) * T_MAX);
    char *sobrenome = (char*) malloc(sizeof(char) * (T_MAX / 5));

    int i = 0;
    while((i < T_MAX) && *(s + (i-1))!= '*'){
        *(s + i) = getche();
        setbuf(stdin, NULL);
        i++;
    }
    i--;
    *(s + i) = NULL;

    encontraSobrenome(s, sobrenome);
    printf("\n\nO sobrenome dessa pessoa é: ");
    for(int i = 0; *(sobrenome + i) != '\0'; i++){
        printf("%c", *(sobrenome + i));
    }

}

void encontraSobrenome(char *s, char *sobrenome){
    int j = 0;
    int ativa_sobrenome = 0;
    for(int i = 0; (*(s + i)) != '\0'; i++){
        if((isupper(*(s + i))) && (*(s + (i-1)) == ' ')){
            ativa_sobrenome = 1;
        }
        if(ativa_sobrenome){
            *(sobrenome + j) = *(s + i);
            j++;
        }
    }
}
