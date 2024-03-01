/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:04:08 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/01 22:57:50 by mfaoussi         ###   ########.fr       */
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

int	check_valid_path(t_vars **x)
{
	floodfill(x, (*x)->pos_x, (*x)->pos_y);
	if ((*x)->valid_path == 0)
		return (0);
	if ((*x)->valid_collectible != (*x)->collectible)
		return (0);
	return (1);
}
