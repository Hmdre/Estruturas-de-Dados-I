#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct data
{
	int dia;
	int mes;
	int ano;
	
}Data;

void somaDias(Data *dia,int dias)
{
		int d=dias, m=0, a=0;
		
		d += dia->dia;
		m += dia->mes;
		a += dia->ano;
		
		if(d>31){
			m+=d/31;
			d=d%31;
			if(m>12){
				a+=m/12;
				m=m%12;
			}
			else
			{
				a=dia->ano;
			}	
		}
		dia->dia = d;
		dia->mes = m;
		dia->ano = a;
		printf("Data: %d / %d / %d ",dia->dia,dia->mes,dia->ano);
}

void stringToStruct(char *String,Data *aux)
{
	aux->dia =  (String[0] - '0')*10 + (String[1]- '0');
	aux->mes = (String[3] - '0')*10 + (String[4]- '0');
	aux->ano = (String[6] - '0')*1000 + (String[7]- '0')*100 +(String[8] - '0')*10 + (String[9]- '0');			
}

void verificaData(Data *d,char *dat, int *x)
{
    char zd=' ',zm=' ';
    char za[4]="";
    
    printf("digite o dia:");
	scanf("%d",&d->dia);

    if(d->dia<1 || d->dia>31)
    {
        printf("\nIntroduza um dia valido\n");
        return;
    }

    printf("digite o mes:");
	scanf("%d",&d->mes);

    if(d->mes<1 || d->mes>12)
    {
        printf("\nIntroduza um mes valido\n");
        return;
    }
    
    if(d->mes==4 || d->mes==6 || d->mes==9 || d->mes==11)
    {
        if(d->dia>30)
        {
            printf("\nIntroduza um dia valido\n");
            return;
        }
    }

    printf("digite o ano (ate 2021):");
	scanf("%d",&d->ano);

    if(d->ano<1 || d->ano>2021)
    {
        printf("\nIntroduza um ano valido\n");
        return;
    }

    if(d->mes == 2)
        {
            if(((d->ano%4)==0) && (d->dia>29))
            {
                printf("\nIntroduza um dia valido\n");
                return;
            }
            if(((d->ano%4)!=0) && (d->dia>28))
            {
                printf("\nIntroduza um dia valido\n");
                return;
            }
        }
            
    if (d->dia < 10)
        zd = '0';
    if (d->mes < 10)
        zm = '0';
    if (d->ano < 1000)
    {
        za[0]='0';
        if (d->ano < 100)
        {
            za[1]='0';
            if (d->ano < 10)
            {
                za[2]='0';
            }
        }
    }
    
    sprintf(dat, "%c%d/%c%d/%s%d", zd,d->dia,zm,d->mes,za,d->ano);
    
    printf("%s",dat);
    *x = 1;
}
