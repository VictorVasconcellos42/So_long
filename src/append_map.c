/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:22:35 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/24 23:39:02 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	insert(t_config *config, void *image, int wid, int hei)

{
	mlx_put_image_to_window(config->server, config->win, image, wid, hei);
}

void	set_phase(t_config *config, int wid, int hei)

{
	if (config->phase[hei][wid] == '1')
		insert(config, config->walls, wid * SPRITE, hei * SPRITE);
	if (config->phase[hei][wid] == '0')
		insert(config, config->floor, wid * SPRITE, hei * SPRITE);
	if (config->phase[hei][wid] == 'P')
	{
		config->avatar.pos_w = wid;
		config->avatar.pos_h = hei;
		insert(config, config->player, wid * SPRITE, hei * SPRITE);
	}
	if (config->phase[hei][wid] == 'C')
		insert(config, config->brahma, wid * SPRITE, hei * SPRITE);
	if (config->phase[hei][wid] == 'E')
		insert(config, config->exit, wid * SPRITE, hei * SPRITE);
}

int	append_map(t_config *config)

{
	int	width;
	int	height;

	height = 0;
	while (config->phase[height])
	{
		width = 0;
		while (config->phase[height][width])
		{
			set_phase(config, width, height);
			width++;
		}
		height++;
	}
	return (0);
}
