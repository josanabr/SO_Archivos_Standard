#include <stdio.h>
#include <stdlib.h>
#include "mi_h.h"

int main(int argc, char *argv[]) {
	char cadena[MAXCADENA];
	char *archivo = "archivo.txt";
	FILE *descriptor;

	descriptor = fopen(archivo, "r");
	if (descriptor == NULL) {
		fprintf(stderr, "Archivo no encontrado\n");
		exit(2);
	}
	fscanf(descriptor,"%s",cadena);
	fprintf(stdout,"Cadena en archivo '%s'\n",cadena);
	fprintf(stderr,"%s\n",cadena);
	return 0;
}
