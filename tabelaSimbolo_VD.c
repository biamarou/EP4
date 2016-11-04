#include <ctype.h>
#include <string.h>
#include "tabelaSimbolo_VO.h"

void insereDesordenado (simb* tab, char* elem, int* n, int* tab_n) {

	int i;
	i = 0;

	while (tab[i].chave != NULL && strcmp(tab[i].chave, elem) != 0)
		i++;

	if (tab[i].chave == NULL) {
		tab[i].chave = elem;
		*tab_n += 1;
	}

	tab[i].freq += 1;
}