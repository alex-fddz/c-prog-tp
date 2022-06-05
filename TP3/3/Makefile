plot: main.o packing.o
	gcc main.o packing.o -o packing

main.o: main.c
	gcc -c main.c

packing.o: packing.c
	gcc -c packing.c

clean:
	rm -rf *.o packing packet_file.bin unpacked_files 
