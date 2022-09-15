# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:45:07 by vde-vasc          #+#    #+#              #
#    Updated: 2022/09/15 05:38:05 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	src/main.c

OBJS	=	$(SRCS:.c=.o)

NAMELIB	=	statics/libft.a

MLX_A	=	statics/libmlx.a

LIBFT	=	utils/libft/libft.a

PATH_LIB	=	utils/libft

GAME	= so_long

FLAGS	= -Wall -Wextra -Werror

all: $(GAME) $(NAMELIB)

$(NAMELIB):
	@$(MAKE) -s -C $(PATH_LIB)
	@cp $(LIBFT) ./statics 
	@echo "Library created!!!"

.c.o:
	@cc $(FLAGS) $< -c -o $@
	@echo "Objects created!!"

$(GAME): $(NAMELIB) $(OBJS)
	@cc $(FLAGS) $(NAMELIB) $(MLX_A) -framework OpenGL -framework AppKit $(OBJS) -o $(GAME)
	@echo "So_long created!!"

clean:
	@$(MAKE) fclean -s -C $(PATH_LIB)
	@echo "Objects successfully removed"

fclean: clean
	@rm -rf $(NAMELIB)

re: fclean all
