/**
* @file scrolling.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program camera
*
*/
#include "scrolling.h"
#include "personnage.h"
#include "bg.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
/**
* @brief To scrolling camera
* @param position perso
* @param position camera
* @return nothing
*/
void set_camera(SDL_Rect *camera,SDL_Rect posperso)

{

    camera->x = ( posperso.x + 100 / 2 ) - 1200 / 2;

    camera->y = ( posperso.y + 100/ 2 ) - 600 / 2;



    if( camera->x < 0 )

    {

        camera->x = 0;

    }

    if( camera->y < 0 )

    {

        camera->y = 0;

    }

    if( camera->x > 9000 - camera->w )

    {

        camera->x = 9000 - camera->w;

    }

    if( camera->y > 600 - camera->h )

    {

        camera->y = 600 - camera->h;

    }

}

