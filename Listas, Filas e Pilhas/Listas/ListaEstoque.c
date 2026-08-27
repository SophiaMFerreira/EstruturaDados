/*      Faça um controle de estoque com:
            * inclusão de produto,
            * compra,
            * venda,
            * posição geral de estoque,
            * consulta estoque de um produto,
            * exclusão de um produto.

        Estrutura dos produtos:
            * Código: inteiro (chave primária)
            * Nome: string
            * Quantidade em estoque: inteiro (>=0)
            * Armazenamento dos produtos: lista encadeada com inserção no início da lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct structProduto{
    int codigo;
    char* nome;
    int qntEstoque;
    struct structProduto *proxProduto;
} Produto;

typedef struct {
    int acao;
    int posicaoAcao;
    int unidades;
    int codigo;
} DadosAcao;

int exibeMenu();
Produto* preencheProduto(Produto *lista, Produto *novoProduto);
int verificaOcorrenciaCodigo(int intRand, Produto *lista);
DadosAcao retornaPosicaoAcao();
DadosAcao mensagemCompraVenda();


Produto* inclusaoInicio(Produto *lista, Produto *novoProduto);
void inclusaoMeio(Produto **lista, Produto *novoProduto, DadosAcao dadosAcao);
void inclusaoFim(Produto **lista, Produto *novoProduto);

void compra(Produto *lista, DadosAcao dadosAcao);
void venda(Produto *lista, DadosAcao dadosAcao);
void posicaoGeral(Produto *lista, int codigo);
void consulta(Produto *lista);

Produto* excluiInicio(Produto *lista);
void excluiMeio(Produto **lista, DadosAcao dadosAcao);
void excluiFim(Produto **lista);

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Produto *lista = NULL;
    int opcao;
    DadosAcao dadosAcao;

    do{
        opcao = exibeMenu();
        switch(opcao){
            case 1:{
                Produto *novoProduto = (Produto*) malloc(sizeof(Produto));
                if(novoProduto != NULL){
                    novoProduto = preencheProduto(lista, novoProduto);
                    if(lista != NULL){
                        do{
                            dadosAcao = retornaPosicaoAcao();
                            switch(dadosAcao.acao){
                                case 1:
                                    lista = inclusaoInicio(lista, novoProduto);
                                    break;
                                case 2:
                                    inclusaoMeio(&lista, novoProduto, dadosAcao);
                                    break;
                                case 3:
                                    inclusaoFim(&lista, novoProduto);
                                    break;
                                default:
                                    printf("Incluir novamente, opção de inclusão inválida.\n");
                                    break;
                            }
                        }while((dadosAcao.acao < 1) || (dadosAcao.acao > 3));
                    }else{
                        lista = inclusaoInicio(lista, novoProduto);
                    }

                } else {
                    printf("\nErro ao iniciar ação! (FALHA DE ALOCAÇÃO)");
                }
            }break;

            case 2:
                dadosAcao = mensagemCompraVenda();
                compra(lista, dadosAcao);
                break;
            case 3:
                dadosAcao = mensagemCompraVenda();
                venda(lista,dadosAcao);
                break;
            case 4:{
                int codigo;
                printf("\tDeseja encontrar a posição de que produto (código) ? ");
                scanf("%d", &codigo);
                posicaoGeral(lista, codigo);
            }break;

            case 5:
                consulta(lista);
                break;
            case 6:
                if(lista != NULL){
                    do{
                        dadosAcao = retornaPosicaoAcao();
                        switch(dadosAcao.acao){
                            case 1:
                                lista = excluiInicio(lista);
                                    break;
                                case 2:
                                    excluiMeio(&lista, dadosAcao);
                                    break;
                                case 3:
                                    excluiFim(&lista);
                                    break;
                            default:
                                printf("Opção de exclusão inválida.\n");
                                break;
                        }
                    }while((dadosAcao.acao < 1) || (dadosAcao.acao > 3));
                } else {
                    printf("Não há produtos em estoque para serem excluidos.\n");
                }
                break;
            default:
                if(opcao != 0)
                    printf("Opção inválida!");
            break;
        }
    }while(opcao != 0);

    free(lista);
}

Produto* inclusaoInicio(Produto *lista, Produto *novoProduto){
    novoProduto->proxProduto = lista;
    return novoProduto;
}

void inclusaoMeio(Produto **lista, Produto *novoProduto, DadosAcao dadosAcao){
    Produto *listaCopia = *lista;
    Produto *anterior = NULL;

    if(dadosAcao.posicaoAcao == 0){
        inclusaoInicio(lista, novoProduto);
    }else{
        int i = 0;
        while((i < dadosAcao.posicaoAcao) && (listaCopia->proxProduto != NULL)){
            anterior = listaCopia;
            listaCopia = listaCopia->proxProduto;
            i++;
        }
        if(i == dadosAcao.posicaoAcao){
            novoProduto->proxProduto = listaCopia;
            anterior->proxProduto = novoProduto;
        }else{
            novoProduto->proxProduto = NULL;
            listaCopia->proxProduto = novoProduto;
            printf("Produto inserido ao final da lista. Posição fornecida inexistente.\n");
        }
    }
    free(listaCopia);
    free(anterior);
}

void inclusaoFim(Produto **lista, Produto *novoProduto){
    Produto *listaCopia = *lista;
    while(listaCopia->proxProduto != NULL){
        listaCopia = listaCopia->proxProduto;
    }
    novoProduto->proxProduto = NULL;
    listaCopia->proxProduto = novoProduto;
    free(listaCopia);
}

void compra(Produto *lista, DadosAcao dadosAcao){
    if(lista != NULL){
        while((lista != NULL) && (dadosAcao.codigo != lista->codigo)){
            lista = lista->proxProduto;
        }
        if(dadosAcao.codigo == lista->codigo){
            lista->qntEstoque  += dadosAcao.unidades;
            printf("\tCompra efetivada com sucesso: %d - %s: (%d unidades em estoque)\n", lista->codigo, lista->nome, lista->qntEstoque);
        } else {
            printf("\tProduto não encontrado, confime o código ou inclua-o no estoque.\n");
        }
    } else{
        printf("Não há estoque.\n");
    }
}

void venda(Produto *lista, DadosAcao dadosAcao){
    if(lista != NULL){
        while((lista != NULL) && (dadosAcao.codigo != lista->codigo)){
            lista = lista->proxProduto;
        }
        if(dadosAcao.codigo == lista->codigo){
            if((lista->qntEstoque  - dadosAcao.unidades) >= 0 ){
                lista->qntEstoque  -= dadosAcao.unidades;
                printf("\tVenda efetivada com sucesso: %d - %s: (%d unidades em estoque)\n", lista->codigo, lista->nome, lista->qntEstoque);
            }else{
                printf("\tA venda não pode ser efetivada, há apenas %d unidades em estoque\n", lista->qntEstoque);
            }
        } else {
            printf("Produto não encontrado,confime o código ou inclua-o no estoque.\n");
        }
    }else{
        printf("Não há estoque.\n");
    }
}

void posicaoGeral(Produto *lista, int codigo){
    int contador = 0;
    while((lista != NULL) && (codigo != lista->codigo)){
        lista = lista->proxProduto;
        contador++;
    }
    if(codigo == lista->codigo){
            printf("\tProduto encontrado: %d \t %d - %s (%d und)\n", contador, lista->codigo, lista->nome, lista->qntEstoque);
    } else {
        printf("Produto não encontrado. O código não consta em estoque.\n");
    }
}

void consulta(Produto *lista){
    if(lista != NULL){
        printf("\n======================================================");
        printf("\n\t\t\t Estoque");
        printf("\n======================================================");
        int contador = 0;
        while(lista != NULL){
            printf("\n\t%d \t %d - %s (%d und)\n", contador, lista->codigo, lista->nome, lista->qntEstoque);
            lista = lista->proxProduto;
            contador++;
        }
    }else{
        printf("Não há estoque.\n");
    }
}

Produto* excluiInicio(Produto *lista){
    return lista->proxProduto;
}

void excluiMeio(Produto **lista, DadosAcao dadosAcao){
    Produto *listaCopia = lista;
    Produto *anterior = NULL;
    int i;
    while((listaCopia->proxProduto != NULL) && (i < dadosAcao.posicaoAcao)){
        anterior = listaCopia;
        listaCopia = listaCopia->proxProduto;
        i++;
    }
    if(dadosAcao.posicaoAcao == i){
        anterior->proxProduto = listaCopia->proxProduto;
    } else {
        printf("Produto não encontrado, posição inexistente.\n");
    }
}
void excluiFim(Produto **lista){
    Produto *listaCopia = *lista;
    Produto *anterior = NULL;
    while(listaCopia->proxProduto != NULL){
            anterior = listaCopia;
            listaCopia = listaCopia->proxProduto;
        }
        anterior->proxProduto = NULL;
}

int exibeMenu(){
    printf("\n======================================================");
    printf("\n\t\t\t Menu");
    printf("\n======================================================");
    printf("\n\t 1 - Inclusão");
    printf("\n\t 2 - Compra");
    printf("\n\t 3 - Venda");
    printf("\n\t 4 - Posição geral");
    printf("\n\t 5 - Consulta");
    printf("\n\t 6 - Exclui");
    printf("\n\t 0 - Sai");
    printf("\n ======================================================\n");

    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

int verificaOcorrenciaCodigo(int intRand, Produto *lista){
    if(lista != NULL){
        while(lista != NULL){
            if(intRand == lista->codigo){
                return 1;
            } else {
                lista = lista->proxProduto;
            }
        }
    }
    return 0;
}

Produto* preencheProduto(Produto *lista, Produto *novoProduto){
        if(novoProduto){
            printf("\n----------------------------------------------");
            printf("\n\t\tDados do Novo Produto");

            int intRand;
            do{
                intRand = rand();
            }while(verificaOcorrenciaCodigo(intRand, lista));
            novoProduto->codigo = intRand;
            printf("\n\tCódigo: %d", novoProduto->codigo);

            novoProduto->nome = (char*) malloc(sizeof(char)*100);
            printf("\n\tNome: ");
                setbuf(stdin, NULL);
                fgets(novoProduto->nome, 99, stdin);
                novoProduto->nome[strcspn(novoProduto->nome, "\n")] = '\0';

            do{
                printf("\tQuantidade: ");
                scanf("%d", &(novoProduto->qntEstoque));
                if(novoProduto->qntEstoque < 0){
                    printf("A quantidade não pode ser negativa!\n");
                }
            }while(novoProduto->qntEstoque < 0);

            printf("\n----------------------------------------------\n");
            return novoProduto;

        } else {
            return NULL;
        }
}

DadosAcao retornaPosicaoAcao(){
    DadosAcao dadosAcao;
    printf("\tOnde deseja realizar a ação? ");
    printf("\n======================================================");
    printf("\n    1. Início \t 2. Meio\t 3. Fim");
    printf("\n======================================================\n");
    scanf("%d", &dadosAcao.acao);
        if(dadosAcao.acao == 2){
            do{
                printf("\tEm que posição deseja realizar a ação? ");
                scanf("%d", &dadosAcao.posicaoAcao);
                if(dadosAcao.posicaoAcao < 0){
                    printf("\nA posição não pode ser negativa.");
                }
            }while(dadosAcao.posicaoAcao < 0);
        }

    return dadosAcao;
}

DadosAcao mensagemCompraVenda(){
    DadosAcao dadosAcao;
    printf("\tA ação é referente a que produto (código) ? ");
    scanf("%d", &dadosAcao.codigo);
    do{
        printf("\tQuantas unidades foram compradas/vendidas ? ");
        scanf("%d", &dadosAcao.unidades);
        if(dadosAcao.unidades < 0){
            printf("\nO número de unidades não pode ser negativa.");
        }
    }while(dadosAcao.unidades < 0);
    return dadosAcao;
}
