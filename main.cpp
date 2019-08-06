
#include "caterpillar.h"
#include "field.h"
#include <ncurses.h>



int main()
{
    //on open console pour le gotoXY
    initscr();
    cbreak();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    timeout(500);


    /* VARIABLES */
    char field[LargeurGrille][HauteurGrille];
    int direction = 'd';
    CATERPILLAR snake;
    INTER interactionJoueur;
    int isDead = 0;

    /* INITIALISATION */
    initifeld(field);
    initcatterpillar(&snake);

    updateField(field, &snake);
    traceField(field);


    /*LOOP DU GAME*/
    while (snake.size < 20  && !isDead)
    {

        interactionJoueur = interact(1);
        if(interactionJoueur.verifie)
            direction = interactionJoueur.saisie;

        isDead = moveCaterpillar(&snake,field, &direction );
        updateField(field, &snake);

        traceField(field);

        //redrawCaterpillar(snake);

    }


    /* ECRAN DE FIN */
    clear();
    refresh();

    if (!isDead)
    {
        move( LINES/2-4, COLS/2);
        printw("YOU WIN");
        // PlaySound(MAKEINTRESOURCE(SND_victory), GetModuleHandle(NULL), SND_SYNC | SND_RESOURCE);
    }
    else
    {
        move( LINES/2 - 4, COLS/2);
        printw("YOU LOSE");
        // PlaySound(MAKEINTRESOURCE(SND_loose), GetModuleHandle(NULL), SND_SYNC | SND_RESOURCE);
    }
    refresh();

    timeout(-1);
    getch();

    endwin();

}
