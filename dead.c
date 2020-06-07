/**
* @file dead.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program affichage dead
*
*/
#include "dead.h"
#include <stdio.h>
#include <SDL/SDL_rotozoom.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
/**
* @brief To initialiser dead
* @param d Dead
* @return nothing
*/
void initialiser_dead(Dead *d)
{
    d->image=NULL;
    d->image=IMG_Load("bg/dead.png");
}
/**
* @brief To affichage dead
* @param d Dead
* @return nothing
*/
void afficher_dead (SDL_Surface *screen,Dead d)
{

    SDL_BlitSurface(d.image,NULL,screen,NULL);
    SDL_Flip(screen);
}

