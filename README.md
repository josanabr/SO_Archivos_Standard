# Archivos *standard* de los procesos en Unix

En este repositorio se explicará como se usan los archivos *standard* que todos los procesos en Unix tienen asociados por defecto. 
Esto quiere decir que cada vez que nosotros creamos un proceso en Unix, el sistema operativo se encarga de asignarle tres archivos.
Estos son los archivos por defecto:

* **Archivo de entrada standard**. Este es el archivo de donde se leen los datos por defecto y los datos van del mundo exterior al proceso. Este archivo está asociado por defecto con el teclado del computador. Este archivo se puede referenciar a través de la macro `stdin` o por su valor numérico `0` directamente.

* **Archivo de salida standard**. Este es el archivo usado para enviar datos del proceso al mundo exterior. Este archivo está asociado por defecto a la pantalla del computador. Este archivo se puede referenciar a través de la macro `stdout` o por su valor numérico `1` directamente.

* **Archivo de salida de error standard**. Este es el archivo usado para enviar datos relacionados a la **ejecución anormal** de un proceso. Este archivo está asociado por defecto a la pantalla del computador. Este archivo se puede referenciar a través de la macro `stderr` o por su valor numérico `2` directamente.

A continuación se presentarán algunos códigos que ejemplifican como estos archivos son usados.

## Leyendo datos de la entrada *standard*

Observe el siguiente código que se encuentra en el archivo [`standard_input.c`](standard_input.c):

```
#include <stdio.h>
#include "mi_h.h"

int main(int argc, char *argv[]) {
	char cadena[MAXCADENA];
	printf("Digite una cadena: ");
	fscanf(stdin,"%s",cadena);
	printf("Cadena digitada '%s'\n",cadena);
	return 0;
}
```

### Hágalo usted mismo

Compile el programa y digite diferentes datos por el teclado. ¿Qué pasa por ejemplo cuando usted digita una cadena como esta `hola mundo`?

## Salida *standard* de los procesos

Los procesos envían sus datos por defecto a la pantalla. 
Modifiquemos el código anterior para corroborar esta afirmación.
Este código se encuentra en el archivo [`standard_output.c`](standard_output.c):

```
#include <stdio.h>
#include "mi_h.h"

int main(int argc, char *argv[]) {
	char cadena[MAXCADENA];
	printf("Digite una cadena: ");
	fscanf(stdin,"%s",cadena);
	fprintf(stdout,"Cadena digitada '%s'\n",cadena);
	return 0;
}
```

Observe que el código ha sido ligeramente modificado. 
El cambio se da después de la instrucción `fscanf(...)` ya que se cambió el llamado a la función `printf(...)` por `fprintf(...)`.

### Hágalo usted mismo

Compile el programa y señale si encuentra algún cambio en la forma como se comporta este programa versus el programa de la sección anterior.

## Salida *standard* de error

La salida *standard* de error de los procesos es referenciada por un descriptor de archivo llamado `stderr`.
Es decisión del programador decidir que información se envía o bien por la salida *standard* o bien por la salida *standard* de error.
Considere el siguiente código, [`standard_err.c`](standard_err.c):

```
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
	return 0;
}
```

Este programa intenta abrir el archivo llamado `archivo.txt`. 
Si se falla en la apertura del archivo (`descriptor == NULL`) entonces se imprime un mensaje por la salida *standard* de error que dice `Archivo no encontrado`.
De lo contrario se leerán los datos del archivo (`fscanf(descriptor,...)`) e imprimirá "lo que se encuentre en el archivo". 

**De acuerdo a este código, ¿Cuáles cadenas piensa usted que se van por la salida *standard* y cuáles por la salida de error *standard*?**

### Hágalo usted mismo

Compile el programa y ejecútelo. 
Ejecútelo inicialmente sin tener un archivo `archivo.txt`.
Ejecútelo de esta manera y asumiendo que el archivo resultado de compilar se llama `a.out`:

```
./a.out 
```

¿Qué observó en la ejecución?

Ejecúte el programa nuevamente de la siguiente manera:

```
./a.out > salida.txt
```

¿Qué observa en la ejecución? Hay algún cambio. 
¿Qué contenido tiene el archivo `salida.txt`?

Ejecute el programa nuevamente de esta otra forma:

```
./a.out >& salida.txt
```

¿Qué observa en la ejecución? Hay algún cambio. 
¿Qué contenido tiene el archivo `salida.txt`?

Ahora cree el archivo `archivo.txt` de la siguiente manera:

```
echo "hola mundo" > archivo.txt
```

Ejecute el programa de estas dos formas:

* `./a.out` 

* `./a.out > salida.txt`

¿Qué imprimió el programa durante su ejecución? 
¿Es la salida que usted esperaba ver?
¿Qué diferencia encuentra entre una ejecución y otra?
