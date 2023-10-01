/*Implemente os algoritmos de Soma de Matrizes nxn (quadradas) e Multiplicação de matrizes nxn (quadradas). Os dados das matrizes de entrada
 podem ser preenchidos de forma aleatória ou usando alguma regra de geradora.
 */

#include <stdio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include <time.h>//necessário p/ função time()


void criaMatriz (int **matriz, int tamMatriz)
{
    for( int i=0 ; i < tamMatriz ;  i++)
    {
        matriz [i] = malloc (tamMatriz * sizeof(int));
    }

    for( int i=0 ; i < tamMatriz ; i++)
    {
        for( int j=0 ; j < tamMatriz ; j++)
        {
            matriz[i][j] = rand() % 2;
        }
    }    
    
    return;
}

void mostraMatriz(int **matriz, int tamMatriz)
{
    for( int i=0 ; i < tamMatriz ; i++)
    {
        for( int j=0 ; j < tamMatriz ; j++)
        {
            printf("[%u] ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    return;
}

void somaMatrizes (int **matriz1, int **matriz2, int tamMatriz, int *operacoes)
{
    int cont=0;
    clock_t t0, tf;
    double tempo_gasto;
    
    printf("Soma das Matrizes 1 e 2:\n");

    t0 = clock();

    for( int i=0 ; i < tamMatriz ; i++)
    {
        for( int j=0 ; j < tamMatriz ; j++)
        {
            //printf("[%u] ", matriz1[i][j] + matriz2[i][j]);
            cont++;
        }
        //printf("\n");
    }

    tf = clock();
    tempo_gasto = ((double)(tf - t0) / (((double)CLOCKS_PER_SEC)/1000));
    printf("Tempo gasto para realiza as somas: %.2lf ms", tempo_gasto);

    *operacoes += cont;
    return;
}

void multMatrizes(int **matriz1, int **matriz2, int tamMatriz, int *operacoes)
{
    int aux=0, x, cont=0;
    clock_t t0, tf;
    double tempo_gasto;

    printf("Multiplicacao das Matrizes 1 e 2:\n");

    t0 = clock();


    for( int i=0 ; i < tamMatriz ; i++)
    {
        for( int j=0 ; j < tamMatriz ; j++)
        {
			for(x = 0; x < tamMatriz; x++) 
            {
				aux +=  matriz1[i][x] * matriz2[x][j];
                cont++;
			}

                //printf("[%u] ", aux);
    			aux = 0;
                
        }
        //printf("\n");
    }

    tf = clock();
    tempo_gasto = ((double)(tf - t0) / (((double)CLOCKS_PER_SEC)/1000));
    printf("Tempo gasto para realizar as multiplicacoes: %.2lf ms", tempo_gasto);

    *operacoes += cont;
    return;
}

int main ()
{
    int **matriz1, **matriz2, **matriz3;
    unsigned int quantOpsM=0, quantOpsS=0;

    srand(time(NULL));
    
    printf("\n------------ Teste para n=1.100 ------------\n");//------------------------------------------------

    matriz1 = (int**) malloc ( 1100 * sizeof (int*));
    criaMatriz(matriz1, 1100);

    matriz2 = (int**) malloc ( 1100 * sizeof (int*));
    criaMatriz(matriz2, 1100);

    somaMatrizes(matriz1, matriz2, 1100, &quantOpsS);
    printf("\nQuantidade de somas realizadas: %u\n\n", quantOpsS);

    multMatrizes(matriz1, matriz2, 1100, &quantOpsM);
    printf("\nQuantidade de multiplicacoes realizadas: %u\n\n", quantOpsM);

    printf("Quantidade total de operacoes: %u\n", quantOpsM + quantOpsS);

    printf("\n------------ Teste para n=1.300 ------------\n");//------------------------------------------------

    quantOpsM=0;
    quantOpsS=0;

    matriz1 = (int**) malloc ( 1300 * sizeof (int*));
    criaMatriz(matriz1, 1300);

    matriz2 = (int**) malloc ( 1300 * sizeof (int*));
    criaMatriz(matriz2, 1300);

    somaMatrizes(matriz1, matriz2, 1300, &quantOpsS);
    printf("\nQuantidade de somas realizadas: %u\n\n", quantOpsS);

    multMatrizes(matriz1, matriz2, 1300, &quantOpsM);
    printf("\nQuantidade de multiplicacoes realizadas: %u\n\n", quantOpsM);

    printf("Quantidade total de operacoes: %u\n", quantOpsM + quantOpsS);

    printf("\n------------ Teste para n=1.500 ------------\n");//------------------------------------------------

    quantOpsM=0;
    quantOpsS=0;

    matriz1 = (int**) malloc ( 1500 * sizeof (int*));
    criaMatriz(matriz1, 1500);

    matriz2 = (int**) malloc ( 1500 * sizeof (int*));
    criaMatriz(matriz2, 1500);

    somaMatrizes(matriz1, matriz2, 1500, &quantOpsS);
    printf("\nQuantidade de somas realizadas: %u\n\n", quantOpsS);

    multMatrizes(matriz1, matriz2, 1500, &quantOpsM);
    printf("\nQuantidade de multiplicacoes realizadas: %u\n\n", quantOpsM);

    printf("Quantidade total de operacoes: %u\n", quantOpsM + quantOpsS);

    return 0;
}
