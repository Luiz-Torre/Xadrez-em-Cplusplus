#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "PecasBrancas.h"
#include "PecasPretas.h"
#include <iostream>

using namespace std;


vector<PecasBrancas> pecasBrancas;
vector<PecasPretas> pecasPretas;

SDL_Window* window = SDL_CreateWindow("Tabuleiro de Xadrez", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
int tam_peca = 100;
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    
    pecasBrancas = PecasBrancas::criarPecasBrancas(renderer);
    pecasPretas = PecasPretas::criarPecasPretas(renderer);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Desenhar o tabuleiro
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((i + j) % 2 == 0) {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Branco
                } else {
                    SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255); // Preto
                }
                SDL_Rect rect = { i * 100, j * 100, 100, 100 };
                SDL_RenderFillRect(renderer, &rect);
            }
        }

        // Adicionar peças brancas
        for (const auto& peca : pecasBrancas) {
                SDL_Rect pieceRect = { peca.getX(), peca.getY(), tam_peca, tam_peca }; // Posição e tamanho
                SDL_RenderCopy(renderer, peca.getTextura(), NULL, &pieceRect);
        }

        for(const auto& peca : pecasPretas){
            SDL_Rect pieceRect = { peca.getX(), peca.getY(), tam_peca, tam_peca }; // Posição e tamanho
            SDL_RenderCopy(renderer, peca.getTextura(), NULL, &pieceRect);
        }

        SDL_RenderPresent(renderer);
    }

    //SDL_DestroyTexture(pieceTexture);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
