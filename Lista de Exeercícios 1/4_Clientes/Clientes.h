#include <stdlib.h>
#include <stdio.h>

typedef struct cliente
{
	char nome[10];
	char codigo[10];
	char telefone[10];
	char endereco[10];
	char ultimaCompra[10];
	char primeiraCompra[10];
	char valorUltimaCompra[10];
	
}Cliente;

void consultaArquivo(Cliente c)
{
	int valor=0;
	  
	printf("--------------------------------------------------------\n");
	printf("O que deseja consultar:\n\n1)Consultar nome\n\n2)Consultar codigo\n\n3)Consultar telefone\n\n4)Consultar endereco\n\n5)Consultar data da ultima compra\n\n");
	printf("6)Consultar data da primeira compra\n\n7)Consultar valor da ultima compra\n\n");
	scanf("%d",&valor);
	printf("\n\n");
	  
	switch ( valor )
  	{
    	case 1 ://Nome
    	printf ("%s\n",c.nome);
    	break;
    
    	case 2 :
    	printf ("%s\n",c.codigo);
    	break;
    
    	case 3 :
    	printf ("%s\n",c.telefone);
    	break;
    
    	case 4 :
    	printf ("%s\n",c.endereco);
    	break;
    
    	case 5 :
    	printf ("%s\n",c.ultimaCompra);
    	break;
    
    	case 6 :
    	printf ("%s\n",c.primeiraCompra);
    	break;
    
   		case 7 :
   		printf ("%s\n",c.valorUltimaCompra);
   		break;
    
    	default :
    	printf ("\nValor invalido ou inexistente!\n"); 
  }	
}

void insereArquivo(Cliente *c)
{
	int valor=0;
	char textoAux[10];
	
	printf("--------------------------------------------------------\n");
	printf("O que deseja inserir:\n\n1)Inserir  nome\n\n2)Inserir codigo\n\n3)Inserir telefone\n\n4)Inserir endereco\n\n5)Inserir data da ultima compra\n\n");
	printf("6)Inserir data da primeira compra\n\n7)Inserir valor da ultima compra\n\n");
	scanf("%d",&valor);
	printf("\n\n");
    
	
	switch ( valor )
  	{
    	case 1 ://Nome
    	scanf("%s",c->nome);
       	printf ("Informacao alterada\n");
    	
    	break;
    
    	case 2 ://Codigo
    	scanf("%s",c->codigo);
    	printf ("Informacao alterada\n");
    	break;
    
    	case 3 ://Telefone
    	scanf("%s",c->telefone);
    	printf ("Informacao alterada\n");
    	break;
    
    	case 4 ://Endereco
    	scanf("%s",c->endereco);
    	printf ("Informacao alterada\n");
    	break;
    
    	case 5 ://Data da ultima compra
    	scanf("%s",c->ultimaCompra);
    	printf ("Informacao alterada\n");
    	break;
    
    	case 6 ://Data da primeira compra
    	scanf("%s",c->primeiraCompra);
    	printf ("Informacao alterada\n");
    	break;
    
   		case 7 ://Valor da ultima compra
    	scanf("%s",c->valorUltimaCompra);
   		printf ("Informacao alterada\n");
   		break;
    
    	default :
    	printf ("\nValor invalido ou inexistente!\n"); 
  }
	return;
}

void excluiArquivo(Cliente *c)
{
	int i,valor=0;
	
	printf("--------------------------------------------------------\n");
	printf("O que deseja excluir:\n\n1)Excluir nome\n\n2)Excluir codigo\n\n3)Excluir telefone\n\n4)Excluir endereco\n\n5)Excluir data da ultima compra\n\n");
	printf("6)Excluir data da primeira compra\n\n7)Excluir valor da ultima compra\n\n");
	scanf("%d",&valor);
	printf("\n\n");
	
	switch ( valor )
  	{
    	case 1 ://Nome
   		for(i=0;i<=9;i++)
		   {
   			c->nome[i] =' ';   		   
		   }
   		printf("Print de Teste:\n%s",c->nome);
       	printf ("Informacao excluida\n");
    	
    	break;
    
    	case 2 ://Codigo
   		for(i=0;i<=9;i++)
		   {
   			c->codigo[i] =' ';   		   
		   }
   		printf("Print de Teste:\n%s",c->codigo);
    	printf ("Informacao excluida\n");
    	break;
    
    	case 3 ://Telefone
   		for(i=0;i<=9;i++)
		   {
   			c->telefone[i] =' ';   		   
		   }
   		printf("Print de Teste:\n%s",c->telefone);
    	printf ("Informacao excluida\n");
    	break;
    
    	case 4 ://Endereco
   		for(i=0;i<=9;i++)
		   {
   			c->endereco[i] =' ';   		   
		   }
   		printf("Print de Teste:\n%s",c->endereco);
    	printf ("Informacao excluida\n");
    	break;
    
    	case 5 ://Data da ultima compra
   		for(i=0;i<=9;i++)
		   {
   			c->ultimaCompra[i] =' ';   		   
		   }
   		printf("Print de Teste:\n%s",c->ultimaCompra);
    	printf ("Informacao excluida\n");
    	break;
    
    	case 6 ://Data da primeira compra
	   		for(i=0;i<=9;i++)
		   {
   			c->primeiraCompra[i] =' ';   		   
		   }
   		printf("Print de Teste:\n%s",c->primeiraCompra);
    	printf ("Informacao excluida\n");
    	break;
    
   		case 7 ://Valor da ultima compra
   			for(i=0;i<=9;i++)
		   {
   			c->valorUltimaCompra[i] =' ';   		   
		   }
   			printf("Print de Teste:\n%s",c->valorUltimaCompra);
			printf ("Informacao excluida\n");
   			break;
   			
    
    	default :
    	printf ("\nValor invalido ou inexistente!\n"); 
  }
	return;	
}