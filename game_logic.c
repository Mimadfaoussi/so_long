/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:48:22 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 17:06:38 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	game_logic_up(t_vars **x)
{
	int	i;
	int	j;

	i = (*x)->pos_y;
	j = (*x)->pos_x;
	if ((*x)->map[i - 1][j] != '1')
	{
		if ((*x)->map[i - 1][j] == 'C')
			(*x)->collectible = (*x)->collectible - 1;
		if ((*x)->map[i - 1][j] != 'E')
			(*x)->map[i - 1][j] = 'P';
		if ((*x)->map[i - 1][j] == 'H')
			(*x)->game_over = 1;
		if ((*x)->map[i][j] != 'E')
			(*x)->map[i][j] = '0';
		(*x)->pos_y = (*x)->pos_y - 1;
		if ((*x)->game_over != 1)
		{
			(*x)->move_count++;
			ft_putstr("MOVES NUMBER : ");
			ft_putnbr((*x)->move_count);
			ft_putchar('\n');
		}
	}
}

void	game_logic_down(t_vars **x)
{
	int	i;
	int	j;

	i = (*x)->pos_y;
	j = (*x)->pos_x;
	if ((*x)->map[i + 1][j] != '1')
	{
		if ((*x)->map[i + 1][j] == 'C')
			(*x)->collectible = (*x)->collectible - 1;
		if ((*x)->map[i + 1][j] == 'H')
			(*x)->game_over = 1;
		if ((*x)->map[i + 1][j] != 'E')
			(*x)->map[i + 1][j] = 'P';
		if ((*x)->map[i][j] != 'E')
			(*x)->map[i][j] = '0';
		(*x)->pos_y = (*x)->pos_y + 1;
		if ((*x)->game_over != 1)
		{
			(*x)->move_count++;
			ft_putstr("MOVES NUMBER : ");
			ft_putnbr((*x)->move_count);
			ft_putchar('\n');
		}
	}
}

void	game_logic_left(t_vars **x)
{
	int	i;
	int	j;

	i = (*x)->pos_y;
	j = (*x)->pos_x;
	if ((*x)->map[i][j - 1] != '1')
	{
		if ((*x)->map[i][j - 1] == 'C')
			(*x)->collectible = (*x)->collectible - 1;
		if ((*x)->map[i][j - 1] == 'H')
			(*x)->game_over = 1;
		if ((*x)->map[i][j - 1] != 'E')
			(*x)->map[i][j - 1] = 'P';
		if ((*x)->map[i][j] != 'E')
			(*x)->map[i][j] = '0';
		(*x)->pos_x = (*x)->pos_x - 1;
		if ((*x)->game_over != 1)
		{
			(*x)->move_count++;
			ft_putstr("MOVES NUMBER : ");
			ft_putnbr((*x)->move_count);
			ft_putchar('\n');
		}
	}
}

void	game_logic_right(t_vars **x)
{
	int	i;
	int	j;

	i = (*x)->pos_y;
	j = (*x)->pos_x;
	if ((*x)->map[i][j + 1] != '1')
	{
		if ((*x)->map[i][j + 1] == 'C')
			(*x)->collectible = (*x)->collectible - 1;
		if ((*x)->map[i][j + 1] == 'H')
			(*x)->game_over = 1;
		if ((*x)->map[i][j + 1] != 'E')
			(*x)->map[i][j + 1] = 'P';
		if ((*x)->map[i][j] != 'E')
			(*x)->map[i][j] = '0';
		(*x)->pos_x = (*x)->pos_x + 1;
		if ((*x)->game_over != 1)
		{
			(*x)->move_count++;
			ft_putstr("MOVES NUMBER : ");
			ft_putnbr((*x)->move_count);
			ft_putchar('\n');
		}
	}
}
