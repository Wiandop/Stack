build: main.o stack.o tests.o
	gcc main.o stack.o tests.o

main.o: main.c
	gcc -c main.c

stack.o: stack.c stack.h
	gcc -c stack.c

tests.o: tests/tests.c tests/tests.h
	gcc -c tests/tests.c

clean: main.o stack.o tests.o
	del a.exe main.o stack.o tests.o
