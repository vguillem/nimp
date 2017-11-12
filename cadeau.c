#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int nb;
	int	tab[ac - 1];
	int	x;
	int	i;
	int	j;
	int	okidak;

	okidak = 0;
	srand(time(NULL));
	nb = ac;
	while (okidak == 0)
	{
		i = 1;
		j = 0;
		while (i++ < ac - 1)
			tab[i] = -1;
		while (ac-- > 1)
		{
			x = rand()%(nb - 1);
			i = 0;
			while (i < nb - 1)
			{
				if ((x == tab[i] || x == j) && j != 9)
				{
					i = -1;
					x = rand()%(nb - 1);
				}
				i++;
			}
			if (j == 9)
			{
				i = 0;
				x = 0;
				while (i < nb - 1)
				{
					if (tab[i] == x)
					{
						x++;
						i = 0;
					}
					i++;
				}
				if (x != 9)
					okidak = 1; 
			}
			tab[j++] = x;
		}
	}
	j = 0;
	nb--;
	while (nb-- > 0)
	{
		printf("%s offre a : %s\n",av[j + 1],av[tab[j] + 1]);
		j++;
		}
}
