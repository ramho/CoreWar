# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 14:14:59 by rhoorntj          #+#    #+#              #
#    Updated: 2021/04/17 14:15:01 by rhoorntj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= corewar
#CFLAGS	= -Wall -Wextra -Werror

SRC		=	corewar.c  parse.c op.c

OBJ		= $(SRC:.c=.o)
LIB		= -L../../libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(SRC) $(LIB) -o $(NAME) #$(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
