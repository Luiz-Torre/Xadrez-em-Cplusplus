#include "PecasBrancas.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

PecasBrancas::PecasBrancas() {
    x; 
    y; 
    textura = nullptr; 
}

bool PecasBrancas::estaDentro(int x = -100, int y = -100) {
    if (x >= this->x && x <= (this->x + 100) && y >= this->y && y <= (this->y + 100)) {
        return true;
    } else {
        return false;
    }
}



SDL_Texture* PecasBrancas::getTextura() const {
    return textura;
}

int PecasBrancas::getX() const {
    return x;
}

int PecasBrancas::getY() const {
    return y;
}
void PecasBrancas::setTextura(SDL_Texture* novaTextura) {
    textura = novaTextura;
}

void PecasBrancas::setX(int novoX) {
    x = novoX;
}

void PecasBrancas::setY(int novoY) {
    y = novoY;
}

std::vector<PecasBrancas> PecasBrancas::criarPecasBrancas(SDL_Renderer* renderer) {
    std::vector<PecasBrancas> pecas;
    
    for(int i = 0; i < 16; i++){
        
        if(i == 0 || i == 7){
            PecasBrancas torre;
            torre.setX(i*100);
            torre.setY(700);
            torre.setTextura(IMG_LoadTexture(renderer, "./images/b_torre.png"));
            pecas.push_back(torre);

        }
        else if(i == 1 || i == 6){
            PecasBrancas cavalo;
            cavalo.setX(i*100);
            cavalo.setY(700);
            cavalo.setTextura(IMG_LoadTexture(renderer, "./images/b_cavalo.png"));
            pecas.push_back(cavalo);

            }
        else if(i == 2 || i == 5){
            PecasBrancas bispo;
            bispo.setX(i*100);
            bispo.setY(700);
            bispo.setTextura(IMG_LoadTexture(renderer, "./images/b_bispo.png"));
            pecas.push_back(bispo);

            }
        else if(i == 3){
            PecasBrancas rainha;
            rainha.setX(i*100);
            rainha.setY(700);
            rainha.setTextura(IMG_LoadTexture(renderer, "./images/b_rainha.png"));
            pecas.push_back(rainha);
            }
        else if(i == 4){
            PecasBrancas rei;
            rei.setX(i*100);
            rei.setY(700);
            rei.setTextura(IMG_LoadTexture(renderer, "./images/b_rei.png"));
            pecas.push_back(rei);
            }

        else{
            PecasBrancas peao;
            peao.setX((i-8)*100);
            peao.setY(600);
            peao.setTextura(IMG_LoadTexture(renderer, "./images/b_peao.png"));
            pecas.push_back(peao);
            }

        }

        return pecas;

    }


