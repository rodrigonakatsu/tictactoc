#include <stdio.h>
#include <stdlib.h>
#define CELULA_X 1 
#define CELULA_Y 2
#define CELULA_NADA 0 

typedef struct tabuleiro{
  int dados[9];
}t_tabuleiro;

t_tabuleiro cria_tabuleiro(){
    int i;
    t_tabuleiro tab;
    for(i = 0; i< 9; i++){
        tab.dados[i] = CELULA_NADA;
    }
    return tab;
}

void mostrar_tabuleiro(t_tabuleiro tab){
    int i;
    for(i=0; i <=2; i++){
        int dado = tab.dados[i];
        if(dado == CELULA_X){
            printf("X");
        }
        if(dado == CELULA_Y){
            printf("O");
        }
        if(dado == CELULA_NADA){
            printf("_");
        }
        
    }

    printf("\n");

    for(i=3; i <=5; i++){
        int dado = tab.dados[i];
        if(dado == CELULA_X){
            printf("X");
        }
        if(dado == CELULA_Y){
            printf("O");
        }
        if(dado == CELULA_NADA){
            printf("_");
        }
    }

    printf("\n");

    for(i=6; i <=8; i++){
        int dado = tab.dados[i];
        if(dado == CELULA_X){
            printf("X");
        }
        if(dado == CELULA_Y){
            printf("O");
        }
        if(dado == CELULA_NADA){
            printf("_");
        }

    }
    printf("\n");
}

void jogada_jogador(t_tabuleiro * tab){
    int posicao;
    while(1){
        printf("\nEscolha a posicao de 0 a 8: ");
        scanf("%d", &posicao);
        if(posicao >= 9 || tab->dados[posicao] != CELULA_NADA ){
            printf("Posicao invalida selecione outra posicao");  
        }
        else 
        {
            printf("Sua opcao foi colocada!\n");  
            tab->dados[posicao] = CELULA_X;
            break;
        }

    }
}

void jogada_computador(t_tabuleiro * tab){
    int posicao;
    int r = rand() % 9;

    while(1){
        if(tab->dados[r] == CELULA_NADA){
            tab->dados[r] = CELULA_Y;
            break;
        }else
        {
            r = rand() % 9;
        }
    }
}

int verifica_ganhou_para(t_tabuleiro tab, int i){

    if(tab.dados[0] == i && tab.dados[1] == i &&tab.dados[2] == i ){
        return 1;
    }
    if(tab.dados[3] == i && tab.dados[4] == i &&tab.dados[5] == i ){
        return 1;
    }
    if(tab.dados[6] == i && tab.dados[7] == i &&tab.dados[8] == i ){
        return 1;
    }
    if(tab.dados[0] == i && tab.dados[4] == i &&tab.dados[8] == i ){
        return 1;
    }
    if(tab.dados[2] == i && tab.dados[4] == i &&tab.dados[6] == i ){
        return 1;
    }
    if(tab.dados[0] == i && tab.dados[3] == i &&tab.dados[6] == i ){
        return 1;
    }
    if(tab.dados[1] == i && tab.dados[4] == i &&tab.dados[7] == i ){
        return 1;
    }
    if(tab.dados[2] == i && tab.dados[5] == i &&tab.dados[8] == i ){
        return 1;
    }

    return 0;
}

int verifica_velha(t_tabuleiro tab){
    int i;
    for(i = 0;i<9; i++){
        if(tab.dados[i] == CELULA_NADA){
            return 0;
        }
    }
    return 1;
}

int verifica_acabou(t_tabuleiro tab){
    if(verifica_ganhou_para(tab, CELULA_X)){
        printf("parabens ganhou do bot no rng");//kkkkj
        return 1;
    }
    else if(verifica_ganhou_para(tab, CELULA_Y)){
        printf("parabens perdeu do bot no rng");//kkkkjsoftint
        return 1;
    }
    else{
        if(verifica_velha(tab)){
            printf("todo mundo perdeu");//kkkkjsoftint
            return 1;
        }
    }
    return 0;
}


int main(void) {
    t_tabuleiro tab;
    tab = cria_tabuleiro();
    srand(time(NULL));
    mostrar_tabuleiro(tab);
    while(1){
        jogada_jogador(&tab);
        mostrar_tabuleiro(tab);
        if(verifica_acabou(tab)){
            break;
        }
        printf("\n================\n");
        jogada_computador(&tab);
        mostrar_tabuleiro(tab);
        if(verifica_acabou(tab)){
            break;
        }
    }
    return 0;
}