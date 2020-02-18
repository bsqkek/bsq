
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
	while (read(g_fd, &c, 1) && c != '\n' && (g_buf[g_cols] = c))
		++g_cols;
	g_cache = (char **)malloc(sizeof(char *) * g_rows);
	g_i = -1;
	while (++g_i < g_rows)
		g_cache[g_i] = (char *)malloc(sizeof(char) * g_cols);
	free(g_buf);
	return (SUCCESS);
}
