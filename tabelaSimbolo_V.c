#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tabelaSimbolo_V.h"

void liberaTabela (Tabela t) {
	int i;
	for (i = 0; i < t->capacidade; i++) {
		if (t->dados[i].chave != NULL)
			free(t->dados[i].chave);
		free(t->dados[i])
	}
}

void realocaTabela (simb *tab, int *tab_n, int *n) {
    simb *nova;
    int i;

    nova = malloc (2*(*n)*sizeof(simb));
    for (i = 0; i < *tab_n; i++) {
        nova[i].chave = tab[i].chave;
        nova[i].freq = tab[i].freq;
    }

    liberaTabela (tab, n);
    *n *= 2;
    tab = nova;
}

int verificaFim (simb *tab, int *n) {
    int i;
    
    for (i = 0; i < *n; i++) {
        if (tab[i].chave == NULL)
            return 0;
    }
    
    return i;
}

Tabela criaTabela (int capacidade_inicial) {
	int i = 0;
	Tabela nova = (Tabela) malloc(sizeof(*nova));

	nova->capacidade = capacidade_inicial;
	nova->tamanho = 0;

    nova->dados = malloc(tamanho_inicial * sizeof(*(nova->dados)));
    
    for (i = 0; i < *n; i++) {
        nova->dados[i].chave = NULL;
        nova->dados[i].freq = 0;
    }

    return nova;
}

void imprimeTabela(Tabela t) {
    int i;
    for (i = 0; t->dados[i].chave < t->tamanho; i++)
        printf("chave: %s freq: %d\n", t->dados[i].chave, t->dados[i].freq);
}