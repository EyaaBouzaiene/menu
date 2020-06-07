#ifndef enigme_H_INCLUDED
#define enigme_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


void reponse(SDL_Surface *screen,int d);
void solution(SDL_Surface *screen,int d);
void question(SDL_Surface *screen,int d);
void good(SDL_Surface *screen);
void work(SDL_Surface *screen,int d);

#endif // screen_H_INCLUDED
