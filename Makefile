
CC = clang++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17

compile: wite

obj/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c -o obj/main.o src/main.cpp

src/buffer.h: src/common.h
	touch src/buffer.h

src/window.h: src/common.h
	touch src/window.h

obj/display.o: src/display.cpp src/buffer.h src/window.h
	$(CC) $(CFLAGS) -c -o obj/display.o src/display.cpp

OBJS = obj/main.o obj/display.o

wite: $(OBJS)
	$(CC) -s -o wite $(OBJS)

