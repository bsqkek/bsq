
#include "ft_bsq.h"


void	ft_print(void)
{
	g_i = 0;
	while (g_i < g_rows)
	{
		g_j = 0;
		while (g_j < g_cols)
		{
			if (g_cache[g_i][g_j] > 1)
				write(1, &g_empty, 1);
			else if (g_cache[g_i][g_j] == 1)
				write(1, &g_full, 1);
			else
				write(1, &g_square, 1);
			g_j++;
		}
		write(1, "\n", 1);
		g_i++;
	}
}
