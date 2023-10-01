/*
2. Um palíndromo é uma string que pode ser lida para frente e para trás com o mesmo resultado. Por exemplo, as seguintes frases são palíndromos:
            A base do teto desaba.
        A diva em Argel alegra-me a vida.
            Adias a data da saída.
        Socorram-me, subi no ônibus em Marrocos.
Observe que nos palíndromos se deve ignorar o espaçamento, a pontuação, e as diferenças entre letras maiúsculas e minúsculas.
Escreva uma função para testar se uma string é um palíndromo usando uma pilha. A ideia é armazenar os caracteres da string na 
pilha e recuperar eles formando uma nova string. Depois comparar a nova string com a string original. Teste a sua função com os exemplos mostrados acima.
*/

#include "PilhaTAD.h"
#include <string.h>
#include <ctype.h>

void verificaPalindromo(char* string)
{
    printf("\nstring: %s",string);
    STACK* pilha = createStack ();
    int i, j = 0, tamString = 0, teste = 0;

    for(i = 0; i < 40; i++)
    {
        if(isalpha(string[i])) tamString++;
    }

    printf("\n%d",tamString);

    for(i = 0; i < 40; i++)
    {
        if(isprint(string[i])) teste++;
    }

    printf("\n%d",teste);

    char* newStrA = (char*) malloc (tamString * sizeof(char));
    char* newStrB = (char*) malloc (tamString * sizeof(char));

    //for(i = 0; string[i]; i++) if(string[i]!='\0') strOriginal[i] = string[i];
    printf("\nstring: %s",string);
    //strcat(strOriginal, string);//concatena o conteudo de string em strOriginal

    for(i = 0; i < teste; i++)
    {
        //printf("teste");
        printf("\ntentando inserir: %c",string[i]);
        if(isalpha(string[i]))//verifica que o char é uma letra ou numero
        {
            if(isupper(string[i])) newStrA[j] = tolower(string[i]);//converte letras maiusculas em minusculas
            else newStrA[j] = string[i];//armazena somente as letras minusculas em uma string auxiliar
            pushStack(pilha, (void*)(newStrA[j]));//empilha somente as letras minusculas
            j++;
            //printf("teste");
            printf("\nnewStrA: %s",newStrA);
        }
    }   
    printf("\nnewStrA: %s",newStrA);

    for(i = 0; i < tamString; i++) newStrB[i] = (char)popStack(pilha);//desempilha as letraas minusculas resultando na frase ao contrario

    printf("\nnewStrB: %s",newStrB);

    destroyStack(pilha);

    if(strcmp(newStrA, newStrB))
    {
        printf("\nA frase: \"%s\" nao e um palindromo",string);//verifica se a frase inversa é igual a original
    } 
    else 
    {
        printf("\nA frase \"%s\" e um palindromo",string);
    }
}

int main ()
{
    char string[40] = "A base do teto desaba"; //abased otet od esab A

    printf("\n%s",string);
    verificaPalindromo(string);

    return 0;
} 