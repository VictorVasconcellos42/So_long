/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/28 12:39:01 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	avatar_steps(t_config *config)

{
	config->avatar_move++;
	ft_printf("Move count: %i\n", config->avatar_move);
}

void	free_to_maps(char **map)

{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
	return ;
}

int	game_finish(t_config *config)

{
	free_to_maps(config->phase);
	mlx_destroy_image(config->server, config->brahma);
	mlx_destroy_image(config->server, config->walls);
	mlx_destroy_image(config->server, config->floor);
	mlx_destroy_image(config->server, config->exit);
	mlx_destroy_image(config->server, config->player);
	mlx_destroy_window(config->server, config->win);
	free(config->server);
	exit(0);
	return (0);
}

void	start_variables(t_config *config)

{
	config->count_brahmas = 0;
	config->end = 0;
	config->avatar_move = 0;
	config->exit_amount = 0;
	config->avatar_amount = 0;
	config->coin_amount = 0;
	config->wall_amount = 0;
}

int	error_msg(char *msg)

{
	ft_printf("Error: %s\n", msg);
	return (1);
}
