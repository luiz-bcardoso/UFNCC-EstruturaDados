typedef struct no {
    int dado;
    struct no* prox;
} Lista;

Lista* inserir(int dado, Lista* lista) {
    if (lista && dado >= lista->dado) {
        if (dado != lista->dado) {
            //avan�ar na lista
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
        // Se o n�mero � par, remove-o e continua com o pr�ximo
        Lista* temp = lista->prox; // Armazena o pr�ximo n�
        free(lista);               // Libera o n� atual
        return removerPares(temp); // Continua com o pr�ximo n�
    }
    else {
        // Se o n�mero � �mpar, mant�m e continua com o pr�ximo
        lista->prox = removerPares(lista->prox);
        return lista;
    }
}

Lista* unir(Lista* listaA, Lista* listaB) {
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    
    if (!listaA && !listaB) {
        // Caso base: ambas as listas est�o vazias
        return NULL;
    }

    if (listaA) {
        // Copia o dado de listaA e avan�a para o pr�ximo n�
        novaLista->dado = listaA->dado;
        novaLista->prox = unir(listaA->prox, listaB);
    }
    else {
        // Copia o dado de listaB e avan�a para o pr�ximo n�
        novaLista->dado = listaB->dado;
        novaLista->prox = unir(listaA, listaB->prox);
    }

    return novaLista;
}