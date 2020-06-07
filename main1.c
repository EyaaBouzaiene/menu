/**
* @file main.c.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program  fonctions global
*
*/
#include <stdio.h>
#include <SDL/SDL_rotozoom.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "personnage.h"
#include "bg.h"
#include "collision1.h"
#include "scrolling.h"
#include "enemy.h"
#include "vie.h"
#include "input.h"
#include "coin.h"
#include "score.h"
#include "fire.h"
#include "hppossion.h"
#include "pause.h"
#include "savegame.h"
#include "temp.h"
#include "dead.h"
#include "enigme.h"
#include "enigme3.h"
#include "e.h"
#include "time.h"
#include "minimap.h"

#define TEMPS       30



int main ()
{

    // SDL_Color color;
    TTF_Init();
    SDL_Surface  *image = NULL, *rotation = NULL, *dead = NULL,*backg=NULL,*image1 = NULL;
    double angle = 0;
    double zoom = 1;
    SDL_Event event;
    int sens = 1,continuer = 1,save=0, startTicks=0,i=0,d,a=0;
    int tempsPrecedent = 0, tempsActuel = 0;
    int done=1,collision1,collision2,collision3,collision4,collision5,collision6,collision_coin1,collision_coin2,collision_ep;
    int collision_fire1,collision_fire2,collision_hpp2,collision_hpp1,collision_enig1,collision_enig2,collision_enig3;


//*******************Les enigmes*******************************
    game g;
    enigme3 enig;
    SDL_Rect positifond;
    backg = IMG_Load("quiz1.png");
    positifond.x=200 ;
    positifond.y=0 ;
    SDL_Surface *fond=NULL;
    SDL_Rect posimg;
    posimg.x=200;
    posimg.y=75;
    SDL_Rect positionFond;
    positionFond.x=344;
    positionFond.y=135;
    fond=IMG_Load("EnigmePFC/fond.png");
    image1=IMG_Load("enigme.png");


//**********************screen et camera***********************
    SDL_Surface *screen=NULL;
    SDL_Rect camera= {0,0,1200,600};
    screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
//*****************image rotozoom****************
    SDL_Rect rect;
    image= SDL_LoadBMP("bg/goodluck1.bmp");

//**********************perso******************
    perssonage p;
    initialiser_perssonage (&p);



//**************************BG**********************
    background b;
    initialiser_backround (&b);

//*******************minimap***********************
    minimap m;
    initialiser_minimap(camera,&m);

    point pt;
    init_point(&pt,camera);


//*********************************coin***********************************
    coin c1,c2;
    SDL_Rect poscoin1,poscoin2;
    poscoin1.x=300;
    poscoin1.y=100;
    poscoin2.x=550;
    poscoin2.y=250;
    init_coin(&c1,poscoin1.x,poscoin1.y);
    init_coin(&c2,poscoin2.x, poscoin2.y);

//*******************************fire***********************
    fire f1,f2,f4,f3;
    init_fire(&f1,280, 405);
    init_fire(&f2,800, 405);
    init_fire(&f3,2280, 405);
    init_fire(&f4,3800, 170);

//**************************time**********************

    Temps t;
    initializerTemps(&t);

//*********************musique**************************
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_Chunk *clik, *mort;
    clik= Mix_LoadWAV("music/coin.wav");
    mort= Mix_LoadWAV("music/mort.wav");
    Mix_Music *musique;
    musique = Mix_LoadMUS("music/background.mp3");
    Mix_PlayMusic(musique, -1);
    Mix_VolumeMusic (MIX_MAX_VOLUME/5);

//******************dead***********************************
    Dead d1;
    initialiser_dead(&d1);

//**********************enemi***************************

    enemie f;
    inisialiser_enemie (&f);

//***********************Input**************************
    Input I;
    initialiser_input (&I);

//******************Health possion****************************
    hpp h1,h2;
    init_hpp(&h1,700, 200);
    init_hpp(&h2,950, 100);

//************************************debut prog*********************************

    while(done)
    {

        while( SDL_PollEvent(&event))

        {
            switch(event.type)
            {
            case SDL_QUIT:
                I.quit=1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    startTicks=SDL_GetTicks();
                    p.vitesse.x=10;
                    break;
                case SDLK_LEFT :
                    startTicks=SDL_GetTicks();
                    p.vitesse.x=-10;
                    break;
                case SDLK_UP :
                    p.onground=0;
                    p.vitesse.y=-20;
                    break;
                case SDLK_DOWN :
                    p.vitesse.y=10;
                    break;

                case SDLK_ESCAPE :
                {
                    I.quit=1;
                }
                break;
                case SDLK_r :

                    I.acction=1;
                    break;
                case SDLK_z : //up

                    p.onground=0;
                    p.vitesse.y=-20;
                    break;
                case SDLK_x : //down

                    p.vitesse.y=10;
                    break;
                case SDLK_d : //right

                    p.vitesse.x=10;
                    break;
                case SDLK_q : //left

                    p.vitesse.x=-10;
                    break;

                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_r :

                    I.acction=0;
                    break;
                case SDLK_ESCAPE :

                    I.quit=0;
                    break;
                case SDLK_d : //right

                    p.vitesse.x=0;
                    break;
                case SDLK_q : //left

                    p.vitesse.x=0;
                    break;
                case SDLK_x : //down

                    p.vitesse.y=0;
                    break;
                case SDLK_RIGHT:
                    p.vitesse.x=0;
                    break;

                case SDLK_LEFT :
                    p.vitesse.x=0;
                    break;
                case SDLK_DOWN :
                    p.vitesse.y=0;
                    break;

                }
                break;
            }
        }
        collision1=collision_right(b,p);
        collision2=collision_left(b,p);
        collision3=collision_top(b,p);
        collision4=collision_down(b,&p);
        collision5=collision_gravite( b, p);
        SDL_Rect ep= {p.posperso.x+camera.x-100,330}; //update ennemi
        SDL_Rect coin1= {c1.pos.x,c1.pos.y,c1.pos.w,c1.pos.h};
        SDL_Rect coin2= {c2.pos.x,c2.pos.y,c2.pos.w,c2.pos.h};
        collision_coin1=collision(coin1,p.posperso);
        collision_coin2=collision(coin2,p.posperso);
        collision6=collision_mort( b,p);
        SDL_Rect fire1= {f1.pos.x,f1.pos.y,f1.pos.w,f1.pos.h};
        collision_fire1=collision(fire1,p.posperso);
        SDL_Rect fire2= {f2.pos.x,f2.pos.y,f2.pos.w,f2.pos.h};
        collision_fire2=collision(fire2,p.posperso);
        SDL_Rect fire3= {f3.pos.x,f3.pos.y,f3.pos.w,f3.pos.h};
        int collision_fire3=collision(fire3,p.posperso);
        SDL_Rect fire4= {f4.pos.x,f4.pos.y,f4.pos.w,f4.pos.h};
        int collision_fire4=collision(fire4,p.posperso);
        SDL_Rect hpp1= {h1.pos.x,h1.pos.y,h1.pos.w,h1.pos.h};
        collision_hpp1=collision(hpp1,p.posperso);
        SDL_Rect hpp2= {h2.pos.x,h2.pos.y,h2.pos.w,h2.pos.h};
        collision_hpp2=collision(hpp2,p.posperso);
        collision_ep=collision(f.rect,p.posperso);
        collision_enig1=collision_enigme1( b,p);
        collision_enig2=collision_enigme2( b,p);
        collision_enig3=collision_enigme3( b,p);
        while(I.quit==1)
        {
            save=pause(screen);
            if (save==0)
            {
                sauvegarder_stage (&p,&b);
            }
            I.quit=0;
            done=0;
        }

        while(I.acction==1)
        {
            SDL_PollEvent(&event);
            switch(event.type)
            {
            case SDL_QUIT:
                I.acction= 0;
                break;

            }

            tempsActuel = SDL_GetTicks();
            if (tempsActuel - tempsPrecedent > TEMPS)
            {
                angle += 2; //On augmente l'angle pour que l'image tourne sur elle-même.
                zoom += 0.0025;
                tempsPrecedent = tempsActuel;
            }
            else
            {
                SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
            }

            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

            rotation = rotozoomSurface(image, angle, zoom, 0); //On transforme la surface image.

            //On repositionne l'image en fonction de sa taille.
            rect.x =  event.button.x - rotation->w / 2;
            rect.y =  event.button.y - rotation->h / 2;

            SDL_BlitSurface(rotation, NULL, screen, &rect);  //On affiche la rotation de la surface image.
            SDL_FreeSurface(rotation); //On efface la surface rotation car on va la redéfinir dans la prochaine boucle. Si on ne le fait pas, cela crée une fuite de mémoire.

            if(zoom >= 2)
            {
                sens = 0;
            }
            else if(zoom <= 0.5)
            {
                sens = 1;
            }

            if(sens == 0)
            {
                zoom -= 0.02;
            }
            else
            {
                zoom += 0.02;
            }

            SDL_Flip(screen);
        }
        if(collision4==0 && p.vitesse.y>0)
        {
            p.vitesse.y=0;
        }
        if(collision5==0)
        {
            p.vitesse.y+=4;// gravity
        }
        if ( p.vitesse.x>0 && collision1==0)
        {
            mouvementright (&p,&startTicks);
            animation_right(&p);
        }
        else if (p.vitesse.x<0 && collision2==0)
        {

            mouvementleft (&p,&startTicks);
            animation_left (&p);
        }
        else if (p.vitesse.y<0  && collision3==0)
        {
            mouvementjump (&p);
            animation_jump (&p);

        }
        else if (p.vitesse.y>0 && collision4==0 )
        {

            mouvementdown (&p);
        }
        else
        {
            animation_stable (&p);
        }

        if(collision_coin1==1)
        {
            Mix_PlayChannel(1,clik,0);
            p.Score.total=p.Score.total+100;
            c1.pos.x+=1300;
            c1.pos.y-=10;

        }
        if(p.posperso.x>c1.pos.x+c1.pos.w+500)
        {
            c1.pos.x+=1300;
            c1.pos.y-=10;
        }

        if(collision_coin2==1)
        {
            Mix_PlayChannel(1,clik,0);
            p.Score.total=p.Score.total+100;
            c2.pos.x+=1300;
            c2.pos.y-=10;
        }
        if(p.posperso.x>c2.pos.x+c2.pos.w+500)
        {
            c2.pos.x+=1300;
            c2.pos.y-=10;
        }
        if(collision6==1)
        {

            p.posperso.x-=400;
            p.posperso.y=0;
            SDL_Delay(50);
            p.Vie.nbrVie--;
        }
        if(collision_fire1==1)
        {

            p.posperso.x-=200;
            p.posperso.y=0;
            SDL_Delay(50);
            p.Vie.nbrVie--;
        }
        if(collision_fire3==1)
        {

            p.posperso.x-=200;
            p.posperso.y=0;
            SDL_Delay(50);
            p.Vie.nbrVie--;
        }
        if(collision_fire4==1)
        {

            p.posperso.x-=200;
            p.posperso.y=0;
            SDL_Delay(50);
            p.Vie.nbrVie--;
        }
        if(collision_fire2==1)
        {

            p.posperso.x-=200;
            p.posperso.y=0;
            SDL_Delay(50);
            p.Vie.nbrVie--;
        }
        if(collision_hpp1==1)
        {
            Mix_PlayChannel(1,clik,0);
            if( p.Vie.nbrVie<3)
            {
                p.Vie.nbrVie++;
            }
            h1.pos.x+=1300;
        }
        if(p.posperso.x>h1.pos.x+h1.pos.w+500)
        {
            h1.pos.x+=1300;
        }
        if(collision_hpp2==1)
        {
            Mix_PlayChannel(1,clik,0);
            if( p.Vie.nbrVie<3)
            {
                p.Vie.nbrVie++;
            }
            h2.pos.x+=1300;
        }
        if(p.posperso.x>h2.pos.x+h2.pos.w+500)
        {
            h2.pos.x+=1300;
        }
        if(collision_ep==1)
        {

            p.posperso.x-=300;
            p.posperso.y=0;
            SDL_Delay(50);
            p.Vie.nbrVie--;
        }
        if(p.Vie.nbrVie==0)
        {
            Mix_PlayChannel(1,mort,0);
            afficher_dead(screen,d1);
            SDL_Delay(5000);
            done=0;
        }

        if( collision_enig1==1)
        {


            srand(time(NULL));
            d=rand()%13+1;
            work(screen,d);
            p.posperso.x+=150;
            p.posperso.y=200;
            p.vitesse.x=0;
            p.vitesse.y=0;


        }
        if( collision_enig2==1)
        {

            SDL_BlitSurface	(fond,NULL,screen,&positionFond);
            SDL_Flip(screen);
            eng(&g,screen);
            resultat(&g,screen);
            a=retur(screen,&g);
            if(a==1)
            {
                p.Score.total+=500;
            }
            else
            {
                p.Score.total-=200;
            }
            p.posperso.x+=100;
            p.posperso.y=150;
            p.vitesse.x=0;
            p.vitesse.y=0;


        }
        if( collision_enig3==1)
        {

            SDL_BlitSurface	(image1,NULL,screen,&posimg);
            SDL_Flip(screen);
            random_enigme(&enig);
            afficher_enigme(screen,&enig) ;
            resolution_enigme( screen,&enig);
            a=retur1( screen,&enig);
            if(a==1)
            {
                p.Score.total+=500;
            }
            else
            {
                p.Score.total-=200;
            }
            p.posperso.x+=100;
            p.posperso.y=150;
            p.vitesse.x=0;
            p.vitesse.y=0;


        }
        if(p.posperso.x==8000)
        {
            save=pause(screen);
            if (save==0)
            {
                sauvegarder_stage (&p,&b);
            }

            done=0;

        }
        mouv_point(&pt,p.posperso);
        set_camera(&camera,p.posperso);
        scroll_mini(event,&camera);
        afficher_background (screen,b,camera);
        afficher_minimap(screen,&m,pt);
        afficherTemps(&t, screen);
        update_ennemi(&f,screen,ep);
        afficher_enemie (f,screen,camera);
        animation (&f);
        afficher_vie(p.Vie,screen);
        afficher_score(p.Score,screen);
        afficher(c1,screen,camera);
        afficher(c2,screen,camera);
        animer_coin(&c1);
        animer_coin(&c2);
        animation_fire(&f1);
        afficher_fire (f1,screen,camera);
        animation_fire(&f2);
        afficher_fire (f2,screen,camera);
        animation_fire(&f3);
        afficher_fire (f3,screen,camera);
        animation_fire(&f4);
        afficher_fire (f4,screen,camera);
        animer_hpp(&h1);
        afficher_hpp(screen,h1,camera);
        animer_hpp(&h2);
        afficher_hpp(screen,h2,camera);
        afficher_perssonage (p,screen,camera);
        SDL_Flip(screen);
        SDL_Delay(10);
    }
    return 0;
}




