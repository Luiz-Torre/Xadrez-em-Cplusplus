#include "PecasPretas.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

PecasPretas::PecasPretas() {
    x = 0; 
    y= 0 ; 
    textura = nullptr; 
}
void PecasPretas::estaDentro(int x = -100, int y = -100, SDL_Renderer* renderer = NULL, int turno = -1) {
    if (x >= this->x && x <= (this->x + 100) && y >= this->y && y <= (this->y + 100) && turno == 2) {
        SDL_Rect rect;
        SDL_SetRenderDrawColor(renderer, 40, 185, 185, 0); // Azul para o quadrado clicado
        x = (x / 100) * 100;
        y = (y / 100) * 100;
        rect = { x, y, 100, 100 };
        SDL_RenderFillRect(renderer, &rect);
    }
}

int PecasPretas::getId() const {
    return id;
}

SDL_Texture* PecasPretas::getTextura() const {
    return textura;
}

int PecasPretas::getX() const {
    return x;
}

int PecasPretas::getY() const {
    return y;
}
void PecasPretas::setId(int novoId) {
    id = novoId;
}

void PecasPretas::setTextura(SDL_Texture* novaTextura) {
    textura = novaTextura;
}

void PecasPretas::setX(int novoX) {
    x = novoX;
}

void PecasPretas::setY(int novoY) {
    y = novoY;
}

std::vector<PecasPretas> PecasPretas::criarPecasPretas(SDL_Renderer* renderer) {
    std::vector<PecasPretas> pecas;
    int id = 16;
    
    for(int i = 16; i < 32; i++){
        
        if(id == 16 || id == 23){
            PecasPretas torre;
            torre.setId(id);
            torre.setX((id-16)*100);
            torre.setY(0);
            torre.setTextura(IMG_LoadTexture(renderer, "./images/p_torre.png"));
            pecas.push_back(torre);

        }
        else if(id == 17 || id == 22){
            PecasPretas cavalo;
            cavalo.setId(id);
            cavalo.setX((id-16)*100);
            cavalo.setY(0);
            cavalo.setTextura(IMG_LoadTexture(renderer, "./images/p_cavalo.png"));
            pecas.push_back(cavalo);

            }
        else if(id == 18 || id == 21){
            PecasPretas bispo;
            bispo.setId(id);
            bispo.setX((id-16)*100);
            bispo.setY(0);
            bispo.setTextura(IMG_LoadTexture(renderer, "./images/p_bispo.png"));
            pecas.push_back(bispo);

            }
        else if(id == 19){
            PecasPretas rainha;
            rainha.setId(id);
            rainha.setX((id-16)*100);
            rainha.setY(0);
            rainha.setTextura(IMG_LoadTexture(renderer, "./images/p_rainha.png"));
            pecas.push_back(rainha);
            }
        else if(id == 20){
            PecasPretas rei;
            rei.setId(id);
            rei.setX((id-16)*100);
            rei.setY(0);
            rei.setTextura(IMG_LoadTexture(renderer, "./images/p_rei.png"));
            pecas.push_back(rei);
            }

        else{
            PecasPretas peao;
            peao.setId(id);
            peao.setX((id-24)*100);
            peao.setY(100);
            peao.setTextura(IMG_LoadTexture(renderer, "./images/p_peao.png"));
            pecas.push_back(peao);
            }
        id++;

        }

        return pecas;

    }
