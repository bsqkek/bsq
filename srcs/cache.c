
#include "ft_bsq.h"

void	set_global_variables(void)
{
	g_rows = 0;
	g_res = 1;
	g_cols = 0;
}

t_bool	read_map_options(void)
{
	int		power10;

	g_1line = (char *)malloc(sizeof(char) * 14);
	if (!g_1line)
		return (ERROR);
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
	printf("3: g_rows = %d\n", g_rows);
	printf("4: empty = %c, full = %c, square = %c\n", g_empty, g_full, g_square);
	if (g_rows < 1 || g_j != g_i
		|| g_empty == g_full || g_empty == g_square || g_full == g_square)
		return (ERROR);
	printf("5: empty = %c, full = %c, square = %c\n", g_empty, g_full, g_square);
	return (SUCCESS);
}

void	ft_realloc(int length)
{
	char	*newstr;
	int		i;

	newstr = (char *)malloc(sizeof(char) * length);
	if (!newstr)
		exit (1);
	i = -1;
	while (++i < length / 14)
		newstr[i] = g_1line[i];
	g_1line = newstr;
	printf("Here!\n");
}

t_bool	ft_create_cache(void)
{
	int		power14;

	set_global_variables();
	if (!read_map_options())
		return (ERROR);
	g_cache = (char **)malloc(sizeof(char *) * g_rows);
		if (!g_cache)
			exit (1);
	g_i = -1;
	while (++g_i < 14 && read(g_fd, &g_1line[g_i], 1) && g_1line[g_i] != '\n')
		if (g_1line[g_i] != g_empty && g_1line[g_i] != g_full)
			return (ERROR);
	power14 = 14;
	while (g_i == power14 && g_1line[power14 - 1] != '\n')
	{
		power14 *= 14;
		ft_realloc(power14);
		g_i--;
		while (++g_i < power14 && read(g_fd, &g_1line[g_i], 1) && g_1line[g_i] != '\n')
			if (g_1line[g_i] != g_empty && g_1line[g_i] != g_full)
				return (ERROR);
	}
	g_cols = g_i;
	printf("g_cols = %d\n", g_cols);
	printf("g_1line = %s\n", g_1line);
	if (g_1line[g_cols] == '\n')
		printf("Yes!\n");
	g_cache[0] = (char *)malloc(sizeof(char) * g_cols);
	g_buffer= (int *)malloc(sizeof(int) * g_cols);
	if (!g_cache || !g_buffer)
		exit (1);
	g_j = -1;
	while(++g_j < g_cols)
	{
		if ((g_cache[0][g_j] = g_1line[g_j]) == g_empty)
			g_buffer[g_j] = 1;
		else
			g_buffer[g_j] = 0;
	}
	free(g_1line);
	return (SUCCESS);
}
