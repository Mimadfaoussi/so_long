/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:04:08 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 17:33:50 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	floodfill(t_vars **x, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_y < 0)
		return ;
	if (pos_x >= (*x)->m_width || pos_y >= (*x)->m_height)
		return ;
	if ((*x)->map2[pos_y][pos_x] == '1' || (*x)->map2[pos_y][pos_x] == '\0')
		return ;
	if ((*x)->map2[pos_y][pos_x] == 'C')
		(*x)->valid_collectible++;
	if ((*x)->map2[pos_y][pos_x] == 'E')
		(*x)->valid_path = 1;
	(*x)->map2[pos_y][pos_x] = '\0';
	floodfill(x, pos_x + 1, pos_y);
	floodfill(x, pos_x - 1, pos_y);
	floodfill(x, pos_x, pos_y + 1);
	floodfill(x, pos_x, pos_y - 1);
	return ;
}

int	check_map(char c)
{
	if (c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '0')
		return (1);
	return (0);
}

int	check_the_map(t_vars **x)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*x)->m_height)
	{
		j = 0;
		while (j < (*x)->m_width)
		{
			if (check_map((*x)->map2[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid_path(t_vars **x)
{
	if (check_the_map(x) == 0)
	{
		ft_putstr("Invalid Map charracter \n");
		return (0);
	}
	floodfill(x, (*x)->pos_x, (*x)->pos_y);
	if ((*x)->valid_path == 0)
	{
		ft_putstr("No valid path to the exit\n");
		return (0);
	}
	if ((*x)->valid_collectible != (*x)->collectible)
	{
		ft_putstr("can't reach all the collectibles\n");
		return (0);
	}
	return (1);
}

void	check_arguments(void)
{
	ft_putstr("wrong number of arguments , usage : ./so_long map.ber\n");
	exit(1);
}
