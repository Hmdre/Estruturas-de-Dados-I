//4-Os dados relativos aos clientes de uma empresa estao armazenados em um arquivo. Para cada cliente sao registrados um codigo,
//nome, o endereco, o telefone, a data em que fez sua primeira compra na empresa, a data da ultima compra e o valor da ultima compra.
//Especifique o TAD Clientes para armazenar os dados dos clientes e as operaoes necessarias para inserir, consultar e excluir esses dados.
//Implemente uma aplicao que utilize o tipo Clientes.


#include "Clientes.h"

int main()
{
	char c;
	int x=0,valor=0,i;
	FILE *pArquivo;
	Cliente cliente1;	
	
	pArquivo = fopen("cliente.txt" , "r+");
	if (pArquivo == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    fscanf(pArquivo,"%s %s %s %s %s %s %s",&cliente1.nome,&cliente1.codigo,&cliente1.telefone,&cliente1.endereco,&cliente1.ultimaCompra,&cliente1.primeiraCompra,&cliente1.valorUltimaCompra);
    fclose(pArquivo);
    
	while(x!=4){


		printf("---------------------\n Selecione uma opcao:\n\n1)Consultar dado\n\n2)Inserir dado\n\n3)Excluir dado\n\n4)Fechar programa\n\n");
		printf("\n");
		scanf("%d",&valor);
		switch ( valor )
	  	{
	  		case 1 ://Consultar
	  		consultaArquivo(cliente1);
	  		break;

	  		case 2 ://Inserir
	  		insereArquivo(&cliente1);
	  		printf ("\n");
	  		break;

	  		case 3 ://Excluir
	  		excluiArquivo(&cliente1);
			break;

			case 4://Fechar programa
			pArquivo = fopen("cliente1.txt" , "w");
			fwrite(&cliente1, sizeof(Cliente), 1, pArquivo);
			fclose(pArquivo);
			x=4;

			break;

	  	  default :
	  	  printf ("Valor invalido!\n");
	  	}
	}
	return 0;
}	
  




