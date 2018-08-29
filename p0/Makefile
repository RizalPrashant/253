#Reference cs.boisestate.edu/~cs253/handouts/make-handout.pdf
#For more information regarding make
CC = gcc
CFLAGS = -Wall -g

hello: main.o
	$(CC) $(CFLAGS) $^ -o $@
	./hello
clean:
	rm -f *.o hello
