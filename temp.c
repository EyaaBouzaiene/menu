/**
* @file temp.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program temps jeux
*
*/
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include "temp.h"

/**
* @brief To initialiser temps
* @param Time time
* @return nothing
*/
void initializerTemps(Temps *time)
{
    time->font = TTF_OpenFont("font/font_temps.ttf", 32);
    time->time = 0;
    sprintf(time->timeString,"00:00");
    SDL_Color color = {255,255,255};
    time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);

}
/**
* @brief To affichage temps
* @param time time
* @param surface screen
* @return nothing
*/
void afficherTemps(Temps *time, SDL_Surface *screen)
{
    SDL_Color color = {255,255,255};
    time->time++;
    if(time->time % 60 == 0)
    {
        sprintf(time->timeString,"%02d:%02d\n",time->time/60/60,(time->time/60)%60);
        time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
    }
    //printf("%s \n",time->timeString);
    SDL_BlitSurface(time->msg,NULL,screen,NULL);

}





