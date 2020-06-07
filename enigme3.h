
#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
/**
* @struct enigme3
* @brief struct for enigme3
*/
typedef struct enigme3
{       
	SDL_Rect poseng;/*!< Rectangle*/ 
      	SDL_Rect posrep1;/*!< Rectangle*/
	SDL_Rect posrep2;/*!< Rectangle*/ 
	SDL_Rect posrep3;/*!< Rectangle*/
        SDL_Rect posfin;/*!< Rectangle*/
        SDL_Rect possol;/*!< Rectangle*/
        char ch1[30],ch2[30],ch3[30];/*!< char*/
        char qus[50];/*!< char*/ 
	int a;/*!< entier*/
        int b;/*!< entier*/
        int c;/*!< entier*/
        float x1,x2,x3;/*!< float*/
        int s;/*!< entier*/
} enigme3;

void random_enigme(enigme3 *eng);
void afficher_enigme(SDL_Surface * screen ,enigme3 *eng) ;
void resolution_enigme(SDL_Surface * screen  ,enigme3 *eng);
int retur1(SDL_Surface * screen  ,enigme3 *eng);

#endif
