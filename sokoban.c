#include "sokoban.h"

void 	deplacement(pos *perso, pos *caisse, pos contour, res reset)
{
	char dep;
	dep = getchar();
	while (getchar() != '\n');
	if (dep == 'z')
	{
		if (perso->y != 1)
		{
			perso->y--;
			if (perso_caisse && perso->y != 1)
				caisse->y--;
			else if (perso_caisse && perso->y == 1)
				perso->y++;
		}
	}
	else if (dep == 's')
	{
		if (perso->y != contour.y-2)
		{
			perso->y++;
			if (perso_caisse && perso->y != contour.y-2)
				caisse->y++;
			else if (perso_caisse && perso->y == contour.y-2)
				perso->y--;
		}
	}
	else if (dep == 'q')
	{
		if (perso->x != 1)
		{
			perso->x--;
			if (perso_caisse && perso->x != 1)
				caisse->x--;
			else if (perso_caisse && perso->x == 1)
				perso->x++;
		}
	}
	else if (dep == 'd')
	{
		if (perso->x != contour.x-2)
		{
			perso->x++;
			if (perso_caisse && perso->x != contour.x-2)
				caisse->x++;
			else if (perso_caisse && perso->x == contour.y-2)
				perso->x--;
		}
	}
	else if (dep == ' ')
	{
		perso->y = reset.iperso.y;
		perso->x = reset.iperso.x;
		caisse->y = reset.icaisse.y;
		caisse->x = reset.icaisse.x;
	}
}

int je_place(pos curseur, pos perso, pos caisse, pos but)
{
	
	if (perso.x == curseur.x && perso.y == curseur.y)
	{
		ft_putchar('M');
		return(1);
	}
	else if (caisse.x == curseur.x && caisse.y == curseur.y)
	{
		ft_putchar('C');
		return(1);
	}
	else if (but.x == curseur.x && but.y == curseur.y)
	{
		ft_putchar('X');
		return(1);
	}
	else 
		return(0);
}

void	map(pos contour, pos perso, pos caisse, pos but)
{
	int o;
	pos curseur;

	curseur.y = 0;
	while (curseur.y < contour.y)
	{
		curseur.x = 0;
		o = 0;
		while (curseur.x < contour.x)
		{
			o = je_place(curseur, perso, caisse, but);
			if (o == 0)
				{
					if (curseur.y == 0 || curseur.y == contour.y - 1)
						ft_putchar('#');
					else
						if (curseur.x == 0 || curseur.x == contour.x - 1)
							ft_putchar('#');
						else
							ft_putchar(' ');
				}
			curseur.x++;
		}
		curseur.y++;
		if (curseur.y < contour.y)
			ft_putchar('\n');
	}
}

res	init_reset(pos perso, pos caisse, pos contour, pos but)
{
	res reset;

	reset.iperso.y = perso.y;
	reset.iperso.x = perso.x;
	reset.icaisse.y = caisse.y;
	reset.icaisse.x = caisse.x;
	reset.icontour.x = contour.x;
	reset.icontour.y = contour.y;
	reset.ibut.x = but.x;
	reset.ibut.y = but.y;
	return (reset);
}

void	sprand(pos *pos, int iix, int iiy, int b)
{
	srand(time(NULL));
	pos->x = rand()%iix + b;
	pos->y = rand()%iiy + b;
}


void	init_pos(pos *perso, pos *caisse, pos *but,  pos contour)
{
	int iix;
	int iiy;
	int b;

	iix = contour.x - 2;
	iiy = contour.y - 2;
	b = 1;
	sprand(but, iix, iiy, b);
	sprand(perso, iix, iiy, b);
	sprand(caisse, iix - 2, iiy - 2, b + 1);
	while (perso->x == but->x && perso->y == but->y)
		sprand(perso, iix, iiy, b);
	while ((caisse->x == but->x && caisse->y == but->y) || (caisse->x == perso->x && caisse->y == perso->y))
		sprand(caisse, iix - 2, iiy - 2, b + 1);
}

void	sokoban(char *nbr1, char *nbr2)
{
	pos contour;
	pos but;
	pos perso;
	pos caisse;
	res reset;

	contour.x = ft_atoi(nbr1);
	contour.y = ft_atoi(nbr2);
	init_pos(&perso, &caisse, &but, contour);
	reset = init_reset(perso, caisse, contour, but);
	
	while (caisse.x != but.x || caisse.y != but.y)
	{
		system("clear");
		map(contour, perso, caisse, but);
		deplacement(&perso, &caisse, contour, reset);
	}
	ft_putstr("\n\nBien joué !!");
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return(0);
	else
		sokoban(argv[1], argv[2]);
	return(0);
}
		
