currency_converter: main.o currencies.o
	gcc main.o currencies.o -o currency_converter

main.o: main.c
	gcc -c main.c

currencies.o: currencies.c
	gcc -c currencies.c

clean:
	rm -f *.o currency_converter
