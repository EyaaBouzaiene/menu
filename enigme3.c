/**
* @file enigme3.c
* @brief Testing Program.
* @author eya
* @version 0.1
* @date may 01, 2020
*
* Testing program enigme equation aleatoire
*
*/
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//#include <Math.h>
#include <time.h>
#include"enigme3.h"
#include <string.h>
#include "time.h"

/**
* @brief To calcul aleatoire de l'equation
* @param eng enigme3
* @return nothing
*/
void random_enigme(enigme3 *eng)
{
    int d=0;
    int a,b,c;
    do
    {
        srand(time(NULL));
        a=rand()%10+1;
        b=rand()%20+1;
        c=rand()%30+1;
        eng->a=a;
        eng->b=b;
        eng->c=c;
    }
    while(a> c-b || c-b<0);
    if(a==0)
    {
        if(b==c)
        {
            printf("solution infine");
        }
        else
        {
            printf("pas de solution");
        }
    }
    else
    {
        d=c-b;
        eng->x1=d+30;
        eng->x2=d/a;
        eng->x3=a*b;
    }

}

/**
* @brief To affiche de l'enigme
* @param eng enigme3
* @param screen surface
* @return nothing
*/

void afficher_enigme(SDL_Surface * screen,enigme3 *eng)
{
    SDL_Color color= {0,0,0};
    TTF_Font *font = NULL;
    TTF_Font *rep = NULL;
    TTF_Init();
    font=TTF_OpenFont("Comic_Sans_MS_Bold.ttf",30);
    rep=TTF_OpenFont("Comic_Sans_MS_Bold.ttf",25);
//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    srand(time(NULL));
    SDL_Surface *equation,*rep1,*rep2,*rep3;
    eng->poseng.x=370;
    eng->poseng.y=230;
    eng->posrep1.x=400;
    eng->posrep1.y=275;
    eng->posrep2.x=400;
    eng->posrep2.y=315;
    eng->posrep3.x=400;
    eng->posrep3.y=345;

    sprintf(eng->qus,"%dX+%d=%d",eng->a,eng->b,eng->c);
    equation= TTF_RenderText_Solid(font,eng->qus,color);
    SDL_BlitSurface	(equation,NULL,screen,&eng->poseng);

    sprintf(eng->ch1,"%.f",eng->x1);
    rep1= TTF_RenderText_Solid(rep,eng->ch1,color);
    SDL_BlitSurface	(rep1,NULL,screen,&eng->posrep1);

    sprintf(eng->ch2,"%.f",eng->x2);
    rep2= TTF_RenderText_Solid(rep,eng->ch2,color);
    SDL_BlitSurface	(rep2,NULL,screen,&eng->posrep2);

    sprintf(eng->ch3,"%.f",eng->x3);
    rep3= TTF_RenderText_Solid(rep,eng->ch3,color);
    SDL_BlitSurface	(rep3,NULL,screen,&eng->posrep3);

    SDL_Flip(screen);
    TTF_CloseFont(font);
    TTF_CloseFont(rep);

}
/**
* @brief To resolution de l'enigme
* @param eng enigme3
* @param screen surface
* @return nothing
*/
void resolution_enigme(SDL_Surface * screen,enigme3 *eng)
{
    SDL_Surface *reslt,*sol;
    SDL_Color color= {250,0,0};
    SDL_Color color2= {0,255,0};
    SDL_Event event;
    int done=1;

    char wrong[50]="WRONG";
    char good[50]="GOOD";
    TTF_Font *font = NULL;
    font=TTF_OpenFont("font.ttf",150 );
    eng->posfin.x=550;
    eng->posfin.y=265;
    eng->possol.x=570;
    eng->possol.y=365;
    Time time;
    timer fps;
    init_Timer(&fps);
    initializer_Time(&time);
    while (done)
    {
        start_Timer(&fps);
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                done=0;
                break;

            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case (SDLK_a) :
                    reslt= TTF_RenderText_Solid(font,wrong,color);
                    SDL_BlitSurface(reslt,NULL,screen,&eng->posfin);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                    sol= TTF_RenderText_Solid(font,eng->ch2,color2);
                    SDL_BlitSurface(sol,NULL,screen,&eng->possol);
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    eng->s=0;
                    done=0;
                    break;

                case (SDLK_b) :
                    reslt= TTF_RenderText_Solid(font,good,color);
                    SDL_BlitSurface(reslt,NULL,screen,&eng->posfin);
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    eng->s=1;
                    done=0;
                    break;

                case (SDLK_c) :
                    reslt= TTF_RenderText_Solid(font,wrong,color);
                    SDL_BlitSurface(reslt,NULL,screen,&eng->possol);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                    sol= TTF_RenderText_Solid(font,eng->ch2,color2);
                    SDL_BlitSurface(sol,NULL,screen,&eng->posfin);
                    SDL_Flip(screen);
                    SDL_Delay(2000);
                    eng->s=0;
                    done=0;
                    break;
                case (SDLK_ESCAPE) :
                    done = 0;
                    break;
                }
                break;
            }
        }
        afficher_Time(time,screen);
        update_Time(&time);
        SDL_Flip(screen);
    }
    TTF_CloseFont(font);
    SDL_Flip(screen);

}

/**
* @brief To gestion score 
* @param eng enigme3
* @param screen surface
* @return entier
*/
int retur1(SDL_Surface * screen,enigme3 *eng)
{

    if(eng->s==1)
    {

        return 1;
       // printf("score augmente: %d \n",eng->s);

    }
    else if(eng->s==0)
    {
        return 0;
        //printf("score diminue : %d \n",eng->s);

    }


}







