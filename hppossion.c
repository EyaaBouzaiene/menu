/**
* @file hp.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program health portion
*
*/
#include "hppossion.h"
/**
* @brief To initialiser health potion 
* @param h hpp
* @param int x
* @param int y
* @return nothing
*/
void init_hpp(hpp *h,int x, int y)
{
    int i;
    char ch[50];
    for (i=0; i<41; i++)
    {
        sprintf(ch,"health/%d.png",i);
        h->tab[i]=IMG_Load(ch);
    }

    h->pos.x=x;
    h->pos.y=y;
    h->frame=0;
}

/**
* @brief To annimer health potion 
* @param h hpp
* @return nothing
*/
void animer_hpp(hpp *h)
{
    if(h->frame==40)
        h->frame=0;
    else
        h->frame++;
}

/**
* @brief To affichage health potion 
* @param h hpp
* @param position camera
* @param surface screen
* @return nothing
*/
void afficher_hpp(SDL_Surface *screen,hpp h,SDL_Rect camera)
{
    SDL_Rect pos;
    pos.x=h.pos.x-camera.x;
    pos.y=h.pos.y-camera.y;

    SDL_BlitSurface(h.tab[h.frame],NULL,screen,&pos);
}


