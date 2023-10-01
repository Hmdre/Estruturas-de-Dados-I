/*
2. Um palíndromo é uma string que pode ser lida para frente e para trás com o mesmo resultado. Por exemplo, as seguintes frases são palíndromos:
            A base do teto desaba.
        A diva em Argel alegra-me a vida.
            Adias a data da saída.
        Socorram-me, subi no ônibus em Marrocos.
Observe que nos palíndromos se deve ignorar o espaçamento, a pontuação, e as diferenças entre letras maiúsculas e minúsculas.
Escreva uma função para testar se uma string é um palíndromo usando uma pilha. A ideia é armazenar os caracteres da string na 
pilha e recuperar eles formando uma nova string. Depois comparar a nova string com a string original. tamanhoUtilizado a sua função com os exemplos mostrados acima.
*/

#include "PilhaTAD.h"
#include <string.h>
#include <ctype.h>

void verificaPalindromo(char* string)
{
    //printf("\nstring: %s",string);
    STACK* pilha = createStack ();
    int i, j = 0, quantLetras = 0, tamanhoUtilizado = 0;

    for(i = 0; i < 41; i++)
    {
        if(isalpha(string[i])) quantLetras++;
    }

    for(i = 0; i < 41; i++)
    {
        if(isprint(string[i])) tamanhoUtilizado++;
    }

    char* newStrA = (char*) malloc ((quantLetras) * sizeof(char));
    char* newStrB = (char*) malloc ((quantLetras) * sizeof(char));

    for(i = 0; i <= tamanhoUtilizado; i++)
    {
        if(isalpha(string[i])||string[i]=='\0')//verifica que o char é uma letra ou numero
        {
            if(isupper(string[i])) newStrA[j] = tolower(string[i]);//converte letras maiusculas em minusculas
            else newStrA[j] = string[i];//armazena somente as letras minusculas em uma string auxiliar
            if(string[i]!='\0') pushStack(pilha, (void*)(newStrA[j]));//empilha somente as letras minusculas
            j++;
        }
    } 

    for(i = 0; i <= quantLetras; i++)
    {
        newStrB[i] = (char)popStack(pilha);//desempilha as letraas minusculas resultando na frase ao contrario
    }

    destroyStack(pilha);

    if(strcmp(newStrA, newStrB)) printf("\nA frase: \"%s\" nao e um palindromo.",string);//verifica se a frase inversa é igual a original
    else printf("\nA frase \"%s\" e um palindromo.",string);
}

int main ()
{
    char string1[41] = "A base do teto desaba";
    char string2[41] = "A diva em Argel alegra-me a vida";
    char string3[41] = "Adias a data da saida";
    char string4[41] = "Socorram-me, subi no onibus em Marrocos";
    char string5[41] = "A casa era branca";
    char string6[41] = "natan";

    verificaPalindromo(string1);
    verificaPalindromo(string2);
    verificaPalindromo(string3);
    verificaPalindromo(string4);
    verificaPalindromo(string5);
    verificaPalindromo(string6);


    return 0;
} 