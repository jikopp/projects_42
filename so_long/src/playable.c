/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:51:38 by ferenc            #+#    #+#             */
/*   Updated: 2025/03/06 15:26:36 by fnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

void	flood_fill(char **map, int row, int col, t_win *game)
{
	if (row < 0 || col < 0 || row >= game->map_rows || col >= game->map_cols)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'F')
		return ;
	if (map[row][col] == 'C')
		game->flood_fill_coins += 1;
	if (map[row][col] == 'E')
		game->exit_row = 1;
	map[row][col] = 'F';
	flood_fill(map, row + 1, col, game);
	flood_fill(map, row - 1, col, game);
	flood_fill(map, row, col + 1, game);
	flood_fill(map, row, col - 1, game);
}

void	check_playable_row(t_win *game, int *c, int *p, int *e)
{
	int	j;
	int	i;

	i = -1;
	while (game->map[++i + 1])
	{
		j = -1;
		while (game->map[i][++j + 1])
		{
			if (game->map[i][j] == 'C')
			{
				*c = 1;
				game->count_coins++;
			}
			if (game->map[i][j] == 'P')
			{
				*p = 1;
				game->y = i;
				game->x = j;
			}
			if (game->map[i][j] == 'E')
				*e = 1;
		}
	}
}

char	**create_map_copy(t_win *game)
{
	char	**map_copy;
	int		i;

	map_copy = ft_calloc(game->map_rows, sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->map_rows)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	return (map_copy);
}

void	free_map_copy(char **map_copy, t_win *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

int	check_playable(t_win *game)
{
	int		p;
	int		e;
	int		c;
	char	**map_copy;

	e = 0;
	p = 0;
	c = 0;
	game->count_coins = 0;
	check_playable_row(game, &c, &p, &e);
	if (c == 0 || p == 0 || e == 0)
		return (1);
	map_copy = create_map_copy(game);
	if (!map_copy)
		return (1);
	game->flood_fill_coins = 0;
	game->exit_row = 0;
	flood_fill(map_copy, game->y, game->x, game);
	free_map_copy(map_copy, game);
	if (game->flood_fill_coins == game->count_coins && game->exit_row == 1)
		return (0);
	return (1);
}
