
#include "ft_bsq.h"

int		ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	ft_clear(void)
{
	free(g_cache);
	g_cache = NULL;
}
