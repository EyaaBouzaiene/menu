/**
* @file coin.c
* @brief Testing Program.
* @author mariem
* @version 0.1
* @date may 01, 2020
*
* Testing program  init et affichage coin
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "coin.h"

/**
* @brief To initialize the coin c.
* @param c the coin
* @param position sur x et y
* @return Nothing
*/

void init_coin(coin *c,int x,int y)
{
	c->tab[0]=IMG_Load("coin/coin1.png");
	c->tab[1]=IMG_Load("coin/coin2.png");
	c->tab[2]=IMG_Load("coin/coin3.png");
	c->tab[3]=IMG_Load("coin/coin4.png");
	c->tab[4]=IMG_Load("coin/coin5.png");
	c->tab[5]=IMG_Load("coin/coin6.png");
	c->tab[6]=IMG_Load("coin/coin7.png");
	c->tab[7]=IMG_Load("coin/coin8.png");
	c->pos.x=x;
	c->pos.y=y;
        c->pos.w=41;
	c->pos.h=42;
	c->frame=0;
}
/********************************************************************************************************/
/********************************************************************************************************/
/**
* @brief To annimer coin c .
* @param c the coin
* @return Nothing
*/
void animer_coin(coin *c)
{
	//SDL_Delay(40);
	if(c->frame==7)
		c->frame=0;
	else
		c->frame++;
}
/**
* @brief To affichage coin c
* @param c the coin
* @param surface du screen
* @param position camera
* @return Nothing
*/
void afficher(coin c,SDL_Surface *screen,SDL_Rect camera)
{
	
		SDL_Rect pos;
                pos.x=c.pos.x-camera.x;
                pos.y=c.pos.y-camera.y;
		SDL_BlitSurface(c.tab[c.frame],NULL,screen,&pos);

}
