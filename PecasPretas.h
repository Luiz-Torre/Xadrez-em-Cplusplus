#ifndef PECAS_PRETAS_H
#define PECAS_PRETAS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class PecasPretas {
private:
    int id;
    SDL_Texture* textura;
    int x, y;

public:
    PecasPretas(); // Construtor sem parâmetros

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
    
    static std::vector<PecasPretas> criarPecasPretas(SDL_Renderer* renderer);
};

#endif // PECAS_PRETAS_H
