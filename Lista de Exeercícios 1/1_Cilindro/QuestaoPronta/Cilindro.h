#include <stdio.h>
#include <math.h>

typedef struct dataPonto
{
    float x, y, z;
} Ponto; 

typedef struct dataCilindro
{
    Ponto pontoUm, pontoDois;
    float raioUm;
} Cilindro;

void mostraPontos ( Cilindro *cil ) //mostra os pontos das extremidades do cilindro dado pelo usuario.
{
    printf("ponto um: ( %.2f , %.2f , %.2f ) \nponto dois: ( %.2f , %.2f , %.2f )", cil->pontoUm.x, cil->pontoUm.y, cil->pontoUm.z, cil->pontoDois.x, cil->pontoDois.y, cil->pontoDois.z);
    return;
}

float calculaAreaBase ( Cilindro *cil ) //calcula e retorna a area da base do cilindro.
{
    float areaBase;

    areaBase = 3.14  * ( (cil->raioUm) * (cil->raioUm) ) ;
    return (areaBase);
}

float calculaAltura ( Cilindro *cil) //calcula e retorna a altura do cilindro pela distancia entre os dois pontos extremos dele.
{
    float alturaCilindro;

    alturaCilindro = sqrt((cil->pontoDois.x - cil->pontoUm.x) + (cil->pontoDois.y - cil->pontoUm.y) + (cil->pontoDois.z - cil->pontoUm.z));
    return ( alturaCilindro );
}

float calculaAreaLateral ( Cilindro *cil) //calcula e retorna a area lateral do cilindro utilizando a funçao de calcular altura e retorna esse valor.
{
    float areaLateral;

    areaLateral = 2 * ( 3.14 * cil->raioUm * ( calculaAltura(cil)));
    return ( areaLateral );
}

void mostrarArea ( Cilindro *cil ) //calcula e mostra a area total do cilindro utilizando as funçoes de calculo da area lateral e da area da base.
{
    float areaTotal;
    
    areaTotal = 2 * ( calculaAreaBase(cil) ) + ( calculaAreaLateral(cil) );
    printf("\nA area total do cilindro dado: %.2f", areaTotal);
    return;   
}

void mostrarVolume ( Cilindro *cil ) //calcula e mostra o volume do cilindro utilizando as funóes de calculo da area da base e da altura.
{
    float volume;

    volume = ( calculaAreaBase(cil) ) * ( calculaAltura(cil) );
    printf("\nO Volume do cilindro: %.2f", volume);
    return;
}

void mostraAlturaRaio ( Cilindro *cil ) //calcula e mostra a altura do cilindro utilizando a funçao de calcular altura e tambem mostra o raio dele.
{   
    
    printf("\nA altura do cilindro: %.2f \nO raio do cilindro: %.2f", calculaAltura(cil), cil->raioUm);
    return;
}