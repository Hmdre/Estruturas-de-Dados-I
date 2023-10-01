/*3.Especifique um TAD que seja capaz de armazenar uma data composta por dia, mês e ano e implemente o seguinte conjunto de operações para manipular esse tipo Data:
	a)Uma função que recebe como parâmetro o dia, o mês, e o ano; verifica se a data for válida e converte ela em uma string no formato DD/MM/AAAA.
	b)Uma função que recebe como parâmetro uma data de tipo string (formato DD/MM/AAAA) e uma estrutura do tipo Data. Armazena os dados da string na estrutura.
	c)Uma função que recebe como parâmetro uma estrutura do tipo Data e um número de dias, e retorna a estrutura modificada com soma da data original mais o número de dias recebido.
Teste o TAD com uma aplicação.
*/
#include "Data.h"

int main()
{
	Data dia, estruturaData;
	char dat[10];
	
	dia.dia = 29;
	dia.mes = 2;
	dia.ano = 1994;

	verificaData(&dia,dat);

	dia.dia = 29;
	dia.mes = 7;
	dia.ano = 1994;

	verificaData(&dia,dat);
	
	transformaStruct(dat,&estruturaData);
	
	somaDias(&dia,5);	

	return 0;
}
