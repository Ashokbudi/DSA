apc.exe: main.o operations.o addition.o substraction.o multiplication.o division.o
	gcc -o apc.exe main.o operations.o addition.o substraction.o multiplication.o division.o
main.o:main.c
	gcc -c main.c
operations.o:operations.c
	gcc -c operations.c
addition.o:addition.c
	gcc -c addition.c
substraction.o:substraction.c
	gcc -c substraction.c
division.o:division.c
	gcc -c division.c
clean:
	rm *.exe *.o