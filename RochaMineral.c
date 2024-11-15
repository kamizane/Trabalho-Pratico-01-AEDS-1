#include "RochaMineral.h"
#include "ListaMinerais.h"
#include "Mineral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função para inicializar uma rocha
void inicializaRochaMineral(RochaMineral *rocha, int id, float peso, ListaMinerais *lista, LocalRochaMineral local, char dataColeta[10]){

    setId(rocha, id);
    setPeso(rocha, peso);
    setListaMinerais(rocha, lista);
    escolheCategoria(rocha);
    setLatitude(rocha, local.latitude);
    setLongitude(rocha, local.longitude);
    setData(rocha, dataColeta);

}

//obtenção de valores (gets)
int getId(RochaMineral* rocha){
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
float getLatitude(RochaMineral* rocha){
    return rocha->local.latitude;
}
float getLongitude(RochaMineral* rocha){
    return rocha->local.longitude;
}
char *getDataColeta(RochaMineral* rocha){
    return rocha->dataColeta;
}

//definição de valores (sets)
void setId(RochaMineral* rocha, int id){
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
void setLatitude(RochaMineral* rocha, float latitude){
    rocha->local.latitude, latitude;
}
void setLongitude(RochaMineral* rocha, float longitude){
    rocha->local.longitude, longitude;
}
void setDataColeta(RochaMineral* rocha, char *data){
    strcpy(rocha->dataColeta, data);
}

//função que define a categoria da rocha a partir da lista de minerais
void escolheCategoria(RochaMineral *rocha){
    //obtendo a lista de minerais da rocha
    ListaMinerais *lista = getListaMinerais(rocha);
    
    //definindo variáveis booleanas para verificar se existe cada mineral na lista
    int tFerrolita = 0, tSolarium = 0, tAquavitae = 0, tTerranita = 0, tCalaris = 0;

    //passando por todas as posições da lista de minerais
    for(int i = 0; i < 3; i++){
        //verificando, a partir do nome do mineral, qual mineral está na posição i
        if(strcmp(lista->minerais[i].nome, "Ferrolita") == 0){
            tFerrolita = 1;
        }else if(strcmp(lista->minerais[i].nome, "Solarium") == 0){
            tSolarium = 1;
        }else if(strcmp(lista->minerais[i].nome, "Aquavitae") == 0){
            tAquavitae = 1;
        }else if(strcmp(lista->minerais[i].nome, "Terranita") == 0){
            tTerranita = 1;
        }else{
            tCalaris = 1;
        } 
    }

    //definindo a categoria da rocha de acordo com os minerais que estão presentes na lista
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
