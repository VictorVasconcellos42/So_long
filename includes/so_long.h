/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:32:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/20 00:06:40 by vde-vasc         ###   ########.fr       */
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
# define MADEIRA "images/madeira.xpm"
# define FERNANDA "images/fernanda.xpm"

typedef struct	s_begin

{
	void	*server;
	void	*sprite;
	int		width;
	int		height;
	void	*window;
}	t_begin;

void	reader(int fd);

#endif
