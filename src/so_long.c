/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:27:10 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/23 14:56:58 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_X_hook(void)

{
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_config *core)

{
	if (keycode == 53)
	{
		mlx_destroy_image(core->server, core->sprite);
		mlx_destroy_window(core->server, core->win);
		exit(0);
	}
	return (0);
}

int	main(void)

{
	t_config		core;
	int			i = -1;

	core.server = mlx_init();
	core.win = mlx_new_window(core.server, 352, 352, "Test");
	core.sprite = mlx_xpm_file_to_image(core.server, WALLS, &core.width, &core.height);
	while (++i * 32 <= 320)
		mlx_put_image_to_window(core.server, core.win, core.sprite, i * 32, 0);
	i = -1;
	while (++i * 32 <= 320)
 		mlx_put_image_to_window(core.server, core.win, core.sprite, 0, i * 32);
	i = -1;
	while (++i * 32 <= 320)
 		mlx_put_image_to_window(core.server, core.win, core.sprite, 320, i * 32);
	i = -1;
	while (++i * 32 <= 320)
 		mlx_put_image_to_window(core.server, core.win, core.sprite, i * 32, 320);
	core.sprite = mlx_xpm_file_to_image(core.server, VICTOR, &core.width, &core.height);
	mlx_put_image_to_window(core.server, core.win, core.sprite, 32, 32);
	core.sprite = mlx_xpm_file_to_image(core.server, BRAHMA, &core.width, &core.height);
	mlx_put_image_to_window(core.server, core.win, core.sprite, 32, 64);
	mlx_key_hook(core.win, key_hook, &core);
	mlx_hook(core.win, 17, 0, key_X_hook, &core);
	mlx_loop(core.server);
	return (0);
}
