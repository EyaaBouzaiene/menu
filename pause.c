/**
* @file pause.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program pause game
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "pause.h"

/**
* @brief To pause 
* @param surface screen
* @return int n
*/
int pause(SDL_Surface *ecran)
{
	SDL_Surface *exit[2],*bg;
	int n=0,t,done=1;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=200;
	pos.y=50;
	exit[1]=IMG_Load("pause/menu_pasue_noselect.png");
        exit[0]=IMG_Load("pause/menu_pause_yesselect.png");
  
    while(done==1)
    {
    	
    	SDL_BlitSurface(exit[n],NULL,ecran,&pos);
    	SDL_Flip(ecran);
    	SDL_WaitEvent(&event);
    	t=0;
    	switch(event.type)
    	{
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym)
    			{
    				case SDLK_LEFT:
						if (n==0 )
						{
							n++;
							
						}
						else if (n==1 )
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RIGHT:
						if (n==0 )
						{
							n++;
							
						}
						else if (n==1)
						{
							n--;
							
						}
					break;

					case SDLK_RETURN:
						if (n==0)
						{
							//return 1;
                                                        done=0; 
						}
						else if (n==1)
						{
							//return 0;
                                                        done=0; 
						}
					break;

    			}
    		break;
    		SDL_FreeSurface(exit[0]);
    		SDL_FreeSurface(exit[1]);
    		SDL_FreeSurface(bg);

    	}
    } //printf("done = %d et n =%d \n",done,n);
return n;
}
