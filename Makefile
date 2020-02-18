# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnovella <lnovella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 19:52:51 by lnovella          #+#    #+#              #
#    Updated: 2020/02/18 14:57:32 by lnovella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = srcs/cache.c srcs/solve_bsq.c srcs/print_bsq.c srcs/main.c srcs/ft_com_funcs.c

OBJS = cache.o solve_bsq.o print_bsq.o main.o ft_com_funcs.o

HEADERS = includes

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I $(HEADERS) -c $(SRCS)
	gcc -o $(NAME) $(OBJS)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
