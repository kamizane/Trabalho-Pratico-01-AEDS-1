#include "RochaMineral.h"
#include "ListaMinerais.h"
#include "Mineral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializaRochaMineral(RochaMineral *rocha, char id[20], float peso, ListaMinerais *lista, LocalRochaMineral local, char dataColeta[10]){
        
    setId(rocha, id);
    setPeso(rocha, peso);
    setListaMinerais(rocha, lista);
    escolheCategoria(rocha);
    setLatitude(rocha, local.latitude);
    setLongitude(rocha, local.longitude);
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
ListaMinerais *getListaMinerais(RochaMineral* rocha){
    return rocha->lista;
}
char *getLatitude(RochaMineral* rocha){
    return rocha->local.latitude;
}
char *getLongitude(RochaMineral* rocha){
    return rocha->local.longitude;
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
void setListaMinerais(RochaMineral* rocha, ListaMinerais* lista){
    rocha->lista = lista;
}
void setCategoria(RochaMineral* rocha, CategoriaRochaMineral categoria){
    rocha->categoria = categoria;
}
void setLatitude(RochaMineral* rocha, char *latitude){
    strcpy(rocha->local.latitude, latitude);
}
void setLongitude(RochaMineral* rocha, char *longitude){
    strcpy(rocha->local.longitude, longitude);
}
void setDataColeta(RochaMineral* rocha, char *data){
    strcpy(rocha->dataColeta, data);
}

void escolheCategoria(RochaMineral *rocha){
    ListaMinerais *lista = getListaMinerais(rocha);
    
    int tFerrolita = 0, tSolarium = 0, tAquavitae = 0, tTerranita = 0, tCalaris = 0;
    for(int i = 0; i < 3; i++){
        if(strcmp(lista->minerais[i].nome, "FERROLITA") == 0){
            tFerrolita = 1;
        }else if(strcmp(lista->minerais[i].nome, "SOLARIUM") == 0){
            tSolarium = 1;
        }else if(strcmp(lista->minerais[i].nome, "AQUAVITAE") == 0){
            tAquavitae = 1;
        }else if(strcmp(lista->minerais[i].nome, "TERRANITA") == 0){
            tTerranita = 1;
        }else{
            tCalaris = 1;
        } 
    }

    if(tAquavitae && tCalaris && tFerrolita){
        setCategoria(rocha, AQUACALIS);

    }else if(tTerranita && tFerrolita){
        setCategoria(rocha, TERRALIS);

    }else if(tSolarium && tFerrolita){
        setCategoria(rocha, SOLARISFER);

    }else if(tCalaris && tAquavitae){
        setCategoria(rocha, CALQUER);

    }else if(tAquavitae && tTerranita){
        setCategoria(rocha, AQUATERRA);

    }else if(tTerranita && tSolarium){
        setCategoria(rocha, TERRASOL);

    }else if(tTerranita && tCalaris){
        setCategoria(rocha, TERROLIS);

    }else if (tFerrolita && tAquavitae){
        setCategoria(rocha, AQUAFERRO);

    }else if (tSolarium){
        setCategoria(rocha, SOLARIS);

    }else if (tFerrolita){
        setCategoria(rocha, FERROM);
    }
    
    
    
    
}
