CC=gcc

INCLUDE_DIR=../include
BIN_DIR=../bin
OBJ_DIR=../obj

CFLAGS=-c -Wall -I$(INCLUDE_DIR)
LDFLAGS=

SOURCES=uart.c
OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS)

%.o: %.c
	@echo "Compilando o arquivo-fonte: " $<
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

.PHONY: clean

clean:
	@rm -rf $(EXECUTABLE) $(OBJECTS)
