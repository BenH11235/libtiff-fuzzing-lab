LIBTIFF_SRC_LOCATION = /usr/src/libtiff-Release-v4-0-6/libtiff

loadtiff.o: loadtiff.c
	afl-gcc -c loadtiff.c -m32 -g -fsanitize=address

loadtiff: loadtiff.o
	afl-g++ -o loadtiff loadtiff.o -fsanitize=address $(LIBTIFF_SRC_LOCATION)/*.o -m32 -g -lz -lasan

fuzz:
	#1. use afl-fuzz to fuzz ./loadtiff.
	#use the provided "samples" directory as input, and create your own
	#empty output directory. Set a memory limit of 900MB.

clean:
	rm -f *.o
	rm loadtiff
	rm -rf out

