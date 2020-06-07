/**
* @file  vie.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program affichage vie
*
*/
#include "vie.h"
/**
* @brief To initialiser vie
* @param v vie
* @return nothing
*/

void init_vie(vie *v)
{
    v->nbrVie=3;
    v->heart=IMG_Load("vie/heart.png");
    v->posVie.x=1045;
    v->posVie.y=7;
}
/**
* @brief To afficher vie
* @param v vie
* @param surface screen
* @return nothing
*/
void afficher_vie(vie v,SDL_Surface *screen)
{
    for (int i = 0; i < v.nbrVie; ++i)
    {
        SDL_BlitSurface(v.heart, NULL,screen,&v.posVie);
        v.posVie.x+=53;

    }


}
