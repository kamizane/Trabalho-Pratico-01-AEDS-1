compile: main.c Lista_sonda_espacial.c Compartimento.c ListaMinerais.c Mineral.c RochaMineral.c Sonda_espacial.c -lm
	gcc -o main main.c Lista_sonda_espacial.c Compartimento.c ListaMinerais.c Mineral.c RochaMineral.c Sonda_espacial.c -lm
run:
	.\main.exe