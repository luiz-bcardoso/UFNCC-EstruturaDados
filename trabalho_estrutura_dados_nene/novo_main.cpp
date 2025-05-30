#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "lista.h"

int main() {
    srand(time(NULL));
    Lista* listaA = NULL;
    Lista* listaB = NULL;

    for (int i = 0; i < 20; i++) {
        listaA = inserir(rand() % 100, listaA);
		listaB = inserir(rand() % 100, listaB);
    }

    cout << "Total de elementos: " << contar(listaA) << endl;
	cout << "Total de elementos: " << contar(listaB) << endl;

	exibir(listaA, listaB);

	/*cout << "\nLista A sem pares: " << endl;
    removerPares(listaA);
    exibir(listaA);*/

	cout << "\nLista A unida com B: " << endl;
    Lista* novaLista = unir(listaA, listaB);
    exibir(novaLista);

    return 1;
}



