libutils.a: utils.o
	ar rcs libutils.a utils.o

utils.o: utils.c utils.h
	gcc -c utils.c -o utils.o

clean:
	rm -f utils.o libutils.a