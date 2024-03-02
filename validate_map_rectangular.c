/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_rectangular.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:07:34 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 18:51:01 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/**
* check_width- function that check the first and last line in map
* @line:the line to check
* @index:will deferentiate between first and last line
* Return : 1 of all good otherwise 0
**/

int	check_width(char *line, int index)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	if (index != 0)
	{
		if (line[i] != '1')
			return (0);
	}
	return (1);
}

/*
* check_borders-check the borders of map , first condition for whole line
* and the second condition for the  height in both sides
* Return : 1 all good otherwise 0 in case of error
*/

int	check_borders(int fd, int nb_lines)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (i == 0 || i == nb_lines - 1)
		{
			if (check_width(line, i) == 0)
			{
				free(line);
				return (0);
			}
		}
		if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
		{
			free(line);
			return (0);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

/*
* check_map_rectangular-checks that the map is rectangular
* @fd:file descriptor
* @height:the number of lines in the file
* Return: if correct 1  else 0 in case of error;
**/

int	check_map_rectangular(int fd, int height, int width)
{
	char	*line;
	int		i;

	i = 0;
	if (height < 3)
		return (0);
	while (i < height - 1)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) - 1 != width)
		{
			free(line);
			return (0);
		}
		i++;
		free(line);
	}
	line = get_next_line(fd);
	if (ft_strlen(line) != width)
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

/***
* valid_all - will put everything together and test the map.
* filename : the map
* Return: 0 if error or 1 if all good.
*/
int	valid_all(char *filename)
{
	int		fd;
	t_map	*map;
	int		nb_lines;

	if (check_map_extension(filename) == 1)
	{
		ft_putstr("Error\nWrong File extension");
		return (0);
	}
	fd = open(filename, O_RDONLY);
	map = get_map_objects(fd);
	if (validate_map_objects(&map) != 1)
	{
		ft_putstr("Error\nnot valid MAP");
		return (0);
	}
	fd = open(filename, O_RDONLY);
	nb_lines = get_nb_lines(fd);
	if (valid_all_2(filename, nb_lines) == 0)
		return (0);
	return (1);
}

int	valid_all_2(char *filename, int nb_lines)
{
	int	fd;
	int	width;

	fd = open(filename, O_RDONLY);
	if (check_borders(fd, nb_lines) == 0)
	{
		ft_putstr("Error\nborders  not good");
		return (0);
	}
	close(fd);
	width = get_line_width(filename);
	fd = open(filename, O_RDONLY);
	if (check_map_rectangular(fd, nb_lines, width) == 0)
	{
		ft_putstr("Error\nnot rectangular");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
