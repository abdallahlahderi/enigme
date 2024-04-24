#include "enigmetf.h"


void delay(int milliseconds) {
    SDL_Delay(milliseconds);
}

void InitEnigme(enigmetf *e, char nomfichier[])
{

	FILE *f = NULL;

	e->pos_selected = 0;
	e->rc = 0;
	e->background1 = IMG_Load("img/background.png");
        e->background2 = IMG_Load("img/backgroundd.png");
        e->currentBackground = 1;
	e->button = IMG_Load("img/button.png");
	e->button_s = IMG_Load("img/button_s.png");

	if (TTF_Init() == -1 ) 
	printf("cant ttf \n " );
	
	SDL_Color couleur = {32, 64, 0};
        SDL_Color couleur1 = {0, 0, 0};

	e->police = TTF_OpenFont("arial.ttf", 30);
	e->police1 = TTF_OpenFont("arial.ttf", 20);

	srand(time(NULL));
	e->num_question = rand() % 4;

	while (e->num_question == 0)
	{
		srand(time(NULL));
		e->num_question = rand() % 4;
	}
	printf("%d \n ",e->num_question);
	

	char rep1[50];
	char rep2[50];
	char rep3[50];
	strcpy(rep1,"");
	strcpy(rep2,"");
	strcpy(rep3,"");
	int rc = 0 ; 

	f = fopen(nomfichier, "r");
	if (f != NULL)
	{
		fscanf(f, "%[^_]_%[^_]_%[^_]_%[^_]_%d", e->chquestion, rep1, rep2, rep3, &rc);
		int test = 1;
		while (test != e->num_question)
		{
			fscanf(f, "%[^_]_%[^_]_%[^_]_%[^_]_%d", e->chquestion, rep1, rep2, rep3, &rc);
			test++;
		}
		fclose(f);
	}
	srand(time(NULL));
	
	puts(e->chquestion);
	puts(rep1);
	puts(rep2);
	puts(rep3);
	e->rc = rc ;
	printf ("%d \n ", e->rc);


	e->question = TTF_RenderText_Blended(e->police, e->chquestion, couleur);
	e->reponses[0] = TTF_RenderText_Blended(e->police1, rep1, couleur1);
	e->reponses[1] = TTF_RenderText_Blended(e->police1, rep2, couleur1);
	e->reponses[2] = TTF_RenderText_Blended(e->police1, rep3, couleur1);

	e->pos_question.x = 450;
	e->pos_question.y = 270;

	e->pos_reponse1.x = 650;
	e->pos_reponse1.y = 500;

	e->pos_reponse2.x = 650 - 240;
	e->pos_reponse2.y = 500+180;

	e->pos_reponse3.x = 650 + 240;
	e->pos_reponse3.y = 500 + 180;

	e->pos_reponse1txt.x = e->pos_reponse1.x + 70;
	e->pos_reponse1txt.y = e->pos_reponse1.y + 20;

	e->pos_reponse2txt.x = e->pos_reponse2.x + 70;
	e->pos_reponse2txt.y = e->pos_reponse2.y + 20;

	e->pos_reponse3txt.x = e->pos_reponse3.x + 70;
	e->pos_reponse3txt.y = e->pos_reponse3.y + 20;

	(*e).image_clock = IMG_Load("clock1.png");

	e->pos_image_clock.x = 750;
	e->pos_image_clock.y = 100;

	e->single_Clock.w = 57,3584;
	e->single_Clock.h = 80;
	e->single_Clock.x = 0;
	e->single_Clock.y = 0;

	e->clock_num = 0;

	
}

void afficherEnigme(enigmetf e, SDL_Surface *ecran)
{

	if (e.currentBackground == 1)
    {
        SDL_BlitSurface(e.background1, NULL, ecran, NULL);
    }
    else
    {
        SDL_BlitSurface(e.background2, NULL, ecran, NULL);
    }
	displayClock(e, ecran);
	SDL_BlitSurface(e.question, NULL, ecran, &e.pos_question);

	switch (e.pos_selected)
	{
	case 0:
		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

		SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

		SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

		SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
		break;

	case 1:
	{
		SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

		SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

		SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

		SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
	}
	break;
	case 2:
	{
		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

		SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);

		SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

		SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

		SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
	}
	break;
	case 3:
	{
		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

		SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

		SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);

		SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

		SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

		SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
	}
	break;
	default:

		break;
	}
}

void verify_enigme(enigmetf e, SDL_Surface *ecran)
{

	SDL_Rect pos = {430, 330};
	printf ("%d \n ",e.pos_selected);
	printf ("%d \n ",e.rc);


	if (e.pos_selected == e.rc)
	{
		printf("You win\n");
		SDL_Surface *win;
		win = IMG_Load("img/youwin.png");
		SDL_BlitSurface(win, NULL, ecran, &pos);
	}
	else
	{
		SDL_Surface *lost;
		lost = IMG_Load("img/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		printf("You lost\n");
	}
	
}
void displayClock(enigmetf e, SDL_Surface *ecran)
{
	SDL_BlitSurface(e.image_clock, &(e.single_Clock), ecran, &e.pos_image_clock);
}
void animer(enigmetf *e)
{

	if (e->clock_num >= 0 && e->clock_num < 8)
	{
		e->single_Clock.x = e->clock_num * e->single_Clock.w;
		e->clock_num++;
	}

	if (e->clock_num == 8)
	{
		e->single_Clock.x = e->clock_num * e->single_Clock.w;
		e->clock_num = 0;
	}
    delay(20); // Ajout du délai de 5 millisecondes après chaque animation

}
void animerBackground(enigmetf *e)
{
    static int frame = 0;
    frame++;
    if (frame % 15 == 0) // Change d'image toutes les 100 frames (à ajuster selon vos besoins)
    {
        // Alternez entre les deux images d'arrière-plan
        e->currentBackground = (e->currentBackground == 1) ? 2 : 1;
    }
}

void free_Surface_enigme(enigmetf *e)
{
	SDL_FreeSurface(e->background1); // Utilisez e->background1 et e->background2 ici
	SDL_FreeSurface(e->background2);
	SDL_FreeSurface(e->question);
	SDL_FreeSurface(e->reponses[0]);
	SDL_FreeSurface(e->reponses[1]);
	SDL_FreeSurface(e->reponses[2]);
	SDL_FreeSurface(e->button);
	SDL_FreeSurface(e->button_s);
}

