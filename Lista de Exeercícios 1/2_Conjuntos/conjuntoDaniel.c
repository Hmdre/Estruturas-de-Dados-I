#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{

	int *elementos;
	unsigned int numElementos;

}ConjuntoInt;

ConjuntoInt* inicializarConjuntoInt();
void liberarConjuntoInt(ConjuntoInt *conjunto);
void imprimirConjuntoInt(ConjuntoInt *conjunto);
bool conjuntoIntVazio(ConjuntoInt *conjunto);
bool pertenceAoConjuntoInt(ConjuntoInt *conjunto, int elemento);
bool conjuntoIntIgual(ConjuntoInt *conjuntoA,ConjuntoInt *conjuntoB);
void inserirElementoInt(ConjuntoInt *conjunto,int elemento);
void removerElementoInt(ConjuntoInt *conjunto,int elemento);



ConjuntoInt* inicializarConjuntoInt(){
	
	ConjuntoInt* conjunto = (ConjuntoInt*)malloc(sizeof(ConjuntoInt));
	conjunto->elementos = NULL;
	conjunto->numElementos = 0;
	
	return conjunto;
}

void liberarConjuntoInt(ConjuntoInt *conjunto){
	free(conjunto->elementos);
	free(conjunto);
}

bool conjuntoIntVazio(ConjuntoInt *conjunto){
	if(conjunto->elementos == NULL){
		return  true;
	}else{
		return false;
	}
}

void imprimirConjuntoInt(ConjuntoInt *conjunto){
	
	if(conjuntoIntVazio(conjunto)){
		printf("Conjunto vazio!\n");
	}else{
		printf("elementos:\n");

			for(int i = 0; i < conjunto->numElementos; i++){
				
				printf("%d ",conjunto->elementos[i]);
			}

		printf("\n");
	}
}



void inserirElementoInt(ConjuntoInt *conjunto,int elemento){

	if(conjuntoIntVazio(conjunto)){
		//verifica se o conjunto é vazio, caso seja inserir o elemento.
		conjunto->elementos = malloc(sizeof(int));
		conjunto->numElementos++;
		conjunto->elementos[0] = elemento;
	
	}else if(pertenceAoConjuntoInt(conjunto , elemento) == false){	
		//verifica se o elemento já pertence ao conjunto, caso pertença como o conjunto nao repete elementos o elemento nao será inserido.
        conjunto->numElementos++;
		conjunto->elementos = (int*)realloc(conjunto->elementos ,conjunto->numElementos*sizeof(int) );
		conjunto->elementos[conjunto->numElementos-1] = elemento;

	}
}


void removerElementoInt(ConjuntoInt *conjunto,int elemento){
	int temp;
	for(int i = 0;i <conjunto->numElementos;i++){

		if(conjunto->elementos[i]==elemento){
			if(i==conjunto->numElementos-1){
				//se o elemento estiver na ultima posição realocar o vetor com menos 1 de tamanho 
				conjunto->numElementos--;
				conjunto->elementos = (int*)realloc(conjunto->elementos ,conjunto->numElementos*sizeof(int));
			}else{
				// caso a contrario trocar o elemento para a ultima posição e realocar
				temp = conjunto->elementos[conjunto->numElementos-1];
				conjunto->elementos[conjunto->numElementos-1] = conjunto->elementos[i];
				conjunto->elementos[i] = temp;

				conjunto->numElementos--;
				conjunto->elementos = (int*)realloc(conjunto->elementos ,conjunto->numElementos*sizeof(int));
			}
		}
	
	}
}

bool pertenceAoConjuntoInt(ConjuntoInt *conjunto, int elemento){
	
	for(int i = 0;i <conjunto->numElementos;i++){
		if(conjunto->elementos[i] == elemento){
			return true;
		}
	}
	return false;

}



int menorValorDoConjuntoInt(ConjuntoInt *conjunto){
	int temp = conjunto->elementos[0];

	for(int i = 0; i < conjunto->numElementos; i++){
		if(conjunto->elementos[i]<temp){
			temp = conjunto ->elementos[i];
		}
	}
	return temp;
}

bool conjuntoIntIgual(ConjuntoInt *conjuntoA,ConjuntoInt *conjuntoB){
	//verifica se o numero de elemtos e igual se for verifica elemento por elemento se existir um elemeto diferente retorna falso
	if(conjuntoA->numElementos != conjuntoB->numElementos){
		return false;
	}else{
		int elementoTemp;
		for(int i = 0;i < conjuntoA->numElementos; i++){

			elementoTemp = conjuntoA->elementos[i];
			if(pertenceAoConjuntoInt(conjuntoB,elementoTemp) == false){
				return false;
			}

		}
	}
	return true;
}

ConjuntoInt* unirConjuntosInt(ConjuntoInt *conjuntoA,ConjuntoInt *conjuntoB){
	ConjuntoInt *conjuntoFinal = inicializarConjuntoInt();
	//criar um conjunto vazio e inserir todos  os elementos dos dois conjuntos, ja que o metodo de inserção nao repete elementos 

	for(int i = 0; i <conjuntoA->numElementos; i++){
		inserirElementoInt(conjuntoFinal,conjuntoA->elementos[i]);
	}

	for(int j = 0; j < conjuntoB->numElementos; j++){
		inserirElementoInt(conjuntoFinal,conjuntoB->elementos[j]);
	}
	return conjuntoFinal;
}



int main(){
	ConjuntoInt *a = inicializarConjuntoInt();
	ConjuntoInt *b = inicializarConjuntoInt();
    ConjuntoInt *c;

	inserirElementoInt(a,4);
	inserirElementoInt(a,1);
	inserirElementoInt(a,4);
	inserirElementoInt(a,3);
	inserirElementoInt(a,5);
	inserirElementoInt(a,4);
 
	inserirElementoInt(b,4);
	inserirElementoInt(b,3);
	inserirElementoInt(b,5);
	inserirElementoInt(b,1);

	inserirElementoInt(b,50);
	inserirElementoInt(b,31);
	inserirElementoInt(b,5);
	inserirElementoInt(b,1);

	c = unirConjuntosInt(a,b); 

	printf("\nconjunto A\n");
	imprimirConjuntoInt(a);
	printf("\nconjunto B\n");
	imprimirConjuntoInt(b);
	printf("\nconjunto C\n");
	imprimirConjuntoInt(c);




	return 0;
}