#include <stdio.h>
#include <stdlib.h>
#include <ctypes.h>

typedef struct {
    char *chave;
    int  freq;
} simb;

void insereElemento (simb *tab, char *elem, int *n, int *tab_n) {
    int pos;
    pos = encontraPos(tab, elem, tab_n);
    if (strcmp(tab[pos]->chave, elem) && tab[pos]->chave != NULL) {
        if (*tab_n == *n)
            realocaTabela(tab, tab_n, n);
        deslocaElementos (tab, elem, pos);
    }

    else if (strcmp(tab[pos]->chave, elem) == 0)
        tab[pos].freq += 1;

    else {
        tab[pos]->chave = elem;
        tab[pos].freq += 1;
    }
}

void criaTabela (simb *tab, int *tab_n, int *n) {
    int i;
    tab = malloc (*n*sizeof(simb));
    
    for (i = 0; i < *tab_n; i++) {
        tab[i]->chave = NULL;
        tab[i].freq = 0;
    }
}

void realocaTabela (simb *tab, int *tab_n, int *n) {
    simb *nova;
    int i;

    nova = malloc (2*n*sizeof(simb));
    for (i = 0; i < *tab_n; i++) {
        nova[i]->chave = tab[i]->chave;
        nova[i].freq = tab[i].freq;
    }

    liberaTabela (tab, n);
    *n *= 2;
    tab = nova;
}

void liberaTabela (sim *tab, int *tab_n) {

}

int encontraPos (simb *tab, char *elem, int *tab_n) {

}

void deslocaElementos (simb *tab, char *elem, int pos, int *tab_n) {
    int i;
    for (i = *tab_n; i > pos; i--) {
        tab[i + 1]->chave = tab[i]->chave;
        tab[i + 1].freq = tab[i].freq;
    }

    tab[pos]->chave = elem;
    tab[pos].freq = 1;
}

void imprimeTabela () {

}