void entraNaFila(PessoaFila **filaComum1, PessoaFila **filaComum2, PessoaFila **filaPrioridade3, int numeroFila, int *identificador){
    PessoaFila *novaPessoa = (PessoaFila*) malloc(sizeof(PessoaFila));
    if(novaPessoa != NULL){
        novaPessoa->id = identificador;
            (*identificador)++;
        novaPessoa->proximaPessoa = NULL;

        if(numeroFila == 1){
            PessoaFila *copiaFila = *filaComum1;
            if(*filaComum1 != NULL){
                while(copiaFila->proximaPessoa != NULL){
                    copiaFila = copiaFila->proximaPessoa;
                }
                copiaFila->proximaPessoa = novaPessoa;
                printf("1a");
            } else {
                copiaFila->proximaPessoa = novaPessoa;
                printf("1b");
            }

        }else {
            if(numeroFila == 2){
                PessoaFila *copiaFila = *filaComum2;
                if(*filaComum2 != NULL){
                    while(copiaFila->proximaPessoa != NULL){
                        copiaFila = copiaFila->proximaPessoa;
                    }
                    copiaFila->proximaPessoa = novaPessoa;
                    printf("2a");
                } else {
                    copiaFila->proximaPessoa = novaPessoa;
                    printf("2b");
                }

            } else {
                PessoaFila *copiaFila = *filaPrioridade3;
                if(*filaPrioridade3 != NULL){
                    while(copiaFila->proximaPessoa != NULL){
                        copiaFila = copiaFila->proximaPessoa;
                    }
                    copiaFila->proximaPessoa = novaPessoa;
                } else {
                    copiaFila->proximaPessoa = novaPessoa;
                }
            }
        }
    } else {
        printf("Falha ao alocar uma nova pessoa.");
    }
}
