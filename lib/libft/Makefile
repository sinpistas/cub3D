# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 14:21:53 by apestana          #+#    #+#              #
#    Updated: 2025/03/26 18:07:03 by apestana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a

SRC_DIR		:= src
BUILD_DIR	:= obj
SRCS 		:= 	ft_isalnum.c    ft_isdigit.c    ft_memcmp.c     ft_memset.c  	\
				ft_strlcpy.c    ft_strnstr.c    ft_toupper.c  	ft_atoi.c    	\
				ft_isalpha.c    ft_isprint.c    ft_memcpy.c     ft_strchr.c  	\
				ft_strlen.c     ft_strrchr.c    ft_bzero.c      ft_isascii.c 	\
				ft_memchr.c     ft_memmove.c    ft_strlcat.c    ft_strncmp.c 	\
				ft_tolower.c	ft_calloc.c		ft_strdup.c		ft_substr.c 	\
				ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c		\
				ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	\
				ft_putendl_fd.c	ft_putnbr_fd.c	ft_lstnew.c						\
				ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c				\
				ft_lstdelone.c	ft_lstclear.c	ft_lstadd_front.c				\
				ft_lstmap.c		ft_lstiter.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS  	:= -Wall -Werror -Wextra
CPPFLAGS	:= -MMD -MP -I inc
AR			:= ar
ARFLAGS		:= -r -c -s

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
#.SILENT:
