LIBTIFF_SRC_LOCATION = /usr/src/libtiff-Release-v4-0-6/libtiff

loadtiff.o: loadtiff.c
	afl-gcc -c loadtiff.c -m32 -g

loadtiff: loadtiff.o
	afl-g++ -o loadtiff loadtiff.o $(LIBTIFF_SRC_LOCATION)/*.o -m32 -g -lz

clean:
	rm -f *.o
	rm loadtiff

#used for auto solve
sol_loadtiff.o: sol_loadtiff.c
	afl-gcc -o loadtiff.o -c sol_loadtiff.c -m32 -g

solve: sol_loadtiff.o loadtiff
	./loadtiff ../samples/brain.tif


