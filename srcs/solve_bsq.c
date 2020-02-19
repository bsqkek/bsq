
#include "ft_bsq.h"

t_bool	ft_solve_bsq(void)
{
	int		last_obstacle;

	if (!(is_valid()))
		return (ERROR);
	g_i = 1;
	while (g_i < g_rows)
	{
		if (g_res > 1)
		{
			last_obstacle = g_res + 1;
			while (last_obstacle && g_cache[g_i][--last_obstacle] != g_full)
				;
			g_j = g_res + 1;
			g_tmp[0] = g_buffer[g_j - 1];
			g_buffer[g_res] = g_res - last_obstacle;
		}
		else
		{
			g_j = 0;
			g_tmp[0] = g_buffer[g_j];
		}
		while (g_j < g_cols)
		{
			if (g_cache[g_i][g_j] == g_full)
				g_buffer[g_j] = 0;
			else if (g_j == 0)
				g_buffer[g_j] = 1;
			else if ((g_tmp[1] = g_buffer[g_j]) >= 0)
				g_buffer[g_j] = 1 + ft_min(g_buffer[g_j], g_buffer[g_j - 1], g_tmp[0]);
			if (g_j > 0)
				g_tmp[0] = g_tmp[1];
			if (g_buffer[g_j] > g_res)
			{
				g_res = g_buffer[g_j];
				g_x = g_j;
				g_y = g_i;
			}
			g_j++;
		}
		g_i++;
	}
	return (SUCCESS);
}

t_bool	is_valid(void)
{
	char	c;

	g_i = 1;
	while (g_i < g_rows)
	{
		g_j = 0;
		g_cache[g_i] = (char *)malloc(sizeof(char) * g_cols);
		while (read(g_fd, &c, 1) && c != '\n')
		{
			if (c != g_empty && c != g_full)
				return (ERROR);
			g_cache[g_i][g_j] = c;
			g_j++;
		}
		if (g_j != g_cols)
			return (ERROR);
		g_i++;
	}
	for (int i = 0; i < g_rows; i++)
		printf("%s\n", g_cache[i]);
	printf("-------------------------\n");
	return (SUCCESS);
}

t_bool	ft_final_cache(void)
{
	g_i = g_y  + 1 - g_res;
	while (g_i <= g_y)
	{
		g_j  = g_x + 1 - g_res;
		while (g_j <= g_x)
		{
			g_cache[g_i][g_j] = g_square;
			g_j++;
		}
		g_i++;
	}
	return (SUCCESS);
}
