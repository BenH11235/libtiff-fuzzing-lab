LIBTIFF_SRC_LOCATION = /usr/src/libtiff-Release-v4-0-6/libtiff

loadtiff.o: loadtiff.c
	gcc -c loadtiff.c -m32 -g

loadtiff: loadtiff.o
	g++ -o loadtiff loadtiff.o $(LIBTIFF_SRC_LOCATION)/*.o -m32 -g -lz

clean:
	rm -f *.o
	rm loadtiff


