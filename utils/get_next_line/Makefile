# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 19:28:56 by vde-vasc          #+#    #+#              #
#    Updated: 2022/09/19 23:04:22 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line.a

SRCS	=	get_next_line.c get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	rcs

AR	=	ar

.c.o:
	${CC} ${FLAGS} -c $<

all: $(NAME)

$(NAME):	${OBJS}
	@${AR} ${LFLAGS} ${NAME} ${OBJS}

clean:
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf $(NAME)
