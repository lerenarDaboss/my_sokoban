#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <stdio.h>
#include <mylib.h>
#include <stdlib.h>
#include <time.h>
#define perso_caisse perso->x == caisse->x && perso->y == caisse->y

typedef struct pos pos;
struct pos
{
	int x;
	int y;
};

typedef struct res res;
struct res
{
	pos icaisse;
	pos iperso;
	pos ibut;
	pos icontour;
};
void	deplacement(pos *perso, pos *caisse, pos contour, res reset);
int	je_place(pos curseur, pos perso, pos caisse, pos but);
void	map(pos contour, pos perso, pos caisse, pos but);
res	init_reset(pos perso, pos caisse, pos contour, pos but);
void	sokoban(char *nbr1, char *nbr2);
void	sprand(pos *pos, int iix, int iiy, int b);
void	init_pos(pos *perso, pos *caisse, pos *but, pos contour);

#endif
