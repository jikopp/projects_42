/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:50:44 by ferenc            #+#    #+#             */
/*   Updated: 2025/01/20 15:55:21 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

void	put_player(t_win *game, int width, int height)
{
	if (game->player_position == RIGHT || game->player_position == LEFT || \
	game->player_position == UP || game->player_position == DOWN)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->player.player_idle_right_1, 0 + width * 32, 0 + (height * 32));
	game->x = width;
	game->y = height;
}

void	move_top(t_win *game, int i, int j)
{
	game->player_position = UP;
	if (game->map[j + 1][i] == 'C')
		game->score += 1;
	else if (game->map[j + 1][i] == 'E' && game->coins == game->score)
		on_destroy(game);
	else if (game->map[j + 1][i] == 'E')
	{
		door_locked_up_down(game, j + 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j + 1][i] = 'P';
	put_player(game, i, j + 1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->textures.ground, 0 + i * 32, 0 + (j * 32));
}

void	move_down(t_win *game, int i, int j)
{
	game->player_position = DOWN;
	if (game->map[j - 1][i] == 'C')
		game->score += 1;
	else if (game->map[j - 1][i] == 'E' && game->coins == game->score)
		on_destroy(game);
	else if (game->map[j - 1][i] == 'E')
	{
		door_locked_up_down(game, j - 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j - 1][i] = 'P';
	put_player(game, i, j - 1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->textures.ground, 0 + i * 32, 0 + (j * 32));
}

void	move_left(t_win *game, int i, int j)
{
	game->player_position = LEFT;
	if (game->map[j][i - 1] == 'C')
		game->score += 1;
	else if (game->map[j][i - 1] == 'E' && game->coins == game->score)
		on_destroy(game);
	else if (game->map[j][i - 1] == 'E')
	{
		door_locked_right_left(game, j, i - 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i - 1] = 'P';
	put_player(game, i - 1, j);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->textures.ground, 0 + i * 32, 0 + (j * 32));
}

void	move_right(t_win *game, int i, int j)
{
	game->player_position = RIGHT;
	if (game->map[j][i + 1] == 'C')
		game->score += 1;
	else if (game->map[j][i + 1] == 'E' && game->coins == game->score)
		on_destroy(game);
	else if (game->map[j][i + 1] == 'E')
	{
		door_locked_right_left(game, j, i + 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i + 1] = 'P';
	put_player(game, i + 1, j);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->textures.ground, 0 + i * 32, 0 + (j * 32));
}
