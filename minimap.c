/**
* @file minimap.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program  mini map
*
*/
#include "minimap.h"
/**
* @brief To initialiser minimap
* @param m minimap
* @param camera position
* @return nothing
*/
void initialiser_minimap(SDL_Rect camera, minimap *m)

{

    m->background = NULL;

    m->camera.x = 0;

    m->camera.y = 0;

    m->camera.w = camera.w ;

    m->camera.h = camera.h ;

    m->posbg.x = 10;

    m->posbg.y = 500;

    m->cadre=IMG_Load("minimap/cadre.png");

    m->background = IMG_Load("minimap/mini.png");
}
/**
* @brief To affichage minimap
* @param m minimap
* @param camera position
* @param pt point
* @return nothing
*/
void afficher_minimap(SDL_Surface *screen, minimap *m, point pt)

{

    SDL_BlitSurface(m->background, &m->camera, screen, &m->posbg);

    SDL_BlitSurface(m->cadre,NULL,screen,&m->posbg);

    SDL_BlitSurface(pt.point, NULL, screen, &pt.pospnt);
}
/**
* @brief To scrolling minimap
* @param e event
* @param b position
* @return nothing
*/
void scroll_mini(SDL_Event e, SDL_Rect *b)

{

    if (e.key.keysym.sym == SDLK_RIGHT)

    {

        b->x += 5;
    }

    else if (e.key.keysym.sym == SDLK_LEFT)

    {

        b->x -= 5;
    }
}
/**
* @brief To initialiser point
* @param pt point
* @param bposition
* @return nothing
*/
void init_point(point *pt, SDL_Rect b)

{
    pt->point = NULL;

    pt->point = IMG_Load("minimap/point.png");

    pt->pospnt.x = 10;

    pt->pospnt.y = b.x+515;
}
/**
* @brief mouvement point
* @param pt point
* @param bposition
* @return nothing
*/
void mouv_point(point *pt, SDL_Rect p)

{

    pt->pospnt.x = (p.x/11);
}
