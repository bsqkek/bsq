
#include "ft_bsq.h"

t_bool	ft_solve_bsq(void)
{
	char		c;

	printf("My error\n");
	return (ERROR);
	g_i = 1;
	while (g_i < g_rows)
	{
		g_j = 0;
		while (read(g_fd, &c, 1) && c != '\n')
		{
			g_cache[g_i][g_j] = c;
			g_tmp = g_buffer[g_j];
			g_j++;
		}
		g_i++;
	}
	if (g_res > 1)
		g_res -= 1;
	return (SUCCESS);
}

t_bool	ft_final_cache(void)
{
	g_i = g_y + 1 - g_res;
	while (g_i <= g_y)
	{
		g_j  = g_x + 1 - g_res;
		while (g_j <= g_x)
		{
			g_cache[g_i][g_j] = 0;
			g_j++;
		}
		g_i++;
	}
	return (SUCCESS);
}
