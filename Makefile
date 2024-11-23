compile: main.c Lista_sonda_espacial.c Compartimento.c ListaMinerais.c Mineral.c RochaMineral.c Sonda_espacial.c 
	gcc main.c Lista_sonda_espacial.c Compartimento.c ListaMinerais.c Mineral.c RochaMineral.c Sonda_espacial.c -Wall -lm -g -o main
run:
	.\main.exe
#gdb --args .\main.exe -f teste1.txt
