#include <cstddef>
#include <corecrt_malloc.h>
#include <iostream>

typedef struct no {
	int dado;
	struct no* esq;
	struct no* dir;
} Arvore;

Arvore* inserir(int valor, Arvore* raiz) {
	if (raiz) {
		if (valor < raiz->dado) {
			// Ir para esquerda
			raiz->esq = inserir(valor, raiz->esq);
		}
		else {
			// Ir para direita
			raiz->dir = inserir(valor, raiz->dir);
		}
		return raiz;
	}
	else {
		Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
		novo->dado = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		return novo;
	}
}

void exibirOrdenado(Arvore* raiz) {
	if (raiz) { // percurso in-fixado ou ERD
		exibirOrdenado(raiz->esq);
		std::cout << raiz->dado << "\t";
		exibirOrdenado(raiz->dir);
	}
}

int contar(Arvore* raiz) {
	if (raiz) {
		return contar(raiz->esq) + contar(raiz->dir);
	}
	else {
		return 0;
	}
}

int somar(Arvore* raiz) {
	if (raiz) {
		return raiz->dado + somar(raiz->esq) + somar(raiz->dir);
	}
	else{
		return 0;
	}
}

int contarPares(Arvore* raiz) {
	if (raiz) {
		int cont = 0;
		if (raiz->dado % 2 == 0) {
			cont = 1;
		}
		return cont + contarPares(raiz->esq) + contarPares(raiz->dir);
	}
	else {
		return 0;
	}
}

void exibirFolhas(Arvore* raiz) {
	if (raiz) {
		if (!raiz->esq && !raiz->dir) {
			std::cout << raiz->dado << "\t"; // É uma folha
		}
		else {
			exibirFolhas(raiz->esq);
			exibirFolhas(raiz->dir);
		}
	}
	else {
		std::cout << "Árvore vazia." << std::endl;
	}
}

int contarFolhas(Arvore* raiz) {
	if (raiz) {
		if (!raiz->esq && !raiz->dir) {
			return 1; // É uma folha
		}
		else {
			return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
		}
	}
	else {
		return 0; // Árvore vazia
	}
}

bool localizar(int valor, Arvore* raiz) {
	if (raiz) {
		if (raiz->dado == valor) {
			return true;
		}
		else if (valor < raiz->dado) {
			return localizar(valor, raiz->esq);
		}
		else {
			return localizar(valor, raiz->dir);
		}
	}
	else {
		return false;
	}
