/*  20. Codificar uma função capaz de concatenar uma string ao final de outra string. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define T_MAX 50
void montaString(char *s);
void concatenaString(char *s1, char *s2);

int main(){
    setlocale(LC_ALL, "Portuguese");

    char *s1 = (char*) malloc(sizeof(char) * T_MAX);
    char *s2 = (char*) malloc(sizeof(char) * T_MAX);

    montaString(s1);
    printf("\n\n");
    montaString(s2);
    printf("\n\nA string concatenada é: ");
    concatenaString(s1, s2);

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


void concatenaString(char *s1, char *s2){
    for(int i= 0; *(s1 + i) != '\0'; i++){
        printf("%c", *(s1 + i));
    }
    for(int i= 0; *(s2 + i) != '\0'; i++){
        printf("%c", *(s2 + i));
    }
}
