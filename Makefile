# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apestana <apestana@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 11:05:33 by apestana          #+#    #+#              #
#    Updated: 2026/02/07 19:55:37 by apestana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Name #################################
NAME 		= cub3D

##### Compiler && Flags ####################
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror 
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

##### Sources ##############################
SRC			= main.c \
			  scene/cub_scene.c \
			  parse/cub_parse.c parse/cub_parse_line.c parse/cub_validate_scene.c \
			  parse/cub_check_extension.c parse/cub_parse_id.c parse/cub_map_push.c \
			  parse/cub_finalize_map.c parse/cub_validate_map.c parse/cub_validate_map_cell.c \
			  parse/cub_parse_color.c parse/cub_parse_color_line.c\
			  utils/utils_free.c
SRCS		= $(addprefix $(SRCDIR)/,$(SRC))

##### Objects / deps (flatten in obj/) #####
OBJ_NAMES	= $(notdir $(SRC:.c=.o))
OBJS		= $(addprefix $(OBJDIR)/,$(OBJ_NAMES))
DEPS		= $(OBJS:.o=.d)

##### Include paths ########################
INCLUDES	= -I$(INCDIR) -I$(LIBFT_DIR)/inc -I$(GNL_DIR)

##### Where to find %.c ####################
vpath %.c $(SRCDIR) $(SRCDIR)/scene $(SRCDIR)/parse $(SRCDIR)/utils

##### Rules ################################
all : $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

##### Objects ##############################
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

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
-include $(DEPS)

.PHONY: all clean fclean re