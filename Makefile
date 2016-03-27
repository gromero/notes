all:	sum.o main.o
	gcc -O0 -g sum.o main.o -o main

main.o:	main.c
	gcc -O0 -g main.c -c -o main.o

sum.o:  sum.S
	gcc -O0 -g sum.S -c -o sum.o

clean:
	rm -fr sum.o main.o main
