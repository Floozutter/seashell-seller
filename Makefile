CC=gcc
CFLAGS=-Wall -Wextra -Wl,-subsystem,windows -IC:/SDL2-2.0.12/i686-w64-mingw32/include
LDFLAGS=-LC:/SDL2-2.0.12/i686-w64-mingw32/lib
LIBS=-lmingw32 -lSDL2main -lSDL2

all: src/main.c build/ecs.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< build/*.o $(LIBS) -o build/seashell-seller

build/ecs.o: src/ecs.c
	$(CC) $(CFLAGS) -c $< -o $@
