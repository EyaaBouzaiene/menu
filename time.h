#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <stdlib.h> 
#include <stdio.h> 
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include <SDL/SDL_image.h> 

/**
* @struct timer
* @brief struct for time
*/
typedef struct
{
//Le temps quand le timer est lancé
    int start_Ticks;/*!< entier*/

    //Les "ticks" enregistré quand le Timer a été mit en pause
    int paused_Ticks; /*!< entier*/

    //Le status du Timer
    int paused;/*!< entier*/
    int started;/*!< entier*/

} timer;

/**
* @struct Time
* @brief struct for time
*/

typedef struct
{
    SDL_Surface * T1[20];/*!< Surface*/
    SDL_Surface * T2[12];/*!< Surface*/
    SDL_Surface * T3[7];/*!< Surface*/
    SDL_Surface * T4;/*!< Rectangle*/
    SDL_Surface * timeSurf;/*!< Surface*/
    SDL_Rect postime;/*!< Rectangle*/
    SDL_Rect pos[4];/*!< Rectangle*/
    timer anim;/*!< struct*/
    int ms,s,m;/*!< entier*/

} Time;


void init_Timer(timer *T);
void start_Timer(timer *T);
int  get_ticks(timer *T);
void initializer_Time(Time *Time);
void update_Time(Time *Time);
void afficher_Time(Time Time,SDL_Surface *screen);




 #endif
