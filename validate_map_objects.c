/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:28:50 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 05:43:12 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/**
* init_validate_map- init all variables to check the map
*/

void	init_validate_map(t_map **map)
{
	*map = malloc(sizeof(t_map));
	(*map)->m_exit = 0;
	(*map)->m_collectible = 0;
	(*map)->m_player = 0;
}

/**
* get_map_objects-get the components of the map to check them
* @fd: file descriptor that contain the map
* Return a structure that contain the objects
*/

t_map	*get_map_objects(int fd)
{
	t_map	*map;
	int		i;
	char	*line;

	init_validate_map(&map);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == 'E')
				map->m_exit++;
			if (line[i] == 'P')
				map->m_player++;
			if (line[i] == 'C')
				map->m_collectible++;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
/**
* validate_map_objects-check the components from earlier and validate
* t_map: a structure that contain the objects
* Return 1 valid map and 0 for non valid
*/

int	validate_map_objects(t_map **map_ref)
{
	t_map	*map;

	map = *map_ref;
	if (map->m_exit != 1 || map->m_player != 1 || map->m_collectible < 1)
	{
		free(map);
		return (0);
	}
	free(map);
	return (1);
}
