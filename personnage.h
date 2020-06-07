#ifndef personnage_H_INCLUDED
#define personnage_H_INCLUDED
#include "vie.h"
#include"score.h"
/**
* @struct perssonage
* @brief struct for personnage
*/
typedef struct
{


    SDL_Surface *perssonage;/*!< Surface*/
    SDL_Rect posperso;/*!< Rectangle*/
    SDL_Rect rects[60];/*!< Rectangle*/
    int frame;/*!< entier*/
    int stable_direction;/*!< entier*/
    SDL_Rect vitesse;/*!< Rectangle*/
    int  onground;/*!< entier*/
    vie Vie; /*!< struct*/
    score Score;/*!< struct*/

} perssonage;


void setrects(SDL_Rect* clip);
void initialiser_perssonage (perssonage *p);
void afficher_perssonage (perssonage p,SDL_Surface *screen,SDL_Rect camera);
void animation_right (perssonage *p);
void animation_left (perssonage *p);
void animation_stable (perssonage *p);
void animation_jump (perssonage *p);
void mouvementright (perssonage *p,int *startTicks);
void mouvementleft (perssonage *p,int *startTicks);
void mouvementdown (perssonage *p);
void mouvementjump (perssonage *p);



#endif 




