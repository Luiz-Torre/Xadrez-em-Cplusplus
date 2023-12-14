#include "PecasBrancas.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

PecasBrancas::PecasBrancas() {
    id; 
    x; 
    y; 
    textura = nullptr; 
}

int PecasBrancas::getId() const {
    return id;
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
void PecasBrancas::setId(int novoId) {
    id = novoId;
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
    int id = 0;
    
    for(int i = 0; i < 16; i++){
        
        if(id == 0 || id == 7){
            PecasBrancas torre;
            torre.setId(id);
            torre.setX(id*100);
            torre.setY(700);
            torre.setTextura(IMG_LoadTexture(renderer, "./images/b_torre.png"));
            pecas.push_back(torre);

        }
        else if(id == 1 || id == 6){
            PecasBrancas cavalo;
            cavalo.setId(id);
            cavalo.setX(id*100);
            cavalo.setY(700);
            cavalo.setTextura(IMG_LoadTexture(renderer, "./images/b_cavalo.png"));
            pecas.push_back(cavalo);

            }
        else if(id == 2 || id == 5){
            PecasBrancas bispo;
            bispo.setId(id);
            bispo.setX(id*100);
            bispo.setY(700);
            bispo.setTextura(IMG_LoadTexture(renderer, "./images/b_bispo.png"));
            pecas.push_back(bispo);

            }
        else if(id == 3){
            PecasBrancas rainha;
            rainha.setId(id);
            rainha.setX(id*100);
            rainha.setY(700);
            rainha.setTextura(IMG_LoadTexture(renderer, "./images/b_rainha.png"));
            pecas.push_back(rainha);
            }
        else if(id == 4){
            PecasBrancas rei;
            rei.setId(id);
            rei.setX(id*100);
            rei.setY(700);
            rei.setTextura(IMG_LoadTexture(renderer, "./images/b_rei.png"));
            pecas.push_back(rei);
            }

        else{
            PecasBrancas peao;
            peao.setId(id);
            peao.setX((id-8)*100);
            peao.setY(600);
            peao.setTextura(IMG_LoadTexture(renderer, "./images/b_peao.png"));
            pecas.push_back(peao);
            }
        id++;

        }

        return pecas;

    }
