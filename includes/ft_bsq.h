/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovella <lnovella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:06:55 by lnovella          #+#    #+#             */
/*   Updated: 2020/02/19 21:07:10 by lnovella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H

# define FT_BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>

# define SUCCESS 1
# define ERROR 0

typedef int		t_bool;

int				g_i;
int				g_j;
int				g_x;
int				g_y;
int				g_rows;
int				g_cols;
int				g_res;
char			g_tmp[2];
char			g_empty;
char			g_full;
char			g_square;
char			*g_cache;
char			g_c;
int				*g_buffer;
char			*g_1line;
short			g_fd;

/*
** cache.c
*/
t_bool	ft_create_cache(void);
t_bool	read_map_options(void);
void	ft_realloc(int length);

/*
** ft_com_funcs.c
*/
int		ft_min(int a, int b, int c);
void	ft_clear(void);

/*
** print_bsq.c
*/
void	ft_print(void);

/*
** solve_bsq.c
*/
t_bool	ft_solve_bsq(void);
t_bool	ft_final_cache(void);
t_bool	is_valid(void);
void	ft_analize(void);

/*
** add.c
*/
t_bool	add_func2(void);

#endif
