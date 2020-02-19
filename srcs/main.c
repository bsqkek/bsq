
#include "ft_bsq.h"

int main(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc || argc == 1)
	{
		if (argc == 1)
			g_fd = 0;
		else
			g_fd = open(argv[i], O_RDONLY);
		if (ft_create_cache() && ft_solve_bsq() && ft_final_cache())
			ft_print();
		else
			write(2, "map error\n", 10);
		if (argc > 2 && i < argc - 1)
			write(1, "\n", 1);
		close(g_fd);
		free(g_cache);
		free(g_buffer);
		if (argc == 1)
			return (0);
	}
	return (0);
}
