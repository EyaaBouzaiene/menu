/**
* @file temp.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program temps enigme
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"time.h"




/**
* @brief To initialiser time
* @param T timer
* @return nothing
*/
void init_Timer(timer *T)
{
    //Initialisation des variables
    T->start_Ticks = 0;
    T->paused_Ticks = 0;
    T->paused = 0;
    T->started = 0;


}
/**
* @brief To start time
* @param T timer
* @return nothing
*/
void start_Timer(timer *T)
{
    //Permet de mettre le timer en marche
    T->started = 1;

    //Permet de mettre le timer en mode non pause
    T->paused = 0;

    //On récupére le temps courant
    T->start_Ticks = SDL_GetTicks();
}

/**
* @brief To calcul time
* @param T timer
* @return entier
*/

int  get_ticks(timer *T)
{
//Si le timer est en marche
    if( T->started == 1 )
    {
        //Si le timer est en pause
        if( T->paused == 1 )
        {
            //On retourne le nombre de ticks quand le timer a été mis en pause
            return T->paused_Ticks;
        }
        else
        {
            //On retourne le temps courant moins le temps quand il a démarré
            return SDL_GetTicks() - T->start_Ticks;
        }
    }

    //Si le timer n'est pas en marche
    else
        return 0;


}
/**
* @brief To initialiser image
* @param Time Time
* @return nothing
*/

void initializer_Time(Time *Time)
{
    char img[50];
    int i,j=2,k=0;
    //init_les premier image

    Time->T1[0]=IMG_Load("time/0.png");

    Time->T2[0]=IMG_Load("time/0.png");

    Time->T1[1]=IMG_Load("time/1.png");

    Time->T2[1]=IMG_Load("time/1.png");

    Time->T3[6]=IMG_Load("time/0.png");

    Time->T4=IMG_Load("time/0.png");

    for (int i = 2; i < 20; ++i)
    {
        snprintf (img, sizeof img,"time/%d.png",i);
        //init T1
        Time->T1[i]=IMG_Load(img);

        //init T2
        if(i>=10)
        {
            Time->T2[j]=IMG_Load(img);
            j++;
        }

        //init T3
        if(i>=14)
        {
            Time->T3[k]=IMG_Load(img);
            k++;
        }

    }



    //init T1
    Time->pos[0].x=490;
    Time->pos[0].y=10;
    //init T2
    Time->pos[1].x=470;
    Time->pos[1].y=10;
    //init T3
    Time->pos[2].x=440;
    Time->pos[2].y=10;
    //init T4
    Time->pos[3].x=420;
    Time->pos[3].y=10;


    Time->ms=0;
    Time->s=0;
    Time->m=0;
    Time->timeSurf=IMG_Load("time/time.png");
    Time->postime.x=430;
    Time->postime.y=5;
    init_Timer(&Time->anim);
    start_Timer(&Time->anim);



}
/**
* @brief To update time
* @param Time Time
* @return nothing
*/
void update_Time(Time *Time)
{
    if (Time->m != 6 || Time->s!=0 || Time->ms!=0 )

    {
        if( get_ticks(&Time->anim) >= 250)
        {

            // On remet le timer à 0
            start_Timer(&Time->anim);

            // On passe à la frame suivante
            if (Time->s==0 && Time->ms==0 ||Time->s==1 && Time->ms==1)
                Time->m++;
            if(Time->ms==0 ||Time->ms==1 )
                Time->s++;
            Time->ms++;

        }
        if(Time->s >=12)
            Time->s = 0;
        if(Time->ms >=20)
            Time->ms = 0;


    }



}
/**
* @brief To affichage time
* @param Time Time
* @param screen surface
* @return nothing
*/

void afficher_Time(Time Time, SDL_Surface *screen)
{


    SDL_BlitSurface(Time.T1[Time.ms],NULL,screen,&Time.pos[0]);
    SDL_BlitSurface(Time.T2[Time.s],NULL,screen,&Time.pos[1]);
    SDL_BlitSurface(Time.T3[Time.m],NULL,screen,&Time.pos[2]);
    SDL_BlitSurface(Time.T4,NULL,screen,&Time.pos[3]);
    SDL_Flip(screen);


}


