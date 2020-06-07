#ifndef COLLISION1_H_INCLUDED
#define COLLISION1_H_INCLUDED
#include "personnage.h"
#include "bg.h"


int collision(SDL_Rect rec1,SDL_Rect rec2);
void init(perssonage p,SDL_Rect pos[]);
int collision_right(background b,perssonage p);
int collision_left(background b,perssonage p);
int collision_top(background b,perssonage p);
int collision_down(background b,perssonage *p);
SDL_Color GetPixel(SDL_Surface *x_background,int x,int y);
int collision_gravite(background b,perssonage p);
int collision_mort(background b,perssonage p);
int collision_enigme1(background b,perssonage p);
int collision_enigme2(background b,perssonage p);
int collision_enigme3(background b,perssonage p);   


  #endif // DS_H_INCLUDED

