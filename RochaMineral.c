#include "RochaMineral.h"
#include "ListaMinerais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializaRochaMineral(RochaMineral *rocha, char id[20], float peso, 
    CategoriaRochaMineral categoria, char latitude[50], char longitude[50], char dataColeta[10]){
        
    setId(rocha, id);
    setPeso(rocha, peso);
    setCategoria(rocha, categoria);
    setLatitude(rocha, latitude);
    setLongitude(rocha, longitude);
    setData(rocha, dataColeta);

}

char *getId(RochaMineral* rocha){
    return rocha->id;
}
float getPeso(RochaMineral* rocha){
    return rocha->peso;
}
CategoriaRochaMineral getCategoria(RochaMineral* rocha){
    return rocha->categoria;
}
ListaMinerais getListaMinerais(RochaMineral* rocha, ListaMinerais Lista){
    return rocha->lista;

}
char *getLatitude(RochaMineral* rocha){
    return rocha->latitude;
}
char *getLongitude(RochaMineral* rocha){
    return rocha->longitude;
}
char *getDataColeta(RochaMineral* rocha){
    return rocha->dataColeta;
}


void setId(RochaMineral* rocha, char *id){
    strcpy(rocha->id, id);

}
void setPeso(RochaMineral* rocha, float peso){
    rocha->peso = peso;
}
void setListaMinerais setListaMinerais(RochaMineral* rocha, ListaMineraisLista){
    rocha->lista = lista;
}
void setCategoria(RochaMineral* rocha, CategoriaRochaMineral categoria){
    rocha->categoria = categoria;
}
void setLatitude(RochaMineral* rocha, char *latitude){
    strcpy(rocha->latitude, latitude);
}
void setLongitude(RochaMineral* rocha, char *longitude){
    strcpy(rocha->longitude, longitude);
}
void setData(RochaMineral* rocha, char *data){
    strcpy(rocha->dataColeta, data);
}
