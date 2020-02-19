/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovella <lnovella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:29:17 by lnovella          #+#    #+#             */
/*   Updated: 2020/02/19 22:16:41 by lnovella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_analize(void)
{
	if (g_cache[g_i * (g_cols + 1) + g_j] == g_full)
		g_buffer[g_j] = 0;
	else if (g_j == 0)
		g_buffer[g_j] = 1;
	else
		g_buffer[g_j] = 1 + ft_min(g_buffer[g_j], g_buffer[g_j - 1], g_tmp[0]);
	if (g_j > 0)
		g_tmp[0] = g_tmp[1];
	if (g_buffer[g_j] > g_res)
	{
		g_res = g_buffer[g_j];
		g_x = g_j;
		g_y = g_i;
	}
}

t_bool	ft_solve_bsq(void)
{
	if (!(is_valid()))
		return (ERROR);
	g_i = 1;
	while (g_i < g_rows)
	{
		g_j = 0;
		g_tmp[0] = g_buffer[g_j];
		while (g_j < g_cols)
		{
			g_tmp[1] = g_buffer[g_j];
			ft_analize();
			g_j++;
		}
		g_i++;
	}
	return (SUCCESS);
}

t_bool	ft_one_column(void)
{
	char	c;

	g_i = g_cols + 1;
	while (read(0, &c, 1))
	{
		if ((g_i % (g_cols + 1) < g_cols && c != g_empty && c != g_full)
			|| (g_i == g_rows * (g_cols + 1) - 1 && c != '\n')
			|| (g_i == g_rows * (g_cols + 1) && c != '\0'))
		{
			while (read(0, &c, 1))
				;
			return (ERROR);
		}
		g_cache[g_i] = c;
		g_i++;
	}
	if (c != '\n')
		return (ERROR);
	return (SUCCESS);
}

t_bool	is_valid(void)
{
	char	c;

	if (!g_fd)
		return (ft_one_column());
	if (read(g_fd, g_cache + g_cols + 1, (g_rows - 1) * (g_cols + 1)) < 0)
		return (ERROR);
	g_i = 1;
	while (g_i < g_rows)
	{
		g_j = 0;
		while (g_j < g_cols)
		{
			if (g_cache[g_i * (g_cols + 1) + g_j] != g_empty &&
				g_cache[g_i * (g_cols + 1) + g_j] != g_full)
				return (ERROR);
			g_j++;
		}
		if (g_cache[g_i * (g_cols + 1) + g_j] != '\n')
			return (ERROR);
		g_i++;
	}
	if (read(g_fd, &c, 1) && c != '\0')
		return (ERROR);
	return (SUCCESS);
}

t_bool	ft_final_cache(void)
{
	g_i = g_y + 1 - g_res;
	while (g_i <= g_y)
	{
		g_j = g_x + 1 - g_res;
		while (g_j <= g_x)
		{
			g_cache[g_i * (g_cols + 1) + g_j] = g_square;
			g_j++;
		}
		g_i++;
	}
	return (SUCCESS);
}
