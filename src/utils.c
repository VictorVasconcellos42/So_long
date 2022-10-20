/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/20 09:40:20 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
