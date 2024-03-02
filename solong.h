/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:16:09 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/03/02 17:32:32 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "./MLX42/include/MLX42/MLX42.h"
# define WIDTH 1800
# define HEIGHT 1800

typedef struct vars{
	mlx_t			*mlx;
	mlx_texture_t	*texture[8];
	mlx_image_t		*img[8];
	char			map[100][100];
	char			map2[100][100];
	int				valid_path;
	int				valid_collectible;
	int				m_width;
	int				m_height;
	int				pos_x;
	int				pos_y;
	int				collectible;
	int				pos_exit_x;
	int				pos_exit_y;
	int				game_over;
	int				move_count;
}t_vars;

void	create_map(t_vars *x, int rows, int cols);
void	setup_img(t_vars *x);
void	clean_up(t_vars **x);
void	error(void);
//void	ft_hook(void *param);
void	ft_hook(mlx_key_data_t keydata, void *param);
int		start_mlx(t_vars **x, char *filename);

/** get next line part */

typedef struct s_list{
	char			*text;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*get_line_text(t_list *head);
void	create_list(t_list **head, int fd);
void	rearrange(t_list **head);
void	append(t_list **head, char *buffer);
t_list	*find_last_node(t_list *head);
int		include_newline(t_list *head);
void	copy_line(char *next_line, t_list *head);
void	free_all(t_list **head, char *buffer);
int		get_line_size(t_list *head);

/** map related stuff */

typedef struct s_map{
	int	m_exit;
	int	m_collectible;
	int	m_player;
}				t_map;
/** creating the virtual table */

void	create_table(char *filename, t_vars **x, int width, int height);
int		ft_strlen(char *str);
void	get_items_positions(t_vars **x);

/** Handling Game Logic */
void	game_logic_right(t_vars **x);
void	game_logic_left(t_vars **x);
void	game_logic_down(t_vars **x);
void	game_logic_up(t_vars **x);
void	fill_table(t_vars **x);
int		e_width(t_vars **x);
int		e_height(t_vars **x);

/** map validation */
int		check_width(char *line, int index);
int		check_borders(int fd, int nb_lines);
int		check_map_rectangular(int fd, int height, int width);
void	init_validate_map(t_map **map);
t_map	*get_map_objects(int fd);
int		validate_map_objects(t_map **map_ref);
int		is_same(char *s1, char *s2);
int		check_map_extension(char *filename);
int		get_nb_lines(int fd);
int		valid_all(char *filename);
int		valid_all_2(char *filename, int nb_lines);
int		get_line_width(char *filename);
void	floodfill(t_vars **x, int pos_x, int pos_y);
int		check_valid_path(t_vars **x);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	check_arguments(void);

#endif
