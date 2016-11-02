#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* leitura (FILE* entrada, int* parada) {
	
	int i, n, l, l_conta;
	char *p;

	n = 1024;
	p = malloc (n);
	l_conta = i = 0;

	l = fgetc(entrada);

	while (l != EOF && (isspace (l) || l_conta == 0 )) {
		
		while (!isspace (l) && l != EOF) {
			
			if (l >= 65 && l <= 90) 
				l += 32;
			
			if (l_conta && ((l >= 48 && l <= 57) || (l >= 97 && l <= 122))) {
				p[i] = ((char)l);
				i++;
			}

			else if (l_conta == 0 && (l >= 97 && l <= 122)) {
				printf("%d\n", l_conta);
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
	int *parada, para;
	FILE *entrada;

	entrada = fopen (argv[1], "r");
	tipo = argv[2];
	modo = argv[3];

	para = 1;
	parada = &para;
	
	while (*parada) {
		palavra = leitura (entrada, parada);
		printf("%s\n", palavra);
	}

	return 0;
}