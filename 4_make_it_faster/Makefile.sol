LIBTIFF_SRC_LOCATION = /usr/src/libtiff-Release-v4-0-6/libtiff
TERMINAL = qterminal

loadtiff.o: loadtiff.c
	afl-gcc -c loadtiff.c -m32 -g -fsanitize=address

loadtiff: loadtiff.o
	afl-g++ -o loadtiff loadtiff.o -fsanitize=address $(LIBTIFF_SRC_LOCATION)/*.o -m32 -g -lz -lasan

prepare_samples: FORCE
	rm -rf ./in
	mkdir in
	cp ../samples/* ./in/
	find ./in/ -type 'f' -size +1k -delete
FORCE: ;

fuzz: prepare_samples
	$(TERMINAL) -e "afl-fuzz -M fuzzer0 -i ./in -o ./out -m 900 ./loadtiff"&
	$(TERMINAL) -e "afl-fuzz -S fuzzer1 -i ./in -o ./out -m 900 ./loadtiff"&
	$(TERMINAL) -e "afl-fuzz -S fuzzer2 -i ./in -o ./out -m 900 ./loadtiff"&
	$(TERMINAL) -e "afl-fuzz -S fuzzer3 -i ./in -o ./out -m 900 ./loadtiff"&

clean:
	rm -f *.o
	rm loadtiff
	rm -rf ./in
	rm -rf ./out

#used for auto solve
sol_loadtiff.o: sol_loadtiff.c
	gcc -o loadtiff.o -c sol_loadtiff.c -m32 -g -fsanitize=address

sol_loadtiff: sol_loadtiff.o 
	afl-g++ -o loadtiff loadtiff.o -fsanitize=address $(LIBTIFF_SRC_LOCATION)/*.o -m32 -g -lz -lasan

solve: sol_loadtiff fuzz

