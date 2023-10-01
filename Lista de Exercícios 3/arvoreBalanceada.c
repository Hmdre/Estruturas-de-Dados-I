#include "ArvoreTAD.h"

int getHeight (NODE* root) {
    if (!root) return -1;
    return ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right)) +1;
}

int comparaNumero(int num1, int num2){
    if (num1 > num2) return  0;
    if (num1 = num2) return  1;
    if (num1 < num2) return -1; 
}

void printaNode (NODE* node){
    printf("%d", node->dataPtr);
}

void printaArvore (BST_TREE* arvore){
    BST_Traverse(arvore, printaNode);
}

// Driver program
int main()
{
    int resultado = 0;
    BST_TREE* arvore = BST_Create(comparaNumero);

    BST_Insert (arvore, 10);
    BST_Insert (arvore, 1);
    BST_Insert (arvore, 16);
    BST_Insert (arvore, 12);
    BST_Insert (arvore, 8);
    BST_Insert (arvore, 11);
    BST_Insert (arvore, 7);
    BST_Insert (arvore, 14);

    resultado = getHeight(arvore->root);

    printf("resultado: %d", resultado);

    return 0;
}