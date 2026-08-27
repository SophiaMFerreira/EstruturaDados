/* Faça um controle de estoque com inclusão de produto, compra, venda, posição geral de estoque, consulta estoque de um produto, exclusão de um produto.
 * Estrutura dos produtos:
 * Código: inteiro (chave primária) (não pode repetir um código)
 * Nome: string
 * Quantidade em estoque: inteiro (>=0)
 * Armazenamento dos produtos: lista encadeada com inserção no início da lista
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct Produto {
    int codigo;
	char* nome;
	int qtd;
    struct Produto* prox;
} Produto;

Produto* cria(int c, char* n, int q) {
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    if (novo == NULL) {
        printf("\nErro 2 de alocação de memória.\n");
        exit(1);
    }
    novo->codigo = c;
	novo->nome = n;
	novo->qtd = q;
    novo->prox = NULL;
    return novo;
}

Produto* busca(int c, Produto* e){
	Produto* atual = e;
    //Produto* ant = NULL;

	while (atual != NULL && atual->codigo != c) {
        //ant = atual;
        atual = atual->prox;
    }

    return(atual);
}

void imprimeEstoque(Produto* e) {
    Produto* atual = e;
    printf("\nEstoque ");
	printf("\nCódigo Nome Quantidade");
    while (atual != NULL) {
        printf("\n%d %s %d", atual->codigo, atual->nome, atual->qtd);
        atual = atual->prox;
    }
    printf("\n");
}

Produto* insere(Produto* n, Produto* e) {
	n->prox = e;
	return(n);
}

/*Esta função recebe o elemento a ser removido
 * Ou seja, o elemento existe na lista
 * É feita uma busca antes
 * O laço inicial é para achar o nó anterior (se houver)
*/
Produto* exclui(Produto* exc, Produto* atual){
	Produto *ant = NULL;
	Produto* inicio = atual;
	while(atual->codigo != exc->codigo){
		ant = atual;
		atual = atual->prox;
	}

	if(ant == NULL){
		atual = atual->prox;
		inicio = atual;
	}
	else{
		ant->prox = atual->prox;
	}
	free(exc);
	return inicio;
}

int menu(){
	int opc;
	printf("\n =======================");
	printf("\n Menu");
	printf("\n =======================");
	printf("\n 1 - Inclusão");
	printf("\n 2 - Compra");
	printf("\n 3 - Venda");
	printf("\n 4 - Posição geral");
	printf("\n 5 - Consulta");
	printf("\n 6 - Exclui");
	printf("\n 7 - Sai");
	printf("\n =======================");
	printf("\n Escolha sua opção: ");
	scanf("%d", &opc);
	return(opc);
}

int main(){
	setlocale(LC_ALL,"Portuguese");

	int opcao, codigo, qtd, valor;
	Produto* estoque = NULL;
	char *nome;

	do{
		opcao = menu();
		switch(opcao){
			case 1:
				printf("\n Código do produto: ");
				scanf("%d", &codigo);
				if(busca(codigo, estoque)==NULL){
					getchar();
					printf("\n Nome: ");
					nome = (char *)malloc((81) * sizeof(char));
					if (nome == NULL) {
						printf("\nErro 1 de alocação de memória.\n");
						return 1;
					}
					//fgets(nome, 81, stdin); Some o warning do compilador quando usa gets(),
					//mas coloca um \n no final da string lida.
					//Fiquei com preguiça de tirar
					gets(nome);
					printf("\n Quantidade (>=0): ");
					scanf("%d", &qtd);
					if(qtd>=0){
						Produto* novo = cria(codigo, nome, qtd);
						estoque = insere(novo, estoque);
					}
					else{
						printf("\nErro na quantidade");
					}
				}
				else{
					printf("\nCódigo já existe.");
				}
				break;
			case 2:
				printf("\n Código do produto a ser comprado: ");
				scanf("%d", &codigo);
				Produto* comprar = busca(codigo, estoque);
				if(comprar==NULL){
					printf("\n Código não existe.");
				}
				else{
					printf("\n Quantidade comprada: ");
					scanf("%d", &valor);
					if(valor>0){
						comprar->qtd += valor;
					}
					else{
						printf("\n Valor inválido.");
					}
				}
				break;
			case 3:
				printf("\n Código do produto a ser vendido: ");
				scanf("%d", &codigo);
				Produto* vender = busca(codigo, estoque);
				if(vender==NULL){
					printf("\n Código não existe.");
				}
				else{
					printf("\n Quantidade vendida: ");
					scanf("%d", &valor);
					if(valor>vender->qtd){
						printf("\n Estoque insuficiente");
					}
					else{
						vender->qtd -= valor;
					}
				}
				break;
			case 4:
				imprimeEstoque(estoque);
				break;
			case 5:
				printf("\n Código a ser consultado: ");
				scanf("%d", &codigo);
				Produto* consultar = busca(codigo, estoque);
				if(consultar==NULL){
					printf("\n Código não existe.");
				}
				else{
					printf("\nCódigo: %d\nNome: %s\nQuantidade: %d\n",consultar->codigo, consultar->nome, consultar->qtd);
				}

				break;
			case 6:
				printf("\n Código do produto a ser excluído: ");
				scanf("%d", &codigo);
				Produto* excluir = busca(codigo, estoque);
				if(excluir==NULL){
					printf("\n Código não existe.");
				}
				else{
					estoque = exclui(excluir, estoque);
				}
				break;
			default:
				printf("\n Opção inválida.");
		}
	}while(opcao!=7);
	free(nome);
}
