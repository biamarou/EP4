#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tabelaSimbolo_VO.h"

void liberaTabela (simb *tab, int *tab_n) {

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

void deslocaElementos (simb *tab, char *elem, int pos, int *tab_n) {
    int i;
    for (i = *tab_n; i > pos; i--) {
        tab[i + 1].chave = tab[i].chave;
        tab[i + 1].freq = tab[i].freq;
    }

    tab[pos].chave = elem;
    tab[pos].freq = 1;
}

int encontraPos (simb *tab, char *elem, int *tab_n) {

    int i;
    i = 0;

    while (i < *tab_n) {
        if (strcmp (tab[i].chave, elem) == 0)
            return i;
        else if (strcmp (tab[i].chave, elem) > 0)
            return (i - 1);
        i++;
    }
    return i;
}

void insereElemento (simb *tab, char *elem, int *n, int *tab_n) {
    int pos;
    pos = encontraPos(tab, elem, tab_n);
    printf("%d achou pos\n", pos);
    if (tab[pos].freq == 0) {
        printf("oie\n");
        tab[pos].chave = elem;
        tab[pos].freq += 1;
        *tab_n += 1;   
    }

    else if (strcmp(tab[pos].chave, elem) == 0)
        tab[pos].freq += 1;

    else {
        if (*tab_n == *n)
            realocaTabela(tab, tab_n, n);
        printf("entra desloca\n");
        deslocaElementos (tab, elem, pos, tab_n);
        printf("deslocou\n");
        *tab_n += 1; 
    }
}

simb* criaTabela (int *n) {
    int i;
    simb *tab;
    tab = malloc ((*n)*sizeof(simb));
    
    for (i = 0; i < *n; i++) {
        tab[i].chave = malloc (1024);
        tab[i].chave = NULL;
        tab[i].freq = 0;
    }

    return (tab);
}



void imprimeTabela (simb *tab, int *tab_n) {

    int i;
    for (i = 0; i < *tab_n; i++) {
        printf("%s ", tab[i].chave);
        printf("%d\n", tab[i].freq);
    }
}