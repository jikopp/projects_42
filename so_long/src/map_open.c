/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:51:25 by ferenc            #+#    #+#             */
/*   Updated: 2025/01/20 16:28:51 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

void	fill_map(t_win *game, int lines, char *map)
{
	int	file;
	int	i;

	i = 0;
	file = open(map, O_RDWR);
	game->moves = 0;
	game->player_position = 0;
	game->map = malloc(sizeof(char *) * (lines + 1));
	if (game->map == NULL)
		return ;
	while (i < lines)
	{
		game->map[i] = get_next_line(file);
		i++;
	}
	game->map[i] = NULL;
	if (check_map(map, game) == 1)
		exit(EXIT_FAILURE);
	game->map_rows = lines;
	game->map_cols = ft_strlen(game->map[0]);
	close(file);
}

int	save_map(char *map, t_win *game)
{
	int		file;
	int		linecount;
	char	*line;

	linecount = 0;
	file = open(map, O_RDWR);
	if (file == -1)
		return (ft_printf("Error\nMap does not exist\n"), 1);
	line = get_next_line(file);
	if (line == NULL)
		exit(EXIT_FAILURE);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		linecount++;
	}
	close(file);
	fill_map(game, linecount, map);
	free(line);
	return (0);
}
