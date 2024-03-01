/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:11:14 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/01 23:59:31 by mfaoussi         ###   ########.fr       */
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

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	**x;

	x = param;
	if (mlx_is_key_down((*x)->mlx, MLX_KEY_ESCAPE))
	{
		//system("leaks exec");
		clean_up(*x);
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

void	mlx_closehook(void* param)
{
	t_vars	**x;

	x = param;
	//system("leaks exec");
	clean_up(*x);
	exit(0);
}

// void mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param);

// void mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param);
// 	mlx_scroll_hook(mlx, &my_scrollhook, NULL);

// void my_scrollhook(double xdelta, double ydelta, void* param)


// void	create_map(t_vars *x, int rows, int cols)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < rows)
// 	{
// 		j = 0;
// 		while (j < cols)
// 		{
// 			if (x->map[i][j] == '0')
// 				mlx_image_to_window(x->mlx, x->img[0], j * 80, i * 80);
// 			else if (x->map[i][j] == '1')
// 				mlx_image_to_window(x->mlx, x->img[1], j * 80, i * 80);
// 			else if (x->map[i][j] == 'C')
// 				mlx_image_to_window(x->mlx, x->img[2], j * 80, i * 80);
// 			else if (x->map[i][j] == 'E')
// 				mlx_image_to_window(x->mlx, x->img[3], j * 80, i * 80);
// 			else if (x->map[i][j] == 'P')
// 				mlx_image_to_window(x->mlx, x->img[4], j * 80, i * 80);
// 			else if (x->map[i][j] == 'H')
// 				mlx_image_to_window(x->mlx, x->img[5], j * 80, i * 80);
// 			j++;
// 		}
// 		i++;
// 	}
// }

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
	if (start_mlx(&x) == 1)
		return (1);
	create_table(argv[1], &x, x->m_width, x->m_height);
	if (check_valid_path(&x) == 0)
	{
		printf("not valid path no exit or collectibles");
		clean_up(x);
		return (1);
	}
	if (!x->mlx)
		error();
	setup_img(x);
	create_map(x, x->m_height, x->m_width);
	mlx_key_hook(x->mlx, &ft_hook, &x);
	mlx_close_hook(x->mlx, &mlx_closehook, &x);
	mlx_loop(x->mlx);
	clean_up(x);
	// system("leaks exec");
	return (EXIT_SUCCESS);
}
//./exec ./maps/map.bef
// gcc  game_logic.c validate_map_extension.c validate_map_rectangular.c validate_map_objects.c solong.c setup_all.c create_table.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ../libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit -o exec