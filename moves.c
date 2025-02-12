
#include "push_swap.h"


void move_swap(int *a, int *b)
{
	int temp;
	temp = a;
	a = b;
	b =temp;
}

void rotate(int **tab)
{
	int i  = 0 ;
	int big = tab[0];

	while (tab[i])
	{
		if (big <= tab[i])
		{
			big = tab[i];
		}
		i++;
	}
}

void rev_rotate(int **tab)
{
	int i  = 0 ;
	int big = tab[ft_strlen(tab)];

	while (i < big)
	{
		if (big <= tab[i])
		{
			big = tab[i];
		}
		i++;
	}
}