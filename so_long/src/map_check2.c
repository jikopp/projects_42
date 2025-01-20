/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:02:07 by ferenc            #+#    #+#             */
/*   Updated: 2025/01/20 16:38:03 by ferenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"

int	check_filename(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (!(file[i + 1] == 'b' && file[i + 2] == 'e' \
			&& file[i + 3] == 'r' && !(file[i + 4])))
				return (ft_printf("Error\nProgramm accepts .ber files\n"), 1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_last_row(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (ft_printf("Error\nLast row has to contain walls\n"), 1);
		i++;
	}
	return (0);
}

int	check_rows(t_win *game, int linecount)
{
	int	row_len;
	int	i;

	row_len = 0;
	while (game->map[0][row_len + 1])
	{
		if (game->map[0][row_len] != '1')
			return (1);
		row_len++;
	}
	if (row_len < 3)
		return (1);
	i = 0;
	while (game->map[i + 1])
	{
		if ((int)ft_strlen(game->map[i]) < game->map_cols || \
		(game->map[i][row_len] && i + 1 == linecount))
			return (1);
		if (game->map[i][row_len + 1] || !(game->map[i][row_len - 1]))
			return (1);
		if (game->map[i][0] != '1' || game->map[i][row_len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_char(t_win *game, int *p, int *e, int i)
{
	int	j;

	j = 0;
	while (game->map[i][j + 1])
	{
		if ((game->map[i][j] != 'P' && game->map[i][j] != 'E' \
		&& game->map[i][j] != '1' && game->map[i][j] != '0' \
		&& game->map[i][j] != 'C') || *p > 1 || *e > 1)
			return (1);
		if (game->map[i][j] == 'P')
			*p += 1;
		if (game->map[i][j] == 'E')
			*e += 1;
		j++;
	}
	return (0);
}

int	check_elements(t_win *game)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (game->map[i])
	{
		if (check_char(game, &p, &e, i) == 1)
			return (1);
		i++;
	}
	return (0);
}
