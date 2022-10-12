/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/12 11:00:54 by vde-vasc         ###   ########.fr       */
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
}
