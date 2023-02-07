LIBTIFF_SRC_LOCATION = /usr/src/libtiff-Release-v4-0-6/libtiff

loadtiff.o: loadtiff.c
	afl-gcc -c loadtiff.c -m32 -g -fsanitize=address -lasan

loadtiff: loadtiff.o
	afl-g++ -o loadtiff loadtiff.o -fsanitize=address $(LIBTIFF_SRC_LOCATION)/*.o -m32 -g -lz -lasan

clean:
	rm -f *.o
	rm loadtiff

