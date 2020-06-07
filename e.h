#ifndef E_H_INCLUDED
#define E_H_INCLUDED
/**
* @struct game
* @brief struct for enigme2
*/
typedef struct
{
    SDL_Rect posp;/*!< Rectangle*/
    SDL_Rect posf;/*!< Rectangle*/
    SDL_Rect posc;/*!< Rectangle*/
    SDL_Rect posppc;/*!< Rectangle*/
    SDL_Rect posfpc;/*!< Rectangle*/
    SDL_Rect poscpc;/*!< Rectangle*/
    SDL_Rect posGagnee;/*!< Rectangle*/
    SDL_Rect posPerdue;/*!< Rectangle*/
    SDL_Rect posEgalite;/*!< Rectangle*/
    SDL_Rect pospartie;/*!< Rectangle*/
    SDL_Surface *pierre;/*!< Surface*/
    SDL_Surface *feuille;/*!< Surface*/
    SDL_Surface *ciseaux;/*!< Surface*/
    SDL_Surface *pierrepc;/*!< Surface*/
    SDL_Surface *feuillepc;/*!< Surface*/
    SDL_Surface *ciseauxpc;/*!< Surface*/
    SDL_Surface *perdue;/*!< Surface*/
    SDL_Surface *gagnee;/*!< Surface*/
    SDL_Surface *egalite;/*!< Surface*/
    SDL_Surface *part;/*!< Surface*/
    char p[50];/*!< Char*/
    int sommepc,sommemoi;/*!< entier*/
    int s;/*!< entier*/
} game;
void eng(game *g,SDL_Surface *screen);
void resultat(game *g,SDL_Surface *screen);
int retur(SDL_Surface * screen,game *g);


#endif
