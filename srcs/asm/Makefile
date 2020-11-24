# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 14:36:19 by rhoorntj          #+#    #+#              #
#    Updated: 2020/11/24 16:22:34 by rhoorntj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm
CFLAGS	= #-Wall -Wextra -Werror

SRC		= asm.c free_error.c parse_tokens.c valid_file.c
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
