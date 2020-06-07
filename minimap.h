#ifndef MINIMAPP_H_INCLUDED
#define MINIMAPP_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "bg.h"
/**
* @struct minimap
* @brief struct for minimap
*/

typedef struct  minimap
{

	    SDL_Surface *background,*cadre;/*!< Surface*/
	    SDL_Rect camera;/*!< Rectangle*/
	    SDL_Rect posbg;/*!< Rectangle*/
}minimap;
/**
* @struct point
* @brief struct for point
*/
typedef struct  point
{

	    SDL_Surface *point;/*!< Surface*/
	    SDL_Rect pospnt;/*!< Rectangle*/
}point;

void initialiser_minimap(SDL_Rect camera,minimap *m);
void afficher_minimap(SDL_Surface *screen,minimap *m,point pt);
void scroll_mini(SDL_Event e,SDL_Rect *b);
void init_point(point *pt, SDL_Rect b);
void mouv_point(point *pt,SDL_Rect p);

//endif // MINIMAP_H_INCLUDED


#endif // MINIMAPP_H_INCLUDED
