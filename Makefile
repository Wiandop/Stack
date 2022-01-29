build: main.o stack.o
	gcc main.o stack.o

main.o: main.c
	gcc -c main.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean: main.o stack.o
	del a.exe main.o stack.o
