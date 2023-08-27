CC=g++
CFLAGS= -c -Wall

all: prog prog1

prog: array.o queueA.o singleLL.o bfs.o
	$(CC) array.o queueA.o singleLL.o bfs.o -o prog
	
prog1: array.o stackA.o singleLL.o dfs.o
	$(CC) array.o stackA.o singleLL.o dfs.o -o prog1	
	
array.o: array.cpp
	$(CC) $(CFLAGS) array.cpp

queueA.o: queueA.cpp
	$(CC) $(CFLAGS) queueA.cpp
	
stackA.o: stackA.cpp
	$(CC) $(CFLAGS) stackA.cpp	

singleLL.o: singleLL.cpp
	$(CC) $(CFLAGS) singleLL.cpp

bfs.o: bfs.cpp
	$(CC) $(CFLAGS) bfs.cpp
	
dfs.o: dfs.cpp
	$(CC) $(CFLAGS) dfs.cpp	

clean:
	rm -rf *.o
