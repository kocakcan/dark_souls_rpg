CC = gcc
CFLAGS = -Wall -Wextra

OBJS = main.o combat.o character.o input.o

all: rpg

rpg: $(OBJS)
	$(CC) $(CFLAGS) -o rpg $(OBJS)

clean:
	rm -f *.o rpg
