/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 03:06:11 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/20 15:18:49 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_game(t_config *game)

{
	game->win_w = ft_strlen(game->phase[0]);
	game->win_h = total_height(game->phase);
}

int	main(int argc, char *argv[])

{
	t_config	game;

	if	(argc != 2)
		return (ft_printf("Invalid format, try ./So_long <map.ber>"));
	game.phase = phase_creator(argv[1]);
	if (!(game.phase))
		return (NULL);
	init_game(&game);
	game.server = mlx_init();
	game.win = mlx_new_window(game.server, game.win_w * 32, game.win_h * 32, "So_long");
}
