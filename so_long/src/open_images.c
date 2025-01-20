/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:50:23 by ferenc            #+#    #+#             */
/*   Updated: 2025/01/20 16:31:06 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

int	open_ground_coins_door(t_win *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./images/floor.xpm", &game->width, &game->height);
	if (game->textures.ground == NULL)
		return (ft_printf("Error\nFailed to load GROUND texture\n"), 1);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./images/collectible.xpm", &game->width, &game->height);
	if (game->textures.coin == NULL)
		return (ft_printf("Error\nFailed to load COLLECTIBLE texture\n"), 1);
	game->textures.door = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./images/exit.xpm", &game->width, &game->height);
	if (game->textures.door == NULL)
		return (ft_printf("Error\nailed to load DOOR texture\n"), 1);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./images/wall.xpm", &game->width, &game->height);
	if (game->textures.wall == NULL)
		return (ft_printf("Error\nFailed to load WALL texture\n"), 1);
	return (0);
}

void	open_images(t_win *game)
{
	game->height = HEIGHT;
	game->width = WIDTH;
	game->current_frame = 0;
	game->player.player_idle_right_1 = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./images/pl.xpm", &game->width, &game->height);
	if (open_ground_coins_door(game) == 1)
		ft_printf("Error\nFailed to open the images\n");
}
