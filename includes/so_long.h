/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:32:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/20 03:39:03 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "../utils/libft/libft.h"
# include <stdlib.h>
# include "../utils/get_next_line/get_next_line.h"

# define VICTOR "images/victor.xpm"
# define WALLS "images/madeira.xpm"

# define SIZE_SPRITE 32

// My struct for player in my game:

typedef struct	s_avatar

{
	int		pos_x;
	int		pos_y;
}	t_avatar;

// My struct for start my graphical conection!

typedef struct	s_server

{
	void	*init;
	void	*win;
}	t_server;

// My struct's struct for my game:

typedef struct	s_config


{
	t_server	server;
	t_avatar	avatar;
	
}	t_config;

#endif
