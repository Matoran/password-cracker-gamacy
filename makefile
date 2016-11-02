# Variables Definition
version = gcc -std=gnu99
flags = -g -Wall -Wextra
clean = rm -rf *.o crack hash

# Main compilation
crack : main.o thread.o string.o
	$(version) main.o thread.o string.o -o crack -lrt -lcrypt -lpthread
main.o : main.c 
	$(version) -c main.c $(flags) -lrt

# String compilation
string.o : string.c string.h
	$(version) -c string.c $(flags) -lcrypt
# Thread compilation
thread.o : thread.c thread.h  threadprivate.h
	$(version) -c thread.c $(flags) -lcrypt -lpthread

# Clean part
clean:
	$(clean)

# Hash compilation
hash : hash.c
	$(version) hash.c $(flags) -o hash -lcrypt

# string test compilation
stringtest : string.o stringtest.c
	$(version) stringtest.c string.o $(flags) -o stringtest
