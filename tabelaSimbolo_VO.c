#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tabelaSimbolo_V.h"

void deslocaElementos (simb *tab, char *elem, int pos, int *tab_n) {
    int i, fim;
    for (fim = 0; tab[fim].chave != NULL; fim++) {}
    
    for (i = fim - 1; i >= pos; i--) {
            
        tab[i + 1].chave = tab[i].chave;
        tab[i + 1].freq = tab[i].freq;
    }

    tab[pos].chave = elem;
    tab[pos].freq = 1;
}

int encontraPos (simb *tab, char *elem, int *tab_n) {

    int i;
    i = 0;

    while (tab[i].chave != NULL && strcmp (elem, tab[i].chave) > 0) {
        i++;
    }
    
    return i;
}

void insereElemento (simb *tab, char *elem, int *n, int *tab_n) {
    int pos;
    pos = encontraPos(tab, elem, tab_n);
    printf("%d achou pos\n", pos);
    if (tab[pos].chave == NULL) {

        tab[pos].chave = elem;
        tab[pos].freq += 1;
        printf("inseriu\n");
        imprimeTabela (tab, tab_n);
        printf("\n");  
    }

    else if (strcmp(tab[pos].chave, elem) == 0)
        tab[pos].freq += 1;

    else {
        if (verificaFim (tab, n))
            realocaTabela(tab, tab_n, n);
        
        deslocaElementos (tab, elem, pos, tab_n);
        printf("deslocou\n");
        imprimeTabela (tab, tab_n);
        printf("\n");
    }
}