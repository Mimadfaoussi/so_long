/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:13:03 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/01 23:01:56 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	get_map_height(char *filename)
{
	int		i;
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
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

int	get_map_width(char *filename)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = get_next_line(fd);
	if (!str)
		return (-1);
	i = ft_strlen(str) - 1;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	setup_img(t_vars *x)
{
	x->texture[0] = mlx_load_png("./temp/wall.png");
	x->texture[1] = mlx_load_png("./temp/solid_wall.png");
	x->texture[2] = mlx_load_png("./temp/seeds.png");
	x->texture[3] = mlx_load_png("./temp/before_heaven.png");
	x->texture[4] = mlx_load_png("./temp/bird.png");
	x->texture[5] = mlx_load_png("./temp/heaven.png");
	x->texture[6] = mlx_load_png("./temp/predators.png");
	x->texture[7] = mlx_load_png("./temp/game_over.png");
	x->img[0] = mlx_texture_to_image(x->mlx, x->texture[0]);
	x->img[1] = mlx_texture_to_image(x->mlx, x->texture[1]);
	x->img[2] = mlx_texture_to_image(x->mlx, x->texture[2]);
	x->img[3] = mlx_texture_to_image(x->mlx, x->texture[3]);
	x->img[4] = mlx_texture_to_image(x->mlx, x->texture[4]);
	x->img[5] = mlx_texture_to_image(x->mlx, x->texture[5]);
	x->img[6] = mlx_texture_to_image(x->mlx, x->texture[6]);
	x->img[7] = mlx_texture_to_image(x->mlx, x->texture[7]);
}

int	start_mlx(t_vars **x)
{
	int	height;
	int	width;

	*x = (t_vars *)malloc(sizeof(t_vars));
	if (!*x)
		return (1);
	(*x)->m_height = get_map_height("./maps/map.bef");
	(*x)->m_width = get_map_width("./maps/map.bef");
	(*x)->collectible = 0;
	(*x)->valid_collectible = 0;
	(*x)->valid_path = 0;
	(*x)->game_over = 0;
	(*x)->move_count = 0;
	height = (*x)->m_height * 80;
	width = (*x)->m_width * 80;
	(*x)->mlx = mlx_init(width, height, "SO_LONG", true);
	return (0);
}

void	clean_up(t_vars *x)
{
	mlx_delete_image(x->mlx, x->img[1]);
	mlx_delete_image(x->mlx, x->img[2]);
	mlx_delete_image(x->mlx, x->img[3]);
	mlx_delete_image(x->mlx, x->img[4]);
	mlx_delete_image(x->mlx, x->img[5]);
	mlx_delete_image(x->mlx, x->img[6]);
	mlx_delete_image(x->mlx, x->img[7]);
	mlx_delete_texture(x->texture[1]);
	mlx_delete_texture(x->texture[2]);
	mlx_delete_texture(x->texture[3]);
	mlx_delete_texture(x->texture[4]);
	mlx_delete_texture(x->texture[5]);
	mlx_delete_texture(x->texture[6]);
	mlx_delete_texture(x->texture[7]);
	mlx_close_window((x)->mlx);
	mlx_terminate(x->mlx);
	free(x);
}
