/**
* @file save.c
* @brief Testing Program.
* @author 
* @version 0.1
* @date may 01, 2020
*
* Testing program save game
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "savegame.h"

/**
* @brief To sauvgarder stage
* @param p personnage
* @param b background
* @return nothing
*/



void sauvegarder_stage (perssonage *p,background *b)
{
	int a=1;
	FILE *f;

	f=fopen("savings.txt", "wb");

	fwrite(p, sizeof(perssonage), 1, f);
	
	fwrite(b,sizeof(background),1,f);

	fclose(f);

	

}
/**
* @brief To continuer le stage
* @param p personnage
* @param b background
* @return nothing
*/
void load_game (perssonage *p,  background *b)
{

	FILE *f=fopen("savings.txt","rb");

	if(f==NULL)
	{
	     printf("Erreur !");
	}


	else
	{
		//printf("loading");
		fread(p, sizeof(perssonage), 1, f);
		
		fread(b, sizeof(background), 1, f);
	}

	fclose(f);
}

