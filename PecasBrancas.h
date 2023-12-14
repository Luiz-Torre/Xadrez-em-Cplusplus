#ifndef PECAS_BRANCAS_H
#define PECAS_BRANCAS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class PecasBrancas {
private:
    int id;
    SDL_Texture* textura;
    int x, y;

public:
    PecasBrancas(); // Construtor sem parâmetros

   // Getters
    int getId() const;
    SDL_Texture* getTextura() const;
    int getX() const;
    int getY() const;

    // Setters
    void setId(int novoId);
    void setTextura(SDL_Texture* novaTextura);
    void setX(int novoX);
    void setY(int novoY);
    
    // Método estático para criar todas as peças brancas
    static std::vector<PecasBrancas> criarPecasBrancas(SDL_Renderer* renderer);
};

#endif // PECAS_BRANCAS_H
