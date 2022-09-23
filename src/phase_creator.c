/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:43:23 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/09/23 16:12:27 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_map(char *path_file)

{
	const int	len = ft_strlen(path_file);

	if (ft_memcmp(path_file + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Invalid map file, please try again.");
		return (0);
	}
	return (1);

}

char	**phase_creator(char *map_path)

{
	char	*phase;
	char	*lines;
	int		fd;

	if (!(valid_map(map_path)))
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Map not found");
		return (NULL);
	}
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
		ft_printf("ERROR!");
		free(lines);
		return (NULL);
	}
	//for (int i = 0; i < 4, i++);
	//	ft_printf("%s", lines);
	return (ft_split(lines, '\n'));
}

