/*  25. Escreva uma função capaz de concatenar 2 strings. A função deve retornar uma string
        resultante da concatenação.  */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define T_MAX 50
void montaString(char *s);
void concatenaString(char *s1, char *s2, char *strings);

int main(){
    setlocale(LC_ALL, "Portuguese");

    char *s1 = (char*) malloc(sizeof(char) * T_MAX);
    char *s2 = (char*) malloc(sizeof(char) * T_MAX);
    char *strings = (char*) malloc(sizeof(char) * (T_MAX*2));

    montaString(s1);
    printf("\n\n");
    montaString(s2);

    printf("\n\nA string concatenada é: ");
    concatenaString(s1, s2, strings);
    for(int i = 0; *(strings + i) != '\0'; i++){
        printf("%c", *(strings + i));
    }


}

void montaString(char *s){
    int i = 0;
    while((i < T_MAX) && *(s + (i-1))!= '*'){
        *(s + i) = getche();
        setbuf(stdin, NULL);
        i++;
    }
    i--;
    *(s + i) = NULL;

}


void concatenaString(char *s1, char *s2, char *strings){
    int j = 0;
    for(int i= 0; *(s1 + i) != '\0'; i++){
        *(strings + j) = *(s1 + i);
        j++;
    }
    for(int i= 0; *(s2 + i) != '\0'; i++){
        *(strings + j) = *(s2 + i);
        j++;
    }
}
