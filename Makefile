all:	sum.o main.o
	gcc -O0 -g sum.o main.o -o main

main.o:	main.c
	gcc -O0 -g main.c -c -o main.o
	gcc -O0 -g -S -mregnames -S -o main.S

sum.o:  sum.S
	gcc -O0 -g sum.S -c -o sum.o

clean:
	rm -fr *.o
	file * | fgrep ELF | gawk 'match($$0, /(.*):/, cap) {print cap[1]}' | xargs rm -fr 


%.o:	%.c
	gcc -O0 -g -mvsx $< -o $@

vlsdoi:	vlsdio.o
	gcc -O0 -g $< -o $@

pvr:	pvr.c
	gcc -O0 -g $< -o $@
