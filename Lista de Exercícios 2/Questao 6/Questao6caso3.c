/*
6.- Usando somente algoritmos no TAD fila, escreva uma função em C chamada catQueue() que concatene duas
filas.
A segunda fila deve ser colocada no final da primeira fila. Considere o caso em que: iii) posso adicionar operações extras
ao TAD para ganhar eficiência na concatenação em ii).
*/
#include "NewFilaTAD.h"

int main()
{
    printf("Inicio do programa\n");
    
    QUEUE* fila1=createQueue();
    QUEUE* fila2=createQueue();

    printf("Comecando programa\n\n\n");
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