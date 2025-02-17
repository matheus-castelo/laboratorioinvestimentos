CC = gcc
CFLAGS = -Wall -Iinclude

all: main

main: src/main.c src/investimento.c src/gerenciamento.c
	$(CC) $(CFLAGS) -o investimentos src/main.c src/investimento.c src/gerenciamento.c -lm

clean:
	rm -f investimentos
