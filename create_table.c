/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:24:16 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/01 22:54:43 by mfaoussi         ###   ########.fr       */
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


// print stuff 

// for (i = 0; i < (*x)->m_height; i++) {
//     for (j = 0; j < (*x)->m_width; j++) {
//         printf("%c ", (*x)->map[i][j]);
//     }
//     printf("\n");
// }


// int main(void)
// {
// 	int fd;
// 	char	tab[100][100];

// 	fd = open("./maps/map.bef",O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	create_table(fd, tab, 13, 5);

// 	for (int i = 0; i < 5; i++)
// 	{
//         for (int j = 0; j < 13; j++)
// 		{
//             printf("%c ", tab[i][j]);
//         }
//         printf("\n");
//     }
// 	return (0);
// }
