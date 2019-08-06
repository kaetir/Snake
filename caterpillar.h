#include "fonctions.h"

#ifndef CATERPILLAR_H

#ifdef __cplusplus
    extern "C" {
#endif

#define  CATERPILLAR_H

typedef struct _Posi {            //structure permettant de stocker les coordonn�es d'un point
    short int x, y;
} POSITION;

typedef struct _caterpillar {    //structure permettant de stocker un tableau avec les coordonn� de la chenille et sa taille
    POSITION pos[101];
    int size;
} CATERPILLAR;

void initcatterpillar(CATERPILLAR *);


int moveCaterpillar(CATERPILLAR *snake, char field[LargeurGrille][HauteurGrille], int *);

#ifdef __cplusplus
    }
#endif


#endif // CATERPILLAR_H
