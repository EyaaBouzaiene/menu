#ifndef COIN_H_INCLUDED
#define COIN_H_INCLUDED

/**
* @struct coin
* @brief struct for coin
*/


typedef struct  coin
{
	SDL_Surface *tab[8];/*!< surface*/
	SDL_Rect pos;/*!< Rectangle*/
	int frame;/*!< entier*/
}coin;

void init_coin(coin *c,int x, int y);
void animer_coin(coin *c);
void afficher(coin c,SDL_Surface *screen,SDL_Rect camera);
  #endif // DS_H_INCLUDED
