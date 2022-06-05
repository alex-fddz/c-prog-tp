logical_use: logical_use.o logical.o
	gcc logical_use.o logical.o -o logical_use

logical_use.o: logical_use.c
	gcc -c logical_use.c
	
logical.o: logical.c
	gcc -c logical.c

clean:
	rm -f logical.o logical_use.o logical_use
