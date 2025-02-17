CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = investimentos

SRCS = src/main.c src/gerenciamento.c src/investimento.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -Iinclude

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) -lm  

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS) $(TARGET)
