/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:17:44 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/24 23:29:35 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	append_map_size(t_config *config)

{
	int	height;

	height = 0;
	while (config->phase[height])
		height++;
	config->phase_columns = (ft_strlen(config->phase[0])) * SPRITE;
	config->phase_rows = height * SPRITE;
}

char	**reader(int fd)

{
	char	*phase;
	char	*lines;

	phase = ft_strdup("");
	if (!phase)
		return (NULL);
	while (1)
	{
		phase = get_next_line(fd);
		if (phase == NULL || phase[0] == '\n')
			break ;
		lines = ft_strjoin_gnl(lines, phase);
		free(phase);
	}
	free(phase);
	close(fd);
	if (!*lines)
	{
		ft_printf("ERROR!\n");
		free(lines);
		return (NULL);
	}
	return (ft_split(lines, '\n'));
}

char	**map_generator(t_config *config, char *path_file)

{
	int		fd;
	char	**matriz_map;

	fd = open(path_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: File not found\n");
		return (NULL);
	}
	matriz_map = reader(fd);
	config->phase = matriz_map;
	config->copy_phase = matriz_map;
	append_map_size(config);
	return (matriz_map);
}
