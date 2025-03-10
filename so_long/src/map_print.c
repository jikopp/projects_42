/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:51:30 by ferenc            #+#    #+#             */
/*   Updated: 2025/01/20 16:29:47 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

void	print_map(char *line, t_win *game, int index)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->textures.wall, i * 32, (index * 32));
		else if (line[i] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->textures.ground, i * 32, (index * 32));
		else if (line[i] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->textures.coin, i * 32, (index * 32));
		else if (line[i] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->textures.door, i * 32, (index * 32));
		else if (line[i] == 'P')
			put_player(game, i, index);
		i++;
	}
}

void	add_graphics(t_win *game)
{
	int		i;

	i = 0;
	game->score = 0;
	if (!game->map)
		return ;
	while (game->map[i] != NULL)
	{
		print_map(game->map[i], game, i);
		i++;
	}
}
