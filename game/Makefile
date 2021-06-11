CC = -gcc
CFLAGS = -c -Wall

all: game 


game: main.o life.o
	$(CC) main.o life.o -o Game_of_life

main.o: main.c
	$(CC) $(CFLAGS) main.c

life.o: life.c
	$(CC) $(CFLAGS) life.c

clean:
	rm -rf *.o Game_of_life
	rm -r latex html

docs: main.c life.c life.h	./Doxyfile
	@doxygen ./Doxyfile