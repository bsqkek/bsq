
#include "ft_bsq.h"

void	set_global_variables(void)
{
	g_rows = 0;
	g_res = 0;
	g_cols = 0;
}

t_bool	read_map_options(void)
{
	int		power10;

	if (!(g_1line = (char *)malloc(sizeof(char) * 14)))
		exit (1);
	while (read(g_fd, &g_1line[0], 1) && g_1line[0] == '0')
		;
	g_i = 0;
	while (++g_i < 14 && read(g_fd, &g_1line[g_i], 1) && g_1line[g_i] != '\n')
		;
	if (g_i > 3 && g_1line[g_i] == '\n')
	{
		g_square = g_1line[--g_i];
		g_full = g_1line[--g_i];
		g_empty = g_1line[--g_i];
	}
	else
		return (ERROR);
	g_j = -1;
	power10 = 1;
	while (++g_j < g_i && g_1line[g_j] >= '0' && g_1line[g_j] <= '9')
	{
		if (g_rows >= 214748364 && g_empty > '7')
			return (ERROR);
		g_rows = g_rows * 10 + g_1line[g_j] - '0';
		if (g_rows < power10)
			return (ERROR);
		power10 *= 10;
	}
	if (g_rows < 1 || g_j != g_i
		|| g_empty == g_full || g_empty == g_square || g_full == g_square)
		return (ERROR);
	return (SUCCESS);
}

void	ft_realloc(int length)
{
	char	*newstr;
	int		i;

	if(!(newstr = (char *)malloc(sizeof(char) * length)))
		exit (1);
	i = -1;
	while (++i < length / 14)
		newstr[i] = g_1line[i];
	g_1line = newstr;
}

t_bool	ft_create_cache(void)
{
	int		power14;
	int		flag;

	set_global_variables();
	if (!read_map_options())
		return (ERROR);
	g_i = -1;
	while (++g_i < 14 && read(g_fd, &g_1line[g_i], 1) && g_1line[g_i] != '\n')
		if (g_1line[g_i] != g_empty && g_1line[g_i] != g_full)
			return (ERROR);
	power14 = 14;
	while (g_i == power14 && g_1line[power14 - 1] != '\n')
	{
		if (power14 != 1475789056)
            power14 *= 14;
        else
            power14 = 2147483647;
		ft_realloc(power14);
		g_i--;
		while (++g_i < power14 && read(g_fd, &g_1line[g_i], 1) && g_1line[g_i] != '\n')
			if (g_1line[g_i] != g_empty && g_1line[g_i] != g_full)
				return (ERROR);
	}
	g_cols = g_i;
	g_cache = (char *)malloc(sizeof(char) * (g_cols + 1) * g_rows);
	g_buffer= (int *)malloc(sizeof(int) * g_cols);
	if (!g_cache || !g_buffer)
		exit (1);
	g_j = -1;
	flag = 0;
	while(++g_j < g_cols)
	{
		if ((g_cache[g_j] = g_1line[g_j]) == g_empty)
		{
			if (!flag && (flag = 1) && (g_res = 1))
				g_x = g_j;
			g_buffer[g_j] = 1;
		}
		else
			g_buffer[g_j] = 0;
	}
	g_cache[g_cols] = '\n';
	free(g_1line);
	return (SUCCESS);
}
