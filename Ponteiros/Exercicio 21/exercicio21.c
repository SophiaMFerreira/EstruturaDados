/*  21. Faça uma função para imprimir uma string de trás para frente. */
//Socorram-me, subi no ônibus em Marrocos

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define T_MAX 50
void inverteString(char *s);
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

    printf("\n\nA string invertida é: ");
    inverteString(s);

}

int tamanhoString(char *s){
    int length = 0;
    while(*(s + length) != '\0'){
        length++;
    }
    return length;
}


void inverteString(char *s){
    for(int length = tamanhoString(s); length >= 0; length--){
        printf("%c", *(s + length));
    }
}
