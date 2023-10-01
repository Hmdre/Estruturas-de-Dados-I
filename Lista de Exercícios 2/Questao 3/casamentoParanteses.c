/*
3.Modifique o programa de casamento de parênteses para considerar o casamento de { }, [ ] e ( ). O programa deverá verificar a 
  correspondência entre o símbolo de abertura e seu correspondente de fechamento.  Identifique e reporte os tipos de erro 
  possíveis caso existam, indicando a linha, ou uma mensagem indicando que o casamento é perfeito. Teste o seu programa com 
  arquivos de texto, com erros e sem erros.   
*/

#include "PilhaTAD.h"

void verifica (char* fileID, int caso)
{ 
	char abre, fecha;
	
	switch (caso)
	{
	    case 1:
			abre = '(';
			fecha = ')';
	    break;

	    case 2:
			abre = '[';
			fecha = ']';
	    break;

	    case 3:
			abre = '{';
			fecha = '}';
		break;

		default:
		break;
	}
//	Local Definitions 
	STACK* stack;
	char   token;
	char*  dataPtr;
	FILE*  fpIn;
	int    lineCount = 1;

//	Statements 
	// Create Stack 
	stack = createStack ();
	
	fpIn = fopen (fileID, "r");
	if (!fpIn)
	    printf("Error opening %s\n", fileID), exit(100);

	// read characters from the source code and parse 
	while ((token = fgetc (fpIn)) != EOF )
	{
	    if (token == '\n') lineCount++;

	    if (token == abre)
	    {
	        dataPtr = (char*) malloc (sizeof (char));
	        *dataPtr = token;     
			pushStack (stack, dataPtr);
	    } // if 
	    else
	    {
	        if (token == fecha)
	        {
	            if (emptyStack (stack))
	            {
	                if(caso==1) printf("Parenteses de abertura faltando na linha %d.\n", lineCount);
					if(caso==2) printf("Colchete de abertura faltando na linha %d.\n", lineCount);
					if(caso==3) printf("Chave de abertura faltando na linha %d.\n", lineCount);
	                return 1;
	            } // if true 
	            else popStack (stack);
	        } // token == 
	    } // else 
	} // while 

	if (!emptyStack (stack))
	{
	    if(caso==1) printf("Parenteses de fechamento faltando na linha %d.\n", lineCount);
		if(caso==2) printf("Colchete de fechamento faltando na linha %d.\n", lineCount);
		if(caso==3) printf("Chave de fechamento faltando na linha %d.\n", lineCount);
	    return 1;
	} // if 

	// Now destroy the stack 
	destroyStack (stack);
	if(caso==1) printf("Analise dos parenteses completa: %d Linhas analisadas.\n", lineCount);
	if(caso==2) printf("Analise dos colchetes completa: %d Linhas analisadas.\n", lineCount);
	if(caso==3) printf("Analise das chaves completa: %d Linhas analisadas.\n", lineCount);
	return 0;
}	// main 

int main ()
{
	char   fileID[] = "parenteses.txt";
	
	//caso queira entrar com uma quivo especifico descomentar essa sessão
	/*
	char   fileID[25];

	printf ("De o nome do arquivo que será verificado: \n");
	scanf  ("%s", fileID);
	*/

	verifica(fileID, 1);
	verifica(fileID, 2);
	verifica(fileID, 3);
	
	return 0;
}