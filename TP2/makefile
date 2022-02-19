CC=gcc
CFLAGS=-Wall -std=c99
OBJ=main.o liste.o tab.o

exec: $(OBJ)
	$(CC) -o exec $(OBJ) $(CFLAGS)

tab.o: tab.c tab.h
	$(CC) -c tab.c $(CFLAGS)

liste.o: liste.c liste.h tab.h
	$(CC) -c liste.c $(CFLAGS)

main.o: main.c liste.h
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
