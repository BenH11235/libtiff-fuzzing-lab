LIBTIFF_SRC_LOCATION = /usr/src/libtiff-Release-v4-0-6/libtiff
#1. Choose your favorite terminal
#If it doesn't support "-e cmd" syntax, use equivalent
#If you're not sure just uncomment the below
#TERMINAL = gnome-terminal

loadtiff.o: loadtiff.c
	afl-gcc -c loadtiff.c -m32 -g -fsanitize=address

loadtiff: loadtiff.o
	afl-g++ -o loadtiff loadtiff.o -fsanitize=address $(LIBTIFF_SRC_LOCATION)/*.o -m32 -g -lz -lasan

prepare_samples: FORCE
	rm -rf ./in
	mkdir in
	cp ../samples/* ./in/
	#2. web search for -size flag and -delete flag of "find" command
	#Get rid of all files in ./in that weigh 1KB or more
	#find ./in -type ### -size ### -###
FORCE: ;

fuzz: prepare_samples
	#3. consult: https://github.com/mirrorer/afl/blob/master/docs/parallel_fuzzing.txt
	# $(TERMINAL) -e "afl-fuzz -### fuzzer# -i ./in -o ./out -m 900 ./loadtiff"&
	# $(TERMINAL) -e "afl-fuzz -### fuzzer# -i ./in -o ./out -m 900 ./loadtiff"&
	# $(TERMINAL) -e "afl-fuzz -###	fuzzer# -i ./in -o ./out -m 900 ./loadtiff"&
	# $(TERMINAL) -e "afl-fuzz -### fuzzer# -i ./in -o ./out -m 900 ./loadtiff"&

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

