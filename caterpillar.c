#include "caterpillar.h"
#include "fonctions.h"

void initcatterpillar(CATERPILLAR *snake)
{
	snake->size = 5;
	for (int i = 0; i < 20; i++)
	{
		if (i < snake->size)
		{
			snake->pos[i].x = 0;
			snake->pos[i].y = snake->size-i;
		}
		else
		{
			snake->pos[i].x = -2;
			snake->pos[i].y = -2;
		}
	}
}


//-1 erreur de taille, 0 pas d'erreur, 1 on sort de l'�cran
int moveCaterpillar(CATERPILLAR* snake, char field[LargeurGrille][HauteurGrille],int* direction)
{
	if (snake->size <= 0) return -1; //erreur on peux pas faire la fonction;
	
	if (*direction == 'q' || *direction == 'Q' || *direction == KEY_LEFT)
	{
		if (snake->pos[0].y - 1 == snake->pos[1].y) { *direction = 'd'; return 0; }
		if (snake->pos[0].y > 0 && field[snake->pos[0].x][snake->pos[0].y - 1] != '*')
		{
			if (field[snake->pos[0].x][snake->pos[0].y-1]== '@')
			{
				snake->size++; 
				//PlaySound(MAKEINTRESOURCE(SND_apple), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
			}
			for (int i = snake->size; i > 0; i--)
			{
				snake->pos[i] = snake->pos[i - 1];
			}
			snake->pos[0].y = snake->pos[1].y - 1;
		}
		else return 1;
	}
	else if (*direction == 'd' || *direction == 'D' || *direction == KEY_RIGHT)
	{
		if (snake->pos[0].y + 1 == snake->pos[1].y) { *direction = 'q'; return 0; }
		if (snake->pos[0].y < HauteurGrille && field[snake->pos[0].x][snake->pos[0].y + 1] != '*')
		{
			if (field[snake->pos[0].x][snake->pos[0].y + 1] == '@')
			{
				snake->size++; 
				//PlaySound(MAKEINTRESOURCE(SND_apple),GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
			}
			for (int i = snake->size; i > 0; i--)
			{
				snake->pos[i] = snake->pos[i - 1];
			}
			snake->pos[0].y = snake->pos[1].y + 1;
		}
		else return 1;
	}
	else if (*direction == 's' || *direction == 'S' || *direction == KEY_DOWN)
	{
		if (snake->pos[0].x + 1 == snake->pos[1].x) { *direction = 'z'; return 0; }
		if (snake->pos[0].x < LargeurGrille-1 && field[snake->pos[0].x+1][snake->pos[0].y] != '*')
		{
			if (field[snake->pos[0].x + 1][snake->pos[0].y] == '@')
			{
				snake->size++; 
				//laySound(MAKEINTRESOURCE(SND_apple), GetModuleHandle(NULL),SND_RESOURCE | SND_ASYNC);
			}
			for (int i = snake->size; i > 0; i--)
			{
				snake->pos[i] = snake->pos[i - 1];
			}
			snake->pos[0].x = snake->pos[1].x + 1;
		}
		else return 1;
	}
	else if (*direction == 'z' || *direction == 'Z' || *direction == KEY_UP)
	{
		if (snake->pos[0].x - 1 == snake->pos[1].x) { *direction = 's'; return 0; }
		if (snake->pos[0].x > 0 && field[snake->pos[0].x - 1][snake->pos[0].y] != '*')
		{
			if (field[snake->pos[0].x - 1][snake->pos[0].y] == '@')
			{	snake->size++;	
			//PlaySound(MAKEINTRESOURCE(SND_apple),GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC );
			}
			for (int i = snake->size; i > 0; i--)
			{
				snake->pos[i] = snake->pos[i - 1];
			}
			snake->pos[0].x = snake->pos[1].x - 1;
		}
		else return 1;
	}
	return 0;
}


