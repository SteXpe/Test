CC=gcc
CFLAGS=-Wall -std=c99
OBJ=main.o

exec: $(OBJ)
	$(CC) -o exec $(OBJ) $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
