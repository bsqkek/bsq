
#include "ft_bsq.h"

void	ft_print(void)
{
		write(1, g_cache, (g_cols + 1) * g_rows);
}
