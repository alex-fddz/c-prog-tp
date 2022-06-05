stocks: main.o stocks.o
	gcc main.o stocks.o -o stocks

main.o: main.c
	gcc -c main.c

stocks.o: stocks.c stocks.h
	gcc -c stocks.c

clean:
	rm -f *.o stocks stocks.txt
