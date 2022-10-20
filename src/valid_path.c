/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:07:51 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/20 13:47:43 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void	append_player(t_config *player, int i, int j)

{
	while (player->cp_map[i])
	{
		j = 0;
		while (player->cp_map[i][++j] != '1')
		{
			if (player->cp_map[i][j] == 'C')
				j++;
			player->cp_map[i][j] = 'P';
		}	
		i++;
	}
}

int	valid_path(t_config *cp, int i, int j)

{
	append_player(cp, i, j);
	while (cp->cp_map[i])
	{
		j = 0;
		while (cp->cp_map[i][++j])
		{
			if (cp->cp_map[i][j] == 'C' || cp->cp_map[i][j] == 'E')
			{
				if (ft_strchr("CP", cp->cp_map[i + 1][j]))
					cp->wall_amount++;
				if (ft_strchr("CP", cp->cp_map[i - 1][j]))
					cp->wall_amount++;
				if (ft_strchr("CP", cp->cp_map[i][j + 1]))
					cp->wall_amount++;
				if (ft_strchr("CP", cp->cp_map[i][j - 1]))
					cp->wall_amount++;
				if (cp->wall_amount < 1)
					return (error_msg("Invalid path, Change please"));
				else
					cp->wall_amount = 0;
			}
		}
		i++;
	}
	return (0);
}
