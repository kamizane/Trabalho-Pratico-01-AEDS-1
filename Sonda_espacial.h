#ifndef SONDA_ESPACIAL_H
#define SONDA_ESPACIAL_H

typedef struct{
    char Latitude[20];
    char Longitude[20];
}Localizacao;

typedef enum{
    ON = 0,
    OFF = 1
}EstaLigada;


typedef struct {
    char Identificador[20];
    Compartimento Compartimento;
    Localizacao Localizacao;
    EstaLigada EstaLigada;
}Sonda_espacial;

void inicializa_Sonda_Espacial(Sonda_espacial * sonda, char * id, char *latitude,char * longitude);
void preenche_Sonda_Espacial(Sonda_espacial * sonda);
int liga_Sonda_Espacial(Sonda_espacial * sonda);
int desliga_Sonda_Espacial(Sonda_espacial * sonda);
void move_Sonda_Espacial (Sonda_espacial * sonda);
void set_Identificador(Sonda_espacial*sonda, char * id);
void set_Compartimento(Sonda_espacial*sonda,float Compartimento);
void set_Localizacao(Sonda_espacial * sonda, char * latitude, char*longitude);
void set_EstaLigada(Sonda_espacial *sonda, EstaLigada estado);


#endif