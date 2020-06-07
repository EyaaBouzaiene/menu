#ifndef BG_H_INCLUDED
#define BG_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
/**
* @struct Background
* @brief struct for backround
*/
typedef struct  background

{
    SDL_Surface *background;/*!< surface*/

    SDL_Surface *background_tile;/*!< surface*/

    SDL_Rect posbg;/*!< Rectangle*/

} background;



void initialiser_backround (background *b);

void afficher_background (SDL_Surface *screen,background b,SDL_Rect camera);

#endif // BG_H_INCLUDED
