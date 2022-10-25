/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:11:47 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/24 23:38:42 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*input_image(t_config *config, char *path_img)

{
	int		width;
	int		height;
	void	*image;

	image = mlx_xpm_file_to_image(config->server, path_img, &width, &height);
	if (!image)
	{
		error_msg("Where's your image bro?");
		exit (1);
	}
	return (image);
}

int	start_game(t_config *config)

{
	config->server = mlx_init();
	config->win = mlx_new_window(config->server, config->phase_columns,
			config->phase_rows, "Vitin Game");
	config->player = input_image(config, VICTOR);
	config->walls = input_image(config, WALLS);
	config->floor = input_image(config, FLOOR);
	config->brahma = input_image(config, BRAHMA);
	config->exit = input_image(config, EXIT);
	return (0);
}
