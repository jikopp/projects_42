/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:51:09 by ferenc            #+#    #+#             */
/*   Updated: 2025/01/20 15:56:25 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

void	free_map(t_win *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free (game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_player(t_win *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player.player_idle_right_1);
}

void	free_textures(t_win *game)
{
	mlx_destroy_image(game->mlx_ptr, game->textures.coin);
	mlx_destroy_image(game->mlx_ptr, game->textures.door);
	mlx_destroy_image(game->mlx_ptr, game->textures.ground);
	mlx_destroy_image(game->mlx_ptr, game->textures.wall);
}
