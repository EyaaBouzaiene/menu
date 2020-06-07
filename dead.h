
#ifndef DEAD_H_INCLUDED
#define DEAD_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


/**
* @struct Dead
* @brief struct for death
*/


typedef struct  Dead
{

	    SDL_Surface *image;/*!< surface*/
     
           
	    
} Dead;



void initialiser_dead(Dead *d);
void afficher_dead(SDL_Surface *screen,Dead d);






#endif
