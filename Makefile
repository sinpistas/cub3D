# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 11:05:33 by apestana          #+#    #+#              #
#    Updated: 2026/02/05 11:36:16 by apestana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Name #################################
NAME 		= cube3D

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
SRC			= main.c
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
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INCDIR) -c $< -o $@

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