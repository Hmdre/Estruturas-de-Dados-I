/*
1. Desenvolva e implemente um TAD que represente um conjunto de inteiros. Para isso, utilize um vetor de inteiros.
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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct conjunto
{
    int *conjunto;
    int tamanho;
} Conjunto;

Conjunto* criaConj()
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

bool testaPertencente(Conjunto *conj, int elemento)
{
	for(int i = 0 ; i <conj->tamanho ; i++)
    {
		if(conj->conjunto[i] == elemento)
			return true;
	}
	return false;
}

bool testaVazio(Conjunto *conj)
{
	if(conj->conjunto == NULL)
		return  true;
    else
    	return false;
}

bool testarIgualdade(Conjunto *conj1,Conjunto *conj2)
{
	//verifica se o numero de elemtos e igual se for verifica elemento por elemento se existir um elemeto diferente retorna falso
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

void liberarConjunt(Conjunto *conj)
{
	free(conj->conjunto);
	free(conj);
}

void insereElem(Conjunto *conj, int elemento)
{
    if(testaVazio(conj))
    {
		//verifica se o conjunto é vazio, caso seja inserir o elemento.
		conj->conjunto = malloc(sizeof(int));
		conj->tamanho++;
		conj->conjunto[0] = elemento;
	
	}
    else if(testaPertencente(conj , elemento) == false)
    {	
		//verifica se o elemento já pertence ao conjunto, caso pertença como o conjunto nao repete elementos o elemento nao será inserido.
        conj->tamanho++;
		conj->conjunto = (int*)realloc(conj->conjunto ,conj->tamanho*sizeof(int) );
		conj->conjunto[conj->tamanho-1] = elemento;

	}
    else
    {
        printf("\nEste elemento ja pertence ao conjunto.\n");
    }
}

void removeElem(Conjunto *conj,int elemento)
{
	int aux;

	for(int i = 0 ; i <conj->tamanho ; i++)
    {
		if(conj->conjunto[i]==elemento)
        {
			if(i==conj->tamanho-1){
				//se o elemento estiver na ultima posição realocar o vetor com menos 1 de tamanho 
				conj->tamanho--;
				conj->conjunto = (int*)realloc(conj->conjunto ,conj->tamanho*sizeof(int));
			}
            else
            {
				// caso a contrario trocar o elemento para a ultima posição e realocar
				aux = conj->conjunto[conj->tamanho-1];
				conj->conjunto[conj->tamanho-1] = conj->conjunto[i];
				conj->conjunto[i] = aux;

				conj->tamanho--;
				conj->conjunto = (int*)realloc(conj->conjunto ,conj->tamanho*sizeof(int));
			}

		}
	
	}
}

int menorValor(Conjunto *conj)
{
	int aux = conj->conjunto[0];

	for(int i = 0; i < conj->tamanho; i++)
    {
		if(conj->conjunto[i]<aux)
			aux = conj ->conjunto[i];
	}
	return aux;
}

void mostra(Conjunto *conj)
{
    printf("[  ");
    for( int i = 0 ; i < conj->tamanho ; i++)
    {
        printf("%d  ",conj->conjunto[i]);
    }
    printf("]\n\n");
}

Conjunto* uniConjuntos(Conjunto *conj1,Conjunto *conj2)
{
	Conjunto *uniaoConj = criaConj();
	//criar um conjunto vazio e inserir todos  os elementos dos dois conjuntos, ja que o metodo de inserção nao repete elementos 

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

int main()
{
    int x=1, caso=0, c2=0, aux, elemento;

    Conjunto *conj1 = criaConj(), *conj2, *conj3;

    system("clear||cls");

    while(x != 0)
    {
        if(c2 == 0)
            printf("Manipule o primeiros conjunto ou crie um segundo:\n");
        else
            printf("-----Quatidade maxima de conjuntos atingida. Selecione a operacao desejada e depois o conjunto:-----\n"); 
 
        printf("\n1. Criar um conjunto vazio.\n2. Inserir elemento em um conjunto.\n3. Remover elemento de um conjunto.\n4. Verificar se um numero pertence a um conjunto.");
        printf("\n5. Menor valor de um conjunto.\n6. Unir dois conjuntos.\n7. Testar igualdade de conjuntos.\n8. Testar se o conjunto esta vazio.\n9. Para finalizar o programa.");
        printf("\n\nDigite o numero do comando escolhido:");
        scanf("%d", &caso);
        
        system("clear||cls");
        
        switch ( caso )
        {
            case 1:
            if(c2 == 0)
            {
                conj2 = criaConj();
                c2 = 1;
                printf("Conjunto vazio criado com sucesso.\n\n");
            }
            else
            {
                printf("Quantidade maxima de conjuntos alcancada.\n\n");
            }
            break;

            case 2:
            printf("\nDigite o elemento que deseja inserir:");
            scanf("%d", &elemento);
            if (c2 == 1)
            {
                printf("Qual conjunto deseja inserir o elemento?\nDigite 1 para o primeiro conjunto.\nDigite 2 para o segundo conjunto\nConjunto desejado:");
                scanf("%d", &aux);
                if(aux == 2)
                {
                    insereElem(conj2, elemento);
                    break;
                }
            }
            insereElem(conj1, elemento);
            break;

            case 3:
            printf("\nDigite o elemento que deseja remover:");
            scanf("%d", &elemento);
            if (c2 == 1)
            {
                printf("Qual conjunto deseja remover o elemento?\nDigite 1 para o primeiro conjunto.\nDigite 2 para o segundo conjunto\nConjunto desejado:");
                scanf("%d", &aux);
                if(aux == 2)
                {
                    removeElem(conj2, elemento);
                    break;
                }
            }
            removeElem(conj1, elemento);
            break;

            case 4:
            printf("\nDigite o elemento que deseja verificar:");
            scanf("%d", &elemento);
            if (c2 == 1)
            {
                printf("Qual conjunto deseja verificar o elemento?\nDigite 1 para o primeiro conjunto.\nDigite 2 para o segundo conjunto\nConjunto desejado:");
                scanf("%d", &aux);
                if(aux == 2)
                {
                    if(testaPertencente(conj2, elemento) == true)
                        printf("\nO elemento %d pertence ao conjunto 2.\n", elemento);
                    else
                        printf("\nO elemento %d nao pertence ao conjunto 2.\n", elemento);
                    break;
                }
            }
            if(testaPertencente(conj1, elemento) == true)
                printf("\nO elemento %d pertence ao conjunto 1.\n", elemento);
            else
                printf("\nO elemento %d nao pertence ao conjunto 1.\n", elemento);
            break;

            case 5:
            if (c2 == 1)
            {
                printf("Qual conjunto deseja verificar o menor elemento?\nDigite 1 para o primeiro conjunto.\nDigite 2 para o segundo conjunto\nConjunto desejado:");
                scanf("%d", &aux);
                if(aux == 2)
                {
                    printf("O menor valor do conjunto 2: %d", menorValor(conj2));
                    break;
                }
            }
            printf("O menor valor do conjunto 1: %d", menorValor(conj1));
            break;

            case 6:
            if (c2 == 1)
            {
                conj3 = uniConjuntos(conj1, conj2);
                printf("\nConjunto resultante da uniao: ");
                mostra(conj3);
                break;
            }
            printf("\nHa apenas um conjunto, crie um segundo conjunto pra efetuar uma uniao deles.\n\n");
            break;

            case 7:
            if (c2 == 1)
            {
                if (testarIgualdade(conj1, conj2) == true)
                    printf("\nOs conjuntos sao iguais.");
                else
                    printf("\nOs conjuntos sao diferentes.");
                break;
            }
            printf("\nHa apenas um conjunto, crie um segundo conjunto pra testar igualdade entre eles.\n\n");
            break;

            case 8:
            if (c2 == 1)
            {
                printf("Qual conjunto deseja verificar se e vazio?\nDigite 1 para o primeiro conjunto.\nDigite 2 para o segundo conjunto\nConjunto desejado:");
                scanf("%d", &aux);
                if(aux == 2)
                {
                    if (testaVazio(conj2) == true)
                        printf("O conjunto 2 e vazio.\n");
                    else
                        printf("O conjunto 2 nao e vazio\n");
                    break;
                }
            }
            if (testaVazio(conj1) == true)
                printf("\n\nO conjunto 1 e vazio.\n");
            else
                printf("\n\nO conjunto 1 nao e vazio\n");
            break;

            case 9:
            x = 0;
            break;

            default:
            printf("\nValor invalido\n");
        }

        if(c2 == 1)
        {
            printf("\nConjunto 1: ");
            mostra(conj1);
            printf("\nConjunto 2: ");
            mostra(conj2);
        }
        else
        {
            printf("\nConjunto 1: ");
            mostra(conj1);
        }
    }
    liberarConjunt(conj1);
    liberarConjunt(conj2);
    liberarConjunt(conj3);
    return 0;
}