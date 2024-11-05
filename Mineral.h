
#ifndef MINERAL_H
#define MINERAL_H



typedef struct Mineral {
    char nome[20];
    char cor[20];
    float dureza;
    float reatividade;
} Mineral;


Inicializa(Mineral * mineral, char nome[], char cor[], float dureza, float reatividade);


get_nome(Mineral * mineral);
get_cor(Mineral * mineral);
get_dureza(Mineral * mineral);
get_reatividade(Mineral * mineral);


set_nome(Mineral * mineral, char nome[]);
set_cor(Mineral * mineral, char cor[]);
set_dureza(Mineral * mineral, float dureza);
set_reatividade(Mineral * mineral, float reatividade);

#endif