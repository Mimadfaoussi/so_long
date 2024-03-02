/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:24:16 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 01:44:19 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/**
* get_items_positions -get's the x axis of the Items in the map 
* and also count the collectibles .
* @x:address of the structure that contain the map
* Return: Nothing , we will change values by reference
*/

void	get_items_positions(t_vars **x)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*x)->m_height)
	{
		j = 0;
		while (j < (*x)->m_width)
		{
			if ((*x)->map[i][j] == 'P')
			{
				(*x)->pos_x = j;
				(*x)->pos_y = i;
			}
			else if ((*x)->map[i][j] == 'C')
				(*x)->collectible++;
			else if ((*x)->map[i][j] == 'E')
			{
				(*x)->pos_exit_x = j;
				(*x)->pos_exit_y = i;
			}
			j++;
		}
		i++;
	}
}
/**
* create_table- parse the map and copy the content to a 2-d array.
* @filename: the structure that contain the map
* @x: address of the structure that contain the map (2d array)
* @width: the width of the map
* @height: the height of the map
* Return:void , we will only change the map variable inside structure x.
*/

void	create_table(char *filename, t_vars **x, int width, int height)
{
	int		i;
	int		j;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < height)
	{
		j = 0;
		line = get_next_line(fd);
		while (j < width)
		{
			(*x)->map[i][j] = line[j];
			(*x)->map2[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
	}
	get_items_positions(x);
	close(fd);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	if (nb < 10)
		ft_putchar(nb + '0');
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
