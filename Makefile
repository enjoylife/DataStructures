CC = gcc
CFLAGS = -Wall
graphtest: graph.o 
	$(CC) $(CFLAGS) graphtest.c graph.o -o graphtest
	 queuetest.c -o queuetest

listtest: list.o listtest.c
	$(CC) $(CFLAGS) listtest.c list.o -o listtest

queuetest: list.o queue.o queuetest.c
	$(CC) $(CFLAGS) list.o queue.o queuetest.c -o queuetest

graph.o: graph.h dbg.h
	cc -c graph.c

queue.o: list.o queue.h dbg.h
	cc -c  queue.c

list.o: list.h list.c dbg.h
	cc -c  list.c

clean:
	rm -f *test *.o *.a

