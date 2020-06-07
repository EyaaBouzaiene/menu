/**
* @file bg.c
* @brief Testing Program.
* @author mariem
* @version 0.1
* @date may 01, 2020
*
* Testing program for init et affichage background
*
*/


#include "bg.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
/**
* @brief To initialize the background b .
* @param b the background
* @return Nothing
*/
void initialiser_backround(background *b)

{
    b->background=NULL;

    b->background=IMG_Load("bg/20.png");

    b->background_tile=NULL;

    b->background_tile=IMG_Load("bg/masque.jpg");
}
/**
* @brief To affichage the background b .
* @param b the background
* @param screen surface
* @param position camera
* @return Nothing
*/
void afficher_background (SDL_Surface *screen,background b,SDL_Rect camera)

{

    SDL_BlitSurface(b.background,&camera,screen,NULL);

}


