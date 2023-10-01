#include <string.h>
#include <ctype.h>
#include "ArvoreTAD.h"

typedef struct
{
    char *nome;
    char *numero;
} Contato;



Contato *alocaContato(char *nome, char* numero)
{
    Contato *cont = (Contato *)malloc(sizeof(Contato));
    cont->nome = nome;
    cont->nome = numero;
    return cont;
}

Contato* converteCharContato(char* vet){
    Contato *cont = (Contato *)malloc(sizeof(Contato));
    char* nome = malloc(sizeof(char));
    char* numero = malloc(sizeof(char));
    int j =0;
    int k =0;
    for(int i=0;i<strlen(vet);i++){
        if(isalpha(vet[i])){
            nome[j] = vet[i];
            j++;
        }else if(isdigit(vet[i])){
            numero[k] =vet[i];
            k++;
        }
    }
    cont->nome =nome;
    cont->numero = numero;
    return cont;
}

//função de comparaçao da arvore
int comparaNome(Contato *cont1, Contato *cont2)
{
    return strcmp(cont1->nome, cont2->nome); // retorna -1 se o nome vem antes 1 se vem depois e 0 se for igual
}

void mostraContato(Contato* cont){
    printf("Nome: %s Numero: %s\n",cont->nome,cont->numero);
} 

BST_TREE *criarArvore(FILE *arquivo)
{
    BST_TREE *arvore = BST_Create(comparaNome);
    int i = 0;
    int numNomes = 0;
    char *nomes[50];
    char linha[50];

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        nomes[i] = strdup(linha);
        i++;
        numNomes++;
    }

    for(int i =0;i<numNomes;i++){
        printf("%s",nomes[i]);
        BST_Insert(arvore,converteCharContato(nomes[i]));
    }


    return arvore;
}

void mostrarArvore(BST_TREE *arvore ){
    printf("Arvore de contatos:\n");
    BST_Traverse(arvore,mostraContato);
}
int main()
{
    FILE *arquivo = fopen("Arquivo.txt", "r"); // abrindo arquivo para leitura e escrita
    BST_TREE *arvore = criarArvore(arquivo);   // criando arvore com base no arquivo usando a ordem alfabetica como função de comparação
    printf("%d",BST_Count(arvore));
    mostrarArvore(arvore);
    BST_Destroy(arvore);
    fclose(arquivo);
    return 0;
}