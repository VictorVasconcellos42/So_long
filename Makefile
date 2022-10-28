# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:45:07 by vde-vasc          #+#    #+#              #
#    Updated: 2022/10/28 07:28:20 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	src/so_long.c src/map_generator.c src/keys.c src/append_map.c \
			src/start_game.c src/utils.c src/ft_valid.c src/valid_path.c

OBJS	=	$(SRCS:.c=.o)

NAMELIB	=	statics/libft.a

MLX_A	=	statics/libmlx.a

MLX		=	mlx/libmlx.a

LIBFT	=	utils/libft/libft.a

GNL_LIB	=	statics/get_next_line.a

GNL		=	utils/get_next_line/get_next_line.a

PATH_LIB	=	utils/libft

PATH_GNL	=	utils/get_next_line

MLX_PATH	=	./mlx

GAME	= so_long

FLAGS	= -Wall -Wextra -Werror

#colors:

GREEN	=	\033[0;32m

RED	=	\033[0;31m

BLUE	=	\033[0;34m

END	=	\033[0m

all: $(GAME) $(NAMELIB) $(MLX_A)

$(NAMELIB):
	@$(MAKE) -s -C $(PATH_LIB)
	@$(MAKE) -s -C $(PATH_GNL)
	@cp $(LIBFT) ./statics
	@cp $(GNL)	./statics
	@echo "$(BLUE)[ C R E A T I N G ... ]$(END)"
	@echo "$(GREEN)Library created!!!$(END)"

$(MLX_A):
	@$(MAKE) -C $(MLX_PATH) &> /dev/null
	@mv $(MLX) ./statics
	@echo "$(BLUE)[ C R E A T I N G ... ]$(END)"	
	@echo "$(GREEN)Library created!!!$(END)"

.c.o:
	@cc $(FLAGS) $< -c -o $@
	@echo "$(GREEN)Objects created!!$(END)"

$(GAME): $(NAMELIB) $(MLX_A) $(OBJS)
	@cc $(FLAGS) $(NAMELIB) $(GNL_LIB) $(MLX_A) -framework OpenGL -framework AppKit $(OBJS) -o $(GAME)
	@echo "$(GREEN)So_long created!!$(END)"

clean:
	@$(MAKE) fclean -s -C $(PATH_LIB)
	@rm -rf src/*.o
	@echo "$(BLUE)[ D E L E T I N G ... ]$(END)"
	@echo "$(RED)Objects successfully removed!$(END)"

fclean: clean
	@rm -rf $(NAMELIB)
	@rm -rf $(GNL_LIB)
	@RM -rf $(MLX_A)
	@make clean -s -C $(MLX_PATH)
	@rm -rf so_long
	@rm -rf so_long.DSYM/

debug: $(NAMELIB) $(OBJS)
	@gcc -g $(FLAGS) $(NAMELIB) $(GNL_LIB) $(MLX_A) -framework OpenGL -framework AppKit $(OBJS) -o $(GAME)
	@rm -rf $(OBJS)
	@rm -rf so_long.DSYM/
	@echo "$(GREEN)So_long debugger created!!$(END)"

re: fclean all
