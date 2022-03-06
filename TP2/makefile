CC=gcc
CFLAGS=-Wall -std=c99
OBJ=main.o listeDouble.o liste.o tab.o get.o

exec: $(OBJ)
	$(CC) -o exec $(OBJ) $(CFLAGS)

get.o: get.c get.h
	$(CC) -c get.c $(CFLAGS)

tab.o: tab.c tab.h
	$(CC) -c tab.c $(CFLAGS)

liste.o: liste.c liste.h tab.h
	$(CC) -c liste.c $(CFLAGS)

listeDouble.o: listeDouble.c listeDouble.h tab.h get.h
	$(CC) -c listeDouble.c $(CFLAGS)

main.o: main.c liste.h
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
