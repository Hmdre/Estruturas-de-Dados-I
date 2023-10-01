#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dataPonto Ponto; 

typedef struct dataCilindro Cilindro;

Cilindro* criaCilindro (float x1, float y1, float z1, float x2, float y2, float z2, float raio); //aloca um cilindro.
void mostraPontos ( Cilindro *cil ); //mostra os pontos das extremidades do cilindro dado pelo usuario.
float calculaAreaBase ( Cilindro *cil ); //calcula e retorna a area da base do cilindro.
float calculaAltura ( Cilindro *cil); //calcula e retorna a altura do cilindro pela distancia entre os dois pontos extremos dele.
float calculaAreaLateral ( Cilindro *cil); //calcula e retorna a area lateral do cilindro utilizando a funçao de calcular altura e retorna esse valor.
void mostrarArea ( Cilindro *cil ); //calcula e mostra a area total do cilindro utilizando as funçoes de calculo da area lateral e da area da base.
void mostrarVolume ( Cilindro *cil ); //calcula e mostra o volume do cilindro utilizando as funóes de calculo da area da base e da altura.
void mostraAlturaRaio ( Cilindro *cil ); //calcula e mostra a altura do cilindro utilizando a funçao de calcular altura e tambem mostra o raio dele.