#ifndef VIE_H_INCLUDED
#define VIE_H_INCLUDED
#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h> 
/**
* @struct vie
* @brief struct for vie
*/
typedef struct
{
    int nbrVie;/*!< entier*/
    SDL_Surface * heart;/*!< Surface*/
    SDL_Rect posVie;/*!< Rectangle*/
} vie;



void init_vie(vie *v);
void afficher_vie(vie v,SDL_Surface *screen);








#endif
