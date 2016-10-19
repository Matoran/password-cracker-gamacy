# Variables Definition
version = gcc -std=gnu99
flags = -c -g 
clean = rm -rf *.o

# Main compilation
main : main.o
	$(version) main.o -o main -lrt
main.o : main.c thread.o string.o
	$(version) -c main.c $(flags) -lrt

# String compilation
string.o : string.c string.h
	$(version) -c string.c $(flags) -lcrypt
# Thread compilation
thread.o : thread.c thread.h
	$(version) -c thread.c $(flags) -lpthread

# Clean part
clean:
	$(clean)