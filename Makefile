all: standard_input standard_output standard_err

clean:
	rm -rf archivo.txt salida.txt standard_input standard_output standard_err a.out

standard_input:
	gcc -o standard_input standard_input.c

standard_output:
	gcc -o standard_output standard_output.c

standard_err:
	gcc -o standard_err standard_err.c
