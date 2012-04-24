CC = gcc
CFLAGS = -Wall -g
graphtest: graph.o  graphtest.c queue.o
	$(CC) $(CFLAGS) graphtest.c graph.o queue.o list.o  -o graphtest

listtest: list.o listtest.c
	$(CC) $(CFLAGS) listtest.c list.o -o listtest

queuetest: list.o queue.o queuetest.c
	$(CC) $(CFLAGS) list.o queue.o queuetest.c -o queuetest

graph.o: graph.h graph.c queue.o dbg.h
	cc -c  graph.c

queue.o: list.o queue.h  queue.c dbg.h
	cc -c  queue.c

list.o: list.h list.c dbg.h
	cc -c  list.c

clean:
	rm -f *test *.o *.a


