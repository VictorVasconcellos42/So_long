/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:52:51 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/25 00:22:08 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	possible_move(int wid, int hei, t_config *config)

{
	if (config->phase[hei][wid] == '1')
		return (0);
	else if (config->phase[hei][wid] == 'E' && config->count_brahmas != 0)
		return (0);
	return (1);
}

void	avatar_img(t_config *config, char *sprite)

{
	mlx_destroy_image(config->server, config->player);
	config->player = input_image(config, sprite); 
}

void	avatar_move(t_config *config, int wid, int hei)

{
	int	old_pos_w;
	int	old_pos_h;

	old_pos_w = config->avatar.pos_w;
	old_pos_h = config->avatar.pos_h;
	if (!possible_move(wid, hei, config))
		return ;
	else if (config->phase[hei][wid] == 'E')
		config->end = 1;
	else if (config->phase[hei][wid] == 'C')
		config->count_brahmas--;
	config->avatar.pos_w = wid;
	config->avatar.pos_h = hei;
	config->phase[old_pos_h][old_pos_w] = '0';
	if (!config->end)
		config->phase[hei][wid] = 'P';
	if (config->end)
	{
		ft_printf("You Win! Uhuuuuuu");
		exit(0);
	}
}

void	moviments(int keycode, t_config *config)

{
	if (config->end)
		return ;
	if (keycode == W_KEY)
	{
		avatar_img(config, W_PLAYER);
		avatar_move(config, config->avatar.pos_w, config->avatar.pos_h - 1);
	}
	if (keycode == A_KEY)
	{
		avatar_img(config, A_PLAYER);
		avatar_move(config, config->avatar.pos_w - 1, config->avatar.pos_h);
	}
	if (keycode == D_KEY)
	{
		avatar_img(config, D_PLAYER);
		avatar_move(config, config->avatar.pos_w + 1, config->avatar.pos_h);
	}
	if (keycode == S_KEY)
	{
		avatar_img(config, S_PLAYER);
		avatar_move(config, config->avatar.pos_w, config->avatar.pos_h + 1);
	}
}

int	keys_game(int keycode, t_config *config)

{
	if (keycode == ESC)
		exit(0);
	moviments(keycode, config);
	return (0);
}
