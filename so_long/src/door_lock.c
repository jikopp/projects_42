/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_lock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:50:59 by ferenc            #+#    #+#             */
/*   Updated: 2025/10/10 11:33:00 by fnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

void	door_locked_up_down_right_left(t_win *game, int door_row, int door_col)
{
	if (game->player_position == UP)
		jump_up(game, door_row, door_col);
	else if (game->player_position == DOWN)
		jump_down(game, door_row, door_col);
	else if (game->player_position == RIGHT)
		jump_right(game, door_row, door_col);
	else if (game->player_position == LEFT)
		jump_left(game, door_row, door_col);
}

void	jump_up(t_win *game, int door_row, int door_col)
{
	if (game->map[door_row + 1][door_col] == '1')
		return ;
	if (game->map[door_row + 1][door_col] == 'C')
		game->score += 1;
	game->map[door_row - 1][door_col] = '0';
	game->map[door_row + 1][door_col] = 'P';
	put_player(game, door_col, door_row + 1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->textures.ground, door_col * 32, (door_row - 1) * 32);
	game->moves += 1;
}

void	jump_down(t_win *game, int door_row, int door_col)
{
	if (game->map[door_row - 1][door_col] == '1')
		return ;
	if (game->map[door_row - 1][door_col] == 'C')
		game->score += 1;
	game->map[door_row + 1][door_col] = '0';
	game->map[door_row - 1][door_col] = 'P';
	put_player(game, door_col, door_row - 1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->textures.ground, door_col * 32, (door_row + 1) * 32);
	game->moves += 1;
}

void	jump_right(t_win *game, int door_row, int door_col)
{
	if (game->map[door_row][door_col + 1] == '1')
		return ;
	if (game->map[door_row][door_col + 1] == 'C')
		game->score += 1;
	game->map[door_row][door_col - 1] = '0';
	game->map[door_row][door_col + 1] = 'P';
	put_player(game, door_col + 1, door_row);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->textures.ground, (door_col - 1) * 32, door_row * 32);
	game->moves += 1;
}

void	jump_left(t_win *game, int door_row, int door_col)
{
	if (game->map[door_row][door_col - 1] == '1')
		return ;
	if (game->map[door_row][door_col - 1] == 'C')
		game->score += 1;
	game->map[door_row][door_col + 1] = '0';
	game->map[door_row][door_col - 1] = 'P';
	put_player(game, door_col - 1, door_row);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->textures.ground, (door_col + 1) * 32, door_row * 32);
	game->moves += 1;
}
