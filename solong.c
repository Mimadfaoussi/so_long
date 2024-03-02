/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:11:14 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 05:58:15 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// void leaks(void)
// {
// 	system("leaks so_long");
// }

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	**x;

	x = param;
	if (mlx_is_key_down((*x)->mlx, MLX_KEY_ESCAPE))
	{
		clean_up(x);
		exit(0);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		game_logic_up(x);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		game_logic_down(x);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		game_logic_right(x);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		game_logic_left(x);
	if ((*x)->collectible == 0)
		(*x)->map[(*x)->pos_exit_y][(*x)->pos_exit_x] = 'H';
	if ((*x)->game_over == 1)
	{
		mlx_image_to_window((*x)->mlx, (*x)->img[7], e_width(x), e_height(x));
		fill_table(x);
	}
	create_map(*x, (*x)->m_height, (*x)->m_width);
}

void	mlx_closehook(void *param)
{
	t_vars	**x;

	x = param;
	clean_up(x);
	exit(0);
}

void	create_map(t_vars *x, int rows, int cols)
{
	int	k[2];

	k[0] = -1;
	while (++k[0] < rows)
	{
		k[1] = -1;
		while (++k[1] < cols)
		{
			if (x->map[k[0]][k[1]] == '0')
				mlx_image_to_window(x->mlx, x->img[0], k[1] * 80, k[0] * 80);
			else if (x->map[k[0]][k[1]] == '1')
				mlx_image_to_window(x->mlx, x->img[1], k[1] * 80, k[0] * 80);
			else if (x->map[k[0]][k[1]] == 'C')
				mlx_image_to_window(x->mlx, x->img[2], k[1] * 80, k[0] * 80);
			else if (x->map[k[0]][k[1]] == 'E')
				mlx_image_to_window(x->mlx, x->img[3], k[1] * 80, k[0] * 80);
			else if (x->map[k[0]][k[1]] == 'P')
				mlx_image_to_window(x->mlx, x->img[4], k[1] * 80, k[0] * 80);
			else if (x->map[k[0]][k[1]] == 'H')
				mlx_image_to_window(x->mlx, x->img[5], k[1] * 80, k[0] * 80);
		}
	}
}


int	main(int argc, char **argv)
{
	t_vars	*x;

	if (argc != 2)
		return (1);
	if (valid_all(argv[1]) == 0)
		return (1);
	if (start_mlx(&x, argv[1]) == 1)
		return (1);
	if (!x->mlx)
		return (1);
	setup_img(x);
	create_table(argv[1], &x, x->m_width, x->m_height);
	if (check_valid_path(&x) == 0)
	{
		clean_up(&x);
		return (1);
	}
	create_map(x, x->m_height, x->m_width);
	mlx_key_hook(x->mlx, &ft_hook, &x);
	mlx_close_hook(x->mlx, &mlx_closehook, &x);
	mlx_loop(x->mlx);
	clean_up(&x);
	return (EXIT_SUCCESS);
}


// atexit(&leaks);
//./exec ./maps/map.bef
// gcc  game_logic.c validate_map_extension.c validate_map_rectangular.c validate_map_objects.c solong.c setup_all.c create_table.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ../libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit -o exec