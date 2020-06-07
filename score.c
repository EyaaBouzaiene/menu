/**
* @file score.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program affichage score
*
*/
#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h> 
#include "score.h"
/**
* @brief To initialiser score
* @param sc score
* @return nothing
*/
void init_score(score *sc)
{

    sc->total=0;
    sc->texte= NULL;
    sc->police= NULL;
    sc->couleurNoire.r=0;
    sc->couleurNoire.g=0;
    sc->couleurNoire.b=0;
    sc->posScore.x=500;
    sc->posScore.y=7;
    sc->police=TTF_OpenFont("font/font.ttf", 65);
    sprintf (sc->chaine,"[%d]",sc->total);
    sc->texte=TTF_RenderText_Blended(sc->police,sc->chaine,sc->couleurNoire);

}
/**
* @brief To affichage score
* @param sc score
* @param surface screen
* @return nothing
*/
void afficher_score(score sc,SDL_Surface *screen)
{
    sprintf (sc.chaine,"[%d]",sc.total);
    sc.texte=TTF_RenderText_Blended(sc.police,sc.chaine,sc.couleurNoire);
    SDL_BlitSurface(sc.texte,NULL,screen,&sc.posScore);
}

