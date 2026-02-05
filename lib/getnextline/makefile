# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 14:46:37 by apestana          #+#    #+#              #
#    Updated: 2025/03/16 16:14:37 by apestana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

LIB = ar rcs

SRC = get_next_line.c \
	get_next_line_utils.c

OBJ = ${SRC:.c=.o}

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
