/*  22. Faça uma função para determinar a quantidade de vogais presentes em um nome. */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#define T_MAX 50

typedef struct {
    int qntA;
    int qntE;
    int qntI;
    int qntO;
    int qntU;
} QntVogais;

QntVogais contaVogais(QntVogais qntVogaisString, char *s);

int main(){
    setlocale(LC_ALL, "Portuguese");

    char *s = (char*) malloc(sizeof(char) * T_MAX);
    QntVogais qntVogaisString;
        qntVogaisString.qntA = 0;
        qntVogaisString.qntE = 0;
        qntVogaisString.qntI = 0;
        qntVogaisString.qntO = 0;
        qntVogaisString.qntU = 0;

    int i = 0;
    while((i < T_MAX) && *(s + (i-1))!= '*'){
        *(s + i) = getche();
        setbuf(stdin, NULL);
        i++;
    }
    i--;
    *(s + i) = NULL;

    qntVogaisString = contaVogais(qntVogaisString, s);
    printf("\n\nA string tem:\n %d vogais A,\n %d vogais E,\n %d vogais I,\n %d vogais O,\n %d vogais U", qntVogaisString.qntA, qntVogaisString.qntE, qntVogaisString.qntI, qntVogaisString.qntO, qntVogaisString.qntU);

}

QntVogais contaVogais(QntVogais qntVogaisString, char *s){

    for(int i = 0; *(s + i) != '\0'; i++){
        char letra = tolower(*(s + i));
        switch (letra){
            case 'a':
                qntVogaisString.qntA++;
                break;
            case 'e':
                qntVogaisString.qntE++;
                break;
            case 'i':
                qntVogaisString.qntI++;
                break;
            case 'o':
                qntVogaisString.qntO++;
                break;
            case 'u':
                qntVogaisString.qntU++;
                break;
            default:
                break;
        }
    }
    return qntVogaisString;
}
