#ifndef HPPOSSION_H_INCLUDED
#define HPPOSSION_H_INCLUDED
#include "bg.h"
/**
* @struct hpp
* @brief struct for healthposion
*/
typedef struct  hpp
{
	SDL_Surface *tab[41];/*!< Surface*/
	SDL_Rect pos;/*!< Rectangle*/
	int frame;/*!< entier*/
	
}hpp;
void init_hpp(hpp *h,int x, int y);
void animer_hpp(hpp *h);
void afficher_hpp(SDL_Surface *screen,hpp h,SDL_Rect camera);
#endif // HPPOSSION_H_INCLUDED
