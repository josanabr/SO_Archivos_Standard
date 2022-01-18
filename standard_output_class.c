#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mi_h.h"

int main(int argc, char *argv[]) {
	char cadena[MAXCADENA];
	FILE* descriptor;
	descriptor = fopen("archivo.txt", "w"); // r - read, w - write
	if (descriptor == NULL) {
		printf("No esta el archivo'n");
		exit(2);
	} 
	printf("Digite una cadena: ");
	fscanf(stdin,"%s",cadena); // FILE*
	fprintf(stdout,
                "[%d] Cadena digitada '%s'\n",
                getpid(),              cadena);
	return 0;
}
