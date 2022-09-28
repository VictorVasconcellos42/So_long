/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:37:38 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/27 15:47:35 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_X(void)

{
	exit(0);
}

int	close_window(int keycode, t_config *config)

{
	if (keycode == ESC)
	{
		mlx_destroy_window(config->server, config->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char *argv[])

{
	t_config config;

	if (argc != 2)
		return (ft_printf("Error: ./so_long maps/<map>.ber only!\n"));
	config.phase = map_generator(&config, argv[1]);
	if (!config.phase)
		return (0);
	start_game(&config);
	append_map(&config);
	mlx_key_hook(config.win, keys_game, &config);
	mlx_hook(config.win, 17, 2, close_X, &config);
	mlx_loop_hook(config.server, &append_map, &config);
	mlx_loop(config.server);
}
