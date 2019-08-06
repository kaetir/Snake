#pragma once

#include <ncurses.h>

#define ESC 27

#define HauteurGrille 50
#define LargeurGrille 25

#ifdef __cplusplus
extern "C" {
#endif

typedef struct interaction   //structure utilis� pour r�cuperer une interaction clavier et voir si il y en a bien eu
{
    int verifie;
    int saisie;
} INTER;


INTER interact(double dificulty);

void setCursorVisibility(int statut);

#ifdef __cplusplus
}
#endif