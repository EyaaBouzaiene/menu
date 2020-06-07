/**
* @file input.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program  init input
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "input.h"

/**
* @brief To initialiser input
* @param I input
* @return nothing
*/

void initialiser_input (Input *I)
{
I->left=0;
I->right=0;
I->down=0;
I->jump=0;
I->acction=0;
I->quit=0;
}
