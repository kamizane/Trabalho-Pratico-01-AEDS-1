#ifndef ROCHA_MINERAL_H
#define ROCHA_MINERAL_H

#include "./ListaMinerais.h"

typedef enum CategoriaRochaMineral {
    FERROM = 1,
    SOLARIS = 2,
    AQUAFERRO = 3,
    TERROLIS = 4,
    TERRASOL = 5,
    AQUATERRA = 6,
    CALQUER = 7,
    SOLARISFER = 8,
    TERRARIS = 9,
    AQUACALIS = 10
} CategoriaRochaMineral;

typedef struct RochaMineral{
    char id[20];
    float peso;
    ListaMinerais *lista;
    CategoriaRochaMineral categoria;
    char latitude[50];
    char longitude[50];
    char dataColeta [10];
}RochaMineral;

void inicializaRochaMineral(RochaMineral *rocha, char id[20], float peso, 
    CategoriaRochaMineral categoria, char latitude[50], char longitude[50], char dataColeta[10]);

char *getId(RochaMineral* rocha);
float getPeso(RochaMineral* rocha);
CategoriaRochaMineral getCategoria(RochaMineral* rocha);
ListaMinerais getListaMinerais(RochaMineral* rocha, ListaMinerais Lista);
char *getLatitude(RochaMineral* rocha);
char *getLongitude(RochaMineral* rocha);
char *getDataColeta(RochaMineral* rocha);

void setId(RochaMineral* rocha, char *id);
void setPeso(RochaMineral* rocha, float peso);
void setListaMinerais setListaMinerais(RochaMineral* rocha, ListaMineraisLista);
void setCategoria(RochaMineral* rocha, CategoriaRochaMineral categoria);
void setLatitude(RochaMineral* rocha, char *latitude);
void setLongitude(RochaMineral* rocha, char *longitude);
void setData(RochaMineral* rocha, char *data);


#endif
