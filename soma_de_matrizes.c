/*Implemente os algoritmos de Soma de Matrizes nxn (quadradas) e Multiplicação de matrizes nxn (quadradas). Os dados das matrizes de entrada
 podem ser preenchidos de forma aleatória ou usando alguma regra de geradora.
 */

#include <stdio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include <time.h>//necessário p/ função time()


void criaMatriz (int **matriz, int *tamMatriz)
{
    for( int i=0 ; i < *tamMatriz ;  i++)
    {
        matriz [i] = malloc (*tamMatriz * sizeof(int));
    }

    for( int i=0 ; i < *tamMatriz ; i++)
    {
        for( int j=0 ; j < *tamMatriz ; j++)
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
            printf("[%d] ", matriz[i][j]);
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
            //printf("[%d] ", matriz1[i][j] + matriz2[i][j]);
            cont++;
        }
        //printf("\n");
    }

    tf = clock();
    tempo_gasto = ((double)(tf - t0) / (((double)CLOCKS_PER_SEC)/1000));
    printf("Tempo gasto para realiza as somas: %lf ms\n", tempo_gasto);

    printf("\n\n");
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

                //printf("[%d] ", aux);
    			aux = 0;
                
        }
        //printf("\n");
    }

    tf = clock();
    tempo_gasto = ((double)(tf - t0) / (((double)CLOCKS_PER_SEC)/1000));
    printf("Tempo gasto para realizar as multiplicacoes: %lf ms\n", tempo_gasto);

    printf("\n\n");
    *operacoes += cont;
    return;
}

int main ()
{
    int tamMatriz, **matriz1, **matriz2, **matriz3, quantOps=0;

    printf("Digite o tamanho das matrizes:\n");
    scanf("%d", &tamMatriz);

    srand(time(NULL));

    matriz1 = (int**) malloc ( tamMatriz * sizeof (int*));
    criaMatriz(matriz1, &tamMatriz);

    matriz2 = (int**) malloc ( tamMatriz * sizeof (int*));
    criaMatriz(matriz2, &tamMatriz);
    
    printf("Matriz 1:\n");
    //mostraMatriz(matriz1, tamMatriz);
    
    printf("Matriz 2:\n");
    //mostraMatriz(matriz2, tamMatriz);

    somaMatrizes(matriz1, matriz2, tamMatriz, &quantOps);

    multMatrizes(matriz1, matriz2, tamMatriz, &quantOps);

    printf("Quantidade de operacoes realizadas: %d", quantOps);

    return 0;
}
