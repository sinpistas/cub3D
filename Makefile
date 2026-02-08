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
MLX_DIR		= lib/minilibx-linux
LIBFT		= $(LIBFT_DIR)/libft.a
GNL			= $(GNL_DIR)/getnextline.a
MLX			= $(MLX_DIR)/libmlx.a
LIBS		= $(LIBFT) $(GNL) $(MLX)

##### Sources ##############################
SRC			= main.c \
			  scene/cub_scene.c \
			  parse/cub_parse.c parse/cub_parse_line.c parse/cub_validate_scene.c \
			  parse/cub_check_extension.c parse/cub_parse_id.c parse/cub_map_push.c \
			  parse/cub_finalize_map.c parse/cub_validate_map.c parse/cub_validate_map_cell.c \
			  parse/cub_parse_color.c parse/cub_parse_color_line.c \
			  game/game_init.c game/load_textures.c game/render.c game/camera.c \
			  game/raycast.c game/raycast_utils.c game/raycast_draw.c \
			  game/events.c game/events_update.c game/movement.c game/rotation.c \
			  utils/utils_free.c
SRCS		= $(addprefix $(SRCDIR)/,$(SRC))

##### Objects / deps (flatten in obj/) #####
OBJ_NAMES	= $(notdir $(SRC:.c=.o))
OBJS		= $(addprefix $(OBJDIR)/,$(OBJ_NAMES))
DEPS		= $(OBJS:.o=.d)

##### Include paths ########################
INCLUDES	= -I$(INCDIR) -I$(LIBFT_DIR)/inc -I$(GNL_DIR) -I$(MLX_DIR)

##### Linker flags #########################
LDFLAGS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

##### Where to find %.c ####################
vpath %.c $(SRCDIR) $(SRCDIR)/scene $(SRCDIR)/parse $(SRCDIR)/game $(SRCDIR)/utils

##### Rules ################################
all : $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LDFLAGS) -o $(NAME)
	@echo "✓ $(NAME) compiled successfully"

##### Objects ##############################
$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

##### Libft ################################
$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null

##### Get Next Line ########################
$(GNL):
	@echo "Building get_next_line..."
	@$(MAKE) -C $(GNL_DIR) > /dev/null

##### Minilibx #############################
$(MLX):
	@echo "Building minilibx..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

##### Clean ################################
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@$(MAKE) -C $(GNL_DIR) clean > /dev/null 2>&1
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@echo "✓ Clean complete"

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@$(MAKE) -C $(GNL_DIR) fclean > /dev/null 2>&1
	@echo "✓ Full clean complete"

re: fclean all

##### Deps #############################
-include $(DEPS)

.PHONY: all clean fclean re