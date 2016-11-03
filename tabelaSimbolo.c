#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tabelaSimbolo_VO.h"


char* leitura (FILE* entrada, int* parada) {
	
	int i, n, l, l_conta;
	char *p;

	n = 1024;
	p = malloc (n);
	l_conta = i = l = 0;

	while (l != EOF && l_conta == 0) {

		l = fgetc(entrada);

		while (!isspace (l) && l != EOF) {
			
			if (l >= 65 && l <= 90) 
				l += 32;
			
			if (l_conta && ((l >= 48 && l <= 57) || (l >= 97 && l <= 122))) {
				p[i] = ((char)l);
				i++;
			}

			else if (l_conta == 0 && (l >= 97 && l <= 122)) {
				
				p[i] = ((char)l);
				l_conta++;
				i++;
			}
			
			l = fgetc(entrada);
		}
	}

	if (l == EOF)
		*parada -= 1;
	
	return (p);
}



int main (int argc, char **argv) {

	char *tipo, *modo, *palavra;
	int *parada, *n, *tab_n;
	int para, padrao, tamanho;
	
	simb *tabela;
	FILE *entrada;

	entrada = fopen (argv[1], "r");
	tipo = argv[2];
	modo = argv[3];

	para = 1;
	padrao = 1024;
	tamanho = 1024;
	
	parada = &para;
	n = &padrao;
	tab_n = &tamanho;

	tabela = criaTabela (n);
	imprimeTabela (tabela, tab_n);
	
	while (*parada) {
		palavra = leitura (entrada, parada);
		printf("%s\n",palavra );
		if (strcmp(tipo, "VO") == 0) {
			
			insereElemento (tabela, palavra, n, tab_n);
			
		}
	}

	imprimeTabela (tabela, tab_n);

	return 0;
}