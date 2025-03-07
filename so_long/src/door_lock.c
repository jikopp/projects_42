/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_lock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:50:59 by ferenc            #+#    #+#             */
/*   Updated: 2025/03/07 13:20:22 by fnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

void	door_locked_up_down(t_win *game, int door_row, int door_col)
{
	if (game->player_position == UP)
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
	else if (game->player_position == DOWN)
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
}

void	door_locked_right_left(t_win *game, int door_row, int door_col)
{
	if (game->player_position == RIGHT)
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
	else if (game->player_position == LEFT)
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
}
