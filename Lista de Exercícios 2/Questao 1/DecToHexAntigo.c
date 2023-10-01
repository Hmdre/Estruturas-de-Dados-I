/*
Escreva um programa que converta um número decimal em hexadecimal, usando o método de divisões sucessivas e uma pilha. Obs. 
Lembrar que caso o resto da divisão for 10, 11, 12, 13, 14 ou 15, o digito correspondente deverá ser A, B, C, D, E ou F.
*/
#include "PilhaTAD.h"

void mostraResultado (STACK* pilha)
{
    int aux;

    while(pilha->count > 0)
    {
        aux = (int)popStack(pilha);
        if (aux > 9)
        {
            if (aux == 10) printf(" A");
            if (aux == 11) printf(" B");
            if (aux == 12) printf(" C");
            if (aux == 13) printf(" D");
            if (aux == 14) printf(" E");
            if (aux == 15) printf(" F");
        }
        else
            printf(" %d", aux);
    }
}

void converteDecHex (STACK* pilha, int dec)
{
    int aux=0;

    while (aux==0)
    {
        pushStack(pilha, (void*)(dec%16));

        if((dec/16) < 16)
        {
            pushStack(pilha, (void*)(dec/16));
            aux++;
        }
        else dec = dec/16;
    }

    mostraResultado(pilha);
}

int main ()
{
    int dec = 350;

    printf("%d convertido para hexadecimal:",dec);

    STACK* pilha = createStack ();
    converteDecHex(pilha, dec);

    
    destroyStack(pilha);
    return 0;
}