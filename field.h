#pragma once

#include "caterpillar.h"
#include "fonctions.h"

#ifdef __cplusplus
extern "C" {
#endif


void initifeld(char tab[LargeurGrille][HauteurGrille]);

int updateField(char field[LargeurGrille][HauteurGrille], CATERPILLAR *);

void traceField(char field[LargeurGrille][HauteurGrille]);

void redrawCaterpillar(const CATERPILLAR);

#ifdef __cplusplus
}
#endif