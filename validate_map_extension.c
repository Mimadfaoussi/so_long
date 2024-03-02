/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_extension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:09:18 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 00:32:30 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/**
* is_same-checks if s1 and s2 are the same 
* return 1 if they are the same  otherwise return 0
**/

int	is_same(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	else
		return (0);
}
/**
* check_map_extension-checking the extension of the file 
* @filename:the file we're gonna check
* Return 0 if correct file extension ".bef" else 1 if not
*/

int	check_map_extension(char *filename)
{
	int	length;

	if (!filename)
		return (1);
	length = ft_strlen(filename);
	if (length < 4)
		return (1);
	if (is_same(filename + length - 4, ".bef") == 1)
		return (0);
	else
		return (1);
}

/**
* get_nb_lines - calculate the number of lines in the file
* @fd: file descriptor 
*/

int	get_nb_lines(int fd)
{
	int		i;
	char	*str;

	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		free(str);
		i++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (i);
}

int	get_line_width(char *filename)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (width);
}
