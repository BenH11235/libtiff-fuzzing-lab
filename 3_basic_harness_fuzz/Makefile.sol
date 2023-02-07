LIBTIFF_SRC_LOCATION = /usr/src/libtiff-Release-v4-0-6/libtiff

loadtiff.o: loadtiff.c
	afl-gcc -c loadtiff.c -m32 -g -fsanitize=address

loadtiff: loadtiff.o
	afl-g++ -o loadtiff loadtiff.o -fsanitize=address $(LIBTIFF_SRC_LOCATION)/*.o -m32 -g -lz -lasan

fuzz:
	afl-fuzz -i ../samples -o out -m 900 ./loadtiff

clean:
	rm -f *.o
	rm loadtiff
	rm -rf out

#used for auto solve
sol_loadtiff.o: sol_loadtiff.c
	gcc -o loadtiff.o -c sol_loadtiff.c -m32 -g -fsanitize=address

sol_loadtiff: sol_loadtiff.o 
	afl-g++ -o loadtiff loadtiff.o -fsanitize=address $(LIBTIFF_SRC_LOCATION)/*.o -m32 -g -lz -lasan

solve: sol_loadtiff fuzz

