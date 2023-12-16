#ifndef PECAS_BRANCAS_H
#define PECAS_BRANCAS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string.h>

using namespace std;

enum TipoPeca { PEAO, TORRE, CAVALO, BISPO, RAINHA, REI };

class PecasBrancas {
private:
    SDL_Texture* textura;
    int x, y;
    TipoPeca tipo;

public:
    PecasBrancas(); // Construtor sem parâmetros
    bool estaDentro(int x, int y, SDL_Renderer* renderer, int turno);
    void move_peca(int novoX, int novoY);
   // Getters
    SDL_Texture* getTextura() const;
    int getX() const;
    int getY() const;
    TipoPeca getTipo() const;

    // Setters
    void setTextura(SDL_Texture* novaTextura);
    void setX(int novoX);
    void setY(int novoY);
    void setTipo(TipoPeca novoTipo);

    // Método estático para criar todas as peças brancas
    static std::vector<PecasBrancas> criarPecasBrancas(SDL_Renderer* renderer);

};

#endif // PECAS_BRANCAS_H
