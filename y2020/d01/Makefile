
CC = gcc -g -lX11
objects = part1 part2

.PHONY: all
all: $(objects)

clean:
	rm -rfv $(objects)

$(objects): %: %.c
	$(CC) -o $@ $<




