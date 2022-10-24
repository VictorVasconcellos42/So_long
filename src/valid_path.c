/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:07:51 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/24 18:39:40 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	exit_tester(t_config *cp, int i, int j)

{
	cp->cp_map[cp->avatar.pos_h][cp->avatar.pos_w] = 'P';
	while (cp->cp_map[++i])
	{
		j = 0;
		while (cp->cp_map[i][++j])
		{
			if (cp->cp_map[i][j] == 'E')
			{
				if (ft_strchr("P", cp->cp_map[i + 1][j]))
					cp->wall_amount++;
				if (ft_strchr("P", cp->cp_map[i - 1][j]))
					cp->wall_amount++;
				if (ft_strchr("P", cp->cp_map[i][j + 1]))
					cp->wall_amount++;
				if (ft_strchr("P", cp->cp_map[i][j - 1]))
					cp->wall_amount++;
				if (cp->wall_amount < 1)
					return (1);
				else
					cp->wall_amount = 0;
			}
		}
	}
	return (0);
}

int	valid_path(t_config *cp, int i, int j)

{
	if (cp->cp_map[i][j] == 'C' || cp->cp_map[i][j] == '0')
	{
		if (cp->cp_map[i][j] == 'C')
			cp->coin_amount--;
		if (cp->cp_map[i][j] == 'E')
			cp->exit_amount--;
		cp->cp_map[i][j] = 'P';
		valid_path(cp, i - 1, j);
		valid_path(cp, i + 1, j);
		valid_path(cp, i, j + 1);
		valid_path(cp, i, j - 1);
	}
	if (cp->coin_amount != 0)
		return (1);
	return (0);
}
