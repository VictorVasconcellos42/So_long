/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:37:38 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/18 18:12:45 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_x(void)

{
	exit(0);
}

int	main(int argc, char *argv[])

{
	t_config	config;

	if (argc != 2)
		return (error_msg("./so_long maps/<map>.ber only!"));
	config.phase = map_generator(&config, argv[1]);
	if (!config.phase)
		return (0);
	start_variables(&config);
	start_game(&config);
	append_map(&config);
	mlx_key_hook(config.win, keys_game, &config);
	mlx_hook(config.win, 17, 2, close_x, &config);
	mlx_loop_hook(config.server, &append_map, &config);
	mlx_loop(config.server);
	return (0);
}
