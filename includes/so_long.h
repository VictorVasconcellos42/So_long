/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:32:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/23 14:57:29 by vde-vasc         ###   ########.fr       */
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
# define BRAHMA "images/brahma.xpm"

# define S_SPRITE 32

// My struct for player in my game:

typedef struct	s_avatar

{
	int		pos_x;
	int		pos_y;
}	t_avatar;

// My struct's struct for my game:

typedef struct	s_config


{
	void	*server;
	void	*win;
	void	*sprite;

	int		width;
	int		height;
	int		win_w;
	int		win_h;
	int		phase_columns;
	int		phase_rows;

	char	**phase;
	char	**copy_phase;

}	t_config;

#endif
