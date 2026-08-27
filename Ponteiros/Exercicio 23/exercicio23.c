/*      23. Codificar um programa que seja capaz de criar uma sigla para cada nome fornecido.
            A sigla deve ser composta da letra inicial de cada parte do nome. Veja exemplos abaixo:
            Jose da Silva => JdS
            José Pedro Nogueira => JPN
            Minas Gerais => MG
            Goiás => G
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#define T_MAX 50

void montaSigla(char *s, char *sigla);

int main(){
    setlocale(LC_ALL, "Portuguese");

    char *s = (char*) malloc(sizeof(char) * T_MAX);
    char *sigla = (char*) malloc(sizeof(char) * (T_MAX / 5));

    int i = 0;
    while((i < T_MAX) && *(s + (i-1))!= '*'){
        *(s + i) = getche();
        setbuf(stdin, NULL);
        i++;
    }
    i--;
    *(s + i) = NULL;

    montaSigla(s, sigla);
    printf("\n\nA sigla da sring fornecida é: ");
    for(int i = 0; *(sigla + i) != '\0'; i++){
        printf("%c", *(sigla + i));
    }

}

void montaSigla(char *s, char *sigla){
    int j = 0;
    for(int i = 0; (*(s + i)) != '\0'; i++){
        if(isupper(*(s + i))){
            *(sigla + j) = *(s + i);
            j++;
        }
    }
}
