#include "fonctions.h"


//revoie une interaction (char saisie et int verif)
INTER interact(double tempsEnSecondes)
{
    INTER interact = { 0, ' ' };


    if (( interact.saisie = getch()) != ERR)			            //on test si une touche est appuille
    {
        //on recupere la touche pressee
            if (interact.saisie == 224)				//les touches speciales type croix directionnelles sont sous la forme 224 xxx
                interact.saisie = getch();
            interact.verifie = 1;
            return interact;
    }

    return interact;

}


//prend en paramettre TRUE = 1 ou FALSE = 0
void setCursorVisibility(int statut) //change la visibilité du curseur
{
    curs_set (statut);
}
