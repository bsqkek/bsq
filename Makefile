# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnovella <lnovella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 19:52:51 by lnovella          #+#    #+#              #
#    Updated: 2020/02/19 21:52:05 by lnovella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = srcs/cache.c srcs/solve_bsq.c srcs/print_bsq.c srcs/main.c srcs/ft_com_funcs.c srcs/add.c

OBJS = cache.o solve_bsq.o print_bsq.o main.o ft_com_funcs.o add.o

FLAGS = -Wall -Wextra -Werror

HEADERS = includes

$(NAME): $(SRCS)
	gcc $(FLAGS) -I $(HEADERS) -c $(SRCS)
	gcc $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
