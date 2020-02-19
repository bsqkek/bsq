/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovella <lnovella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:50:59 by lnovella          #+#    #+#             */
/*   Updated: 2020/02/19 22:02:19 by lnovella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	def_glob(void)
{
	g_rows = 0;
	g_res = 0;
	g_cols = 0;
	g_x = 0;
	g_y = 0;
	g_res = 0;
}

t_bool	add_func2(void)
{
	int	power14;

	def_glob();
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
		while (++g_i < power14 && read(g_fd, &g_1line[g_i], 1)
		&& g_1line[g_i] != '\n')
			if (g_1line[g_i] != g_empty && g_1line[g_i] != g_full)
				return (ERROR);
	}
	return (SUCCESS);
}
