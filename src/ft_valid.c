/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:14:19 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/20 07:49:41 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	has_plus_newline(char *string)

{
	int	i;

	i = -1;
	while (string[++i])
		if (string[i] == '\n' && string[i + 1] == '\n')
			return (error_msg("Wrong Format!!!"));
	return (0);
}

static int	valid_map_format(t_config *config)

{	
	const int	width_len = ft_strlen(config->copy_phase[0]);
	int			i;

	i = 1;
	while (config->copy_phase[i])
	{
		if (width_len != ft_strlen(config->phase_rows[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	valid_walls(t_config	*config, int i, int j, int count)

{
	while (config->copy_phase[i])
	{
		if (config->copy_phase[i + 1] == NULL || i == 0)
		{
			j = -1;
			while (config->copy_phase[i][++j])
				if (config->copy_phase[i][j] != '1')
					return (1);
		}
		j = ft_strlen(config->copy_phase[i]) - 1;
		if (config->copy_phase[i][0] == '1')
			count++;
		if (config->copy_phase[i][j] == '1')
			count++;
		if (count != 2)
			return (1);
		else
			count = 0;
		i++;
	}
	return (0);
}

static int	valid_quantiy(t_config	*config, int i, int j, int count)

{
	while (config->copy_phase[i])
	{
		j = -1;
		while (config->copy_phase[i][++j])
		{
			if (config->copy_phase[i][j] == 'E')
				config->exit_amount++;
			else if (config->copy_phase[i][j] == 'C')
				config->coin_amount++;
			else if (config->copy_phase[i][j] == 'P')
				config->avatar_amount++;
			j++;
		}
	}
	if (config->avatar_amount != 1 || config->exit_amount != 1 \
	|| config->coin_amount < 1)
		return (1);
	return (0);
}

int	ft_valid(t_config	*config)

{
	if (valid_map_format(config) == 1)
		return (error_msg("Map isn't a rectangle!!"));
	else if (valid_walls(config, 0, 0, 0) == 1)
		return (error_msg("Map isn't surrounded by walls"));
	else if (valid_quantiy(config, 0, 0, 0) == 1)
		return (error_msg("Map Invalid, Too many or too few characters"));
	return (0);
}
