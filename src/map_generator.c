/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:17:44 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/10/28 07:22:24 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(char *array, t_config *config)

{
	char	**copy;
	char	**map;

	map = ft_split(array, '\n');
	if (!map)
		return (NULL);
	copy = ft_split(array, '\n');
	if (!copy)
		return (NULL);
	config->cp_map = copy;
	return (map);
}

int	validator(t_config *config)

{
	if (ft_valid(config) == 1)
		return (1);
	else if (valid_path(config, config->avatar.pos_h, \
	config->avatar.pos_w) == 1)
	{
		error_msg("No access to all collectibles");
		return (1);
	}
	if (exit_tester(config, 0, 0) == 1)
		return (1);
	return (0);
}

void	append_map_size(t_config *config)

{
	int	height;

	height = 0;
	while (config->cp_map[height])
		height++;
	config->phase_columns = (ft_strlen(config->phase[0])) * SPRITE;
	config->phase_rows = height * SPRITE;
}

char	*reader(int fd)

{
	static char	*phase;
	static char	*lines;

	while (1)
	{
		phase = get_next_line(fd);
		if (!phase || phase[0] == '\n')
			break ;
		lines = ft_strjoin_gnl(lines, phase);
		if (!lines)
			return (NULL);
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
	if (has_plus_newline(lines) == 1)
		return (NULL);
	return (lines);
}

char	**map_generator(t_config *config, char *path_file)

{
	int			fd;
	char		*map;
	char		**matriz;

	fd = open(path_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: File not found\n");
		return (NULL);
	}
	map = reader(fd);
	if (!(map))
		return (NULL);
	matriz = copy_map(map, config);
	if (!matriz)
	{
		free(map);
		return (NULL);
	}
	free(map);
	return (matriz);
}
