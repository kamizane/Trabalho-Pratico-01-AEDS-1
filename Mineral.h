
#ifndef MINERAL_H
#define MINERAL_H



typedef struct Mineral {
    char nome[20];
    char cor[20];
    float dureza;
    float reatividade;
} Mineral;

void atribui_mineral(Mineral * mineral, char nome_mineral[]);

void cria_catalogo_minerais(Mineral minerais[5]);

int inicializa_mineral(Mineral * mineral, char * nome, char * cor, float dureza, float reatividade);

int preenche_mineral(Mineral * mineral);

char * get_nome(Mineral * mineral);
char * get_cor(Mineral * mineral);
float get_dureza(Mineral * mineral);
float get_reatividade(Mineral * mineral);


void set_nome(Mineral * mineral, char * nome);
void set_cor(Mineral * mineral, char * cor);
void set_dureza(Mineral * mineral, float dureza);
void set_reatividade(Mineral * mineral, float reatividade);

#endif