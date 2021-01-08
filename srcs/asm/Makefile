# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 14:36:19 by rhoorntj          #+#    #+#              #
#    Updated: 2021/01/08 17:37:19 by rhoorntj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm
#CFLAGS	= -Wall -Wextra -Werror

SRC		=	asm.c free_error.c parse_tokens.c valid_file.c parse_header.c \
			parse_op.c parse_param.c parse_label.c op_chained_list.c \
			label_chained_list.c init.c

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
