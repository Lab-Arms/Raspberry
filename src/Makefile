CC=gcc

INCLUDE_DIR=../include
BIN_DIR=../bin
OBJ_DIR=../obj

CFLAGS=-c -Wall -I$(INCLUDE_DIR)

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
DEPS=$(addprefix $(OBJ_DIR)/, $(OBJECTS))

all: $(DEPS)

$(OBJ_DIR)/%.o: %.c
	@echo "Compilando o arquivo-fonte: " $<
	@$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	@echo -e "\nLimpando os objetos."
	@rm -rf $(DEPS)
	@echo -e "Limpeza finalizada.\n"
