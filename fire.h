#ifndef FIRE_H_INCLUDED
#define FIRE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
/**
* @struct fire
* @brief struct for fire
*/
typedef struct  fire
{

	    SDL_Surface *image;/*!< Surface*/
            int frame;/*!< entier*/
	    SDL_Rect pos;/*!< Rectangle*/
            SDL_Rect rects[8];/*!< Rectangle*/
	    
}fire;

void animation_fire (fire *f);
void setrects_fire(SDL_Rect* clip);
void init_fire(fire *f,int x, int y);
void afficher_fire (fire f,SDL_Surface *screen,SDL_Rect camera);

#endif // FIRE_H_INCLUDED
