CC=gcc
CFLAGS=-Wall -Wextra -Wl,-subsystem,windows -IC:/SDL2-2.0.12/i686-w64-mingw32/include
LDFLAGS=-LC:/SDL2-2.0.12/i686-w64-mingw32/lib
LIBS=-lmingw32 -lSDL2main -lSDL2

all: src/main.c build/ecs.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< build/*.o -o build/seashell-seller $(LIBS)

build/ecs.o: src/ecs.c
	$(COMPILE) -c $< -o $@

build/.make:
	mkdir -p build
	touch build/.make

clean:
	rm -rf build
