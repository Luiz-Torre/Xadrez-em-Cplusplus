#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "PecasBrancas.h"
#include "PecasPretas.h"
#include <iostream>

using namespace std;


vector<PecasBrancas> pecasBrancas;
vector<PecasPretas> pecasPretas;
int MOUSEX = -1;
int MOUSEY = -1;

SDL_Window* WINDOW = SDL_CreateWindow("Tabuleiro de Xadrez", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);
SDL_Renderer* RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_ACCELERATED);
int TAM_PECA = 100;
int TURNO = 1;
PecasBrancas* pecaSelecionadaBranca = nullptr;
PecasPretas* pecaSelecionadaPreta = nullptr;
bool pecaEstaSelecionada = false;
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    
    pecasBrancas = PecasBrancas::criarPecasBrancas(RENDERER);
    pecasPretas = PecasPretas::criarPecasPretas(RENDERER);

    bool running = true;
    SDL_Event event;

    while (running) {
        SDL_Event e;

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {

                if (e.button.button == SDL_BUTTON_LEFT) {
                    SDL_GetMouseState(&MOUSEX, &MOUSEY);

                    if (!pecaEstaSelecionada) {
                        for (auto& peca : pecasBrancas) {
                            if (peca.estaDentro(MOUSEX, MOUSEY, RENDERER, TURNO)) {
                                pecaSelecionadaBranca = &peca;
                                pecaEstaSelecionada = true;
                                break;
                            }
                        }
                    }

                     if (pecaEstaSelecionada) {
                        int novoX = (MOUSEX / 100) * 100;
                        int novoY = (MOUSEY / 100) * 100;
                        printf("Oiii");
                        if (pecaSelecionadaBranca != nullptr) {
                            pecaSelecionadaBranca->move_peca(novoX, novoY); // Chamada para mover a peça
                            pecaSelecionadaBranca = nullptr; // Reset da peça selecionada
                        }

                        pecaEstaSelecionada = false; // Reset do estado de seleção
                    }

                }
            }
           
        }

        SDL_SetRenderDrawColor(RENDERER, 255, 255, 255, 255);
        SDL_RenderClear(RENDERER);

        // Desenhar o tabuleiro
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                SDL_Rect rect;

                if ((i + j) % 2 == 0) {
                    SDL_SetRenderDrawColor(RENDERER, 255, 255, 255, 255); // Branco
                    rect = { i * 100, j * 100, 100, 100 };
                } else {
                    SDL_SetRenderDrawColor(RENDERER, 180, 180, 180, 255); // Preto
                    rect = { i * 100, j * 100, 100, 100 };
                }
                SDL_RenderFillRect(RENDERER, &rect);
            }
        }

        // Adicionar peças brancas
        for (auto& peca : pecasBrancas) {
            peca.estaDentro(MOUSEX, MOUSEY, RENDERER, TURNO);
            SDL_Rect pieceRect = { peca.getX(), peca.getY(), TAM_PECA, TAM_PECA }; // Posição e tamanho
            SDL_RenderCopy(RENDERER, peca.getTextura(), NULL, &pieceRect);
            


        }
        for(auto& peca : pecasPretas){
            peca.estaDentro(MOUSEX, MOUSEY, RENDERER, TURNO);
            SDL_Rect pieceRect = { peca.getX(), peca.getY(), TAM_PECA, TAM_PECA }; // Posição e tamanho
            SDL_RenderCopy(RENDERER, peca.getTextura(), NULL, &pieceRect);
        }

        SDL_RenderPresent(RENDERER);
    }

    IMG_Quit();
    SDL_DestroyRenderer(RENDERER);
    SDL_DestroyWindow(WINDOW);
    SDL_Quit();

    return 0;
}
