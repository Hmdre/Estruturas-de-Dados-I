/*3.Especifique um TAD que seja capaz de armazenar uma data composta por dia, mês e ano e implemente o seguinte conjunto de operações para manipular esse tipo Data:
	a)Uma função que recebe como parâmetro o dia, o mês, e o ano; verifica se a data for válida e converte ela em uma string no formato DD/MM/AAAA.
	b)Uma função que recebe como parâmetro uma data de tipo string (formato DD/MM/AAAA) e uma estrutura do tipo Data. Armazena os dados da string na estrutura.
	c)Uma função que recebe como parâmetro uma estrutura do tipo Data e um número de dias, e retorna a estrutura modificada com soma da data original mais o número de dias recebido.
Teste o TAD com uma aplicação.
*/
#include "DataOld.h"

int main()
{
	Data dia, estruturaData;
	char dat[10];
	int dias, x=0;
	
	while (x == 0)
	{	
		verificaData(&dia,dat,&x);
	}
	
	stringToStruct(dat,&estruturaData);
	
	printf("\ndigite um numero de dias:\n");
	scanf("%d",&dias);
	
	somaDias(&dia,dias);	

	return 0;
}
