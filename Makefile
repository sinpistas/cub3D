# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 11:05:33 by apestana          #+#    #+#              #
#    Updated: 2026/02/05 12:05:59 by apestana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Name #################################
NAME 		= cub3D

##### Compiler && Flags ####################
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror 
CPPFLAGS	= -MMD -MP

##### Directories ##########################
SRCDIR 		= src
OBJDIR		= obj
INCDIR		= inc

##### Libraries ############################
LIBFT_DIR	= lib/libft
GNL_DIR		= lib/getnextline
LIBFT		= $(LIBFT_DIR)/libft.a
GNL			= $(GNL_DIR)/getnextline.a
LIBS		= $(LIBFT) $(GNL)

##### Sources, objects and deps ############
SRC			= main.c cub_scene.c cub_parse.c utils_free.c
SRCS		= $(addprefix $(SRCDIR)/,$(SRC))
OBJS		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
DEPS		= $(OBJS:.o=.d)

##### Rules ################################
all : $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

##### Objects ##############################
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) \
		-I$(INCDIR) \
		-I$(LIBFT_DIR)/inc \
		-I$(GNL_DIR) \
		-c $< -o $@

##### Libft ################################
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

##### Get Next Line ########################
$(GNL):
	$(MAKE) -C $(GNL_DIR)

##### Clean ################################
clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

##### Deps #############################
-include $(DEP)

.PHONY: all clean fclean re