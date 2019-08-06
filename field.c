#include "field.h"
#include <stdlib.h>


void initifeld(char tab[LargeurGrille][HauteurGrille])
{
	int nbat = 15;
	int i, j;

	for (i = 0; i < LargeurGrille; i++)
	{
		for (j = 0; j < HauteurGrille; j++)
		{
			tab[i][j] = ' ';

		}
	}
	while (nbat > 0)
	{
		int x = rand() % LargeurGrille ,y = rand() % HauteurGrille;
		if (tab[x][y] != '@')
		{
			tab[x][y] = '@';
			nbat--;
		}
	}
}

//-1 erreur; 0 NP
int updateField(char field[LargeurGrille][HauteurGrille], CATERPILLAR* snake)
{
	for (int i = 0; i < snake->size; i++)
	{
		if (snake->pos[i].x >= LargeurGrille ||
			snake->pos[i].x < 0 ||
			snake->pos[i].y >= HauteurGrille ||
			snake->pos[i].y < 0)  //on test si on touche les bord ou on les depasse
			return -1;
		
		field[snake->pos[i].x][snake->pos[i].y] = '*';
	}
	field[snake->pos[snake->size].x][snake->pos[snake->size].y] = ' ';
	return 0;
}

//trace une barre
void barre()
{
	addch('+');
	for (int i = 0; i < HauteurGrille; i++)
		addch('-');
	printw("+\n");
}

//afface l'ecran et trace le field 
void traceField(char field[LargeurGrille][HauteurGrille])
{

	clear();
	move(0,0);
    barre();
    for (int i = 0; i < LargeurGrille; i++)
	{
        printw("|");
        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY );
        for (int j = 0; j < HauteurGrille; j++)
		{
            printw("%c", field[i][j]);
        }
        // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
        printw("|\n");
    }
    barre();
    refresh();
}

//redessine la chenille
void redrawCaterpillar(const CATERPILLAR snake)
{
	
	// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 0; i < snake.size -1; i++)
	{
		move(snake.pos[i].y +1, snake.pos[i].x+1);
		addch('*');
	}
	move(snake.pos[snake.size].y +1, snake.pos[snake.size].x +1);
	addch(' ');
	refresh();
	// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	
}

