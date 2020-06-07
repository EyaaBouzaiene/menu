/**
* @file personnage.c
* @brief Testing Program.
* @author mayssa
* @version 0.1
* @date may 01, 2020
*
* Testing program personnage
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "personnage.h"
#include "vie.h"
#include"time.h"


int nb_frames_p=15;


/**
* @brief To initialiser personnage
* @param p personnage
* @return nothing
*/

void initialiser_perssonage (perssonage *p)
{
    p->onground=1;  //position  initiale
    p->vitesse.x=0;
    p->vitesse.y=0;
    p->perssonage=IMG_Load("perso/dante-run.png");

    p->frame=1;
    p->stable_direction=0;
    p->posperso.x=10;
    p->posperso.y=348;
    p->posperso.w=100;
    p->posperso.h=100;
    init_vie(&p->Vie);
    init_score(&p->Score);
    setrects (p->rects);
}

/**
* @brief To afficher personnage
* @param p personnage
* @param surface screen
* @param position camera
* @return nothing
*/


void afficher_perssonage (perssonage p,SDL_Surface *screen,SDL_Rect camera)
{
    SDL_Rect pos;

    pos.x=p.posperso.x-camera.x;
    pos.y=p.posperso.y-camera.y;
    SDL_BlitSurface(p.perssonage,&p.rects[p.frame],screen,&pos);
    // SDL_Flip(screen);
}


/**
* @brief To animation right 
* @param p personnage
* @return nothing
*/
void animation_right (perssonage *p)
{


    p->stable_direction=0;
    if(p->frame<=0 || p->frame>=15)
        p->frame=0;
    p->frame++;
    if (p->frame>=nb_frames_p)
        p->frame=0;
}

/**
* @brief To animation left
* @param p personnage
* @return nothing
*/


void animation_left (perssonage *p)
{


    p->stable_direction=1;
    if(p->frame<=14 || p->frame>=30)
        p->frame=15;

    p->frame++;
    if (p->frame>=2*nb_frames_p)
        p->frame=16;
}

/**
* @brief To jump 
* @param p personnage
* @return nothing
*/

void animation_jump (perssonage *p)
{
    p->stable_direction=0;
    if(p->frame<=0 || p->frame>=15)
        p->frame=0;
    p->frame++;
    if (p->frame>=nb_frames_p)
        p->frame=0;


}
/**
* @brief To stable 
* @param p personnage
* @return nothing
*/
void animation_stable (perssonage *p)
{

    if (p->stable_direction==0)
    {
        if(p->frame<=29 || p->frame>=45)
            p->frame=30;

        p->frame++;
        if (p->frame>=3*nb_frames_p)
            p->frame=30;
    }

    else if (p->stable_direction==1)
    {
        if(p->frame<=44 || p->frame>=60)
            p->frame=45;

        p->frame++;
        if (p->frame>=4*nb_frames_p)
            p->frame=45;
    }

}
/**
* @brief To position personnage
* @param p personnage
* @return nothing
*/
void setrects(SDL_Rect* clip)
{


    //vers droite
    clip[0].x=0;
    clip[0].y=0;
    clip[0].w=100;
    clip[0].h=100;
    int i;
    for (i=1; i<nb_frames_p; i++)
    {
        clip[i].w=100;
        clip[i].h=100;
        clip[i].x=clip[i].w+clip[i-1].x;
        clip[i].y=0;
    }

//vers gauche
    clip[15].x=0;
    clip[15].y=100;
    clip[15].w=100;
    clip[15].h=100;
    i=16;
    for (i=16; i<(2*nb_frames_p); i++)
    {
        clip[i].w=100;
        clip[i].x=clip[i-1].x+clip[i].w;
        clip[i].y=100;
        clip[i].h=100;
    }
//stable right
    clip[30].x=0;
    clip[30].y=200;
    clip[30].w=100;
    clip[30].h=100;
    i=31;
    for (i=31; i<(3*nb_frames_p); i++)
    {
        clip[i].w=100;
        clip[i].x=clip[i-1].x+clip[i].w;
        clip[i].y=200;
        clip[i].h=100;
    }


//stable left
    clip[45].x=0;
    clip[45].y=300;
    clip[45].w=100;
    clip[45].h=100;
    i=46;
    for (i=46; i<(4*nb_frames_p); i++)
    {
        clip[i].w=100;
        clip[i].x=clip[i-1].x+clip[i].w;
        clip[i].y=300;
        clip[i].h=100;
    }

}
/**
* @brief To mouvement right 
* @param p personnage
* @param int stratticks
* @return nothing
*/
void mouvementright (perssonage *p,int *startTicks)
{
    int tempsActuel;
    tempsActuel=SDL_GetTicks();
    if(tempsActuel- *startTicks>=300)
    {
        *startTicks=tempsActuel;
        p->vitesse.x+=1;
    }
    if(p->vitesse.x>=20)
    {
        p->vitesse.x=20;
    }
    if(p->onground==0)
    {
        p->posperso.x+=p->vitesse.x;
        p->posperso.y+=p->vitesse.y;
    }
    else
    {
        p->posperso.x+=p->vitesse.x;
    }


}
/**
* @brief To mouvement left
* @param p personnage
* @param int stratticks
* @return nothing
*/
void mouvementleft (perssonage *p,int *startTicks)
{
    int tempsActuel;
    tempsActuel=SDL_GetTicks();
    if(tempsActuel- *startTicks>=300)
    {
        *startTicks=tempsActuel;
        p->vitesse.x-=1;
    }
    if(p->vitesse.x<=-20)
    {
        p->vitesse.x=-20;
    }
    if(p->onground==0)
    {
        p->posperso.x+=p->vitesse.x;
        p->posperso.y+=p->vitesse.y;
    }
    else
    {
        p->posperso.x+=p->vitesse.x;
    }



}
/**
* @brief To mouvement down
* @param p personnage
* @return nothing
*/
void mouvementdown (perssonage *p)
{
    p->posperso.y+=p->vitesse.y;

}

/**
* @brief To mouvement jump 
* @param p personnage
* @return nothing
*/


void mouvementjump (perssonage *p)
{

    p->posperso.y+=p->vitesse.y;

}


                     
