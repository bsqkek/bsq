
#include "ft_bsq.h"

void	ft_print(void)
{
	g_i = 0;
	while (g_i < g_rows)
	{
		write(1, g_cache[g_i], g_cols);
		write(1, "\n", 1);
		g_i++;
	}
}
