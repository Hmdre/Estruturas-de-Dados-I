#include "FilaTAD.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void imprimeFila(QUEUE* fila,char* nome){
	void* aux;
    printf("fila %s \nnumero de elementos: %d\n",nome,queueCount(fila));
	for(int i = 0;i<queueCount(fila);i++){
		dequeue(fila,&aux);
			printf("%s\n",(char*)aux);
		enqueue(fila,aux);
	}	
	printf("\n");
}


char* lerAqr(char* nomeArquivo){
    char* texto = (char*)malloc(sizeof(char));
	char aux;
	FILE* arquivo = fopen(nomeArquivo,"r");
	if(!arquivo) printf("Erro ao abrir o aquivo %s\n",nomeArquivo),  exit(100);
    int i = 0;
	while ((aux = fgetc(arquivo))!=EOF){
		texto[i] = aux;
		i++;
		texto = realloc(texto,sizeof(char)*strlen(texto)+1);
	}
	return texto;
}

QUEUE* enfileraPalavras(char* texto,char inicial){
	QUEUE* filaPalavras = createQueue();
	char *palavra;
	int count =0;
	int indiceAux=0;
	
	for(int i=0;i<strlen(texto);i++){
	    //conta se é um letra ou nao
		if(isalpha(texto[i])){	
			indiceAux++;
		}else{
			
			char* palavra = (char*)calloc(indiceAux+1,sizeof(char)); //foi alocado uma posiçao a mais para o '\0'
	
			for(int j=0;j<indiceAux;j++){
				int temp = j+count;
				palavra[j] = texto[temp];
				
			}
			palavra[indiceAux] ='\0'; //importante! Ultima posiçao da string '/0' para denotar o final

			//enfileira caso a inicial seja igual a letra passada por parâmetro
			//tolower coverte para letras minusculas assim nao vai ter diferença entre A e A
			if(tolower(*palavra) == inicial) enqueue(filaPalavras,palavra);	

			count+=indiceAux+1;
			indiceAux =0;	
		}
		free(palavra);
	}
	return filaPalavras; 
}


void menu(){

	
    char* fila = lerAqr("textoteste.txt");
	printf("O arquivo deve ser escrito da seguinte forma\n");
	printf("Palavra1 palavra2 palavra3 ... palavraN.\n");
	printf("Deve ter um espaco ou pontuacao apos a ultima palavra\n\n");
	//printf("Escreva o nome do arquivo a ser lido:\n");	
	

	QUEUE *a = enfileraPalavras(fila,'a');
	QUEUE *b = enfileraPalavras(fila,'b');	
    QUEUE *c = enfileraPalavras(fila,'c');
	QUEUE *d = enfileraPalavras(fila,'d');	
	QUEUE *e = enfileraPalavras(fila,'e');
	QUEUE *f = enfileraPalavras(fila,'f');	
	QUEUE *g = enfileraPalavras(fila,'g');
	QUEUE *h = enfileraPalavras(fila,'h');	
	QUEUE *i = enfileraPalavras(fila,'i');
	QUEUE *j = enfileraPalavras(fila,'j');	
	QUEUE *k = enfileraPalavras(fila,'k');
	QUEUE *l = enfileraPalavras(fila,'l');	
	QUEUE *m = enfileraPalavras(fila,'m');
	QUEUE *n = enfileraPalavras(fila,'n');	
	QUEUE *o = enfileraPalavras(fila,'o');
	QUEUE *p = enfileraPalavras(fila,'p');	
	QUEUE *q = enfileraPalavras(fila,'q');
	QUEUE *r = enfileraPalavras(fila,'r');	
	QUEUE *s = enfileraPalavras(fila,'s');
	QUEUE *t = enfileraPalavras(fila,'t');	
	QUEUE *u = enfileraPalavras(fila,'u');
	QUEUE *v = enfileraPalavras(fila,'v');	
	QUEUE *w = enfileraPalavras(fila,'w');
	QUEUE *x = enfileraPalavras(fila,'x');	
	QUEUE *y = enfileraPalavras(fila,'y');
	QUEUE *z = enfileraPalavras(fila,'z');
 
    imprimeFila(a,"iniciados com a letra  a:");
	imprimeFila(b,"iniciados com a letra  b:");	
    imprimeFila(c,"iniciados com a letra  c:");
	imprimeFila(d,"iniciados com a letra  d:");	
	imprimeFila(e,"iniciados com a letra  e:");
	imprimeFila(f,"iniciados com a letra  f:");	
	imprimeFila(g,"iniciados com a letra  g:");
	imprimeFila(h,"iniciados com a letra  h:");	
	imprimeFila(i,"iniciados com a letra  i:");
	imprimeFila(j,"iniciados com a letra  j:");	
	imprimeFila(k,"iniciados com a letra  k:");
	imprimeFila(l,"iniciados com a letra  l:");	
	imprimeFila(m,"iniciados com a letra  m:");
	imprimeFila(n,"iniciados com a letra  n:");	
	imprimeFila(o,"iniciados com a letra  o:");
	imprimeFila(p,"iniciados com a letra  p:");	
	imprimeFila(q,"iniciados com a letra  q:");
	imprimeFila(r,"iniciados com a letra  r:");	
	imprimeFila(s,"iniciados com a letra  s:");
	imprimeFila(t,"iniciados com a letra  t:");	
	imprimeFila(u,"iniciados com a letra  u:");
	imprimeFila(v,"iniciados com a letra  v:");	
	imprimeFila(w,"iniciados com a letra  w:");
	imprimeFila(x,"iniciados com a letra  x:");	
	imprimeFila(y,"iniciados com a letra  y:");
	imprimeFila(z,"iniciados com a letra  z:");
    

	destroyQueue(a);
    destroyQueue(b);
    destroyQueue(c);
    destroyQueue(d);
    destroyQueue(e);
    destroyQueue(f);
    destroyQueue(g);
    destroyQueue(h);
    destroyQueue(i);
    destroyQueue(j);
    destroyQueue(k);
    destroyQueue(l);
    destroyQueue(m);
    destroyQueue(n);
    destroyQueue(o);
    destroyQueue(p);
    destroyQueue(q);
    destroyQueue(r);
    destroyQueue(s);
    destroyQueue(t);
    destroyQueue(u);
    destroyQueue(v);
    destroyQueue(w);
    destroyQueue(x);
    destroyQueue(y);
    destroyQueue(z);	
	
}

int main(void){ 
	menu();
	
	return 0;
}