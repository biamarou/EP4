#ifndef __TABELAVO_H__
#define __TABELAVO_H__

typedef struct {
    char *chave;
    int  freq;
} simb;

void insereElemento (simb *tab, char *elem, int *n, int *tab_n);

simb* criaTabela (int *n);

void realocaTabela (simb *tab, int *tab_n, int *n);

void liberaTabela (simb *tab, int *tab_n);

int encontraPos (simb *tab, char *elem, int *tab_n);

void deslocaElementos (simb *tab, char *elem, int pos, int *tab_n);

void imprimeTabela (simb *tab, int *tab_n);

#endif