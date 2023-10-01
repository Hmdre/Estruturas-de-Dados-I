/*
2. Desenvolva e implemente um TAD que represente um conjunto de inteiros. Para isso, utilize um vetor de inteiros.
   O TAD deverá conter as seguintes funções:
	a) Criar um conjunto vazio.
	b) Inserir um elemento no conjunto.
	c) Remover um elemento no conjunto.
	d) Testar se um número pertence ao conjunto.
	e) Menor valor do conjunto.
	f) União de dois conjuntos.
	g) Testar se os dois conjuntos são iguais.
	h) Testar se o conjunto é vazio.
   Para cada função, explique brevemente a ideia adotada. Teste o TAD com uma aplicação.
*/

#include "conjuntos.h"

int main()
{
    Conjunto *conj1 = criaConj();

    insereElem(conj1, 5);
    insereElem(conj1, 6);
    insereElem(conj1, 42);
    insereElem(conj1, 1);
    insereElem(conj1, 6);
    insereElem(conj1, 1);

    removeElem(conj1, 1);

    printf("\nConjunto 1: ");
    mostra(conj1);

    printf("\nO menor valor do conjunto 1: %d", menorValor(conj1));

    Conjunto *conj2 = criaConj();

    insereElem(conj2, 3);
    insereElem(conj2, 24);
    insereElem(conj2, 7);
    insereElem(conj2, 1);
    insereElem(conj2, 42);

    printf("\nConjunto 2: ");
    mostra(conj2);

    if (testarIgualdade(conj1, conj2) == true)
        printf("\nOs conjuntos sao iguais.");
    else
        printf("\nOs conjuntos sao diferentes.");
    
    Conjunto *conj3 = uniConjuntos(conj1, conj2);
    printf("\nConjunto resultante da uniao: ");
    mostra(conj3);
    
    liberarConjunt(conj1);
    liberarConjunt(conj2);
    liberarConjunt(conj3);

    return 0;
}