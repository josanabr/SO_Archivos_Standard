#include <stdio.h>
#include "mi_h.h"

int main(int argc, char *argv[]) {
	char cadena[MAXCADENA];
	printf("Digite una cadena: ");
	fscanf(stdin,"%s",cadena);
	printf("Cadena digitada '%s'\n",cadena);
	return 0;
}
