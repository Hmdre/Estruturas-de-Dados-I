#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct conjunto
{
    int *conjunto;
    int tamanho;
} Conjunto;

Conjunto* criaConj()//aloca dinamicamente um conjunto vazio
{
    Conjunto *conj = (Conjunto*) malloc(sizeof(Conjunto));
    if(conj != NULL)
    {
        conj->conjunto = NULL;
        conj->tamanho = 0;
        return conj;
    }
    return NULL;
} 

bool testaPertencente(Conjunto *conj, int elemento)//testa se o elemento pertence ao conjunto
{
	for(int i = 0 ; i <conj->tamanho ; i++)
    {
		if(conj->conjunto[i] == elemento)
			return true;
	}
	return false;
}

bool testaVazio(Conjunto *conj)//testa se o conjunto e vazio
{
	if(conj->conjunto == NULL)
		return  true;
    else
    	return false;
}

bool testarIgualdade(Conjunto *conj1, Conjunto *conj2)//primeiro testa o tamanho para ver se sao iguais, caso seja testa igualdade dos elementos
{
	if(conj1->tamanho != conj2->tamanho)
		return false;
	else
    {
		int aux;
		for(int i = 0 ; i < conj1->tamanho ; i++)
        {
    		aux = conj1->conjunto[i];
			if(testaPertencente(conj2, aux) == false)
				return false;
		}
	}
	return true;
}

void liberarConjunt(Conjunto *conj)//libera os espacos alocados dos conjuntos
{
	free(conj->conjunto);
	free(conj);
}

void insereElem(Conjunto *conj, int elemento)//insere o elemento caso o conjunto seja vazio, se nao for verifica se o elemento esta no conjunto e caso nao esteja insere
{
    if(testaVazio(conj))
    {
		conj->conjunto = (int*) malloc(sizeof(int));
		conj->tamanho++;
		conj->conjunto[0] = elemento;
	
	}
    else if(testaPertencente(conj , elemento) == false)
    {	
        conj->tamanho++;
		conj->conjunto = (int*)realloc(conj->conjunto ,conj->tamanho*sizeof(int) );
		conj->conjunto[conj->tamanho-1] = elemento;

	}
    else
    {
        printf("\nO elemento %d ja pertence ao conjunto.\n", elemento);
    }
}

void removeElem(Conjunto *conj, int elemento)//realoca o vetor com menos 1 de tamanho se o elemento estiver na ultima posicao, se nao coloca o elemento na ultima posicao trocando com o que estiver la e realoca com menos 1 posicao
{
	int aux;

	for(int i = 0 ; i <conj->tamanho ; i++)
    {
		if(conj->conjunto[i]==elemento)
        {
			if(i==conj->tamanho-1)
			{
				conj->tamanho--;
				conj->conjunto = (int*)realloc(conj->conjunto ,conj->tamanho*sizeof(int));
			}
            else
            {
				aux = conj->conjunto[conj->tamanho-1];
				conj->conjunto[conj->tamanho-1] = conj->conjunto[i];
				conj->conjunto[i] = aux;

				conj->tamanho--;
				conj->conjunto = (int*)realloc(conj->conjunto ,conj->tamanho*sizeof(int));
			}

		}
	
	}
}

int menorValor(Conjunto *conj)//procura e mostra menor valor do conjunto
{
	int aux = conj->conjunto[0];

	for(int i = 0; i < conj->tamanho; i++)
    {
		if(conj->conjunto[i]<aux)
			aux = conj ->conjunto[i];
	}
	return aux;
}

void mostra(Conjunto *conj)//printa o conjunto
{
    printf("[  ");
    for( int i = 0 ; i < conj->tamanho ; i++)
    {
        printf("%d  ",conj->conjunto[i]);
    }
    printf("]\n\n");
}

Conjunto* uniConjuntos(Conjunto *conj1, Conjunto *conj2)//aloca um novo conjunto e insere os elementos dos conjuntos existentes nele
{
	Conjunto *uniaoConj = criaConj();

	for(int i = 0 ; i <conj1->tamanho ; i++)
    {
		insereElem(uniaoConj,conj1->conjunto[i]);
	}

	for(int i = 0 ; i < conj2->tamanho ; i++)
    {
		insereElem(uniaoConj,conj2->conjunto[i]);
	}
	return uniaoConj;
}
