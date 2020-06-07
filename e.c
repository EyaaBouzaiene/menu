/**
* @file enigme2.c
* @brief Testing Program.
* @author eya
* @version 0.1
* @date may 01, 2020
*
* Testing program enigme pierre ciseaux
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
#include "e.h"
#include "time.h"


/**
* @brief To affichage du resultat
* @param g game
* @param screen surface
* @return nothing
*/

void resultat(game *g,SDL_Surface *screen)
{

    int cont=1;
    SDL_Surface *winner=NULL;
    SDL_Surface *loser=NULL;
    SDL_Rect positionresult;
    winner=IMG_Load("EnigmePFC/winner.png");
    loser=IMG_Load("EnigmePFC/loser.png");
    positionresult.x=344;
    positionresult.y=135;
    if(g->sommemoi > g->sommepc)
    {
        SDL_BlitSurface(winner,NULL,screen,&positionresult);
        SDL_Flip(screen);
        g->s=1;
    }
    else
    {
        SDL_BlitSurface(loser,NULL,screen,&positionresult);
        SDL_Flip(screen);
        g->s=0;
    }
    SDL_Delay(1000);
    SDL_FreeSurface(winner);
    SDL_FreeSurface(loser);

}
/**
* @brief To gestion score 
* @param g game
* @param screen surface
* @return entier
*/
int retur(SDL_Surface * screen,game *g)
{

    if(g->s==1)
    {
        printf("score augmente: %d \n",g->s);
        return 1;


    }
    else if(g->s==0)
    {
        printf("score diminue : %d \n",g->s);
        return 0;


    }


}
/**
* @brief To resolution enigme contre ordi
* @param g game
* @param screen surface
* @return entier
*/

void eng(game *g,SDL_Surface *screen)
{
    SDL_Surface *fond=NULL;
    SDL_Rect positionFond;
    fond=IMG_Load("EnigmePFC/fond.png");
    positionFond.x=344;
    positionFond.y=135;
    g->sommepc=0;
    g->sommemoi=0;
    int partie=0;
    int choixPc=0;
    int done = 1;
    SDL_Event event;
    SDL_Color color= {0,0,0};
    TTF_Font *font = NULL;
    TTF_Init();
    font=TTF_OpenFont("EnigmePFC/Comic_Sans_MS_Bold.ttf",28);
//posmoi
    g->posp.x=543;
    g->posp.y=190;
    g->posf.x=543;
    g->posf.y=190;
    g->posc.x=543;
    g->posc.y=190;
//posresult
    g->posGagnee.x=419;
    g->posGagnee.y=140;
    g->posPerdue.x=413;
    g->posPerdue.y=140;
    g->posEgalite.x=419;
    g->posEgalite.y=140;
//pospc //  j ai pas fait ca
    g->posppc.x=245;
    g->posppc.y=190;
    g->posfpc.x=245;
    g->posfpc.y=190;
    g->poscpc.x=245;
    g->poscpc.y=190;
//pospartie
    g->pospartie.x=584;
    g->pospartie.y=412;
    g->pierre=NULL;
    g->feuille=NULL;
    g->ciseaux=NULL;
    g->pierrepc=NULL;
    g->feuillepc=NULL;
    g->ciseauxpc=NULL;
    g->perdue=NULL;
    g->gagnee=NULL;
    g->egalite=NULL;
    g->part=NULL;
//loadimage
    g->pierre=IMG_Load("EnigmePFC/pierre.png");
    g->feuille=IMG_Load("EnigmePFC/feuille.png");
    g->ciseaux=IMG_Load("EnigmePFC/ciseaux.png");
    g->pierrepc=IMG_Load("EnigmePFC/pierre_pc.png");
    g->feuillepc=IMG_Load("EnigmePFC/feuille_pc.png");
    g->ciseauxpc=IMG_Load("EnigmePFC/ciseaux_pc.png");
    g->gagnee=IMG_Load("EnigmePFC/gagnee.png");
    g->perdue=IMG_Load("EnigmePFC/perdue.png");
    g->egalite=IMG_Load("EnigmePFC/egalite.png");
    Time time;
    timer fps;
    init_Timer(&fps);
    initializer_Time(&time);

    while(done)
    {
        start_Timer(&fps);
        choixPc=(rand()%3+1);
        while( SDL_PollEvent(&event))
        {


            switch(event.type)
            {
            case SDL_QUIT:
                done= 0;
                break;

            case SDL_KEYDOWN:
                if(partie <=3)
                {
                    switch(event.key.keysym.sym )

                    {

                    case (SDLK_a):

                        if(choixPc == 1)
                        {


                            SDL_BlitSurface(fond,NULL,screen,&positionFond);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->pierrepc,NULL,screen,&g->posppc);
                            SDL_Flip(screen);

                            SDL_BlitSurface(g->pierre,NULL,screen,&g->posp);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->egalite,NULL,screen,&g->posEgalite);
                            SDL_Flip(screen);
                            partie++;
                            sprintf(g->p,"%d",partie);
                            g->part=TTF_RenderText_Solid(font,g->p,color);
                            SDL_BlitSurface(g->part,NULL,screen,&g->pospartie);

                            SDL_Flip(screen);

                        }

                        else if(choixPc == 2)
                        {


                            SDL_BlitSurface(fond,NULL,screen,&positionFond);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->feuillepc,NULL,screen,&g->posfpc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->pierre,NULL,screen,&g->posp);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->perdue,NULL,screen,&g->posPerdue);
                            SDL_Flip(screen);
                            g->sommepc++;
                            partie++;
                            sprintf(g->p,"%d",partie);
                            g->part=TTF_RenderText_Solid(font,g->p,color);
                            SDL_BlitSurface(g->part,NULL,screen,&g->pospartie);
                            SDL_Flip(screen);


                        }
                        else if(choixPc == 3)
                        {

                            SDL_BlitSurface(fond,NULL,screen,&positionFond);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->ciseauxpc,NULL,screen,&g->poscpc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->pierre,NULL,screen,&g->posp);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->gagnee,NULL,screen,&g->posGagnee);
                            SDL_Flip(screen);
                            g->sommemoi++;
                            partie++;
                            sprintf(g->p,"%d",partie);
                            g->part=TTF_RenderText_Solid(font,g->p,color);
                            SDL_BlitSurface(g->part,NULL,screen,&g->pospartie);

                            SDL_Flip(screen);
                        }
                        break;
                    case (SDLK_b) :

                        if(choixPc == 1)
                        {
                            SDL_BlitSurface(fond,NULL,screen,&positionFond);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->pierrepc,NULL,screen,&g->posppc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->feuille,NULL,screen,&g->posf);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->gagnee,NULL,screen,&g->posGagnee);
                            SDL_Flip(screen);
                            g->sommemoi++;
                            partie++;
                            sprintf(g->p,"%d",partie);
                            g->part=TTF_RenderText_Solid(font,g->p,color);
                            SDL_BlitSurface(g->part,NULL,screen,&g->pospartie);

                            SDL_Flip(screen);
                        }

                        else if(choixPc == 2)
                        {
                            SDL_BlitSurface(fond,NULL,screen,&positionFond);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->feuillepc,NULL,screen,&g->posfpc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->feuille,NULL,screen,&g->posf);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->egalite,NULL,screen,&g->posEgalite);
                            SDL_Flip(screen);

                            partie++;
                            sprintf(g->p,"%d",partie);
                            g->part=TTF_RenderText_Solid(font,g->p,color);
                            SDL_BlitSurface(g->part,NULL,screen,&g->pospartie);

                            SDL_Flip(screen);

                        }

                        else if(choixPc == 3)
                        {
                            SDL_BlitSurface(fond,NULL,screen,&positionFond);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->ciseauxpc,NULL,screen,&g->poscpc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->feuille,NULL,screen,&g->posf);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->perdue,NULL,screen,&g->posPerdue);
                            SDL_Flip(screen);
                            g->sommepc++;
                            partie++;
                            sprintf(g->p,"%d",partie);
                            g->part=TTF_RenderText_Solid(font,g->p,color);
                            SDL_BlitSurface(g->part,NULL,screen,&g->pospartie);

                            SDL_Flip(screen);

                        }
                        break;
                    case (SDLK_c):

                        if(choixPc == 1)
                        {
                            SDL_BlitSurface(fond,NULL,screen,&positionFond);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->pierrepc,NULL,screen,&g->posppc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->ciseaux,NULL,screen,&g->posc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->perdue,NULL,screen,&g->posPerdue);
                            SDL_Flip(screen);
                            g->sommepc++;
                            partie++;
                            sprintf(g->p,"%d",partie);
                            g->part=TTF_RenderText_Solid(font,g->p,color);
                            SDL_BlitSurface(g->part,NULL,screen,&g->pospartie);
                            SDL_Flip(screen);
                        }
                        else if(choixPc == 2)
                        {
                            SDL_BlitSurface(fond,NULL,screen,&positionFond);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->feuillepc,NULL,screen,&g->posfpc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->ciseaux,NULL,screen,&g->posc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->gagnee,NULL,screen,&g->posGagnee);
                            SDL_Flip(screen);
                            g->sommemoi++;
                            partie++;
                            sprintf(g->p,"%d",partie);
                            g->part=TTF_RenderText_Solid(font,g->p,color);
                            SDL_BlitSurface(g->part,NULL,screen,&g->pospartie);
                            SDL_Flip(screen);
                        }
                        else if(choixPc == 3)
                        {
                            SDL_BlitSurface(fond,NULL,screen,&positionFond);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->ciseauxpc,NULL,screen,&g->poscpc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->ciseaux,NULL,screen,&g->posc);
                            SDL_Flip(screen);
                            SDL_BlitSurface(g->egalite,NULL,screen,&g->posEgalite);
                            SDL_Flip(screen);

                            partie++;
                            sprintf(g->p,"%d",partie);
                            g->part=TTF_RenderText_Solid(font,g->p,color);
                            SDL_BlitSurface(g->part,NULL,screen,&g->pospartie);
                            SDL_Flip(screen);
                        }

                        break;

                    case (SDLK_ESCAPE) :
                        done = 0;
                        break;


                    }
                    if(partie==3)
                    {
                        resultat(g,screen);
                        /* SDL_WaitEvent(&event);
                         switch(event.type)
                         {
                         case SDL_KEYDOWN:
                             switch(event.key.keysym.sym )
                             {
                             case (SDLK_ESCAPE) :
                                 done= 0;
                                 break;
                             }
                             break;


                         }*/
                        done=0;

                    }

                }
                break;

            }
        }

        afficher_Time(time,screen);
        update_Time(&time);
        SDL_Flip(screen);
    }


    SDL_FreeSurface(fond);
    SDL_FreeSurface(g->pierre);
    SDL_FreeSurface(g->pierrepc);
    SDL_FreeSurface(g->feuille);
    SDL_FreeSurface(g->feuillepc);
    SDL_FreeSurface(g->ciseaux);
    SDL_FreeSurface(g->ciseauxpc);
    SDL_FreeSurface(g->perdue);
    SDL_FreeSurface(g->gagnee);
    SDL_FreeSurface(g->egalite);
    SDL_FreeSurface(g->part);
    TTF_CloseFont(font);
    SDL_Flip(screen);

}



