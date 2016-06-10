CC=gcc

INCLUDE_DIR=../include
BIN_DIR=../bin
OBJ_DIR=../obj

CFLAGS=-c -Wall -I$(INCLUDE_DIR)

SOURCES=uart.c
OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS)

%.o: %.c
	@echo "Compilando o arquivo-fonte: " $<
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@

.PHONY: clean

clean:
	@echo -e "\nLimpando os objetos."
	rm -rf $(addprefix $(OBJ_DIR)/, $(OBJECTS))
	@echo -e "Limpeza finalizada.\n"
