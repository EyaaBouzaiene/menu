
#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h> 
/**
* @struct score
* @brief struct for score
*/

typedef struct
{
    int total;/*!< entier*/
    char chaine[20];/*!< char*/
    SDL_Surface *texte;/*!< Surface*/
    SDL_Rect posScore;/*!< Rectangle*/
    TTF_Font *police;/*!< police*/
    SDL_Color couleurNoire;/*!< couleur*/
} score;



void init_score(score *sc);
void afficher_score(score sc,SDL_Surface *screen);








#endif
