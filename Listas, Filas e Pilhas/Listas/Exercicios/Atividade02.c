/*      2) Proponha uma nova funcionalidade para o programa listalinear3: uma função que seja capaz de inserir nós ao final da lista.   */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct EstruturaAluno {
    int matricula;
    char *nome;
    float nota;
    struct EstruturaAluno *proxAluno;
};
typedef struct EstruturaAluno Aluno;

Aluno *insereInicio(Aluno *atualAluno, Aluno no);
//Aluno *insereFinal(Aluno *atualAluno, Aluno no);

void imprime(Aluno *atualAluno);
Aluno *Remove(Aluno *atualAluno, int matricula);

//Aluno *libera(Aluno *atualAluno);
//Aluno *busca(Aluno *atualAluno, int matricula);

Aluno cadastraAluno();



int main(){
    setlocale(LC_ALL, "Portuguese");

    Aluno *listaAluno = NULL;
    int opc = 1;

    while(opc != 0){
        printf("\n\nEscolha a ação que deseja fazer sobre a lista:\n 1:Inserir no inicio;\n 2:Inserir no final;\n 3:Imprimir;\n 4:Remover;\n 5:Liberar tudo;\n 6:Busca;\n 0:ENCERRAR;\n");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                listaAluno = insereInicio(listaAluno, cadastraAluno());
                break;
            case 2:
                //listaAluno = insereFinal(listaAluno, cadastraAluno());
                break;
            case 3:
                imprime(listaAluno);
                break;
            case 4:
                //int matricula;
                //printf("Matrícula do aluno a ser excluido: ");
                //scanf("%d", &matricula);
                //listaAluno = Remove(listaAluno, matricula);
                listaAluno = Remove(listaAluno, 111);
                break;
            case 5:
                //listaAluno = libera(listaAluno);
                break;
            case 6:
                //int matricula;
                //printf("Matrícula do aluno a ser buscado: ");
                //scanf("%d", &matricula);
                //listaAluno = busca(listaAluno, matricula);
                //listaAluno = busca(listaAluno, 111);
                break;
            default:
                printf("\n\nERRO");
                break;
        }
    }
    return 0;
}

Aluno cadastraAluno(){
    Aluno no;
    printf("Matrícula do novo aluno: ");
    scanf("%d", &no.matricula);
    printf("Nome do novo aluno:");
    setbuf(stdin, NULL);
    gets(&no.nome);
    no.nome = "LALALa";
    printf("Nota do novo aluno: ");
    scanf("%d", &no.nota);
    no.nota = 10;
    return no;
}

Aluno *insereInicio(Aluno *atualAluno, Aluno no){
    Aluno *novoAluno = (Aluno*) malloc(sizeof(Aluno));

    novoAluno->matricula = no.matricula;
    novoAluno->nome = no.nome;
    novoAluno->nota = no.nota;

    if (atualAluno == NULL){                         //Lista está vazia?
        novoAluno->proxAluno = NULL;
    } else{
        novoAluno->proxAluno = atualAluno;
    }
        return novoAluno;
}

void imprime(Aluno *atualAluno){
    if (atualAluno == NULL){
        printf("\nLista Vazia!");
    }
    while(atualAluno != NULL){
        printf("\nMatrícula: %d", atualAluno->matricula);
        printf("\nNome.....: %s", atualAluno->nome);
        printf("\nNota.....: %f", atualAluno->nota);
        printf("\n");
        atualAluno = atualAluno->proxAluno;
    }
}

Aluno *Remove(Aluno *atualAluno, int matricula){
    Aluno *antAluno = NULL;                                                                 // ponteiro para elemento anterior

    Aluno *inicioAluno = atualAluno;                                                        // guarda o inicio da lista
    while((atualAluno != NULL) && (atualAluno->matricula != matricula)){
        antAluno = atualAluno;
        atualAluno = atualAluno->proxAluno;
    }

    if(atualAluno == NULL) return inicioAluno;                                              // não achou: retorna lista original

    Aluno *excluiAluno = atualAluno;
    if(antAluno == NULL){                                                                   // remove elemento do inicio
        atualAluno = atualAluno->proxAluno;
        inicioAluno = atualAluno;
    } else{                                                                                 // remove elemento intermediario ou último
        antAluno->proxAluno = atualAluno->proxAluno;
    }

    free(excluiAluno);
    return inicioAluno;
}
