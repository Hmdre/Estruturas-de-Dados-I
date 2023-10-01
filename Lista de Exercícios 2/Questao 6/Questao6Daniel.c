/*
6.- Usando somente algoritmos no TAD fila, escreva uma função em C chamada catQueue() que concatene duas
filas.
A segunda fila deve ser colocada no final da primeira fila. Considere os casos em que: i) a segunda fila
precisa ser preservada; ii) a segunda fila não deve ser preservada; iii) posso adicionar operações extras
ao TAD para ganhar eficiência na concatenação em ii).
*/
#include "FilaTAD.h"
#include<stdio.h>

//Nao mantendo a fila2
/*
void catQueue(QUEUE* fila1,QUEUE* fila2)
{
    void** aux = malloc(sizeof(int**));

    while (fila2->count>0)
    {
        dequeue(fila2,aux);
        enqueue(fila1,aux);
    }
    destroyQueue(fila2);
}
*/

//mantendo a fila2
/*
void catQueue2(QUEUE* fila1, QUEUE* fila2)
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
*/

//linkando o fim da fila 1 no inicio da 2
void catQueue3 (QUEUE* fila1, QUEUE* fila2)
{
    fila1->count += fila2->count;
    fila1->rear->next = fila2->front;
    fila1->rear = fila2->rear;
    
    while(!emptyQueue(fila2)){
        void** aux =malloc(sizeof(void*));
        dequeue(fila2,aux);
        free(aux);
    }
  free(fila2);
    
}

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

/*printf("Inicio fila1: %d\n",fila1->front->dataPtr);
printf("Traseira fila1: %d\n",fila1->rear->dataPtr);
catQueue(fila1,fila2);// I)
printf("Inicio fila1: %d\n",fila1->front->dataPtr);
printf("Traseira fila1: %d\n\n",fila1->rear->dataPtr);//Não ecxiste mais*/

//printf("Inicio fila1: %d\n",fila2->front->dataPtr);
//printf("Traseira fila1: %d\n",fila2->rear->dataPtr);
catQueue3(fila1,fila2);// II)

printf("Inicio fila1: %d\n",fila1->front->dataPtr);
printf("Traseira fila1: %d\n\n",fila1->rear->dataPtr);
printf("Inicio fila2: %d\n",fila2->front->dataPtr);
printf("Traseira fila2: %d\n\n",fila2->rear->dataPtr);
printf("Contador F1: %d\n",fila1->count);
printf("Contador F2: %d",fila2->count);


    return 0;
}