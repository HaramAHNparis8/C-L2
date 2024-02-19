CC = gcc
CFLAGS = -Wall -Wextra
TARGET = maBibli
SOURCES = main.c maBibli.c
HEADERS = maBibli.h
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET)



