/**
* @file fire.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program affichage fire
*
*/

#include "bg.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include "fire.h"
//3orth 68
//toul 58
/**
* @brief To initialiser fire
* @param int x
* @param int y
* @return nothing
*/
void init_fire(fire *f,int x, int y)
{

    f->image=IMG_Load("fire/fire.png");
    f->pos.x=x;
    f->pos.y=y;
    f->pos.w=68;
    f->pos.h=58;
    f->frame=0;
    setrects_fire(f->rects);
}

/**
* @brief To position fire
* @param position clip
* @return nothing
*/
void setrects_fire(SDL_Rect* clip)
{

    clip[0].x=0;
    clip[0].y=0;
    clip[0].w=68;
    clip[0].h=58;
    int i;
    for (i=1; i<8; i++)
    {
        clip[i].w=68;
        clip[i].x=clip[i-1].x+clip[i].w;
        clip[i].y=0;
        clip[i].h=58;
    }


}
/**
* @brief To afficher fire
* @param f fire
* @param surface screen
* @param position camera
* @return nothing
*/
void afficher_fire (fire f,SDL_Surface *screen,SDL_Rect camera)
{

    SDL_Rect pos;
    pos.x=f.pos.x-camera.x;
    pos.y=f.pos.y-camera.y;
    SDL_BlitSurface(f.image,&f.rects[f.frame],screen,&pos);
}
/**
* @brief To animation fire
* @param f fire
* @return nothing
*/
void animation_fire (fire *f)
{

    f->frame++;
    if (f->frame>=8)
        f->frame=0;
}

