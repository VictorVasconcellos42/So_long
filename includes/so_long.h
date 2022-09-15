/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:32:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/15 11:49:58 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "../utils/libft/libft.h"

# define VICTOR "images/victor.xpm"
# define MADEIRA "images/madeira.xpm"

typedef struct	s_sprite

{
	void	*sprite;
	int		width;
	int		height;
}	t_sprite;

typedef struct	s_begin

{
	void	*server;
	void	*window;
}	t_begin;

#endif
