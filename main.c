#include <stdio.h>
#include <string.h>
#include "Sonda_espacial.h"
#include "Lista_sonda_espacial.h"

int main(int argc,char **argv){
    if(strcmp(argv[1],"-f")==0){
        FILE *file = file = fopen(argv[2],"r");
        Lista_sonda_espacial lista_de_sondas;
        do{
            char ch = getc(file);
            int numero_sondas = (ch - '0');

            for (int i=0; i<numero_sondas; i++){
                char id =(char)i;
                Sonda_espacial sonda;
                float lat_i,long_i,c_i,v_i,nc_i;
                fscanf(file, "%f %f %f %f %f", &lat_i,&long_i,&c_i,&v_i,&nc_i);
                inicializa_Sonda_Espacial(&sonda, &id, &lat_i,&long_i,c_i,v_i,nc_i);
                insere_item_lista_sonda_espacial(&lista_de_sondas,&sonda);
                imprime_lista_sonda_espacial(&sonda);
                
            }
        }
        while(!feof(file));
    
    }
    else{
            
    }
}