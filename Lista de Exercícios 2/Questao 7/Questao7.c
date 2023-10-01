/*
7.- Escreva um programa em C que classifique as palavras em um texto, disponível na forma de arquivo,
 em categorias de acordo com a letra inicial de cada palavra. As palavras iniciadas com a mesma letra
 deverão ser colocadas em uma mesma fila. Após a classificação, exiba o número de palavras existentes
 em cada categoria.
*/

#include "FilaTAD.h"
#include <ctype.h>


QUEUE* A;
QUEUE* B;
QUEUE* C;
QUEUE* D;
QUEUE* E;
QUEUE* F;
QUEUE* G;
QUEUE* H;
QUEUE* I;
QUEUE* J;
QUEUE* K;
QUEUE* L;
QUEUE* M;
QUEUE* N;
QUEUE* O;
QUEUE* P;
QUEUE* Q;
QUEUE* R;
QUEUE* S;
QUEUE* T;
QUEUE* U;
QUEUE* V;
QUEUE* W;
QUEUE* X;
QUEUE* Y;
QUEUE* Z;

void imprimeFila(QUEUE* fila,char letra){
	void* aux;
    printf("fila das plavras iniciadas com a letra %c: \nnumero de elementos: %d\n",letra,queueCount(fila));
	for(int i = 0;i<queueCount(fila);i++)
	{
		dequeue(fila,&aux);
		printf("%s\n",(char*)aux);
		enqueue(fila,aux);
	}	
	printf("\n");
}

char* alocaPalavra(char* string, int tamanho)
{
    char* palavra = malloc ((tamanho+1)*sizeof(char));
	int i;

    for(i = 0; i < tamanho; i++)
    {
        palavra[i] = string[i];
    }
	palavra[i] ='\0';
	return palavra;
}

void enfileiraPalavra(char* string, int numLetras, char primeiraLetra)
{
	void* stringPalavra = alocaPalavra(string, numLetras);
	switch ( primeiraLetra )
	{
		case 'a':
		enqueue(A, stringPalavra);
		break;

		case 'b':
		enqueue(B, stringPalavra);
		break;

		case 'c':
		enqueue(C, stringPalavra);
		break;

		case 'd':
		enqueue(D, stringPalavra);
		break;

		case 'e':
		enqueue(E, stringPalavra);
		break;

		case 'f':
		enqueue(F, stringPalavra);
		break;

		case 'g':
		enqueue(G, stringPalavra);
		break;

		case 'h':
		enqueue(H, stringPalavra);
		break;

		case 'i':
		enqueue(I, stringPalavra);
		break;

		case 'j':
		enqueue(J, stringPalavra);
		break;

		case 'k':
		enqueue(K, stringPalavra);
		break;

		case 'l':
		enqueue(L, stringPalavra);
		break;

		case 'm':
		enqueue(M, stringPalavra);
		break;

		case 'n':
		enqueue(N, stringPalavra);
		break;

		case 'o':
		enqueue(O, stringPalavra);
		break;

		case 'p':
		enqueue(P, stringPalavra);
		break;

		case 'q':
		enqueue(Q, stringPalavra);
		break;

		case 'r':
		enqueue(R, stringPalavra);
		break;

		case 's':
		enqueue(S, stringPalavra);
		break;

		case 't':
		enqueue(T, stringPalavra);
		break;

		case 'u':
		enqueue(U, stringPalavra);
		break;

		case 'v':
		enqueue(V, stringPalavra);
		break;

		case 'w':
		enqueue(W, stringPalavra);
		break;

		case 'x':
		enqueue(X, stringPalavra);
		break;

		case 'y':
		enqueue(Y, stringPalavra);
		break;

		case 'z':
		enqueue(Z, stringPalavra);
		break;

		default :
		break;
	}
}

void scanTexto(char* fileID)
{ 
	char   token, primeiraLetra;
	char   string[25];
	FILE*  fpIn;
	int    numLetras = 0;
	

	fpIn = fopen (fileID, "r");
	if (!fpIn) printf("Erro ao abrir %s\n", fileID), exit(100);
 
	while ((token = fgetc (fpIn)) != EOF )
	{
	    if (token == ' ' || token == '.' || token == ',')
		{
			if(numLetras != 0) 
			{
				enfileiraPalavra(string, numLetras, tolower(string[0]));
				numLetras = 0;
			}	
		}
	    else
	    {
	        string[numLetras] = token;
            numLetras++;
	    }
	}
}

void mostraString()
{
	imprimeFila(A,'a');
	imprimeFila(B,'b');	
    imprimeFila(C,'c');
	imprimeFila(D,'d');	
	imprimeFila(E,'e');
	imprimeFila(F,'f');
	imprimeFila(G,'g');
	imprimeFila(H,'h');
	imprimeFila(I,'i');
	imprimeFila(J,'j');
	imprimeFila(K,'k');
	imprimeFila(L,'l');
	imprimeFila(M,'m');
	imprimeFila(N,'n');
	imprimeFila(O,'o');
	imprimeFila(P,'p');
	imprimeFila(Q,'q');
	imprimeFila(R,'r');
	imprimeFila(S,'s');
	imprimeFila(T,'t');
	imprimeFila(U,'u');
	imprimeFila(V,'v');
	imprimeFila(W,'w');
	imprimeFila(X,'x');
	imprimeFila(Y,'y');
	imprimeFila(Z,'z');
}

int main ()
{
	char   fileID[] = "textoteste.txt";

	A = createQueue();
	B = createQueue();
	C = createQueue();
	D = createQueue();
	E = createQueue();
	F = createQueue();
	G = createQueue();
	H = createQueue();
	I = createQueue();
	J = createQueue();
	K = createQueue();
	L = createQueue();
	M = createQueue();
	N = createQueue();
	O = createQueue();
	P = createQueue();
	Q = createQueue();
	R = createQueue();
	S = createQueue();
	T = createQueue();
	U = createQueue();
	V = createQueue();
	W = createQueue();
	X = createQueue();
	Y = createQueue();
	Z = createQueue();

	printf ("De o nome do arquivo para ser classificado: \n");
	//scanf  ("%s", fileID);

	scanTexto(fileID);
	//para que a ultima palavra seja detectada precisa de uma barra de espaço ou ponto ao final do arquivo.

	mostraString();
	
	return 0;
}