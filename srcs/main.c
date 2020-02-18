
#include "ft_bsq.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		g_fd = 0;
	else
		g_fd = open(argv[1], O_RDONLY);
	if (ft_create_cache() && ft_solve_bsq() && ft_final_cache())
		ft_print();
	else
		write(2, "map error\n", 10);
	close(g_fd);
	return (0);
}
