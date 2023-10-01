/*Desenvolva e implemente um TAD que represente um cilindro. Inclua as funções de inicializações necessárias e as operações que retornem a sua altura
 e o raio, a sua área e o seu volume. Para cada função, explique brevemente a ideia adotada.  Teste o TAD com exemplos. Teste o TAD com uma aplicação.*/

#include "Cilindro.h"


int main()
{
    Cilindro cil;

    cil.pontoUm.x = 1;
    cil.pontoUm.y = 2;
    cil.pontoUm.z = 3;

    cil.pontoDois.x = 4;
    cil.pontoDois.y = 5;
    cil.pontoDois.z = 6;
    
    cil.raioUm = 2;

    mostraPontos(&cil);
    mostraAlturaRaio(&cil);
    mostrarArea(&cil);
    mostrarVolume(&cil);

    return 0;
}