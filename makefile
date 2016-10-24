# Variables Definition
version = gcc -std=gnu99
flags = -c -g 
clean = rm -rf *.o crack

# Main compilation
crack : main.o thread.o string.o
	$(version) main.o thread.o string.o -o crack -lrt -lpthread
main.o : main.c 
	$(version) -c main.c $(flags) -lrt

# String compilation
string.o : string.c string.h
	$(version) -c string.c $(flags) -lcrypt
# Thread compilation
thread.o : thread.c thread.h  threadprivate.h
	$(version) -c thread.c $(flags) -lpthread

# Clean part
clean:
	$(clean)
