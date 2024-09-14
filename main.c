#include <stdio.h>
#include <string.h>
#define max 503
#define asciinumstart 48
#define asciinumend 57
#define base 10

int scanfnum(char numfirst[], char numsecond[]);
int highestnumber(char numfirst[], char numsecond[]);
void operationswitch(int operation, char numfirst[], char numsecond[], int flag);
void add(int lenfirst, int lensecond, char numfirst[], char numsecond[]);
void sub(int lenfirst, int lensecond, char numfirst[], char numsecond[], int flag);
void mult(int lenfirst, int lensecond, char numfirst[], char numsecond[]);
void printfaux(int aux[], int maxaux, int flag);

int main(void)
{
	int interactions;
	char numfirst[max], numsecond[max];
	scanf("%d", &interactions);
	for (int i = 0; i < interactions; ++i)     //loop de leitura;
	{                  
		int operation = scanfnum(numfirst, numsecond);
		operationswitch(operation, numfirst, numsecond, highestnumber(numfirst, numsecond));
	}
	return 0;

}
int scanfnum(char numfirst[], char numsecond[])  //leitura os inputs a serem utilizados;
{
	int operation = 0;
	for (int i = 0; i < max; ++i)
	{
		numfirst[i] = 0;
		numsecond[i] = 0;                //zera-se todo o vetor;
	}
	scanf("%s", numfirst);
	scanf("%s", numsecond);
	scanf("%d", &operation);
	return operation;
}

int highestnumber(char numfirst[], char numsecond[])  //ordenador de números, 'numfirst' recebe o maior número(obs: as operações aritmedicas sao desenvolvidas através desse fator);
{
	int lenfirst = strlen(numfirst);
	int lensecond = strlen(numsecond);
	char aux[max];
	for (int i = 0; i < max; ++i)
	{
		aux[i] = 0;                //zera-se todo o vetor;
	}
	if (lenfirst < lensecond )
	{
		strcpy(aux,numsecond);     // caso o 'numsecond' seja maior que 'numfirst' troca-se;
		strcpy(numsecond,numfirst);
		strcpy(numfirst,aux);
		return 1;
	}
	else if ( lenfirst == lensecond)
	{
		for (int i = 0; i < lenfirst; ++i)
		{
			if (numfirst[i] < numsecond[i])
			{
				strcpy(aux,numsecond);          // caso o 'numsecond' seja maior que 'numfirst' troca-se;
				strcpy(numsecond,numfirst);
				strcpy(numfirst,aux);
				return 1;
				break;
			}
			else if (numfirst[i] > numsecond[i])
			{
				break;
			}
		}
	}
	return 0;
}

void operationswitch(int operation, char numfirst[], char numsecond[], int flag)  //seletor de operações;
{
	int lenfirst = strlen(numfirst);
	int lensecond = strlen(numsecond);
	switch(operation)   //selecting 	operation;
	{
	case 1:
		add(lenfirst, lensecond, numfirst, numsecond);
		break;
	case 2:	
		sub(lenfirst, lensecond, numfirst, numsecond,flag);
		break;
	case 3:
		mult(lenfirst, lensecond, numfirst, numsecond);
		break;
	}
}

void add(int lenfirst, int lensecond, char numfirst[], char numsecond[])
{
	int aux[max*2], carry = 0, maxaux = 0;
	for (int i = 0; i < max*2; ++i)
	{
		aux[i] = 0;                //zera-se todo o vetor;
	}
	for (int i = 0, j = lenfirst - 1, k = lensecond - 1; j >= 0; ++i, --j, --k)
	{
		if ( k >= 0)                                                               //enquanto o index da segunda string for maior que 0,ou seja, existirem digitos;
		{                                                                         //soma dos digitos das strings do final até o inicio da string e converção para decimal, via subtração da ascii correspondente ao número;
			aux[i] = numfirst[j] + numsecond[k] - (asciinumstart * 2) + carry; 
		}
		else                                                                     //caso o index seja menor que zero da segunda string, 'aux' recebe apernas o digito do maior número;
		{
			aux[i] = numfirst[j] - asciinumstart + carry;
		}
		carry = 0;
		if (aux[i] >= base)                                                    //caso a resultante ultrapasse a base decimal, cria-se um carry que adiciona um a proxima interação;
		{
			aux[i] -= base;
			carry++;	
		}
		maxaux = i;
	}
	if (carry)                                                               //caso a adição de carry seja na ultima interação, cria-se um digito adicional;
	{
		aux[maxaux+1] = 1;
		maxaux++;
	}
	printfaux(aux, maxaux, 0);
}

void sub(int lenfirst, int lensecond, char numfirst[], char numsecond[], int flag)
{
	int aux[max*2], carry = 0, maxaux = 0;
	for (int i = 0; i < max*2; ++i)
	{
		aux[i] = 0;                //zera-se todo o vetor;
	}
	for (int i = 0, j = lenfirst - 1, k = lensecond - 1; j >= 0; ++i, --j, --k)
	{
		if ( k >= 0)
		{
			aux[i] = numfirst[j] - numsecond[k] - carry;                //enquanto o index da segunda string for maior que 0,ou seja, existirem digitos;
		}                                                               //subtração entre os digites das strings;
		else                                                            //caso o index seja menor que zero da segunda string, 'aux' recebe apernas o digito do maior número menos a ascii, para converter para 'número';
		{
			aux[i] = numfirst[j] - asciinumstart - carry;
		}
		carry = 0;
		if (aux[i] < 0)                                                 //caso a resultante fique negativa em razao da subtração, cria-se um carry que subtrai um da próxima interação;
		{
			aux[i] += base;
			carry++;	
		}
		maxaux = i;
	}
	printfaux(aux, maxaux, flag);
}
void mult(int lenfirst, int lensecond, char numfirst[], char numsecond[])
{
	int aux[max*2], carry = 0, maxaux = 0; 
	for (int i = 0; i < max*2; ++i)
	{
		aux[i] = 0;                //zera-se todo o vetor;
	}
	for (int k = lensecond - 1; k >= 0; --k)
	{
		for (int i = lensecond - 1 - k, j = lenfirst - 1; j >= 0; --j, ++i)
		{
			aux[i] += ((numsecond[k] - asciinumstart) * (numfirst[j] - asciinumstart)) + carry;           //multiplica-se cada digito do 'numsecond' por todos os digitos do 'numfirst' armazenando em aux[i], com i sendo soma um a cada novo digito da segunda string;
			carry = 0;
			if (aux[i] >= base )       //caso a resultante ultrapasse a base decimal, cria-se um carry que adiciona a próxima interação o primeiro digito de 'aux' e mantem-se o outro;                                           
			{
			carry = aux[i] / 10;
			aux[i] = aux[i] % 10;	
			}
			maxaux = i;
		}
		if (carry > 0)                                                   //caso a adição de carry seja na ultima interação, cria-se um digito adicional;
		{
			aux[maxaux+1] = carry;
			carry = 0;
			maxaux++;
		}
	}
	printfaux(aux, maxaux, 0);
}
void printfaux(int aux[],int maxaux, int flag)
{
	int zeroflag = 0;
	if (flag)      //print do sinal negativo;
	{
		printf("-");
	}
	for (int i = maxaux; i >= 0; --i)
	{
		if ((i == maxaux && aux[i] == 0) || (zeroflag && aux[i] == 0))        //caso existam zeros a esquerda, ignore-os;
		{
			zeroflag = 1;
			continue;
		}
		zeroflag = 0;
		printf("%d", aux[i]);               
	}
	if (zeroflag)
	{
		printf("%d", aux[maxaux]);
	}
	printf("\n");
}
