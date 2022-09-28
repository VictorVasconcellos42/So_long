/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:11:47 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/28 12:30:29 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*input_image(t_config *config, char *path_img)

{
	int		width;
	int		height;
	void	*image;

	image = mlx_xpm_file_to_image(config->server, path_img, &width, &height);
	return (image);
}

int	start_game(t_config *config)

{
	config->server = mlx_init();
	config->win = mlx_new_window(config->server, config->phase_columns,
			config->phase_rows, "Vitin Game");
	config->player = input_image(config, VICTOR);
	config->meat = input_image(config, MEAT);
	config->walls = input_image(config, WALLS);
	config->floor = input_image(config, FLOOR);
	config->brahma = input_image(config, BRAHMA);
	config->exit = input_image(config, EXIT);
	return (0);
}
