/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:27:10 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/15 11:50:23 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keye_hook(int keycode)

{
	if (keycode == 13)
		ft_printf("W\n");
	if (keycode == 0)
		ft_printf("A\n");
	if (keycode == 1)
		ft_printf("S\n");
	if (keycode == 2)
		ft_printf("D\n");
	if (keycode == 3)
		ft_printf("❤️ \n");
	return (0);
}

int	main(void)

{
	t_begin		start;
	t_sprite	img;
	int			i = -1;

	start.server = mlx_init();
	start.window = mlx_new_window(start.server, 352, 352, "Test");
	img.sprite = mlx_xpm_file_to_image(start.server, MADEIRA, &img.width, &img.height);
	while (++i * 32 <= 320)
		mlx_put_image_to_window(start.server, start.window, img.sprite, i * 32, 0);
	i = -1;
	while (++i * 32 <= 320)
 		mlx_put_image_to_window(start.server, start.window, img.sprite, 0, i * 32);
	i = -1;
	while (++i * 32 <= 320)
 		mlx_put_image_to_window(start.server, start.window, img.sprite, 320, i * 32);
	i = -1;
	while (++i * 32 <= 320)
 		mlx_put_image_to_window(start.server, start.window, img.sprite, i * 32, 320);
	mlx_loop(start.server);
	return (0);
}
