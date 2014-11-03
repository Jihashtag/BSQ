# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbert <jbert@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/29 23:05:58 by jbert             #+#    #+#              #
#    Updated: 2014/08/21 05:58:36 by jbert            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq

SRC		=	main.c	bsq.c	ft_split_whitespaces.c	map.c

OBJ		=	$(SRC:.c=.o)

FLAG	=	-Wall -Wextra -Werror -Ofast -ansi -pedantic

$(NAME):
			gcc $(FLAG) -c $(SRC)
			gcc $(FLAG) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(OBJ) $(NAME)

re:	fclean all

.PHONY: all NAME clean fclean re
