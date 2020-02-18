
#include "ft_bsq.h"

t_bool	ft_create_cache(void)
{
	char c;
	//char flag;

	g_rows = 0;
	g_res = 1;
	while (read(g_fd, &g_empty, 1) && g_empty >= '0' && g_empty <= '9')
	{
		if (g_rows >= 214748364 && g_empty > '7')
			return (ERROR);
		g_rows = g_rows * 10 + g_empty - '0';
	}
	g_cols = 0;
	if (read(g_fd, &g_full, 1) < 0 || read(g_fd, &g_square, 1) < 0
		|| read(g_fd, &c, 1) < 0 || g_rows < 1 || g_empty == g_full
		|| g_empty == g_square || g_full == g_square || c != '\n')
		return (ERROR);
	g_buf = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while (read(g_fd, &c, 1) && c != '\n')
	{
		g_buf[g_cols] = c;
		++g_cols;
	}
	g_cache = (char **)malloc(sizeof(char *) * g_rows);
	g_cache[0] = (char *)malloc(sizeof(char) * g_cols);
	g_buffer= (int *)malloc(sizeof(int) * g_cols);
	g_j = -1;
	while(++g_j < g_cols)
	{
		if ((g_cache[0][g_j] = g_buf[g_j]) == g_empty)
			g_buffer[g_j] = 1;
		else
			g_buffer[g_j] = 0;
	}
	free(g_buf);
	return (SUCCESS);
}
