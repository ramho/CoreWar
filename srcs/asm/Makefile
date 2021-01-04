# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoorntj <rhoorntj@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 14:36:19 by rhoorntj          #+#    #+#              #
#    Updated: 2020/12/16 16:35:52 by rhoorntj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm
CFLAGS	= #-Wall -Wextra -Werror

SRC		= asm.c free_error.c parse_tokens.c valid_file.c parse_header.c
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
