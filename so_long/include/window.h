/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:06:23 by fnagy             #+#    #+#             */
/*   Updated: 2025/01/03 10:43:11 by fnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WINDOW_H
# define WINDOW_H


# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>

# define WIDTH 32
# define HEIGHT 32
# define RIGHT 0
# define LEFT 1
# define UP 2
# define DOWN 3

typedef struct s_player
{
	void	*player_idle_right_1;
}	t_player;

typedef struct s_textures
{
	void	*ground;
	void	*coin;
	void	*door;
	void	*wall;
}	t_textures;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			score;
	int			coins;
	int			moves;
	int			height;
	int			width;
	int			x;
	int			y;
	int			map_rows;
	int			map_cols;
	int			exit_row;
	int			exit_col;
	int			flood_fill_coins;
	int			current_frame;
	int			player_position;
	char		**map;
	t_textures	textures;
	t_player	player;
}	t_win;

int		on_destroy(t_win *game);
int		key_hook(int keycode, t_win *game);
void	update_player_position(t_win *game, int key);
void 	count_coins(t_win *game);

int		save_map(char *map, t_win *game);
void	fill_map(t_win *game, int lines, char *map);

void	open_images(t_win *game);
int		open_ground_coins_door(t_win *game);

void	add_graphics(t_win *game);
void	print_map(char *line, t_win *game, int index);

void	put_player(t_win *game, int width, int height);
void	door_locked_up_down(t_win *game, int door_row, int door_col);

void	put_player(t_win *game, int width, int height);
void	move_top(t_win *game, int i, int j);
void	move_down(t_win *game, int i, int j);
void	move_right(t_win *game, int i, int j);
void	move_left(t_win *game, int i, int j);

void	free_map(t_win *game);
void	free_player(t_win *game);
void	free_textures(t_win *game);

int		check_map(char *map, t_win *game);
int		advanced_checks(t_win *game, int linecount, char *map);
int		check_last_row_rectan(t_win *game);
int		check_elements(t_win *game);
int		check_char(t_win *game, int *p, int *e, int i);
int		check_rows(t_win *game, int linecount);
int		check_last_row(char *line);
int		check_filename(char *file);

void	door_locked_up_down(t_win *game, int door_row, int door_col);
void	door_locked_right_left(t_win *game, int door_row, int door_col);

int		check_playable(t_win *game);
void	check_playable_row(t_win *game, int *c, int *p, int *e);

#endif