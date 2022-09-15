/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:27:10 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/15 07:37:20 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keye_hook(int keycode)

{
	if (keycode == 13)
		ft_printf("BOM DIA LETICIA!!!\n");
	if (keycode == 0)
		ft_printf("ESPERO QUE VOCE TENHA UM EXCELENTE DIA HOJE!\n");
	if (keycode == 1)
		ft_printf("POIS VOCE MERECE BASTANTE\n");
	if (keycode == 2)
		ft_printf("PORQUE VAI SOFRER NO LABORATORIO HAHAHA beijos!\n");
	if (keycode == 3)
		ft_printf("❤️  ❤️  ❤️  ❤️  ❤️  ❤️  ❤️ \n");
	return (0);
}

int	main(void)

{
	t_begin		start;
	t_sprite	img;
	int			i = -1;

	start.server = mlx_init();
	start.window = mlx_new_window(start.server, 352, 352, "Test");
	img.sprite = mlx_xpm_file_to_image(start.server, VICTOR, &img.width, &img.height);
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
