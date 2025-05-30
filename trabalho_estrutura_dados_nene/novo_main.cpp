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

	// 1. Exibir as duas listas
	exibir(listaA, listaB);

	// 2. Remover os números pares da lista A
	cout << "\nLista A sem pares: " << endl;
    //removerPares(listaA); //TODO: Fix bug primeiro elemento par!!!
    exibir(listaA);

	// 3. Unir as duas listas
	cout << "\nLista A unida com B: " << endl;
    Lista* listaAB = unir(listaA, listaB);
    exibir(listaAB);

	// 4. Ordenar a lista unida
	cout << "\nLista A unida com B ordenada: " << endl;
	ordenar(listaAB);
	exibir(listaAB);

	// 5. Remover toda a lista unida
	cout << "\Removendo lista A unida com B..." << endl;
	remover(listaAB);

    return 1;
}


