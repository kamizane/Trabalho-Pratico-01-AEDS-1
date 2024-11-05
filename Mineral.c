#include <stdio.h>
#include <string.h>
#include "Mineral.h"

Inicializa(Mineral * mineral, char nome[], char cor[], float dureza, float reatividade){
    set_nome(&mineral, nome);
    set_cor(&mineral, cor);
    set_dureza(&mineral, dureza);
    set_reatividade(&mineral, reatividade);
    
}




get_nome(Mineral * mineral){
    return mineral->nome;
}


get_cor(Mineral * mineral){
    return mineral->cor;
}


get_dureza(Mineral * mineral){
    return mineral->dureza;
}


get_reatividade(Mineral * mineral){
    return mineral->reatividade;
}



set_nome(Mineral * mineral, char nome[]){


}


set_cor(Mineral * mineral, char cor[]){


}


set_dureza(Mineral * mineral, float dureza){


}


set_reatividade(Mineral * mineral, float reatividade){


}



