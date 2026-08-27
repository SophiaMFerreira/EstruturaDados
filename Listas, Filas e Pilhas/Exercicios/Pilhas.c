// Pilha simples

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct structNo {
    char* nomeLivro;
    int numero;
    struct structNo *proximoNo;
} No;

int exibeMenu();
No leLivro();

No* push(No *topo);
No* pop(No **topo);
No* peck(No *topo);
void imprime(No *topo);
void apaga(No **topo);

int main(){
    setlocale(LC_ALL, "Portuguese");
    No *topo = NULL;
    No *antigoTopo = NULL;
    int opcao;
    do{
        opcao = exibeMenu();
        switch(opcao){
            case 1:
                topo = push(topo);
            break;
            case 2:
                antigoTopo = pop(&topo);
                if(antigoTopo != NULL){
                    printf("\nLivro removido: %s - %d", antigoTopo->nomeLivro, antigoTopo->numero);
                }else{
                    printf("\nPilha vazia");
                }
            break;
            case 3:
               topo = peck(topo);
            break;
            case 4:
                imprime(topo);
            break;
            case 5:
                apaga(topo);
            break;
            default:
                if(opcao != 0)
                    printf("\nOpção inválida!");
            break;
        }
    }while(opcao != 0);


}

int exibeMenu(){
    printf("\n =======================");
    printf("\n 1 - Inclusão - Push");
    printf("\n 2 - Exclusão e Retorno - Pop");
    printf("\n 3 - Verifica - Peck");
    printf("\n 4 - Imprime");
    printf("\n 5 - Apaga");
    printf("\n 0 - FIM");
    printf("\n =======================\n");

    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

No leLivro(){
    No livro;
    livro.nomeLivro = (char*) malloc(sizeof(char)*51);
    if(livro.nomeLivro != NULL){
        printf("\nNome do livro: ");
        setbuf(stdin, NULL);
        fgets(livro.nomeLivro, 50, stdin);
        livro.nomeLivro[strcspn(livro.nomeLivro, "\n")] = '\0';

        printf("Número do livro: ");
        setbuf(stdin, NULL);
        scanf("%d", &livro.numero);

        return livro;
    }else{
        printf("Erro ao alocar nome!");
    }
}

No* push(No *topo){
    No *novoTopo = (No*) malloc(sizeof(No));
    if(novoTopo){
        No livro = leLivro();
        novoTopo->nomeLivro = livro.nomeLivro;
        novoTopo->numero = livro.numero;
        novoTopo->proximoNo = topo;

       return novoTopo;
    }else{
        printf("\nErro ao criar um novo livro (ERRO DE ALOCAÇÃO)!");
    }
    return NULL;
}

No* pop(No **topo){
    if(*topo != NULL){
        No *topoRemover = *topo;
        *topo = topoRemover->proximoNo;
        return topoRemover;
    }
    return NULL;
}

No* peck(No *topo){
        if(topo != NULL){
            printf("\nLivro: %s - nº %d", topo->nomeLivro, topo->numero);
            return topo;
        } else {
           printf("\nPilha vazia");
        }
}

void imprime(No *topo){
    if(topo != NULL){
        printf("\n =========== PILHA ===========");
        No *printTopo = topo;
            while(printTopo != NULL){
                printf("\nLivro: %s - nº %d", printTopo->nomeLivro, printTopo->numero);
                printTopo = printTopo->proximoNo;
            }
        printf("\n =============================\n");
    } else{
        printf("\nPilha vazia");
    }
}

void apaga(No **topo){
    if(*topo != NULL){
        while(topo != NULL){
            No *topoRemover = *topo;
            *topo = topoRemover->proximoNo;
            free(topoRemover->nomeLivro);
            free(topoRemover);
        }
        printf("Pilha apagada!");
    } else{
        printf("\nA pilha já está vazia");
    }
}
