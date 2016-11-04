#ifndef __TABELAV_H__
#define __TABELAV_H__

typedef struct {
    char *chave;
    int  freq;
} simb;

struct tabela {
	int tamanho, capacidade;
	simb* dados;
};
typedef struct tabela *Tabela;

void liberaTabela (simb *tab, int *tab_n);

void realocaTabela (simb *tab, int *tab_n, int *n);

int verificaFim (simb *tab, int *n);

simb* criaTabela (int **n, int **tab_n);

void imprimeTabela (simb *tab, int *tab_n);

#endif