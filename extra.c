/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:03:26 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 00:03:48 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/***
* fill_table-function that set the map to '\0' to stop printing
* @x:structure that contain the map
* Return: nothing we will change the map directly.
**/
void	fill_table(t_vars **x)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*x)->m_height)
	{
		j = 0;
		while (j < (*x)->m_width)
		{
			(*x)->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}
/***
* e_width- get the perfect position of the exit image
* @x: the structure that contain map width
* Return:the position in x which we can put the exit img
**/

int	e_width(t_vars **x)
{
	int	width;

	width = (((*x)->m_width * 80) / 2) - 200;
	return (width);
}

/***
* e_height- get the perfect position of the exit image
* @x: the structure that contain map height
* Return:the position in x which we can put the exit img
**/

int	e_height(t_vars **x)
{
	int	height;

	height = (((*x)->m_height * 80) / 2) - 100;
	return (height);
}
