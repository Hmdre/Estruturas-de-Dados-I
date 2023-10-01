/*Desenvolva e implemente um TAD que represente um cilindro. Inclua as funções de inicializações necessárias e as operações que retornem a sua altura
 e o raio, a sua área e o seu volume. Para cada função, explique brevemente a ideia adotada.  Teste o TAD com exemplos. Teste o TAD com uma aplicação.*/

#include "Cilindro.h"


int main()
{
    float x1, y1, z1, x2, y2, z2, raio;

    printf("Entre com os dois pontos das extremidades do cilindro e o raio.");
    printf("\nPrimeiro ponto (x0, y0, z0):");
    scanf("%f  %f  %f", &x1, &y1, &z1);
    printf("\nSegundo ponto (x1, y1, z1):");
    scanf("%f  %f  %f", &x2, &y2, &z2);
    printf("\nRaio:");
    scanf("%f", &raio);

    Cilindro* cil = criaCilindro(x1, y1, z1, x2, y2, z2, raio);
    mostraPontos(cil);
    mostraAlturaRaio(cil);
    mostrarArea(cil);
    mostrarVolume(cil);

    return 0;
}