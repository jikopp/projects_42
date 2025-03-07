/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:51:19 by ferenc            #+#    #+#             */
/*   Updated: 2025/03/06 15:39:29 by fnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

int	check_last_row_rectan(t_win *game)
{
	int	i;

	i = 0;
	while (game->map[game->map_rows][i])
		i++;
	if (i != game->map_cols - 1)
		return (ft_printf("Error\nLast row is incorrect\n"), 1);
	return (0);
}

int	advanced_checks(t_win *game, int linecount, char *map)
{
	if (check_filename(map) == 1)
		return (1);
	if (check_last_row(game->map[linecount - 1]) == 1)
		return (1);
	if (check_rows(game, linecount) == 1)
		return (ft_printf("Error\nMust be surrounded by walls\n"), 1);
	if (check_elements(game) == 1)
		return (ft_printf("Error\nThe map does not have all components\n"), 1);
	if (check_playable(game) == 1)
		return (ft_printf("Error\nThe map is not playable\n"), 1);
	if (check_last_row_rectan(game) == 1)
		return (1);
	return (0);
}

int	check_map(char *map, t_win *game)
{
	int		linecount;
	int		colcount;

	linecount = 0;
	while (game->map[linecount])
		linecount++;
	colcount = 0;
	while (game->map[0][colcount])
		colcount++;
	game->map_cols = colcount;
	game->map_rows = linecount - 1;
	if (advanced_checks(game, linecount, map) == 1)
		return (free_map(game), 1);
	return (0);
}
