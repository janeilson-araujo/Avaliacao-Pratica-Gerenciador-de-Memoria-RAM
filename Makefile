CC = gcc 
CFLAGS = -Wall -Wextra -std=c11
TARGET = memoria

all:
	$(CC) $(CFLAGS) main.c memoria.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean run

run:
	./$(TARGET)