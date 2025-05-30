typedef struct no {
    int dado;
    struct no* prox;
} Lista;

Lista* inserir(int dado, Lista* lista) {
    if (lista && dado >= lista->dado) {
        if (dado != lista->dado) {
            //avançar na lista
            lista->prox = inserir(dado, lista->prox);
        }
        return lista;
    }
    else { //cheguei no final da lista
        Lista* novo = (Lista*)malloc(sizeof(Lista));
        novo->dado = dado;
        if (lista) {
            novo->prox = lista;
        }
        else {
            novo->prox = NULL;
        }
        return novo;
    }
}

void exibir(Lista* lista) {
    if (lista) {
        cout << lista->dado << endl;
        exibir(lista->prox);
    }
}

void exibir(Lista* listaA, Lista* listaB) {
    if (listaA && listaB) {
        cout << "A: " << listaA->dado << " | B: " << listaB->dado << endl;
        exibir(listaA->prox, listaB->prox);
    }
    else if (listaA) {
        cout << "A: " << listaA->dado << " |" << endl;
        exibir(listaA->prox, NULL);
    }
    else if (listaB) {
        cout << "      | B: " << listaB->dado << endl;
        exibir(NULL, listaB->prox);
    }
}

int contar(Lista* lista) {
    if (lista) {
        return 1 + contar(lista->prox);
    }
    return 0;
}

Lista* removerPares(Lista* lista) {
    if (!lista) return NULL; // Lista vazia

    if (lista->dado % 2 == 0) {
        // Se o número é par, remove-o e continua com o próximo
        Lista* temp = lista->prox; // Armazena o próximo nó
        free(lista);               // Libera o nó atual
        return removerPares(temp); // Continua com o próximo nó
    }
    else {
        // Se o número é ímpar, mantém e continua com o próximo
        lista->prox = removerPares(lista->prox);
        return lista;
    }
}

Lista* unir(Lista* listaA, Lista* listaB) {
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    
    if (!listaA && !listaB) {
        // Caso base: ambas as listas estão vazias
        return NULL;
    }

    if (listaA) {
        // Copia o dado de listaA e avança para o próximo nó
        novaLista->dado = listaA->dado;
        novaLista->prox = unir(listaA->prox, listaB);
    }
    else {
        // Copia o dado de listaB e avança para o próximo nó
        novaLista->dado = listaB->dado;
        novaLista->prox = unir(listaA, listaB->prox);
    }

    return novaLista;
}