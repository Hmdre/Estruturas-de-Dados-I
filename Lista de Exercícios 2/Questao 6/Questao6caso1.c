/*
6.- Usando somente algoritmos no TAD fila, escreva uma função em C chamada catQueue() que concatene duas
filas.
A segunda fila deve ser colocada no final da primeira fila. Considere o caso em que: i) a segunda fila
precisa ser preservada;.
*/
#include "FilaTAD.h"

void catQueue(QUEUE* fila1, QUEUE* fila2)
{
    void** aux = malloc(sizeof(int**));
    int i;

    for(i = 0 ; i< fila2->count ; i++)
    {
        dequeue(fila2,aux);
        enqueue(fila1,*aux);
        enqueue(fila2,*aux);
    }
}

int main()
{    
    QUEUE* fila1=createQueue();
    QUEUE* fila2=createQueue();

    enqueue(fila1,(void*)1);
    enqueue(fila1,(void*)2);
    enqueue(fila1,(void*)3);

    enqueue(fila2,(void*)4);
    enqueue(fila2,(void*)5);
    enqueue(fila2,(void*)6);

    printf("Primeiro elemento da fila1: %d\n",fila1->front->dataPtr);
    printf("Ultimo elemento da fila1: %d\n\n",fila1->rear->dataPtr);

    printf("Primeiro elemento da fila2: %d\n",fila2->front->dataPtr);
    printf("Ultimo elemento da fila2: %d\n\n",fila2->rear->dataPtr);

    catQueue(fila1,fila2);

    printf("Primeiro elemento da fila1 apos catQueue: %d\n",fila1->front->dataPtr);
    printf("Ultimo elemento da fila1 apos catQueue: %d\n\n",fila1->rear->dataPtr);

    printf("Primeiro elemento da fila2 apos catQueue: %d\n",fila2->front->dataPtr);
    printf("Ultimo elemento da fila2 apos catQueue: %d\n\n",fila2->rear->dataPtr);

    return 0;
}