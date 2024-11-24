# compile: main.c Lista_sonda_espacial.c Compartimento.c ListaMinerais.c Mineral.c RochaMineral.c Sonda_espacial.c 
# 	gcc main.c Lista_sonda_espacial.c Compartimento.c ListaMinerais.c Mineral.c RochaMineral.c Sonda_espacial.c -Wall -lm -g -o ../main
# run:
# 	..\main.exe
# #gdb --args .\main.exe -f teste1.txt

CC=gcc
CFLAGS=-Wall -Wextra -g  -I./src/Compartimento -I./src/Lista_sonda_espacial -I./src/ListaMinerais -I./src/Mineral -I./src/RochaMineral -I./src/Sonda_espacial
SRC=$(wildcard src/*/*.c src/*/*/*.c)
OBJ=$(SRC:.c=.o)
TARGET=main.exe

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q /S $(OBJ) $(TARGET)