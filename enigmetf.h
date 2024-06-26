#ifndef ENIGMETF_H_INCLUDED
#define ENIGMETF_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


typedef struct
{ 

	SDL_Surface *background;
        SDL_Surface *background1;
        SDL_Surface *background2; 
	SDL_Surface *question;	  
	SDL_Surface *reponses[4]; 
	SDL_Surface *button;	 
	SDL_Surface *button_s;
	char  chquestion[50];
	char chrep[2][50];
	int rc; 
	int pos_selected;	   
	SDL_Rect pos_question; 
	SDL_Rect pos_reponse1; 
	SDL_Rect pos_reponse2; 
	SDL_Rect pos_reponse3; 
	int num_question;
	SDL_Rect pos_reponse1txt;
	SDL_Rect pos_reponse2txt; 
	SDL_Rect pos_reponse3txt; 		  
	TTF_Font *police;
	TTF_Font *police1;
	SDL_Surface *image_clock;
	SDL_Rect pos_image_clock;

	SDL_Rect single_Clock;

	int clock_num;
        int currentBackground;

} enigmetf;

void InitEnigme(enigmetf *e, char nomfichier[]);
void afficherEnigme(enigmetf e, SDL_Surface *ecran);
void displayClock(enigmetf e, SDL_Surface *ecran);
void verify_enigme(enigmetf e, SDL_Surface *ecran);
void animer(enigmetf *e);
void free_Surface_enigme(enigmetf *e);
void delay(int milliseconds);
void animerBackground(enigmetf *e);
#endif
