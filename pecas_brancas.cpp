#include "PecasBrancas.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

PecasBrancas::PecasBrancas() {
    x = 0; 
    y= 0 ;
    tipo = PEAO; // Valor padrão, mas pode ser ajustado com setTipo()
    textura = nullptr; 
}

bool PecasBrancas::estaDentro(int x = -100, int y = -100, SDL_Renderer* renderer = NULL, int turno = -1) {
    if (x >= this->x && x <= (this->x + 100) && y >= this->y && y <= (this->y + 100) && turno == 1) {
        SDL_Rect rect;
        SDL_SetRenderDrawColor(renderer, 40, 185, 185, 0); // Azul para o quadrado clicado
        x = (x / 100) * 100;
        y = (y / 100) * 100;
        rect = { x, y, 100, 100 };
        SDL_RenderFillRect(renderer, &rect);
           
        return true;
    }
    else{
        return false;
    }
}

void PecasBrancas::move_peca(int novoX, int novoY) {
    if (tipo == PEAO) {
        int deltaY = y - novoY; // Diferença no eixo Y (considerando movimento de baixo para cima)
        int deltaX = abs(x - novoX); // Diferença absoluta no eixo X

        // Primeiro movimento: pode mover 2 casas para frente
        bool primeiroMovimento = (y == 600); // Supondo que a posição inicial dos peões seja y=600

        // Movimento padrão: 1 casa para frente
        bool movimentoPadrao = (deltaY == 100 && deltaX == 0);

        // Movimento de captura: 1 casa diagonal
        bool movimentoCaptura = (deltaY == 100 && deltaX == 100); // Supondo que você tem uma lógica para verificar se há uma peça para capturar

        if ((primeiroMovimento && deltaY <= 200) || movimentoPadrao || movimentoCaptura) {
            setX(novoX);
            setY(novoY);
        }
    }
}


SDL_Texture* PecasBrancas::getTextura() const {
    return textura;
}

int PecasBrancas::getX() const {
    return x;
}

TipoPeca PecasBrancas::getTipo() const {
    return tipo;
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

void PecasBrancas::setTipo(TipoPeca novoTipo) {
    tipo = novoTipo;
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


