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
    TERRALIS = 9,
    AQUACALIS = 10
} CategoriaRochaMineral;

typedef struct LocalRochaMineral{
    float latitude;
    float longitude;
}LocalRochaMineral;


typedef struct RochaMineral{
    char id[20];
    float peso;
    ListaMinerais *lista;
    CategoriaRochaMineral categoria;
    LocalRochaMineral local;
    char dataColeta [10];
}RochaMineral;

void inicializaRochaMineral(RochaMineral *rocha, char id[20], float peso, ListaMinerais *lista,
    LocalRochaMineral local, char dataColeta[10]);

char *getId(RochaMineral* rocha);
float getPeso(RochaMineral* rocha);
CategoriaRochaMineral getCategoria(RochaMineral* rocha);
ListaMinerais *getListaMinerais(RochaMineral* rocha);
float getLatitude(RochaMineral* rocha);
float getLongitude(RochaMineral* rocha);
char *getDataColeta(RochaMineral* rocha);

void setId(RochaMineral* rocha, char *id);
void setPeso(RochaMineral* rocha, float peso);
void setListaMinerais(RochaMineral* rocha, ListaMinerais* lista);
void setCategoria(RochaMineral* rocha, CategoriaRochaMineral categoria);
void setLatitude(RochaMineral* rocha, float latitude);
void setLongitude(RochaMineral* rocha, float longitude);
void setDataColeta(RochaMineral* rocha, char *data);

void escolheCategoria(RochaMineral *rocha);

#endif
