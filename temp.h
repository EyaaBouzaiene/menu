#pragma once
#ifndef TEMP_H_INCLUDED
#define TEMP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

/**
* @struct Temps
* @brief struct for temp
*/
typedef struct Temps {
	SDL_Surface *msg;/*!< Surface*/
	TTF_Font *font;/*!< police*/
	int time;/*!< entier*/
	char timeString[10];/*!< char*/
       
} Temps;

void initializerTemps(Temps *time);
void afficherTemps(Temps *time,SDL_Surface *screen);


#endif
