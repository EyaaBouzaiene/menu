/**
* @file enigme1.c
* @brief Testing Program.
* @author celine
* @version 0.1
* @date may 01, 2020
*
* Testing program  enigme quiz
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include <string.h>
#include <time.h>
/**
* @brief To affichage de la solution 
* @param d int
* @param screen surface
* @return nothing
*/
void solution(SDL_Surface *screen,int d)

{

    char im[100];

    SDL_Surface *wrong = NULL;

    SDL_Rect positionFond1;

    positionFond1.x = 200 ;

    positionFond1.y =  0 ;

    SDL_Surface *solution = NULL;

    SDL_Rect positionFond;

    positionFond.x = 200 ;

    positionFond.y =  0 ;

    wrong= IMG_Load("enigme1/no.png");

    SDL_BlitSurface(wrong,NULL,screen,&positionFond1);

    SDL_Flip(screen);

    SDL_Delay(3000);

    sprintf(im,"solu/%d.png",d);

    solution= IMG_Load(im);

    SDL_BlitSurface(solution,NULL,screen,&positionFond);

    SDL_Flip(screen);

    SDL_Delay(4000);

}

/**
* @brief To affichage congratulation
* @param screen surface
* @return nothing
*/

void good(SDL_Surface *screen)

{



    SDL_Surface *yes = NULL;

    SDL_Rect positionFond;

    positionFond.x =  200 ;

    positionFond.y =  0 ;

    yes= IMG_Load("enigme1/good.png");

    SDL_BlitSurface(yes,NULL,screen,&positionFond);

    SDL_Flip(screen);

    SDL_Delay(3000);

}

/**
* @brief To affichage des questions
* @param d int
* @param screen surface
* @return nothing
*/

void question(SDL_Surface *screen,int d)

{

    char ques[100];

    SDL_Surface *image = NULL;

    SDL_Rect positionFond;

    positionFond.x =  200 ;

    positionFond.y =  0 ;

    sprintf(ques,"question/%d.png",d);

    image= IMG_Load(ques);

    SDL_BlitSurface(image,NULL,screen,&positionFond);

    SDL_Flip(screen);

    SDL_Delay(5000);

}


/**
* @brief To affichage des reponses
* @param d int
* @param screen surface
* @return nothing
*/


void reponse(SDL_Surface *screen,int d)

{

    SDL_Event event;



    char im[100], im1[100], im2[100], im3[100];

    SDL_Surface *image = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL;

    SDL_Rect positionim;

    positionim.x =  200 ;

    positionim.y =  0 ;

    sprintf(im,"reponse/%d.png",d);

    image= IMG_Load(im);

    sprintf(im1,"reponse/%d/1.png",d);

    sprintf(im2,"reponse/%d/2.png",d);

    sprintf(im3,"reponse/%d/3.png",d);

    image1= IMG_Load(im1);

    image2= IMG_Load(im2);

    image3= IMG_Load(im3);





    int continuer=1;

    int i=0;

    while (continuer)

    {

        SDL_WaitEvent(&event);

        switch(event.type)

        {

        case SDL_QUIT:

            continuer=0;

            break;



        case SDL_KEYDOWN:

            switch(event.key.keysym.sym)

            {



            case SDLK_RETURN:

                if(i>=1 && i<=3)

                {



                    if (i==1 && d%3==1)

                    {

                        good(screen);

                        continuer=0;

                    }

                    else if (i==2 && d%3==2)

                    {

                        good(screen);

                        continuer=0;

                    }

                    else if (i==3 && d%3==0)

                    {

                        good(screen);

                        continuer=0;

                    }

                    else

                    {

                        solution(screen,d);

                        continuer=0;

                    }

                }

                break;



            case SDLK_DOWN:

                i++;

                if(i==4)

                {

                    i=1;

                }

                if(i==1)

                {

                    SDL_BlitSurface(image1,NULL, screen, &positionim);

                    SDL_Flip(screen);

                    SDL_Delay(500);

                }

                if(i==2)

                {

                    SDL_BlitSurface(image2,NULL, screen, &positionim);

                    SDL_Flip(screen);

                    SDL_Delay(500);

                }

                if(i==3)

                {

                    SDL_BlitSurface(image3,NULL, screen, &positionim);

                    SDL_Flip(screen);

                    SDL_Delay(500);

                }

                ;

                break;

            case SDLK_UP:

                i--;

                if(i==0)

                {

                    i=3;

                }

                if(i==4)

                {

                    i=1;

                }

                if(i==1)

                {

                    SDL_BlitSurface(image1,NULL, screen, &positionim);

                    SDL_Flip(screen);

                    SDL_Delay(500);

                }

                if(i==2)

                {

                    SDL_BlitSurface(image2,NULL, screen, &positionim);

                    SDL_Flip(screen);

                    SDL_Delay(500);

                }

                if(i==3)

                {

                    SDL_BlitSurface(image3,NULL, screen, &positionim);

                    SDL_Flip(screen);

                    SDL_Delay(500);

                }

                break;

            case SDLK_ESCAPE :

                continuer = 0;

                break;

            }

            break;

        }





    }





}

/**
* @brief To fonctionement de l'enigme
* @param d int
* @param screen surface
* @return nothing
*/

void work(SDL_Surface *screen,int d)

{







    SDL_Surface *backg=NULL,*bg=NULL ;

    SDL_Rect positifond;

    positifond.x=200 ;

    positifond.y=0 ;



    backg = IMG_Load("enigme1/quiz1.png");

    SDL_BlitSurface(backg,NULL, screen, &positifond);

    SDL_Flip(screen);

    SDL_Delay(1500);

    question(screen,d);

    reponse(screen,d);

    SDL_FreeSurface(backg);





}










