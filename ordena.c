#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tabelaSimbolo_VO.h"

int encontraIndice (simb* tab, int inicio, int fim) {

	int i, f;
	char *piv;

	piv = malloc (strlen(tab[i].chave));
	piv = tab[i].chave;
	i = inicio;
	f = fim;
	
	while (f > i) {
		
		while (strcmp(tab[f].chave, piv) > 0 && f > i) f--;

		if (f > i) {
			tab[i].chave = tab[f].chave;
			tab[i].freq = tab[f].freq;
		}

		while (f > i && strcmp(tab[i].chave, piv) <= 0) i++;

		if (f > i) {
			tab[f].chave = tab[i].chave;
			tab[f].freq = tab[i].freq;		
		}
	}

	tab[i].chave = piv;
	
	free(piv);
	piv = NULL;
	
	return i;
}

void ordenaAlfabetico (simb* tab, int ini, int tab_n) {

	int meio;

	if (ini < tab_n) {
		meio = encontraIndice (tab, ini, tab_n - 1);
		ordenaAlfabetico (tab, ini, meio - 1);
		ordenaAlfabetico (tab, meio + 1, tab_n);
	}
}
